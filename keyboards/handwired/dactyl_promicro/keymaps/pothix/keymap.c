#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define KC_SCTL LSFT(KC_LCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        KC_EQL , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9   , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O   , KC_P  ,KC_BSLS,
        KC_ESC,  KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L   ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT ,KC_SLSH,KC_RSFT,
        KC_GRV,KC_BSLS,KC_LEFT ,KC_RGHT,KC_LCTL, KC_SPC,                                        KC_BSPC, KC_ENT,KC_DOWN, KC_UP  ,KC_LBRC,KC_RBRC,
                                                KC_LGUI,_______,TT(_LOWER),     KC_PGDN,_______,KC_LALT ,
                                                                KC_DEL,         KC_PGUP,
                                                                KC_LALT,        KC_ALGR
    ),
    [_LOWER] = LAYOUT_6x6(
        _______    ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                          KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______    ,KC_EXLM,KC_AT  ,KC_LBRC,KC_RBRC,KC_PIPE,                                          KC_DOWN,KC_RGHT,_______,_______,KC_PAST,KC_F12 ,
        TT(_QWERTY),KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                                          KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_PPLS,_______,
        _______    ,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,                                          KC_UP  ,_______,_______,_______,KC_PSLS,KC_RSFT,
        RESET      ,_______,A(KC_BSPC),KC_PSCR,KC_LCTL,_______,                                       _______,_______,KC_PDOT,_______,KC_PEQL,_______,
                                                       _______,_______,_______,       _______,_______,_______,
                                                                       _______,       _______,
                                                                       _______,       _______
    ),
    [_RAISE] = LAYOUT_6x6(
        _______    ,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______    ,_______,_______,KC_MS_U,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        TT(_QWERTY),_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,                                       _______,_______,_______,_______,_______,KC_MPLY,
        _______    ,_______,_______,_______,_______,_______,                                       _______,_______,KC_MPRV,KC_MNXT,_______,_______,
        RESET      ,_______,_______,KC_BTN1,KC_BTN2,_______,                                       KC_WBAK,KC_VOLU,KC_VOLD,KC_MUTE,_______,_______,
                                                    _______,_______,_______,       _______,_______,_______,
                                                                    _______,       _______,
                                                                    _______,       _______
    )
};
