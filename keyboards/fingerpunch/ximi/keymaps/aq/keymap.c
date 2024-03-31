#include QMK_KEYBOARD_H

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_A):
        case LCTL_T(KC_S):
        case LGUI_T(KC_D):
        case LSFT_T(KC_F):
        case RSFT_T(KC_J):
        case RGUI_T(KC_K):
        case RCTL_T(KC_L):
        case RALT_T(KC_SCLN):
           return TAPPING_TERM;
        // case LT(1,KC_BSPC):
        // case LT(4,KC_DELETE):
        // case LT(3,KC_SPACE):
        //     return TAPPING_TERM;
        default:
            return TAPPING_TERM * 0.75;
    }
}

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY_AQ,
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* 0
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  Q*  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  A*  |  S*  |  D*  |  F*  |   G  |           |   H  |  J*  |  K*  |  L*  |  *;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | Esc | BSPC* | Del* |    | Enter| Spc* | Tab* |
 *                  `--------------------'    `--------------------.
 */
[0] = LAYOUT_ximi36(
  LT(6,KC_Q),   KC_W,         KC_E,           KC_R,           KC_T,           KC_Y,        KC_U,          KC_I,          KC_O,         KC_P,
  LALT_T(KC_A), LCTL_T(KC_S), LGUI_T(KC_D),   LSFT_T(KC_F),   KC_G,           KC_H,        RSFT_T(KC_J),  RGUI_T(KC_K),  RCTL_T(KC_L), RALT_T(KC_SCLN),
  KC_Z,         KC_X,         KC_C,           KC_V,           KC_B,           KC_N,        KC_M,          KC_COMM,       KC_DOT,       KC_SLSH,
                              KC_ESCAPE,      LT(1,KC_BSPC),  LT(4,KC_DELETE),KC_ENTER,    LT(3,KC_SPACE),KC_TAB
),

/* 1
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   `  |   \  |   -  |   =  |      |           |      |   '  |   "  |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   (  |   )  |   [  |   ]  |      |           |      | Shft |  Gui |  Ctl |  Alt |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   <  |   >  |   {  |   }  |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |     |#######|      |    |      |      |      |
 *                  `--------------------'    `--------------------.
 */
[1] = LAYOUT_ximi36(
  KC_GRAVE,     KC_BSLS,      KC_MINUS,       KC_EQUAL,       KC_NO,          KC_NO,       KC_QUOTE,      KC_DQUO,       KC_NO,        KC_NO,
  KC_LPRN,      KC_RPRN,      KC_LBRC,        KC_RBRC,        KC_NO,          KC_NO,       KC_RSFT,       KC_RGUI,       KC_RCTL,      KC_RALT,
  KC_LABK,      KC_RABK,      KC_LCBR,        KC_RCBR,        KC_NO,          KC_NO,       KC_NO,         KC_NO,         KC_NO,        KC_NO,
                              KC_NO,          KC_NO,          KC_NO,          KC_NO,       KC_NO,         KC_NO
),

/* 2
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   ~  |   |  |   -  |   +  |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   #  |   @  |   !  |Capslk|      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   _  |      |   *  |   &  |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |     |       |      |    |      |      |      |
 *                  `--------------------'    `--------------------.
 */
//[2] = LAYOUT_ximi36(
//  KC_TILD,      KC_PIPE,      KC_UNDS,        KC_PLUS,        KC_NO,          KC_NO,       KC_NO,      KC_NO,       KC_NO,       KC_NO,
//  KC_HASH,      KC_AT,        KC_EXLM,        KC_CAPS_LOCK,   KC_NO,          KC_NO,       KC_NO,      KC_NO,       KC_NO,       KC_NO,
//  KC_UNDS,      KC_NO,        KC_ASTR,        KC_AMPR,        KC_NO,          KC_NO,       KC_NO,      KC_NO,       KC_NO,       KC_NO,
//                              KC_NO,          KC_NO,          KC_NO,          KC_NO,       KC_NO,      KC_NO
//),

/* 3
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   #  |   @  |   !  |Capslk|      |           | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |     |       |      |    |      |######|      |
 *                  `--------------------'    `--------------------.
 */
[3] = LAYOUT_ximi36(
  KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,       KC_NO,      KC_NO,       KC_NO,       KC_NO,
  KC_LALT,    KC_LCTL,        KC_LGUI,        KC_LSFT,        KC_NO,          KC_LEFT,     KC_DOWN,    KC_UP,       KC_RIGHT,    KC_NO,
  KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,       KC_NO,      KC_NO,       KC_NO,       KC_NO,
                              KC_NO,          KC_NO,          KC_NO,          KC_NO,       KC_NO,      KC_NO
),

/* 4
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   =  |   6  |   5  |   4  |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   3  |   2  |   1  |   0  |      |           |      | MO(5)|  Gui |  Ctl |  Alt |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   -  |   9  |   8  |   7  |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |     |       |######|    |      |      |      |
 *                  `--------------------'    `--------------------.
 */
[4] = LAYOUT_ximi36(
  KC_EQUAL,       KC_6,           KC_5,           KC_4,          KC_NO,       KC_NO,   KC_NO,          KC_NO,         KC_NO,        KC_NO,
  KC_3,           KC_2,           KC_1,           KC_0,          KC_NO,       KC_NO,   MO(5),          KC_RGUI,       KC_RCTL,     KC_RALT,
  KC_MINUS,       KC_9,           KC_8,           KC_7,          KC_NO,       KC_NO,   KC_NO,          KC_NO,         KC_NO,        KC_NO,
                                  KC_NO,          KC_NO,         KC_NO,       KC_NO,   KC_NO,          KC_NO
),

/* 5
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   +  |   6  |   5  |   4  |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   #  |   @  |   !  |Capslk|      |           |      | MO(5)|  Gui |  Ctl |  Alt |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   _  |      |   *  |   &  |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |     |       |      |    |      |      |      |
 *                  `--------------------'    `--------------------.
 */
[5] = LAYOUT_ximi36(
  KC_PLUS,        KC_CIRC,        KC_PERC,        KC_DLR,        KC_NO,       KC_NO,          KC_NO,          KC_NO,         KC_NO,        KC_NO,
  KC_HASH,        KC_AT,          KC_EXLM,        KC_CAPS_LOCK,  KC_NO,       KC_NO,          MO(5),          KC_RGUI,       KC_RCTL,      KC_RALT,
  KC_UNDS,        KC_NO,          KC_ASTR,        KC_AMPR,       KC_NO,       KC_NO,          KC_NO,          KC_NO,         KC_NO,        KC_NO,
                                  KC_NO,          KC_NO,         KC_NO,       KC_NO,          KC_NO,         KC_NO
),

/* 6
 *
 * ,----------------------------------.           ,----------------------------------.
 * |######| Debug| Eeclr|  Rbt |      |           | Lclk | Rclk |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Alt |  Ctl |  Gui | Shft |      |           | Wleft| Wdown|  Wup |Wright|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      | Boot |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |     |       |      |    |      |      |      |
 *                  `--------------------'    `--------------------.
 */
[6] = LAYOUT_ximi36(
  KC_NO,        DB_TOGG,     EE_CLR,          QK_RBT,       KC_NO,       KC_BTN1,        KC_BTN2,        KC_NO,         KC_NO,          KC_NO,
  KC_LALT,      KC_LCTL,     KC_LGUI,         KC_LSFT,      KC_NO,       KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,   KC_MS_WH_RIGHT, KC_NO,
  KC_NO,        FP_DPI_DOWN, FP_SCROLL_DPI_DN,KC_NO,        QK_BOOT,     KC_NO,          KC_NO,          KC_NO,         KC_NO,          KC_NO,
                             KC_NO,           KC_NO,        KC_NO,       KC_NO,          KC_NO,          KC_NO
),

};