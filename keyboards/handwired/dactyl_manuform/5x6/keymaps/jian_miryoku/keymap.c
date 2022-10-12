#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  // Other custom keys...
};

#include "features/layer_lock.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
  // Your macros ...

  return true;
}

void matrix_scan_user(void) {
  layer_lock_task();
  // Other tasks...
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LALT_T(KC_I):
    case LALT_T(KC_L):
    case LALT_T(KC_R):
    case LALT_T(KC_S):
    case LCTL_T(KC_D):
    case LCTL_T(KC_S):
    case LGUI_T(KC_A):
    case RALT_T(KC_D):
    case RALT_T(KC_G):
    case RALT_T(KC_H):
    case RCTL_T(KC_E):
    case RCTL_T(KC_K):
    case RGUI_T(KC_O):
    case RGUI_T(KC_SCLN):
      return TAPPING_TERM + 100;
    default:
      return TAPPING_TERM;
  }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3,KC_ENT):
        case LT(4,KC_BSPC):
        case LT(5,KC_DEL):
        case LT(6,KC_SPC):
        case LT(7,KC_TAB):
        case LT(8,KC_ESC):
        case LT(10,KC_0):
        case LT(10,KC_ENT):
            return false;
        default:
            return true;
    }
}

#include "keymap2.c"
