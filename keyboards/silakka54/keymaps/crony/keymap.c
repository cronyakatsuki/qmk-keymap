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

// Chordal Hold: explicitly define left/right handedness for the split matrix.
// Rows 0-4 = left hand, rows 5-9 = right hand.
// '*' = exempt from opposite-hands rule (thumb cluster can chord with either hand).
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                               '*', '*', '*',   '*', '*', '*'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_BSLS,
        KC_EQL,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                             KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,  KC_QUOT,
        KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RBRC,
                                             L_GMNG,  L_MOUSE, L_ARROW,       L_FUNCTIONS, L_CRO,  KC_DEL
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

// Per-key tapping term offsets.
// GUI keys get a bump since accidental Win/Cmd shortcuts are disruptive with
// standard TAPPING_TERM. Shift no longer needs shortening — Chordal Hold
// handles the roll case correctly.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_SCLN:
            return TAPPING_TERM + 20;   // LGUI / RGUI — need firmer hold
        default:
            return TAPPING_TERM;
    }
}

// ── Flow Tap: exempt Shift keys so they always have a fair chance to be
// modifiers, even during fast typing. Also disable Flow Tap while a hotkey
// mod is active (stock QMK behavior) to prevent eating mod-intent keys.
bool is_flow_tap_key(uint16_t keycode) {
    // Never flow-tap while a hotkey modifier is already active
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false;
    }
    switch (get_tap_keycode(keycode)) {
        case KC_F:   // LSFT_T(KC_F)
        case KC_J:   // RSFT_T(KC_J)
            return false;  // Shift keys always bypass Flow Tap
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
        case KC_SPC:
        case KC_ESC:
        case KC_ENT:
        case KC_BSPC:
            return true;   // Typing keys flow-tap while typing fast
        default:
            return false;
    }
}

// ── Chordal Hold: allow common same-hand hotkeys and shift+letter combos
// that would otherwise be incorrectly settled as taps.
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        // Left Shift + any left-hand letter → hold for capitalization
        case HOME_F:  // LSFT_T(KC_F)
            // Allow same-hand shift+letter for capitalization
            if (other_keycode >= KC_A && other_keycode <= KC_G) {
                return true;
            }
            if (other_keycode == KC_Z || other_keycode == KC_X || other_keycode == KC_V || other_keycode == KC_B) {
                return true;
            }
            break;

        // Right Shift + any right-hand letter → hold for capitalization
        case HOME_J:  // RSFT_T(KC_J)
            if (other_keycode >= KC_H && other_keycode <= KC_SCLN) {
                return true;
            }
            if (other_keycode == KC_N || other_keycode == KC_M || other_keycode == KC_COMM || other_keycode == KC_DOT || other_keycode == KC_SLSH || other_keycode == KC_QUOT) {
                return true;
            }
            break;

        // Left Ctrl + common hotkeys on the same hand
        case HOME_D:  // LCTL_T(KC_D)
            switch (other_keycode) {
                case KC_C:  // Ctrl+C (copy)
                case KC_V:  // Ctrl+V (paste)
                case KC_X:  // Ctrl+X (cut)
                case KC_Z:  // Ctrl+Z (undo)
                case KC_A:  // Ctrl+A (select all)
                case KC_S:  // Ctrl+S (save)
                case KC_F:  // Ctrl+F (find)
                case KC_W:  // Ctrl+W (close tab)
                case KC_R:  // Ctrl+R (refresh)
                    return true;
            }
            break;

        // Left Alt + Tab for Alt+Tab switching
        case HOME_S:  // LALT_T(KC_S)
            if (other_keycode == KC_TAB || other_keycode == KC_LBRC) {
                return true;
            }
            break;

        // Left GUI + Space for search/spotlight (space is right thumb)
        case HOME_A:  // LGUI_T(KC_A)
            if (other_keycode == KC_SPC) {
                return true;
            }
            break;

        // Right Ctrl + /  (common in some apps)
        case HOME_K:  // RCTL_T(KC_K)
            if (other_keycode == KC_SLSH) {
                return true;
            }
            break;
    }
    // Default: use the opposite-hands rule
    return get_chordal_hold_default(tap_hold_record, other_record);
}
