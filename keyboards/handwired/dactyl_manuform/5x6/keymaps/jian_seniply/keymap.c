#include QMK_KEYBOARD_H

enum unicode_names {
    Q, W, F, P, G,
    A, R, S, T, D,
    Z, X, C, V, B,
    q, w, f, p, g
};

const uint32_t PROGMEM unicode_map[] = {
    [Q] = 0xC4,
    [W] = 0xD6,
    [F] = 0xDC,
    [P] = 0xDF,
    [G] = 0x20AC,
    [A] = 0x1F44F,
    [R] = 0xAE,
    [S] = 0x1F604,
    [T] = 0x2122,
    [D] = 0x1F641,
    [Z] = 0x1F910,
    [X] = 0x2717,
    [C] = 0xA9,
    [V] = 0x1F973,
    [B] = 0x1F4A9,
    [q] = 0xE4,
    [w] = 0xF6,
    [f] = 0xFC,
    [p] = 0xDF,
    [g] = 0xB5
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case LT(3,KC_F24):
      if (record->tap.count > 0 && record->event.pressed) {
        set_oneshot_mods(MOD_LSFT);
        return false;
      }
      break;
  }
  return true; // Process all other keycodes normally
}

// bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case LT(2,KC_SPC):
//     case LT(3,KC_F24):
//     case LT(4,KC_TAB):
//     case LT(5,KC_BSPC):
//     case LT(6,KC_ENT):
//     case LT(7,KC_DEL):
//       return false;
//     default:
//       return true;
//   }
// }

#include "keymap2.c"
