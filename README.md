# crony keymap — QMK layout for Silakka54

A personal QMK keymap overlay for the **Silakka54** split ergonomic keyboard.
Built around home-row mods, Chordal Hold, Flow Tap, and custom layers for
navigation, mouse control, and Croatian diacritics.

> **Keyboard**: [Silakka54](https://github.com/piit79/Silakka54) — a 54-key
> column-staggered split keyboard (RP2040 Zero controllers, EE_HANDS).
>
> **QMK**: [`silakka54:crony`](https://git.cronyakatsuki.xzy/crony/qmk-keymap)

## Features

- **Home-row mods** — six Mod-Tap keys on the home row for Shift, Ctrl, Alt,
  and GUI. No dedicated modifier keys needed.
- **Chordal Hold** — QMK's opposite-hands rule for mod-tap keys. When you
  press a mod-tap key and another key on the *same* hand, the mod-tap always
  resolves as a tap (character). When the other key is on the *opposite* hand,
  it resolves as a modifier hold. Explicit exceptions are configured for
  common same-hand shortcuts like Ctrl+C/V/X/Z, Alt+Tab, and Shift+letter
  capitalization.
- **Flow Tap** — reduces the effective tapping term when typing at speed by
  detecting fast sequences and treating them as taps. Shift keys are exempt so
  they reliably produce capitals.
- **Gaming layer** — disables home-row mods on WASD and provides a dedicated
  layer toggle. No accidental mods during gameplay.
- **Navigation layer** — arrow keys and Page Up/Down on the right hand,
  activated by holding Escape.
- **Mouse layer** — mouse movement, scrolling, and clicks on the right hand,
  activated by holding Space.
- **Function layer** — F1–F12 and media controls, activated by holding Enter.
- **Croatian layer** — five diacritic letters (š, đ, č, ć, ž) on the right
  side, activated by holding Backspace. Works with the standard Croatian
  `hr(us)` keyboard layout (AltGr-based dead keys).
- **TRRS hot-plug warnings** — the `flash-crony` script prints prominent
  safety instructions to prevent controller damage when connecting/disconnecting
  the split halves.

## Layer overview

### Base layer (`_BASE`)

```
┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┐
│ `  │  1 │  2 │  3 │  4 │  5 │    │  6 │  7 │  8 │  9 │  0 │  - │
├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
│Tab │  Q │  W │  E │  R │  T │    │  Y │  U │  I │  O │  P │  \ │
├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
│  = │A_GU│S_AL│D_CT│F_SH│  G │    │  H │J_SH│K_CT│L_AL│;GUI│  ' │
├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
│  [ │  Z │  X │  C │  V │  B │    │  N │  M │  , │  . │  / │  ] │
└────┴────┴────┴────┴────┴────┤    ├────┴────┴────┴────┴────┴────┘
                    ┌────┬────┬────┐  ┌────┬────┬────┐
                    │TG  │S→M │E→N│  │E→F │B→HR│Del │
                    └────┴────┴────┘  └────┴────┴────┘
```

**Home-row mods:**

| Key | Tap | Hold       |
|-----|-----|------------|
| `A` | a   | GUI (Win)  |
| `S` | s   | Alt        |
| `D` | d   | Ctrl       |
| `F` | f   | Shift      |
| `J` | j   | Shift      |
| `K` | k   | Ctrl       |
| `L` | l   | Alt        |
| `;` | ;   | GUI (Win)  |

**Thumb cluster (left→right):**

| Key          | Tap  | Hold             |
|--------------|------|------------------|
| `TG(_GAMING)`| —    | toggle gaming on |
| `LT(_MOUSE)` | Space| mouse layer      |
| `LT(_NAV)`   | Esc  | navigation layer |
| `LT(_FUNC)`  | Enter| function layer   |
| `LT(_CRO)`   | Bksp | Croatian layer   |
| Del          | Del  | —                |

### Gaming layer (`_GAMING`)

```
┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┐
│    │    │    │    │    │    │    │    │    │    │    │    │    │
├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
│    │    │    │    │    │    │    │    │    │    │    │    │    │
├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
│F→E │  A │  S │  D │  F │    │    │    │  J │  K │  L │  ; │    │
├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
│LSft│    │    │    │    │    │    │    │    │    │    │    │    │
└────┴────┴────┴────┴────┴────┤    ├────┴────┴────┴────┴────┴────┘
                    ┌────┬────┬────┐  ┌────┬────┬────┐
                    │L_CT│Spc │Esc │  │    │    │Base│
                    └────┴────┴────┘  └────┴────┴────┘
```

- WASD are plain keys (no mod-tap distractions).
- Left Ctrl is on the thumb for crouch-jump.
- `L_BASE` exits back to the base layer.
- Enter (`L_FUNCTIONS`) is on the leftmost pinky spot — some games use it for
  chat/menu.

### Mouse layer (`_MOUSE`)

```
Left half: nothing (or transparent)
Right half:
    WHEEL UP
  ┌─────────┐
  │         │
  │ ←  ↓  ↑ →│    mouse movement
  │         │
  └─────────┘
    BTN1  BTN2  BTN3    left/middle/right click
```

Activated by holding **Space**.

### Navigation layer (`_NAV`)

```
Right half:
    PG UP
  ┌────────┐
  │        │
  │ ←  ↓  ↑ →│    arrow keys
  │        │
  └────────┘
    PG DN
```

Activated by holding **Escape**.

### Function layer (`_FUNC`)

```
Left half:                  Right half:
┌────┬────┬────┬────┐       ┌────┬────┬────┬────┐
│ F1 │ F2 │ F3 │ F4 │       │    │    │    │    │
├────┼────┼────┼────┤       ├────┼────┼────┼────┤
│ F5 │ F6 │ F7 │ F8 │       │    │    │    │Mply│
├────┼────┼────┼────┤       ├────┼────┼────┼────┤
│ F9 │F10 │F11 │F12 │       │Prv │Vol-│Vol+│Nxt │
├────┼────┼────┼────┤       ├────┼────┼────┼────┤
│LSft│    │    │    │       │Mute│    │    │RSft│
└────┴────┴────┴────┘       └────┴────┴────┴────┘
```

Activated by holding **Enter**.

### Croatian layer (`_CRO`)

Sends `RALT(keycode)` combos for the standard Croatian `hr(us)` keyboard
layout:

| Combo     | Result |
|-----------|--------|
| RALT(`[`) | š / Š  |
| RALT(`]`) | đ / Đ  |
| RALT(`;`) | č / Č  |
| RALT(`'`) | ć / Ć  |
| RALT(`\`) | ž / Ž  |

The diacritics are placed on the right pinky column, mirroring the physical
key positions that produce them in the OS layout.

Activated by holding **Backspace**.

## Requirements

- [QMK CLI](https://docs.qmk.fm/#/cli) (`python3 -m pip install qmk`)
- QMK firmware checked out locally with your keyboards directory configured
- A Silakka54 keyboard (or other compatible split with RP2040 controllers)

## Building

```bash
qmk compile -kb silakka54 -km crony
```

Or use the included flash script:

```bash
./flash-crony          # compile + flash both halves
./flash-crony compile  # compile only
./flash-crony left     # flash left half only
./flash-crony right    # flash right half only
```

## Flashing

The Silakka54 uses **EE_HANDS** — each half must be flashed with a
handedness-specific UF2 file. The `-bl uf2-split-left` / `-bl uf2-split-right`
flags write the hand identifier to EEPROM during flashing.

The `flash-crony` script handles the full workflow:
1. Builds the firmware.
2. Waits for the left half's RP2040 bootloader (RPI-RP2 volume).
3. Flashes the left half with the `uf2-split-left` bootloader target.
4. Waits for the right half's bootloader.
5. Flashes the right half with the `uf2-split-right` target.
6. Prints detailed reconnect instructions (USB power → TRRS → power on).

### ❗ TRRS safety

The Silakka54 has no ESD/short protection on the TRRS jack. **Always** follow
this sequence:

1. **Unplug** both halves from USB.
2. **Connect** the TRRS cable.
3. **Plug in** the left half to USB (it powers both halves).

To disconnect: unplug USB first, then disconnect TRRS.

## Firmware configuration

Key settings in [`config.h`](keyboards/silakka54/keymaps/crony/config.h):

| Setting              | Value | Notes                              |
|----------------------|-------|------------------------------------|
| `TAPPING_TERM`       | 225ms | Base mod-tap timeout               |
| `FLOW_TAP_TERM`      | 150ms | Tap acceleration window            |
| `QUICK_TAP_TERM`     | 0     | Double-tap always = character      |
| `CHORDAL_HOLD`       | on    | Opposite-hands rule                |
| `PERMISSIVE_HOLD`    | on    | Allow mod + key on same press      |
| `SPECULATIVE_HOLD`   | on    | Early hold decision when possible  |

Per-key tapping term bumps for GUI keys (+20ms) to reduce accidental
Win/Cmd activations.

## Project structure

```
├── keyboards/
│   └── silakka54/
│       └── keymaps/
│           └── crony/
│               ├── keymap.c      # layer definitions, home-row mods, logic
│               ├── config.h      # QMK config, mod-tap tuning
│               └── rules.mk      # build rules (MOUSEKEY_ENABLE)
├── flash-crony                  # compile + flash script
├── .gitignore
├── LICENSE                      # GPLv3
└── README.md                    # this file
```

## License

This keymap is released under the **GNU General Public License v3.0**.
See [LICENSE](LICENSE) for the full text.

This is a personal keymap overlay for QMK firmware. QMK itself is licensed
under GPL-2.0-or-later.
