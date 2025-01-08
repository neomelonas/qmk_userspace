// Defines actions for my global custom keycodes. Defined in oxinai.h file, parts (most) shamelessly stolen from drashna :)
// Then runs the _keymap's record handler if not processed here
#include "oxinai.h"

uint16_t copy_paste_timer;
static bool key_trigger = false;
#ifdef SOCD_ENABLE
socd_cleaner_t socd_v = {{KC_W, KC_S}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_h = {{KC_A, KC_D}, SOCD_CLEANER_LAST};
#endif

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

__attribute__ ((weak))
uint32_t layer_state_set_keymap(uint32_t state) {
    return state;
}

#ifdef TRILAYER_ENABLED
uint32_t layer_state_set_user(uint32_t state)
{
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
#endif

__attribute__ ((weak))
bool process_caps_word(uint16_t keycode, keyrecord_t* record) { return true; }

__attribute__ ((weak))
bool process_autocorrection(uint16_t keycode, keyrecord_t* record)  { return true; }

// here be dragons...
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

// If console is enabled, it will print the matrix position and status of each key pressed
#if defined(KEYLOGGER_ENABLE) && defined(CONSOLE_ENABLE)
if (record->event.pressed) {
    uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
             keycode,
             record->event.key.row,
             record->event.key.col,
             get_highest_layer(layer_state),
             record->event.pressed,
             get_mods(),
             get_oneshot_mods(),
             record->tap.count
           );
    }
//  uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state));
#endif //KEYLOGGER_ENABLE

#ifdef SOCD_ENABLE
  if (!process_socd_cleaner(keycode, record, &socd_v)) { return false; }
  if (!process_socd_cleaner(keycode, record, &socd_h)) { return false; }

  switch (keycode) {
    case SOCDON:  // Turn SOCD Cleaner on.
      if (record->event.pressed) {
        socd_cleaner_enabled = true;
      }
      return false;
    case SOCDOFF:  // Turn SOCD Cleaner off.
      if (record->event.pressed) {
        socd_cleaner_enabled = false;
      }
      return false;
    case SOCDTOG:  // Toggle SOCD Cleaner.
      if (record->event.pressed) {
        socd_cleaner_enabled = !socd_cleaner_enabled;
      }
      return false;
  }
#endif
// #ifdef SENCASE_ENABLE
//   if (!process_sentence_case(keycode, record)) { return false; }
//     case SC_TOGG:  // Toggle SOCD Cleaner.
//     if (record->event.pressed) {
//       sentence_case_toggle();
//     }
//     return false;
// #endif

// If dynamic macros are enabled, use 'em.
#ifdef DYNMAC_ENABLE
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
#endif //DYNMAC_ENABLE
  switch (keycode) {
  //Switch Default layouts
  case KC_QWERTY:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_QWERTY);
    }
    break;
  case KC_COLEMAK:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_COLEMAK);
    }
    break;
  case KC_DVORAK:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_DVORAK);
    }
    break;
  case KC_WORKMAN:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_WORKMAN);
    }
    break;
  case KC_GREEK:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_GREEK);
    }
    break;
#ifdef UCIS_ENABLE
  case KC_UCIS:
    qk_ucis_start();
    return false;
    break;
#endif
  // Because hitting two or three keys at once is toooooo many D:
  case LOCKITM:
    SEND_STRING(SS_LCTL(SS_LGUI("q")));
    return false;
    break;
  case LOCKITW:
    SEND_STRING(SS_LGUI("l"));
    return false;
    break;
  // Prints version if Console is enabled.
  case VRSN:
    if (record->event.pressed) {
      send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), MACRO_TIMER);
    }
    break;
#if defined(WPM_ENABLE)
  case KC_WPM:
    get_current_wpm();
    break;
#endif
  case SL_SHRG:
    if (record->event.pressed) {
      send_string("/shrug");
    }
    break;
  case SL_FOOL:
    if (record->event.pressed) {
      send_string(":fool:");
    }
    break;
  case SL_THNK:
    if (record->event.pressed) {
      send_string(":thunking:");
    }
    break;
  case SL_JC:
    if (record->event.pressed) {
      send_string(":jimcannon:");
    }
    break;
  case DbZ:  // 10key double 0
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_KP_0)SS_TAP(X_KP_0));
    }
    break;
  case KEY_TIMER:  // mouse jiggler
    if (record->event.pressed) {
        key_trigger ^= 1;
    }
    break;
  }
  return process_record_keymap(keycode, record) &&
  process_record_secrets(keycode, record);
}
