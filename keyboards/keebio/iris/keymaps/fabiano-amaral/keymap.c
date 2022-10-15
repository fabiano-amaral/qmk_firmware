#include QMK_KEYBOARD_H
#include "quantum.h"

#define _START 0
#define _LOWER 1
#define _RAISE 2
#define RSESPC LT(_RAISE, KC_SPC)
#define LSELECT G(KC_A)
#define LSAVE G(KC_S)
#define LCLOSE G(KC_W)
#define LUNDO G(KC_Z)
#define LCUT G(KC_X)
#define LCOPY G(KC_C)
#define LPASTE G(KC_V)
#define LFIND G(KC_F)
#define LSPACE G(KC_SPC)
#define TERM C(KC_GRV)

// Mods, teclas com duas funções
#define CESC MT(MOD_LCTL, KC_ESC)
#define CMD_SPC MT(MOD_LGUI, KC_SPC)
#define SHT_BSP MT(MOD_LSFT, KC_BSPC)
#define HYPER MT(MOD_HYPR, KC_ESC)
// home row mod
#define KM_A LALT_T(KC_A)
#define KM_F LCTL_T(KC_F)
#define KM_D LSFT_T(KC_D)
#define KM_S LGUI_T(KC_S)

#define KM_SC RALT_T(KC_SCLN)
#define KM_J RCTL_T(KC_J)
#define KM_K RSFT_T(KC_K)
#define KM_L RGUI_T(KC_L)

#define KM_H LT(LOWER, KC_H)
#define KM_G LT(LOWER, KC_G)

enum macro_keycodes { KC_ALT_TAB };


enum custom_keycodes {
    START = SAFE_RANGE,
    LOWER,
    RAISE,

    // Here are the custom keycodes related to the Qwerty -> Colemak difference.
    // It's not possible to just send the right hex because the OS will translate
    // and it will be wrong when it arrives. i.e. 1F44F will become 1E44E since
    // "f" is positioned as "e" on Colemak.
    THMUP,
};

enum unicode_names {
    CRY2,   // crying face 😢
    CELEB,  // celebration 🙌
    CONFU,  // confused 😕
    EYES,   // eyes 👀
    GRIN,   // grinning face 😊
    HEART,  // heart ❤
    OKHND,  // ok hand sign 👌
    THINK,  // thinking face 🤔
    CLAP,   // clap 👏
    TJOY,   // tears of joy 😂
    UNAMU,  // unamused 😒
    WINK,   // wink 😉
};

const uint32_t PROGMEM unicode_map[] = {
    // name = clmk'ed, // original
    [CRY2]  = 0x1E622,  // 0x1F622
    [CELEB] = 0x1E64C,  // 0x1F64C
    [CONFU] = 0x1E615,  // 0x1F615
    [EYES]  = 0x1E440,  // 0x1F440
    [GRIN]  = 0x1E600,  // 0x1F600
    [HEART] = 0x2764,   // 0x2764
    [OKHND] = 0x1E44C,  // 0x1F44C
    [THINK] = 0x1E914,  // 0x1F914
    [CLAP]  = 0x1E44E,  // 0x1F44F
    [TJOY]  = 0x1E602,  // 0x1F602
    [UNAMU] = 0x1E612,  // 0x1F612
    [WINK]  = 0x1E609,  // 0x1F609
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_START] = LAYOUT(
            _______,   KC_1,   KC_2,    KC_3,     KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,     KC_9,   KC_0,   KC_MINS,
           KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSLS,
            CESC,    KM_A,    KM_S,     KM_D,    KM_F,    KM_G,                             KM_H,    KM_J,    KM_K,    KM_L,    KM_SC,   KC_QUOT,
           KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,     _______,    KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,  KC_RSHIFT,
                                        LOWER, KC_SPC, KC_LGUI,                            KC_ENT,  KC_BSPC, RAISE
        ),

    [_LOWER] = LAYOUT(
           KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,
           _______, KC_GRV,  _______, KC_CIRC, _______, _______,                      KC_LCBR, KC_RCBR, _______, KC_LBRC,  KC_RBRC,  TERM,
           _______, KC_TILD, KC_MINS, KC_PPLS, KC_PEQL, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
           _______, _______, KC_UNDS, _______, _______,  _______, KC_GRV,      RESET, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______, _______,
                                      XXXXXXX, RSESPC,   _______,                     _______, _______, XXXXXXX
        ),

    // EMOJIS
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
    //    👍       👌       👏       ❤       😊        🤔                               🙌       😉       😂       😒       😕       😢
    //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
    //    👀
    //└────────┴────────┴────────┴────────┴────────┴────────┘                    └────────┴────────┴────────┴────────┴────────┴────────┘

    [_RAISE] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌───────────┬───────────┬───────────┬─────────────┬────────────┬───────────┐
            KC_MUTE, KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT,                     X(CELEB),    X(WINK),    X(TJOY),    X(UNAMU),     X(CONFU),    X(CRY2),
        //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├───────────┼───────────┼────────────┼────────────┼────────────┼───────────┤
            X(EYES), KC_1,     KC_2,     KC_3,   KC_4,    KC_5,                         KC_1,       KC_2,       KC_3,         _______,    _______,    _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├───────────┼───────────┼────────────┼────────────┼────────────┼───────────┤
            _______, _______, _______, _______, _______, _______,                       DT_PRNT,    DT_DOWN,     DT_UP,         _______,    _______,    _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼───────────┼───────────┼────────────┼────────────┼────────────┼───────────┤
            _______, _______, _______, _______, _______, _______, RGB_HUI,    RGB_MOD,  KC_7,       KC_8,       KC_9,         _______,    _______,    _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬───────┴─────────┬─┴────────────┴────────────┴────────────┴───────────┘
                                          XXXXXXX, RGB_VAI, BL_STEP,             RGB_TOG, RGB_SAI, XXXXXXX
                                      // └────────┴────────┴────────┘           └────────┴────────┴────────┘
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case START:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_START);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
            break;
        case THMUP:
            if (record->event.pressed) {
                // 0x1F44D
                SEND_STRING(":eyes:");
            }
            return false;
            break;
    }
    return true;
}
