# Nova Lemokey X2 keymap

This is the firmware half of Nova's personal input architecture on the
Lemokey X2 ANSI red board. The accepted branch is `nova/x2-baseline`.

Firmware owns stable physical identities, deterministic interruption-based
tap/hold behavior, pointer layers, and the physical layer lamp. Host meanings
belong to the separate XKB/GNOME repository.

## Current special controls

| Physical role | Tap / base action | Hold / layer action |
| --- | --- | --- |
| Caps position | `PB_11` Hyper transport | — |
| Compose / AltGr | `PB_12` | `PB_25` |
| Menu / Right Control | `KC_MENU` | `KC_RCTL` |
| Any / Meta | `PB_26` | `KC_APP` |
| Insert / Level5 | `KC_INS` | `PB_29` |
| Whisper | `PB_28` press and release | — |
| NumLock position | toggle Mouse layer | — |

A pending dual-role key becomes its hold action when another key interrupts
it. Releasing it alone emits the tap action. There is no tapping-term race.

`KC_APP` is intentionally the Meta transport because Linux/XKB carries it as
`<COMP>`. `KC_MENU` remains separately available as `<PROP>`.

## Pointer layers and lamp

- The NumLock position toggles the Mouse layer.
- Arrow keys move the pointer on Mouse.
- Delete, End, and Page Down act as mouse buttons.
- Either Shift momentarily selects Scroll; the arrows then send wheel motion.
- The physical NumLock lamp is off on Base, solid on Mouse, and blinks every
  250 ms on Scroll.

The firmware never sends `KC_NUM_LOCK`, never mirrors host NumLock state, and
contains no NumLock reassertion watchdog. The keypad remains numeric through
the host XKB design.

## Build and flash

```bash
qmk compile -kb keychron/x2/ansi/red -km default
```

```bash
qmk flash -kb keychron/x2/ansi/red -km default
```

The current firmware was compiled, flashed, and accepted on MACE. The layer
lamp works in live use, and the retired watchdog's repeated phantom NumLock
events are absent.

## Host-side meaning and status

The canonical whole-system status lives in
[`wdcallahan/x1_keyboard_layout`](https://github.com/wdcallahan/x1_keyboard_layout):

- [guided tour](https://github.com/wdcallahan/x1_keyboard_layout/blob/main/docs/nova-keyboard-input-architecture.md)
- [technical architecture](https://github.com/wdcallahan/x1_keyboard_layout/blob/main/docs/keyboard-architecture.md)
- [symbol vocabulary](https://github.com/wdcallahan/x1_keyboard_layout/blob/main/docs/symbol-vocabulary.md)

In particular, a working firmware transport does not imply that every
application consumes the resulting modifier. General Meta in Ptyxis and the
Whisper recording/transcription service remain separate host-side work.
