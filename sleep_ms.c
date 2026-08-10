#include "sleep_ms.h"

#if defined(_WIN32)

#include <windows.h>

void sleep_ms(uint64_t milliseconds)
{
    /*
     * Sleep() akzeptiert nur DWORD.
     * Sehr große Zeiträume werden daher portionsweise verarbeitet.
     */
    while (milliseconds > UINT32_MAX) {
        Sleep(UINT32_MAX);
        milliseconds -= UINT32_MAX;
    }

    Sleep((DWORD)milliseconds);
}

#elif defined(__unix__) || defined(__APPLE__) || defined(__linux__)

#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <errno.h>

void sleep_ms(uint64_t milliseconds)
{
    struct timespec remaining = {
        .tv_sec  = (time_t)(milliseconds / 1000),
        .tv_nsec = (long)((milliseconds % 1000) * 1000000ULL)
    };

    /*
     * nanosleep() kann durch ein Signal unterbrochen werden.
     * In diesem Fall schlafen wir für die verbleibende Dauer weiter.
     */
    while (nanosleep(&remaining, &remaining) == -1 && errno == EINTR) {
    }
}

#else

#error "sleep_ms() wird auf diesem Betriebssystem noch nicht unterstützt."

#endif
