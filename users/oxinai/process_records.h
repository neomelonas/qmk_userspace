#pragma once
#include "oxinai.h"

#if defined(KEYMAP_SAFE_RANGE)
  #define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
  #define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
  VRSN = PLACEHOLDER_SAFE_RANGE,              // Prints QMK Firmware and board info
  KC_QWERTY,         // Sets default layer to QWERTY
  KC_COLEMAK,        // Sets default layer to COLEMAK
  KC_DVORAK,         // Sets default layer to DVORAK
  KC_WORKMAN,        // Sets default layer to WORKMAN
  KC_GREEK,          // Sets default layer to GREEK
  KC_FUNCTIONS,      // Sets default layer to FUNCTION
  LAY_QWE,
  LAY_COL,
  LAY_WOR,
  LAY_DVO,
  KC_RGB_T,          // Toggles RGB Layer Indication mode
  KC_UCIS,           // Start UCIS stuff
  KC_SECRET_1,       // test1
  KC_SECRET_2,       // test2
  KC_SECRET_3,       // test3
  KC_SECRET_4,       // test4
  KC_SECRET_5,       // test5
  UC_FLIP,           // (ಠ痊ಠ)┻━┻
  UC_TABL,           // ┬─┬ノ( º _ ºノ)
  UC_SHRG,           // ¯\_(ツ)_/¯
  UC_DISA,           // ಠ_ಠ
  SL_THNK,
  SL_FOOL,
  SL_SHRG,
  SL_JC,
  OS_LIN,            // Linux
  OS_MAC,            // MacOSX
  OS_WIN,            // Windows
  LOCKITM,
  LOCKITW,
  DbZ,               // sends a double zero (00)
  KC_WPM,            // WPM Printer
  UNO,               // whatever my 1 key uno keeb is doing this week
  KEY_TIMER,           // mouse jiggler?
//  DYNAMIC_MACRO_RANGE,// DYN MACROS
  NEW_SAFE_RANGE     //use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
#define XXXXXXX KC_NO

#define KC_RESET RESET
#define KC_RST   KC_RESET

// Function Keys... ALLLL of them.
#define FN_CAPS LT(_FUNC, KC_CAPS)
#define FN_TAB  LT(_FUNC, KC_TAB)
#define FN_SPC  LT(_FUNC, KC_SPC)

#define LO_TAB  LT(_LOWER, KC_TAB)

#define FN_FUNC MO(_FUNC)
#define KC_FUNC MO(_FUNC)

#define FN_MODS MO(_MODS)
#define KC_MODS MO(_MODS)

#define FN_RGBL MO(_RGB)
#define KC_RGBL MO(_RGB) // RGB Layer Momentary

#define KC_FKHM RCTL(KC_RGUI)

#define FN_CTRL LT(_FUNC, KC_LCTRL)
#define CTRLENT MT(MOD_RCTL, KC_ENT)
#define CTRLRGT MT(MOD_RCTL, KC_RIGHT)
#define SHIFTUP MT(MOD_RSFT, KC_UP)
#define MCRSDWN LT(_MACROS, KC_DOWN)
#define FNCDOWN LT(_FUNC, KC_DOWN)
#define GUILEFT MT(MOD_RGUI, KC_LEFT)
#define GUIDOWN MT(MOD_RGUI, KC_DOWN)
#define ALTLEFT MT(MOD_RALT, KC_LEFT)
#define SYS_ESC LT(_SYSTEM, KC_ESC)
#define KC_FINS LT(_FUNC, KC_INS)
#define FN_SPC  LT(_FUNC, KC_SPC)

// Layer keys
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define OLOW    OSL(_LOWER)
#define ORAI    OSL(_RAISE)
#define ADJUST  MO(_ADJUST)
#define MACRS   MO(_MACROS)
#define TG_MODS TG(_MODS)

#define MO_GAME MO(_GAMEPAD)
#define TG_GAME TG(_GAMEPAD)

// Dynamic Macro Keys
#define KC_DMR1 DYN_REC_START1
#define KC_DMR2 DYN_REC_START2
#define KC_DMP1 DYN_MACRO_PLAY1
#define KC_DMP2 DYN_MACRO_PLAY2
#define KC_DMRS DYN_REC_STOP

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

// Layer stuff Part 2: Now with maybe keymap changers
#define QWERTY  KC_QWERTY
#define DVORAK  KC_DVORAK
#define COLEMAK KC_COLEMAK
#define WORKMAN KC_WORKMAN
#define GREEK   KC_GREEK
#define OS_FUNC OSL(_FUNC)
#define OS_MARS OSL(_MACROS)
#define OS_RGB  OSL(_RGB)

#ifdef SWAP_HANDS_ENABLE
#define KC_C1R3 SH_TT
#else // SWAP_HANDS_ENABLE
#define KC_C1R3 KC_BSPC
#endif // SWAP_HANDS_ENABLE

#define BK_LWER LT(_LOWER, KC_BSPC)
#define SP_LWER LT(_LOWER, KC_SPC)
#define DL_RAIS LT(_RAISE, KC_DEL)
#define ET_RAIS LT(_RAISE, KC_ENTER)

/* One Shot keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

// Misc
#define ALT_APP ALT_T(KC_APP)

#define MG_NKRO MAGIC_TOGGLE_NKRO

#define UC_IRNY UC(0x2E2E)
#define UC_CLUE UC(0x203D)
