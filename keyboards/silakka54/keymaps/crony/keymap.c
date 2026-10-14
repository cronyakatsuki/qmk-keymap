// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_croatian.h"

/* ══════════════════════════════════════════════════════════════
 *  DIAGNOSTICS BUILD (temporary) — HRM decision telemetry
 *  Captured with `qmk console`. Remove the marked blocks after
 *  the capture run to restore the lean production build.
 * ══════════════════════════════════════════════════════════════ */

enum custom_keycodes {
    MARK_RACE = SAFE_RANGE,
};

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
        MARK_RACE, CW_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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

static const char *hrm_kc_name(uint16_t kc) {
    switch (kc) {
        case HOME_A: return "A(GUI)";
        case HOME_S: return "S(ALT)";
        case HOME_D: return "D(CTL)";
        case HOME_F: return "F(SHFT)";
        case HOME_J: return "J(SHFT)";
        case HOME_K: return "K(CTL)";
        case HOME_L: return "L(ALT)";
        case HOME_SCLN: return ";(GUI)";
        case KC_SLSH: return "SLSH";
        case KC_SPACE: return "SPACE";
        case KC_ENTER: return "ENTER";
        case KC_BSPC: return "BKSP";
    }
    if ((kc & 0xF000) != 0u) return "OTHER";
    return "UNNAMED";
}

// ── Combos (data-driven race fixes) ──
// COMBO_TERM 150 covers both measured bands (TAP ≤116 ms, HOLD ≥134 ms), so
// any of these paired presses resolves to the intentional output regardless
// of which timing race would have lost.
enum combo_events {
    C_F_SLSH,   // F + /  → ?   (the f/-race becomes the intended ?)
    C_J_SLSH,   // J + /  → ?
    C_F_J,      // F + J  → Caps Word (single twin-shift gesture)
};
const uint16_t PROGMEM combo_f_slsh[] = {HOME_F, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_j_slsh[] = {HOME_J, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_f_j[]    = {HOME_F, HOME_J,  COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_f_slsh, S(KC_SLSH)),
    COMBO(combo_j_slsh, S(KC_SLSH)),
    COMBO(combo_f_j,    CW_TOGG),
};

// Per-key tapping term offsets.
// With RETRO_TAPPING + HOLD_ON_OTHER_KEY_PRESS, the GUI bump is no longer
// needed — the uniform chordal-hold timing rule guards accidental Win chords,
// and retro tapping prevents dropped keys on slow releases.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return TAPPING_TERM;
}

// ── Chordal Hold: uniform timing rule (Achordion-style) ──
// Every home-row mod uses the same single discriminator: how long the mod
// key was held before the other key arrived.
//   • other key pressed within the mod's chord term (CHORD_TERM, or the
//     shorter CHORD_TERM_SHIFT for Shift keys) of the mod going down →
//     typing roll → tap. Protects fast typing in either hand, any language
//     ("da", "dva", "država", "kako", "first", "slon", "a word" …).
//   • other key pressed later → deliberate → hold. Works for same-hand AND
//     cross-hand chords: press-hold the mod ~a beat, then the key
//     (hold D then C → Ctrl+C; hold F then E → capital E).
// Layer-tap thumb keys are excluded below: they keep the default '*' rule
// (hold whenever chorded), so fluent layer use (Esc + arrows) stays instant.
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
    // ── DIAGNOSTICS: decision capture for urob/positional comparison ──
    bool out            = false;
    uint16_t gap_ms     = TIMER_DIFF_16(other_record->event.time,
                                       tap_hold_record->event.time);

    switch (tap_hold_keycode) {
        case HOME_A:
        case HOME_S:
        case HOME_D:
        case HOME_F:
        case HOME_J:
        case HOME_K:
        case HOME_L:
        case HOME_SCLN:
            if (!other_record->event.pressed) {
                out = false;
            } else {
                bool is_shift_mod = (tap_hold_keycode == HOME_F) ||
                                    (tap_hold_keycode == HOME_J);
                uint16_t chord_term = is_shift_mod ? CHORD_TERM_SHIFT : CHORD_TERM;
                out = gap_ms >= chord_term;
            }
            break;
        default:
            out = get_chordal_hold_default(tap_hold_record, other_record);
            break;
    }

    if (other_record->event.pressed) {  // only log the deciding (press) consult
        uprintf("[CHD] mod=%s other=%s gap_ms=%u verdict=%s\n",
                hrm_kc_name(tap_hold_keycode),
                hrm_kc_name(other_keycode),
                gap_ms,
                out ? "HOLD" : "TAP");
    }
    return out;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uint32_t t = timer_read32();
    if (record->event.pressed) {
        switch (keycode) {
        case CW_TOGG:
            uprintf("==== [CAPSWORD] toggle t=%lu ms ====\n", (unsigned long)t);
            break;
        case MARK_RACE:
            uprintf("==== ⚑ RACE MARK t=%lu ms layer=%u ====\n",
                    (unsigned long)t, get_highest_layer(layer_state));
            break;
        default:
            if (keycode < QK_LAYER_TAP || IS_USER_KEYCODE(keycode)) {
                uprintf("[KEY] %5s dn t=%lu ms layer=%u\n",
                        hrm_kc_name(keycode), (unsigned long)t,
                        get_highest_layer(layer_state));
            } else if ((keycode & 0xF000) == QK_LAYER_TAP) {
                // layer-tap key: decode the tap key so LT-sourced backspaces
                // (your LT(_CRO, KC_BSPC)) get counted for the misfire ledger
                uprintf("[KEY] %5s dn t=%lu ms layer-tapLT=%u hold-layer=%u\n",
                        hrm_kc_name(keycode & 0x00FF), (unsigned long)t,
                        (keycode >> 8) & 0x0FLAYER(0x0F),
                        get_highest_layer(layer_state));
            } else if ((keycode & 0xF000) == QK_MOD_TAP) {
                uprintf("[KEY] %5s dn t=%lu ms layer=%u\n",
                        hrm_kc_name(keycode & 0x00FF), (unsigned long)t,
                        get_highest_layer(layer_state));
            }
            break;
        }
    } else if (keycode == MARK_RACE) {
        uprintf("──── ⚑ mark released t=%lu ms ────\n", (unsigned long)t);
    }
#else
    (void)keycode;
    (void)record;
#endif
    return true;
}

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable = true;   // stream print output over the console endpoint
#endif
}
