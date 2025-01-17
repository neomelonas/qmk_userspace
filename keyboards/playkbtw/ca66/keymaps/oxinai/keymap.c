#include QMK_KEYBOARD_H
#include "oxinai.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    QK_GESC,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_BSPC, KC_GRV,
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,          KC_PGUP,
    KC_LCTRL,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,           KC_PGDN,
    KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    LT(_FUNC,KC_V),KC_B,   KC_N, KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,                     KC_RGUI,
    KC_LCTL,          KC_LGUI, KC_LALT,          FN_SPC,    FN_SPC,                  KC_NO,   KC_RALT, FN_FUNC, KC_LEFT,  KC_DOWN, KC_RGHT),

  [_FUNC] = LAYOUT(
    KC_GRV,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL, RGB_TOG,
    _______,          KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_INS,  _______,   _______, _______, _______, AC_TOGG, SOCDTOG, VRSN,    QK_BOOT,         KC_HOME,
    _______,          KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,  KC_DEL,  SELWORD, _______, _______, _______, RGB_VAD, RGB_VAI,          _______,         KC_END,
    KC_LSFT, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_CAPS, _______, RGB_HUI,                  RGB_MOD,
    KC_LCTL,          KC_LGUI, KC_LALT,          _______,          _______,          _______, _______, _______, RGB_SAD, RGB_HUD, RGB_SAI),
};
