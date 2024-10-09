#pragma once
#include "quantum.h"
#include "version.h"
//#include "eeprom.h"
#include "process_records.h"

#if defined(CONSOLE_ENABLE)
#include "print.h"
#endif

#if defined(QMKRC_ENABLE)
#include "qmk_rc.h"
#endif

#if defined(CAPS_WORD)
#include "caps_word.h"
#endif

#if defined(AUTO_CORRECT)
#include "autocorrection.h"
#endif
/*
#if defined(SELECT_WORD)
#include "select_word.h"
#endif
*/
#if defined(TAP_DANCE_ENABLE)
  #include "tap_dances.h"
#endif

/* Define layer names */
enum userspace_layers {
  _QWERTY = 0,
  _NUMLOCK,
  _COLEMAK,
  _WORKMAN,
  _DVORAK,
  _SYSTEM,
//  _CALC,
  _GREEK,
  _FUNC,
//  _MODS,
//  _RGB,
//  _EMOJI,
//  _GAMEPAD,
//  _HITBOX,
//  _MACROS,
//  _MEDIA,
//  _MOUSE,
//  _LOWER,
//  _RAISE,
//  _ADJUST,
};

typedef union {
  uint8_t raw;
} userspace_config_t;

extern userspace_config_t userspace_config;
