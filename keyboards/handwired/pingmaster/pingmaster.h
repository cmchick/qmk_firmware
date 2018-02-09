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
#ifndef PINGMASTER_H
#define PINGMASTER_H

#include "quantum.h"

#define KC_KEYMAP( \
  K00,K08,K05,K0D,K15,K1D,K25,K2D,K35,K3D,K45,K4D,K55,K5D,K65,K6F, K77,K7F,K7D, K75,K6D,K68,K70, \
  K01, K09,K04,K0C,K14,K1C,K24,K2C,K34,K3C,K44,K4C,K54, K5C,  K64, K76,K7E,K7C, K74,K6C,K69,K71, \
   K10, K18,K03,K0B,K13,K1B,K23,K2B,K33,K3B,K43,K4B,K53, K5B, K63, K73,K6E,K7B, K6B,K61,K59,K66, \
   K19,  K02,K0A,K12,K1A,K22,K2A,K32,K3A,K42,K4A,K5A,   K52,  K62, K6A,K72,K7A, K49,K60,K58,K50, \
  K20, K21,  K28,           K31,            K38,  K39,    K40,     K41,K30,K48, K51,K67,K79,K78 \
) { \
  { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_NO,    KC_NO    }, \
  { KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D, KC_NO,    KC_NO    }, \
  { KC_##K10, KC_NO,    KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_NO,    KC_NO    }, \
  { KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_NO,    KC_NO    }, \
  { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_NO,    KC_NO    }, \
  { KC_##K28, KC_NO,    KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_NO,    KC_NO    }, \
  { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_NO,    KC_NO    }, \
  { KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D, KC_NO,    KC_NO    }, \
  { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_NO,    KC_NO    }, \
  { KC_##K48, KC_##K49, KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D, KC_NO,    KC_NO    }, \
  { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_NO,    KC_NO    }, \
  { KC_##K58, KC_##K59, KC_##K5A, KC_##K5B, KC_##K5C, KC_##K5D, KC_NO,    KC_NO    }, \
  { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67 }, \
  { KC_##K68, KC_##K69, KC_##K6A, KC_##K6B, KC_##K6C, KC_##K6D, KC_##K6E, KC_##K6F }, \
  { KC_##K70, KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_##K76, KC_##K77 }, \
  { KC_##K78, KC_##K79, KC_##K7A, KC_##K7B, KC_##K7C, KC_##K7D, KC_##K7E, KC_##K7F } \
}

#define KEYMAP( \
  K00,K08,K05,K0D,K15,K1D,K25,K2D,K35,K3D,K45,K4D,K55,K5D,K65,K6F, K77,K7F,K7D, K75,K6D,K68,K70, \
  K01, K09,K04,K0C,K14,K1C,K24,K2C,K34,K3C,K44,K4C,K54, K5C,  K64, K76,K7E,K7C, K74,K6C,K69,K71, \
   K10, K18,K03,K0B,K13,K1B,K23,K2B,K33,K3B,K43,K4B,K53, K5B, K63, K73,K6E,K7B, K6B,K61,K59,K66, \
   K19,  K02,K0A,K12,K1A,K22,K2A,K32,K3A,K42,K4A,K5A,   K52,  K62, K6A,K72,K7A, K49,K60,K58,K50, \
  K20, K21,  K28,           K31,            K38,  K39,    K40,     K41,K30,K48, K51,K67,K79,K78 \
) { \
  { K00,   K01, K02, K03, K04, K05, KC_NO, KC_NO }, \
  { K08,   K09, K0A, K0B, K0C, K0D, KC_NO, KC_NO }, \
  { K10, KC_NO, K12, K13, K14, K15, KC_NO, KC_NO }, \
  { K18,   K19, K1A, K1B, K1C, K1D, KC_NO, KC_NO }, \
  { K20,   K21, K22, K23, K24, K25, KC_NO, KC_NO }, \
  { K28, KC_NO, K2A, K2B, K2C, K2D, KC_NO, KC_NO }, \
  { K30,   K31, K32, K33, K34, K35, KC_NO, KC_NO }, \
  { K38,   K39, K3A, K3B, K3C, K3D, KC_NO, KC_NO }, \
  { K40,   K41, K42, K43, K44, K45, KC_NO, KC_NO }, \
  { K48,   K49, K4A, K4B, K4C, K4D, KC_NO, KC_NO }, \
  { K50,   K51, K52, K53, K54, K55, KC_NO, KC_NO }, \
  { K58,   K59, K5A, K5B, K5C, K5D, KC_NO, KC_NO }, \
  { K60,   K61, K62, K63, K64, K65,   K66,   K67 }, \
  { K68,   K69, K6A, K6B, K6C, K6D,   K6E,   K6F }, \
  { K70,   K71, K72, K73, K74, K75,   K76,   K77 }, \
  { K78,   K79, K7A, K7B, K7C, K7D,   K7E,   K7F }  \
}

#define KC_KEYMAP_STACKED( \
  K00,K08,K05,K0D,K15,K1D,K25,K2D,K35,K3D,K45,K4D,K55,K5D,K65,K6F, \
  K01, K09,K04,K0C,K14,K1C,K24,K2C,K34,K3C,K44,K4C,K54, K5C,  K64, \
   K10, K18,K03,K0B,K13,K1B,K23,K2B,K33,K3B,K43,K4B,K53, K5B, K63, \
   K19,  K02,K0A,K12,K1A,K22,K2A,K32,K3A,K42,K4A,K5A,   K52,  K62, \
  K20, K21,  K28,           K31,            K38,  K39,    K40, \
\
  K77,K7F,K7D, K75,K6D,K68,K70, \
  K76,K7E,K7C, K74,K6C,K69,K71, \
  K73,K6E,K7B, K6B,K61,K59,K66, \
  K6A,K72,K7A, K49,K60,K58,K50, \
  K41,K30,K48, K51,K67,K79,K78  \
) { \
  { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_NO,    KC_NO    }, \
  { KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D, KC_NO,    KC_NO    }, \
  { KC_##K10, KC_NO,    KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_NO,    KC_NO    }, \
  { KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_NO,    KC_NO    }, \
  { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_NO,    KC_NO    }, \
  { KC_##K28, KC_NO,    KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_NO,    KC_NO    }, \
  { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_NO,    KC_NO    }, \
  { KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D, KC_NO,    KC_NO    }, \
  { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_NO,    KC_NO    }, \
  { KC_##K48, KC_##K49, KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D, KC_NO,    KC_NO    }, \
  { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_NO,    KC_NO    }, \
  { KC_##K58, KC_##K59, KC_##K5A, KC_##K5B, KC_##K5C, KC_##K5D, KC_NO,    KC_NO    }, \
  { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67 }, \
  { KC_##K68, KC_##K69, KC_##K6A, KC_##K6B, KC_##K6C, KC_##K6D, KC_##K6E, KC_##K6F }, \
  { KC_##K70, KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_##K76, KC_##K77 }, \
  { KC_##K78, KC_##K79, KC_##K7A, KC_##K7B, KC_##K7C, KC_##K7D, KC_##K7E, KC_##K7F } \
}

#define KEYMAP_STACKED( \
  K00,K08,K05,K0D,K15,K1D,K25,K2D,K35,K3D,K45,K4D,K55,K5D,K65,K6F, \
  K01, K09,K04,K0C,K14,K1C,K24,K2C,K34,K3C,K44,K4C,K54, K5C,  K64, \
   K10, K18,K03,K0B,K13,K1B,K23,K2B,K33,K3B,K43,K4B,K53, K5B, K63, \
   K19,  K02,K0A,K12,K1A,K22,K2A,K32,K3A,K42,K4A,K5A,   K52,  K62, \
  K20, K21,  K28,           K31,            K38,  K39,    K40, \
\
  K77,K7F,K7D, K75,K6D,K68,K70, \
  K76,K7E,K7C, K74,K6C,K69,K71, \
  K73,K6E,K7B, K6B,K61,K59,K66, \
  K6A,K72,K7A, K49,K60,K58,K50, \
  K41,K30,K48, K51,K67,K79,K78 \
) { \
  { K00,   K01, K02, K03, K04, K05, KC_NO, KC_NO }, \
  { K08,   K09, K0A, K0B, K0C, K0D, KC_NO, KC_NO }, \
  { K10, KC_NO, K12, K13, K14, K15, KC_NO, KC_NO }, \
  { K18,   K19, K1A, K1B, K1C, K1D, KC_NO, KC_NO }, \
  { K20,   K21, K22, K23, K24, K25, KC_NO, KC_NO }, \
  { K28, KC_NO, K2A, K2B, K2C, K2D, KC_NO, KC_NO }, \
  { K30,   K31, K32, K33, K34, K35, KC_NO, KC_NO }, \
  { K38,   K39, K3A, K3B, K3C, K3D, KC_NO, KC_NO }, \
  { K40,   K41, K42, K43, K44, K45, KC_NO, KC_NO }, \
  { K48,   K49, K4A, K4B, K4C, K4D, KC_NO, KC_NO }, \
  { K50,   K51, K52, K53, K54, K55, KC_NO, KC_NO }, \
  { K58,   K59, K5A, K5B, K5C, K5D, KC_NO, KC_NO }, \
  { K60,   K61, K62, K63, K64, K65,   K66,   K67 }, \
  { K68,   K69, K6A, K6B, K6C, K6D,   K6E,   K6F }, \
  { K70,   K71, K72, K73, K74, K75,   K76,   K77 }, \
  { K78,   K79, K7A, K7B, K7C, K7D,   K7E,   K7F }  \
}

#endif
