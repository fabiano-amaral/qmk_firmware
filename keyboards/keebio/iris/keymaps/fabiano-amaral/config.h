/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

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
#define EE_HANDS
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#define AUTO_SHIFT_TIMEOUT 160
#define RETRO_SHIFT


// #define NO_AUTO_SHIFT_SPECIAL
// I'm only using Linux, so let's set the Linux mode

// Using "I" because it translates to "U" on Colemak
// #define UNICODE_KEY_LNX  LCTL(LSFT(KC_I))

// #define RGBLIGHT_LIMIT_VAL 150

// Both are not supported when using lto compilation
// I'm disabling them since I enabled it on `rules.mk`
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
