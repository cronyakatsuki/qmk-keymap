// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_croatian.h"

// Layer names
enum layer {
    _BASE = 0,
    _GAMING,
    _MOUSE,
    _NAV,
    _FUNC,
    _CRO,
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Layer switch keys
#define L_GMNG       TG(_GAMING)           // toggle gaming layer on/off
#define L_BASE       TO(_BASE)             // go to base layer (exits gaming mode)
#define L_MOUSE      LT(_MOUSE, KC_SPC)
#define L_ARROW      LT(_NAV, KC_ESC)
#define L_FUNCTIONS  LT(_FUNC, KC_ENT)
#define L_CRO        LT(_CRO, KC_BSPC)     // hold Backspace → Croatian layer

// Croatian letters: AltGr + key (for hr(us) OS layout)
// RALT(kc) sends Right Alt + kc in one keypress
#define CRO_S    RALT(HR_SCAR)   // š / Š  (AltGr + [)
#define CRO_D    RALT(HR_DSTR)   // đ / Đ  (AltGr + ])
#define CRO_C    RALT(HR_CCAR)   // č / Č  (AltGr + ;)
#define CRO_CACU RALT(HR_CACU)   // ć / Ć  (AltGr + ')
#define CRO_Z    RALT(HR_ZCAR)   // ž / Ž  (AltGr + \)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_BSLS,
        KC_EQL,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                             KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,  KC_QUOT,
        KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RBRC,
                                             L_GMNG,  L_ARROW, L_MOUSE,       L_FUNCTIONS, L_CRO,  KC_DEL
    ),

    [_GAMING] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        L_FUNCTIONS, KC_A, KC_S,   KC_D,    KC_F,    KC_TRNS,                         KC_TRNS, KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                             KC_LCTL, KC_SPC,  KC_ESC,       KC_TRNS, KC_TRNS, L_BASE
    ),

    [_MOUSE] = LAYOUT(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, MS_WHLD, MS_WHLU, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS,       MS_BTN1,  MS_BTN2,  MS_BTN3
    ),

    [_NAV] = LAYOUT(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [_FUNC] = LAYOUT(
        KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS,
        KC_TRNS,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,                           KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS,
        KC_LSFT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,
                                             KC_ENT,  KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [_CRO] = LAYOUT(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  CRO_D,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  CRO_S,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CRO_CACU, CRO_C,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  CRO_Z,
                                             KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};

// Set diff tapping term for specific keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + 15;
        case HOME_SCLN:
            return TAPPING_TERM + 15;
        default:
            return TAPPING_TERM;
    }
}
