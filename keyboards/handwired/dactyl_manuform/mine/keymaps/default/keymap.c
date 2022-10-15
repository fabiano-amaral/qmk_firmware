#include "../../keyboard.h"
#include "action_layer.h"
#include "quantum.h"
extern keymap_config_t keymap_config;

#define _BASE 0
#define _FN   1

#define _____ KC_NO

#define KM_A LALT_T(KC_A)
#define KM_S LCTL_T(KC_S)
#define KM_D LSFT_T(KC_D)
#define KM_F LGUI_T(KC_F)

#define KM_SC RALT_T(KC_SCLN)
#define KM_L RCTL_T(KC_L)
#define KM_K RSFT_T(KC_K)
#define KM_J RGUI_T(KC_J)

// Mod-Tap
#define SFT_BSPC LSFT_T(KC_BSPC)
#define CMD_BSPC LCMD_T(KC_BSPC)
#define CTL_BSPC LCTL_T(KC_BSPC)
#define SFT_A    LSFT_T(KC_A)
#define SFT_Z    LSFT_T(KC_Z)
#define SFT_SCLN LSFT_T(KC_SCLN)
#define SFT_QUOT LSFT_T(KC_QUOT)
#define SFT_DEL  LSFT_T(KC_DEL)
#define CMD_DEL  LCMD_T(KC_DEL)
#define CMD_SPC  RCMD_T(KC_SPC)
#define CTL_SPC  RCTL_T(KC_SPC)
#define ALT_CAPS ALT_T(KC_CAPS)
#define SFT_ENT  RSFT_T(KC_ENT)
#define CTL_TAB  CTL_T(KC_TAB)
#define ALT_TAB  ALT_T(KC_TAB)
#define ALT_ESC  ALT_T(KC_ESC)
#define CTL_ESC  CTL_T(KC_ESC)

// compose keys
#define CMD_TAB  LCMD(KC_TAB)
#define CMD_RTAB LCMD(KC_GRAVE)
#define CTL_LEFT LCTL(KC_LEFT)
#define CTL_RGHT LCTL(KC_RIGHT)

// mouse keys
#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

// active layers
#define LY_FN  MO(_FN)

// detect mod status
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
  KC_GRV,  KC_1,  KC_2,    KC_3,  KC_4,    KC_5,                         KC_6,    KC_7,  KC_8,    KC_9,   KC_0,   KC_PSCR,\
  KC_TAB,  KC_Q,  KC_W,    KC_E,  KC_R,    KC_T,                         KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,   KC_BSLS,\
  CTL_ESC, KM_A,  KM_S,    KM_D,  KM_F,    KC_G,                         KC_H,    KM_J,  KM_K,    KM_L,   KM_SC,  KC_QUOT,\
  KC_LCMD, KC_Z,  KC_X,    KC_C,  KC_V,    KC_B,                         KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,_____,  \
                  KC_LBRC, KC_RBRC,                                                      KC_MINS, KC_EQL,                 \
                                LY_FN, CMD_SPC, SFT_DEL,     ALT_ESC, CTL_BSPC, SFT_ENT                                 \
),

[_FN] = LAYOUT( \
  _____,   KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,  KC_F11,\
  KC_TAB,  KC_GRV,  _____,  KC_CIRC, _____, _____,                       _____,   _____,   _____,   _____,     KC_VOLU, KC_F12,\
  _____, KC_TILD, KC_MINS, KC_PPLS, KC_PEQL, _____,                       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  KC_MUTE, _____, \
  _____, _____,  _____,  _____, _____,_____,                       KC_HOME, KC_END,  KC_PGUP, KC_PGDOWN, KC_VOLD, _____, \
                   _____,  RESET,                                                       CTL_LEFT,  CTL_RGHT,                \
                                 SFT_DEL,CTL_BSPC, _____,   KC_LALT, CTL_SPC, SFT_ENT                                      \
)};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            return TAPPING_TERM + 1250;
        case LT(1, KC_GRV):
            return 130;
        default:
            return TAPPING_TERM;
    }
}
