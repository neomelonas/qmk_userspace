// Defines actions for my global custom keycodes. Defined in oxinai.h file, parts (most) shamelessly stolen from drashna :)
// Then runs the _keymap's record handler if not processed here
#include "oxinai.h"

uint16_t copy_paste_timer;
static bool key_trigger = false;

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
/*
#if defined(AUTO_CORRECT)
  if (!process_autocorrection(keycode, record)) { return false; }
#endif // Autocorrect

#if defined(CAPS_WORD)
  if (!process_caps_word(keycode, record)) { return false; }
#endif // capitalize just a word
*/

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
#ifdef UNICODE_ENABLE
  case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
    if (record->event.pressed) {
      //send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
    }
    break;
  case UC_TABL: // ┬─┬ノ( º _ ºノ)
    if (record->event.pressed) {
      //send_unicode_string("┬─┬ノ( º _ ºノ)");
    }
    break;
  case UC_SHRG: // ¯\_(ツ)_/¯
    if (record->event.pressed) {
      //send_unicode_string("¯\_(ツ)_/¯");
    }
    break;
  case UC_DISA: // ಠ_ಠ
    if (record->event.pressed) {
      //send_unicode_string("ಠ_ಠ");
    }
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

