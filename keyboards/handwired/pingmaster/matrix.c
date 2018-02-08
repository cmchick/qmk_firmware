/*
Copyright 2012-2018 Jun Wako, Jack Humbert, Cleon Chick

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include "wait.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "timer.h"

static uint16_t debouncing_time;
static bool debouncing = false;

/* Matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];
static void init_cols(void);
static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row);
static void select_row(uint8_t row);

__attribute__((weak))
void matrix_init_kb(void) {
  matrix_init_user();
}

__attribute__((weak))
void matrix_scan_kb(void) {
  matrix_scan_user();
}

__attribute__((weak))
void matrix_init_user(void) {
}

__attribute__((weak))
void matrix_scan_user(void) {
}

inline
uint8_t matrix_rows(void) {
  return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void) {
  return MATRIX_COLS;
}

void matrix_init(void) {
  init_cols();
  /* Initialize matrix state to all keys off */
  for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
    matrix[i] = 0;
    matrix_debouncing[i] = 0;
  }

  matrix_init_kb();
}

uint8_t matrix_scan(void) {
  /* For each row, update matrix debounce states */
  for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
    bool matrix_changed = read_cols_on_row(matrix_debouncing, current_row);

    if (matrix_changed) {
      debouncing = true;
      debouncing_time = timer_read();
    }
  }

  if (debouncing && (timer_elapsed(debouncing_time) > DEBOUNCING_DELAY)) {
    /* Debouncing threshold met, realize debounced matrix */
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
      matrix[i] = matrix_debouncing[i];
    }
    debouncing = false;
  }

  matrix_scan_kb();
  return 1;
}

bool matrix_is_modified(void) {
  return !debouncing;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col) {
  return (matrix[row] & ((matrix_row_t)1<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row) {
  return matrix[row];
}

void matrix_print(void) {
  print("\nr/c 01234567\n"); /* matrix header */

  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    phex(row); print(": ");
    print_bin_reverse8(matrix_get_row(row)); /* matrix row */
    print("\n");
  }
}

/*
Column pin config
col: 0   1   2   3   4   5   6   7
pin: D1  D0  D4  C6  D7  E6  B4  B5
*/
static void init_cols(void) {
  /* Input with pull-up(DDR:0, PORT:1) */
  DDRE &= ~_BV(PE6);
  PORTE |= _BV(PE6);
  DDRD &= ~(_BV(PD0) | _BV(PD1) | _BV(PD4) | _BV(PD7));
  PORTD |=  _BV(PD0) | _BV(PD1) | _BV(PD4) | _BV(PD7);
  DDRC &= ~_BV(PC6);
  PORTC |= _BV(PC6);
  DDRB &= ~(_BV(PB4) | _BV(PB5));
  PORTB |=  _BV(PB4) | _BV(PB5);
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
  matrix_row_t last_row_value = current_matrix[current_row];

  select_row(current_row);
  wait_us(10); /* Wait for row selection to stabilize */
  current_matrix[current_row] =
    (PIND & _BV(PD1) ? 0 : _BV(0))
    | (PIND & _BV(PD0) ? 0 : _BV(1))
    | (PIND & _BV(PD4) ? 0 : _BV(2))
    | (PINC & _BV(PC6) ? 0 : _BV(3))
    | (PIND & _BV(PD7) ? 0 : _BV(4))
    | (PINE & _BV(PE6) ? 0 : _BV(5))
    | (PINB & _BV(PB4) ? 0 : _BV(6))
    | (PINB & _BV(PB5) ? 0 : _BV(7));

  return (last_row_value != current_matrix[current_row]);
}

/*
Row pin configuration
mux: 0   1   2   3
pin: F4  F5  F6  F7
*/
inline
void select_row(uint8_t row) {
  /* Output low(DDR:1, PORT:0) to select */
  DDRF |= 0b11110000; /* PF7:4 */
  PORTF = (PORTF & ~0b11110000) | (row << 4); /* mux address is PF7:4 */
}
