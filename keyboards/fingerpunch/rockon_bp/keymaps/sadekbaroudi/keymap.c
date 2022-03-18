/* Copyright 2021 Sadek Baroudi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sadekbaroudi.h"
#include QMK_KEYBOARD_H

// Uncomment to set up WPM
//char wpm_as_str[8];

#define _GAME 8
#define _KICAD 9

/*
 * The `LAYOUT_rockon_bp_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg ALPHA_ALT, Alpha, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_rockon_bp_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K33, K34, K35, K36, K37, K38 \
  ) \
  LAYOUT_wrapper( \
    KC_ESC,    KC_1,           KC_2,           KC_3,           KC_4,                KC_5,                   _______,                                               TO(_KICAD),         KC_6,                  KC_7,               KC_8,             KC_9,           KC_0,            KC_BSPC, \
    KC_TAB,    K01,            K02,            K03,            LT(_FUNCTION, K04),  K05,                    _______,                                               TO(_NAVIGATION),    K06,                   LT(_FUNCTION, K07), K08,            K09,            K0A,             KC_BSLS, \
    KC_CAPS,   LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),         K15,                    _______,                                               TO(_ALPHA),       LT(_MOUSE, K16),       RSFT_T(K17),        RALT_T(K18),      RGUI_T(K19),    RCTL_T(K1A),     KC_QUOT, \
    KC_LSFT,   K21,            K22,            K23,            K24,                 K25,                    _______,                                               _______,            K26,                   K27,                K28,              K29,            K2A,             KC_ENT, \
                               KC_LCTL,        KC_LGUI,        K33,                 LT(_NAVIGATION,K34),    LT(_FUNCTION,K35),    KC_MUTE,  LCTL(KC_BSPC),         LT(_MEDIA,K36),     LT(_SYMBOLS,K37),      K38,            KC_RGUI,          KC_RCTL \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_rockon_bp_base_wrapper(...)       LAYOUT_rockon_bp_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_ALT] = LAYOUT_rockon_bp_base_wrapper(
        _________________ALPHA_ALT_L1_________________, _________________ALPHA_ALT_R1_________________,
        _________________ALPHA_ALT_L2_________________, _________________ALPHA_ALT_R2_________________,
        _________________ALPHA_ALT_L3_________________, _________________ALPHA_ALT_R3_________________,
                                             __ALPHA_ALT_THUMBS_6__
    ),

    [_ALPHA] = LAYOUT_rockon_bp_base_wrapper(
        __________________ALPHA_L1____________________, __________________ALPHA_R1____________________,
        __________________ALPHA_L2____________________, __________________ALPHA_R2____________________,
        __________________ALPHA_L3____________________, __________________ALPHA_R3____________________,
                                              __ALPHA_THUMBS_6__
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        _______,       _______,       _______,       _______,       _______,       _______,       _______,                              TO(_ALPHA),  _______,       _______,       _______,       _______,       _______,       _______,
        _______,                   ________________NAVIGATION_1_______________,                   _______,                              TO(_SYMBOLS),              _________________NUMPAD_1__________________,                   _______,
        _______,                   ________________NAVIGATION_2_______________,                   _______,                              _______,                   _________________NUMPAD_2__________________,                   _______,
        _______,                   ________________NAVIGATION_3_______________,                   _______,                              _______,                   _________________NUMPAD_3__________________,                   _______,
                                      _______,       _______,       _______,       _______,       KC_TAB,     _______,       _______,   KC_BSPC,       KC_SPACE,       KC_DOT,       _______,       _______
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        _______,       _______,       _______,       _______,       _______,       _______,       _______,                              TO(_NAVIGATION), _______,     _______,       _______,       _______,       _______,       _______,
        _______,                   ________________SYMBOLS_L1_________________,                   _______,                              TO(_FUNCTION),             ________________SYMBOLS_R1_________________,                   _______,
        _______,                   ________________SYMBOLS_L2_________________,                   _______,                              _______,                   ________________SYMBOLS_R2_________________,                   _______,
        _______,                   ________________SYMBOLS_L3_________________,                   _______,                              _______,                   ________________SYMBOLS_R3_________________,                   _______,
                                      _______,       _______,       _______,       KC_ENT,        KC_DEL,     _______,       _______,   KC_BSPC,         _______,     _______,       _______,       _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        _______,       _______,       _______,       _______,       _______,       _______,       _______,                              TO(_SYMBOLS),  _______,       _______,       _______,       _______,       _______,       _______,
        _______,                   ________________SHIFTNAV_1_________________,                   _______,                              TO(_MEDIA),                ________________FUNCTION_1_________________,                   _______,
        _______,                   ________________SHIFTNAV_2_________________,                   _______,                              _______,                   ________________FUNCTION_2_________________,                   _______,
        _______,                   ________________SHIFTNAV_3_________________,                   _______,                              _______,                   ________________FUNCTION_3_________________,                   _______,
                                      _______,       _______,       _______,       _______,       _______,    _______,       _______,   N_DEL_LINE,    KC_SPACE,      _______,       _______,       _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        _______,       _______,       _______,       _______,       _______,       _______,       _______,                              TO(_FUNCTION), _______,       _______,       _______,       _______,       _______,       _______,
        _______,                   ___________________RGB_1___________________,                   _______,                              TO(_MOUSE),                _________________MACROS_1__________________,                   _______,
        _______,                   ___________________RGB_2___________________,                   _______,                              _______,                   _________________MACROS_2__________________,                   _______,
        _______,                   ___________________RGB_3___________________,                   _______,                              _______,                   _________________MACROS_3__________________,                   _______,
                                      _______,       _______,       _______,       _______,       _______,    _______,       _______,   _______,       _______,       _______,       _______,       _______
    ),
    
    [_MOUSE] = LAYOUT_wrapper(
        _______,       _______,       _______,       _______,       _______,       _______,       _______,                              TO(_MEDIA),    _______,       _______,       _______,       _______,       _______,       _______,
        _______,                   __________________MOUSE_1__________________,                   _______,                              TO(_GAME),                 ___________________BLANK___________________,                   _______,
        _______,                   __________________MOUSE_2__________________,                   _______,                              _______,                   ___________________BLANK___________________,                   _______,
        _______,                   __________________MOUSE_3__________________,                   _______,                              _______,                   ___________________BLANK___________________,                   _______,
                                      _______,       _______,       _______,       KC_MS_BTN1,    KC_MS_BTN3,    _______,    _______,   KC_MS_BTN3,    KC_MS_BTN2,    _______,       _______,       _______
    ),

    [_GAME] = LAYOUT_wrapper(
        __GAMES_R0_L__,     ___________________GAMES_0_________________,     __GAMES_R0_R__,                                                TO(_MOUSE),   _______,       _______,       _______,       _______,       _______,       _______, \
        __GAMES_R1_L__,     ___________________GAMES_1_________________,     __GAMES_R1_R__,                                                TO(_KICAD),                ___________________BLANK___________________,                   _______, \
        __GAMES_R2_L__,     ___________________GAMES_2_________________,     __GAMES_R2_R__,                                                _______,                   ___________________BLANK___________________,                   _______, \
        __GAMES_R3_L__,     ___________________GAMES_3_________________,     __GAMES_R3_R__,                                                _______,                   ___________________BLANK___________________,                   _______, \
                       __GAMES_R4_1__, __GAMES_R4_3__, __GAMES_TH_L__, __GAMES_TH_C__, __GAMES_TH_R__,    _______,       _______,     _______,       _______,       _______,       _______,       _______ \
    ),

    [_KICAD] = LAYOUT_wrapper(
        __KICAD_R0_L__,     ___________________KICAD_0_________________,     __KICAD_R0_R__,                                                TO(_GAME),     _______,       _______,       _______,       _______,       _______,       _______, \
        __KICAD_R1_L__,     ___________________KICAD_1_________________,     __KICAD_R1_R__,                                                TO(_ALPHA),              _________________NUMPAD_1__________________,                   _______, \
        __KICAD_R2_L__,     ___________________KICAD_2_________________,     __KICAD_R2_R__,                                                _______,                   _________________NUMPAD_2__________________,                   _______, \
        __KICAD_R3_L__,     ___________________KICAD_3_________________,     __GAMES_R3_R__,                                                _______,                   _________________NUMPAD_3__________________,                   _______, \
                       __KICAD_R4_1__, __KICAD_R4_3__, __KICAD_TH_L__, __KICAD_TH_C__, __KICAD_TH_R__,    _______,       _______,     KC_BSPC,       KC_SPACE,      KC_DOT,       _______,       _______ \
    )
};


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
      return OLED_ROTATION_180;
} 

static void render_logo(void) {
    // rockon logo, 128x64px
    static const char PROGMEM rockon_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xe0, 0xf8, 0xfc, 0x1e, 0x0e, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0e, 0x3e, 0xfc, 0xf8, 0xe0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
    0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfe, 0xff, 0x7f, 
    0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xef, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0x7f, 0x78, 
    0x38, 0x38, 0x70, 0x70, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0x1f, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf8, 0xfc, 
    0x1c, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x1e, 0x1c, 0x1c, 0x38, 0x38, 0x78, 0x70, 0xf0, 0xe0, 0xe0, 
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x1f, 0x3f, 
    0x78, 0x70, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x80, 0xf8, 0xff, 0x7f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x1e, 0x1c, 0x7c, 0xf8, 0xf0, 
    0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 
    0xe0, 0xf8, 0x7e, 0x3f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
    0x0f, 0x1f, 0x7e, 0xf8, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
    0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf8, 0x7f, 0x3f, 
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

};
    oled_write_raw_P(rockon_logo, sizeof(rockon_logo));

}


void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _ALPHA_ALT:
            oled_write_P(PSTR("Alphalt\n"), false);
            break;
        case _ALPHA:
            oled_write_P(PSTR("Alpha\n"), false);
            break;
        case _NAVIGATION:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("RGB Media\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _KICAD:
            oled_write_P(PSTR("Kicad\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Write host Keyboard LED Status to OLEDs
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);

    // rockon logo, 128x48px
    static const char rockon_logo_small [] PROGMEM = {

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf8, 0xfc, 0x0e, 0x07, 0x03, 0x03, 0x03, 0x07, 0x0e, 0xfc, 0xf8, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x70, 0x30, 0x30, 0x30, 0x30, 0x70, 
    0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x08, 0x08, 0xf8, 0x10, 0x08, 0x08, 0x08, 0x08, 0x10, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 
    0x08, 0x08, 0x08, 0x08, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0x08, 0x08, 
    0x10, 0x38, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x80, 0xc0, 0x28, 0x18, 0x08, 0x08, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
    0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x08, 0x08, 0x0f, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 
    0x08, 0x08, 0x08, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x08, 0x08, 0x08, 
    0x08, 0x04, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x01, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x08, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x60, 0xf8, 0xfc, 0x0e, 0x06, 0x06, 0x06, 0x06, 0x0e, 0x0c, 0x1c, 0x18, 0x18, 
    0x38, 0x70, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
    0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x0c, 0x1c, 0x18, 0x38, 0x30, 0x70, 0x60, 0xe0, 
    0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf8, 0x7f, 0x0f, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0x80, 
    0x80, 0x80, 0x80, 0x80, 0x41, 0x3e, 0x00, 0x00, 0x00, 0x80, 0xff, 0x81, 0x00, 0x00, 0x00, 0x80, 
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x01, 0x07, 0x1f, 0x7c, 0xf0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0x7e, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(rockon_logo_small, sizeof(rockon_logo_small));

}

bool oled_task_user(void) {
    // If you don't want to display the logo, switch
    if (true) {
        render_status();
    } else if (false) {
        render_logo();
    } else {
        //render_logo_text();
    }
    return true;
}

#endif
