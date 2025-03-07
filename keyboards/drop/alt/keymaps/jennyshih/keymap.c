// Copyright 2023 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "features/select_word.h"

enum custom_keycodes {
  SWORD = SAFE_RANGE,
  SBACK,
  SLINE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE,
        LT(1, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_VOLU,
        CTL_T(KC_GRV), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_VOLD,
        SC_LSPO,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,          KC_UP,   KC_MEDIA_PLAY_PAUSE,
        MO(1),         KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RCTL, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT, KC_DEL,
        _______, KC_GRV,  SWORD,   SLINE,   SBACK,   KC_F15,  _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, KC_HOME,
        _______, KC_F16,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, KC_PGUP,
        _______, _______, RM_TOGG, _______, _______, RM_NEXT, NK_TOGG, _______, _______, _______, _______, _______,          KC_BRIU, KC_PGDN,
        _______, _______, _______,                            _______,                            KC_APP,  _______, KC_INS,  KC_BRID, KC_END
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_select_word(keycode, record)) { return false; }

  switch (keycode) {
    case SBACK:  // Backward word selection.
      if (record->event.pressed) {
        select_word_register('B');
      } else {
        select_word_unregister();
      }
      break;

    case SWORD:  // Forward word selection.
      if (record->event.pressed) {
        select_word_register('W');
      } else {
        select_word_unregister();
      }
      break;

    case SLINE:  // Line selection.
      if(record->event.pressed) {
        select_word_register('L');
      } else {
        select_word_unregister();
      }
      break;
  }

  return true;
}
