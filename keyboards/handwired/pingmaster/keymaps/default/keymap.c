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
     ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSPC,BSPC, F21,  PSCR,SLCK,PAUS,    F1,  F2,  F3,  F4,
     TAB,    Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,  BSLS,   F22,   INS,HOME,PGUP,    F5,  F6,  F7,  F8,
     LCTL,    A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT, ENT,   ENT,  F23,   DEL, END,PGDN,    F9, F10, F11, F12,
     LSFT,     Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT,     RSFT,   F24,    NO,  UP,  NO,   F13, F14, F15, F16,
     FN1, LGUI,  LALT,                SPC,              RALT,  RGUI,       FN1,       LEFT,DOWN,RGHT,   F17, F18, F19, F20
  ),

  [1] = KC_KEYMAP( /* FN1 */
     GRV,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  VOLD,VOLU,MUTE,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,  TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
     TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS, TRNS,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,
     TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,  TRNS,  TRNS,PGUP,TRNS,  TRNS,TRNS,TRNS,TRNS,
    TRNS, TRNS,  TRNS,               TRNS,              TRNS,  TRNS,      TRNS,       HOME,PGDN, END,  TRNS,TRNS,TRNS,TRNS
  )
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_MOMENTARY(1),
};
