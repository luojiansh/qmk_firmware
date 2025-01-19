#include QMK_KEYBOARD_H

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

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(2,KC_SPC):
    case LT(3,KC_F24):
    case LT(4,KC_TAB):
    case LT(5,KC_BSPC):
    case LT(6,KC_ENT):
    case LT(7,KC_DEL):
      return false;
    default:
      return true;
  }
}

#include "keymap2.c"
