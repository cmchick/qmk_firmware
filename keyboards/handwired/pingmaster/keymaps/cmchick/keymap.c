/* Copyright 2018 Cleon Chick
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "pingmaster.h"

#define FN_SCLN LT(3, KC_SCLN)
#define CTLCLCK RCTL_T(KC_CLCK)
#define ALTBSPC ALT_T(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KEYMAP_STACKED(
     KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,KC_BSPC,  KC_NO,
     KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,   KC_BSLS,      KC_NO,
     CTLCLCK,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,FN_SCLN,KC_QUOT, KC_ENT,     KC_ENT,    KC_NO,
     KC_LSFT,     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,      KC_RSFT,         TT(1),
    KC_LCTL, KC_LGUI,  ALTBSPC,                    LT(2,KC_SPC),                    KC_RALT,  KC_RGUI,          KC_RCTL,

     KC_INS,KC_HOME,KC_PGUP,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
     KC_DEL, KC_END,KC_PGDN,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_PSCR,KC_SLCK,KC_PAUS,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_TRNS,  KC_UP,KC_TRNS,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_LEFT,KC_DOWN,KC_RGHT,   KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),
  [1] = KC_KEYMAP( /* "FN" */
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    P7,  P8,  P9,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,  TRNS,    P4,  P5,  P6,  TRNS,TRNS,TRNS,TRNS,
     TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS, TRNS,    P1,  P2,  P3,  TRNS,TRNS,TRNS,TRNS,
     TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,  TRNS,    P0,TRNS,PDOT,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,  TRNS,               TRNS,              TRNS,  TRNS,      TRNS,       TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS
  ),
  [2] = KC_KEYMAP( /* SPC */
     GRV,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,  TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
     TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS, TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
     TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,  TRNS,  TRNS,PGUP,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,  TRNS,               TRNS,              TRNS,  TRNS,      TRNS,       HOME,PGDN, END,  TRNS,TRNS,TRNS,TRNS
  ),
  [3] = KC_KEYMAP( /* SCLN */
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, PGUP,  UP,PGDN,TRNS,TRNS,TRNS,PGUP,  UP,PGDN,TRNS,TRNS,TRNS,  TRNS,  TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
     TRNS, LEFT,DOWN,RGHT,TRNS,HOME, END,LEFT,DOWN,RGHT,TRNS,TRNS,PENT,  PENT, TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
     TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,  NLCK,  TRNS,PMNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,  TRNS,               TRNS,              TRNS,  TRNS,      TRNS,       PSLS,PPLS,PAST,  TRNS,TRNS,TRNS,TRNS
  )
};
