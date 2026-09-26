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

// ── Flow Tap ──
#define FLOW_TAP_TERM 150

// ── Home row mod tuning ──

// Base tapping term — 190ms with RETRO_TAPPING removes the drop window.
// Chordal Hold settles same-hand rolls as taps immediately, so the tapping
// term mainly affects lone mod holds and cross-hand chords.
#define TAPPING_TERM 190

// Per-key override enabled
#define TAPPING_TERM_PER_KEY

// Double-tap always = character (not hold auto-repeat)
#define QUICK_TAP_TERM 0
