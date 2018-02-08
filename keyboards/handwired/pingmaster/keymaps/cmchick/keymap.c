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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KC_KEYMAP(
     ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSPC,BSPC,  NO,   INS,HOME,PGUP,    NO,  NO,  NO,  NO,
     TAB,    Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,  BSLS,    NO,   DEL, END,PGDN,    NO,  NO,  NO,  NO,
     FN31,    A,   S,   D,   F,   G,   H,   J,   K,   L, FN3,QUOT, ENT,   ENT,   NO,  PSCR,SLCK,PAUS,    NO,  NO,  NO,  NO,
     LSFT,     Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT,     RSFT,   FN1,  TRNS,  UP,TRNS,    NO,  NO,  NO,  NO,
    LCTL, LGUI,  FN30,                FN2,              RGUI,  RALT,      RCTL,       LEFT,DOWN,RGHT,    NO,  NO,  NO,  NO
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

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1),
  [2] = ACTION_LAYER_TAP_KEY(2, KC_SPC),
  [3] = ACTION_LAYER_TAP_KEY(3, KC_SCLN),
  [30] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_BSPC),
  [31] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_CLCK)
};
