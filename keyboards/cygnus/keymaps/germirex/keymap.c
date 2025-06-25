#include QMK_KEYBOARD_H
#include "./mapgerman.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ B │       │ J │ L │ U │ U │ ' │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤DEL│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘
      *               └───┤TAB│   │ENT├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT_split_3x5_3(
           KC_Q,        KC_W,        KC_F,        KC_P,    KC_B,                       KC_J,       KC_L,        KC_U,        DE_Y,     KC_QUOT,
    LGUI_T(KC_A),LALT_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T),   KC_G,                       KC_M,RSFT_T(KC_N),RCTL_T(KC_E),LALT_T(KC_I),RGUI_T(KC_O),
           DE_Z,        KC_X,        KC_C,        KC_D,    KC_V,                       KC_K,       KC_H,     KC_COMM,      KC_DOT,     DE_FSLH,
                                                KC_ESC,  KC_SPC, KC_TAB,   KC_ENT,  KC_BSPC,  KC_DEL
    )
};
