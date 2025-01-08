#pragma once

#ifndef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2
#endif // !ONESHOT_TAP_TOGGLE

#ifndef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 3000
#endif// !ONESHOT_TIMEOUT

#ifndef QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 4
#endif // !QMK_KEYS_PER_SCAN

#define MACRO_TIMER 5
#define USB_MAX_POWER_CONSUMPTION 100

#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_LINUX
#endif

#if defined(SENCASE_ENABLE)
#define SENTENCE_CASE_TIMEOUT 2000  // Reset state after 2 seconds.
#endif

#if defined(SOCD_ENABLE)
#define SOCD_STRAT SOCD_CLEANER_LAST  // Set what SOCD Cleaning strat to use (SOCD_CLEANER _LAST, _0_WINS, _1_WINS, _NEUTRAL, _OFF) https://getreuer.info/posts/keyboards/socd-cleaner/index.html#resolution-strategies
#endif
