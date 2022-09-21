#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum jian_keycodes {
	EXT_PLV = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(2);
      }
      return false;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LALT_T(KC_H):
    case LALT_T(KC_R):
    case LALT_T(KC_S):
    case LCTL_T(KC_D):
    case LCTL_T(KC_S):
    case LGUI_T(KC_A):
    case RALT_T(KC_D):
    case RALT_T(KC_G):
    case RALT_T(KC_I):
    case RALT_T(KC_L):
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
        case LT(9,KC_SLSH):
        case LT(9,KC_Z):
        case LT(10,KC_0):
        case LT(10,KC_ENT):
            return false;
        default:
            return true;
    }
}

#include "keymap2.c"
