/* Copyright 2025 crony
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

#pragma once

// ── Chordal Hold (opposite-hands rule) ──
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS

// ── Retro Tapping ──
#define RETRO_TAPPING

// ── Speculative Hold ──
#define SPECULATIVE_HOLD

// ── Home row mod tuning ──

// Base tapping term — 190ms with RETRO_TAPPING removes the drop window.
// Chordal Hold settles same-hand rolls as taps immediately, so the tapping
// term mainly affects lone mod holds and cross-hand chords.
#define TAPPING_TERM 190

// Per-key override enabled
#define TAPPING_TERM_PER_KEY

// How long ANY home-row mod must be held before a chord with another key
// counts as deliberate (modifier/capital). A key pressed sooner than this
// after the mod goes down resolves as taps (fast-typing protection).
// The threshold must sit ABOVE your casual typing gaps (chat rhythm runs
// 100-200ms — 90 was too low) and BELOW your deliberate hold (~200ms+).
//   Tune: still accidental while typing casually → raise (170-180)
//         hotkeys need uncomfortably long hold → lower (120-130)
#define CHORD_TERM 150

// Double-tap always = character (not hold auto-repeat)
#define QUICK_TAP_TERM 0
