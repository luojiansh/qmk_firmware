#include "keymap2.c"


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
        case RSFT_T(KC_ENT):
            return true;
        default:
            return false;
    }
}

