#include QMK_KEYBOARD_H
#include "./mapgerman.h"

#define DEF 0
#define MED 1
#define NAV 2
#define MOU 3
#define SYM 4
#define NUM 5
#define FUN 6

#define _______ KC_NO

const key_override_t lt = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, DE_LT);
const key_override_t gt = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, DE_GT);
const key_override_t ques = ko_make_basic(MOD_MASK_SHIFT, DE_FSLH, DE_QUES);
const key_override_t dqt = ko_make_basic(MOD_MASK_SHIFT, DE_SQT, DE_DQT);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&lt,
    &gt,
    &ques,
    &dqt,
};

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
    [DEF] = LAYOUT_split_3x5_3(
           KC_Q,        KC_W,        KC_F,        KC_P,    KC_B,                       KC_J,       KC_L,        KC_U,        DE_Y,     DE_SQT,
    LGUI_T(KC_A),LALT_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T),   KC_G,                       KC_M,RSFT_T(KC_N),RCTL_T(KC_E),LALT_T(KC_I),RGUI_T(KC_O),
           DE_Z,        KC_X,        KC_C,        KC_D,    KC_V,                       KC_K,       KC_H,     KC_COMM,      KC_DOT,     DE_FSLH,
                             LT(MED,KC_ESC),LT(NAV,KC_SPC),LT(MOU,KC_TAB),LT(SYM,KC_ENT),LT(NUM,KC_BSPC),LT(FUN,KC_DEL)
    ),
    [MED] = LAYOUT_split_3x5_3(
        _______,     _______,     _______,      _______, _______,                   _______,    _______,     _______,     _______,     _______,
    LGUI_T(KC_MPRV),LALT_T(KC_VOLD),LCTL_T(KC_VOLU),LSFT_T(KC_MNXT),_______,_______,RSFT_T(KC_MPRV),RCTL_T(KC_VOLD),LALT_T(KC_VOLU),RGUI_T(KC_MNXT),
        _______,     _______,     KC_MUTE,      KC_MPLY, _______,                   _______,    _______,     _______,     _______,     _______,
                                                _______, _______, _______, KC_MSTP, KC_MPLY,    KC_MUTE
    ),
    [NAV] = LAYOUT_split_3x5_3(
        C(DE_Z),     C(KC_X),     C(KC_C),      C(KC_V), C(DE_Y),                   C(DE_Y),    C(KC_V),     C(KC_C),     C(KC_X),     C(DE_Z),
        KC_LGUI,     KC_LALT,     KC_LCTL,      KC_LSFT,  KC_DEL,                   KC_CAPS,    KC_LEFT,     KC_DOWN,       KC_UP,     KC_RGHT,
        _______,     _______,     _______,      _______, _______,                    KC_INS,    KC_HOME,     KC_PGDN,     KC_PGUP,      KC_END,
                                                _______, _______, _______,  KC_ENT, KC_BSPC,     KC_DEL
    ),
    [MOU] = LAYOUT_split_3x5_3(
         KC_NUM,     MS_WHLD,     MS_WHLU,      _______, _______,                   C(DE_Y),    C(KC_V),     C(KC_C),     C(KC_X),     C(DE_Z),
        KC_LGUI,     KC_LALT,     KC_LCTL,      KC_LSFT, MS_BTN2,                   _______,    MS_LEFT,     MS_DOWN,       MS_UP,     MS_RGHT,
        MS_LEFT,     MS_DOWN,       MS_UP,      MS_RGHT, MS_BTN1,                   _______,    MS_WHLL,     MS_WHLD,     MS_WHLU,     MS_WHLR,
                                                _______, _______, _______, MS_BTN2, MS_BTN1,    MS_BTN3
    ),
    [SYM] = LAYOUT_split_3x5_3(
        DE_LBRC,     DE_AMPS,     DE_STAR,      DE_LPAR, DE_RBRC,                   _______,    _______,     _______,     _______,     _______,
        DE_COLO,     DE_DLLR,     DE_PRCT,      DE_CIRC, DE_PLUS,                   _______,    KC_RSFT,     KC_RCTL,     KC_LALT,     KC_RGUI,
        DE_TILD,     DE_EXLM,       DE_AT,      DE_HASH, DE_PIPE,                   _______,    _______,     _______,     _______,     _______,
                                                DE_LPAR, DE_RPAR, DE_USCR, _______, _______,    _______
    ),
    [NUM] = LAYOUT_split_3x5_3(
        DE_LBKT,        KC_7,        KC_8,         KC_9, DE_RBKT,                   DE_EURO,    DE_ACUT,       DE_Ae,       DE_Ue,       DE_Oe,
        DE_SEMI,        KC_4,        KC_5,         KC_6,  DE_EQL,                   DE_DEGR,RSFT_T(DE_SS),RCTL_T(DE_ae),LALT_T(DE_ue),RGUI_T(DE_oe),
         DE_GRV,        KC_1,        KC_2,         KC_3, DE_BSLH,                   _______,    _______,     _______,     _______,     _______,
                                                 KC_DOT,    KC_0, DE_MINS, _______, _______,    _______
    ),
    [FUN] = LAYOUT_split_3x5_3(
         KC_F12,       KC_F7,       KC_F8,        KC_F9, KC_PSCR,                   _______,    _______,     _______,     _______,     _______,
         KC_F11,       KC_F4,       KC_F5,        KC_F6, KC_SCRL,                   _______,    KC_RSFT,     KC_RCTL,     KC_LALT,     KC_RGUI,
         KC_F10,       KC_F1,       KC_F2,        KC_F3, KC_PAUS,                   _______,    _______,     _______,     _______,     _______,
                                                 KC_APP,  KC_SPC,  KC_TAB, _______, _______,    _______
    ),
};
