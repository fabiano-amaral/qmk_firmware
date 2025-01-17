/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#include "config_common.h"

#define PRODUCT         Mini-Thumb-Dactyl

/* USB Device descriptor parameter */
#define PRODUCT_ID      0x3536
#define DEVICE_VER      0x0001

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }

#define DIODE_DIRECTION COL2ROW

// #define LED_CAPS_LOCK_PIN F5

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* How to determine left/right hand. Choose one: */
// #define SPLIT_HAND_PIN D2  // must have 10k resistor connect to RXI pin
#define MASTER_LEFT
// #define MASTER_RIGHT
// #undef SOFT_SERIAL_PIN
// #define SOFT_SERIAL_PIN D1
