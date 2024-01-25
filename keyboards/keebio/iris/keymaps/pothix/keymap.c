#include QMK_KEYBOARD_H


#define _START 0
#define _LOWER 1
#define _RAISE 2

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
  CRY2,  // crying face 😢
  CELEB, // celebration 🙌
  CONFU, // confused 😕
  EYES,  // eyes 👀
  GRIN,  // grinning face 😊
  HEART, // heart ❤
  OKHND, // ok hand sign 👌
  THINK, // thinking face 🤔
  CLAP,  // clap 👏
  TJOY,  // tears of joy 😂
  UNAMU, // unamused 😒
  WINK,  // wink 😉
};

const uint32_t PROGMEM unicode_map[] = {
  // name = clmk'ed, // original
  [CRY2]  = 0x1E622, // 0x1F622
  [CELEB] = 0x1E64C, // 0x1F64C
  [CONFU] = 0x1E615, // 0x1F615
  [EYES]  = 0x1E440, // 0x1F440
  [GRIN]  = 0x1E600, // 0x1F600
  [HEART] = 0x2764,  // 0x2764
  [OKHND] = 0x1E44C, // 0x1F44C
  [THINK] = 0x1E914, // 0x1F914
  [CLAP]  = 0x1E44E, // 0x1F44F
  [TJOY]  = 0x1E602, // 0x1F602
  [UNAMU] = 0x1E612, // 0x1F612
  [WINK]  = 0x1E609, // 0x1F609
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_START] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,    KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LOWER,   KC_SPC,  KC_LCTL,             KC_ENT,  KC_BSPC, KC_LALT
                                // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  ),


  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   _______, _______, _______, _______, _______,                      _______, _______, _______, KC_LCBR, KC_RCBR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_GRV,  _______, _______, _______, _______, _______,    KC_LALT, KC_END,  KC_PGDN, KC_PGUP, KC_LBRC, KC_RBRC, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, _______, _______,             KC_HOME, KC_DEL,  RAISE
                                // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  ),


  // EMOJIS
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //    👍       👌       👏       ❤       😊        🤔                            🙌       😉       😂       😒       😕       😢
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
  //    👀
  //└────────┴────────┴────────┴────────┴────────┴────────┘                    └────────┴────────┴────────┴────────┴────────┴────────┘

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
      THMUP,  X(OKHND),X(CLAP) ,X(HEART),X(GRIN), X(THINK),                     X(CELEB),X(WINK), X(TJOY), X(UNAMU),X(CONFU),X(CRY2),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     X(EYES),  _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV, KC_MNXT, KC_VOLU, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, _______, _______, RGB_HUI,    RGB_MOD, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘  └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, RGB_VAI, BL_STEP,             RGB_TOG, RGB_SAI, XXXXXXX
                                // └────────┴────────┴────────┘           └────────┴────────┴────────┘
  )
};

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
        send_unicode_hex_string("1E44G");
      }
      return false;
      break;
  }
  return true;
}
