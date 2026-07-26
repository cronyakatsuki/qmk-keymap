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

// ── Home row mod tuning ──

// Base tapping term — generous to avoid accidental mods
#define TAPPING_TERM 180

// Per-key override enabled
#define TAPPING_TERM_PER_KEY

// Cross-hand mod fires instantly — same-hand waits for tapping term.
// This lets you type fast across hands (e.g. Shift + letter) while
// preventing accidental mods from same-hand rollover.
#define HOLD_ON_OTHER_KEY_PRESS

// Long hold + release without pressing anything else = tap on release.
// Catches accidental holds when you're just hesitating.
#define RETRO_TAPPING

// Double-tap always = character (not hold auto-repeat)
#define QUICK_TAP_TERM 0
