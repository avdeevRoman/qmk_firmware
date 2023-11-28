/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include <stdint.h>
#include QMK_KEYBOARD_H

enum custom_keycodes{
    SSHOT_MAC_MACRO = SAFE_RANGE,
    SSHOT_WIN_MACRO,
    EXIT_MAC_MACRO,
    EXIT_WIN_MACRO,
    LEFT_DESKTOP_MAC_MACRO,
    LEFT_DESKTOP_WIN_MACRO,
    RIGHT_DESKTOP_MAC_MACRO,
    RIGHT_DESKTOP_WIN_MACRO,
    CTRL_Y_WIN_MACRO,
    KC_SPACE_L1, //better LT(MAC_FN, KC_SPC). Based on isAnyKeyPressed flag, not time delay. Allows to send KC_SPC even after long pressed spacebar if no other key been pressed
    KC_SPACE_L3
};

// clang-format off
enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

static uint32_t isSpacePressed = 0;
static uint32_t isMacroDone = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case SSHOT_MAC_MACRO:
                SEND_STRING(SS_LGUI(SS_LSFT("4")));
                isMacroDone = 1;
                return false;
            case SSHOT_WIN_MACRO:
                SEND_STRING(SS_LGUI(SS_LSFT("s")));
                isMacroDone = 1;
                return false;
            case EXIT_MAC_MACRO:
                SEND_STRING(SS_LGUI(SS_LCTL("q")));
                isMacroDone = 1;
                return false;
            case EXIT_WIN_MACRO:
                SEND_STRING(SS_LGUI("l"));
                isMacroDone = 1;
                return false;
            case LEFT_DESKTOP_MAC_MACRO:
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
                isMacroDone = 1;
                return false;
            case LEFT_DESKTOP_WIN_MACRO:
                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
                isMacroDone = 1;
                return false;
            case RIGHT_DESKTOP_MAC_MACRO:
                SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
                isMacroDone = 1;
                return false;
            case RIGHT_DESKTOP_WIN_MACRO:
                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                isMacroDone = 1;
                return false;
            case CTRL_Y_WIN_MACRO:
                SEND_STRING(SS_LCTL("y"));
                isMacroDone = 1;
                return false;
            case KC_SPACE_L1:
                isSpacePressed = 1;
                default_layer_set(1 << 1);
                return true;
            case KC_SPACE_L3:
                if(isSpacePressed){
                    return false;
                }
                isSpacePressed = 1;
                default_layer_set(1 << 3);
                return false;
        }
    }
    else {
        switch(keycode) {
            case KC_SPACE_L1:
                if(!isMacroDone) {
                    SEND_STRING(" ");
                    default_layer_set(1 << 0);
                    return false;
                }
                else {
                    default_layer_set(1 << 0);
                    isMacroDone = 0;
                    return false;
                }
            case KC_SPACE_L3:
                if(isSpacePressed) {
                    SEND_STRING(" ");
                }
                default_layer_set(1 << 0);
                isSpacePressed = 0;
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_82(
        //f row
        KC_ESC,
        KC_BRID,
        KC_BRIU,
        KC_MCTL,
        KC_LPAD,
        RGB_VAD,
        RGB_VAI,
        KC_MPRV,
        KC_MPLY,
        KC_MNXT,
        KC_MUTE,
        KC_VOLD,
        KC_VOLU,
        KC_DEL,
        SSHOT_MAC_MACRO,

        //numbers row
        KC_GRV,
        KC_1,
        KC_2,
        KC_3,
        KC_4,
        KC_5,
        KC_6,
        KC_7,
        KC_8,
        KC_9,
        KC_0,
        KC_MINS,
        KC_EQL,
        KC_BSPC,
        RGB_TOG,

        //tab row
        KC_TAB,
        KC_Q,
        KC_W,
        KC_E,
        KC_R,
        KC_T,
        KC_Y,
        KC_U,
        KC_I,
        KC_O,
        KC_P,
        KC_LBRC,
        KC_RBRC,
        KC_BSLS,
        RGB_MOD,

        //caps row
        KC_LCTL,
        KC_A,
        KC_S,
        KC_D,
        KC_F,
        KC_G,
        KC_H,
        KC_J,
        KC_K,
        KC_L,
        KC_SCLN,
        KC_QUOT,
        KC_ENT,
        RGB_RMOD,

        //shift row
        KC_LSFT,
        KC_Z,
        KC_X,
        KC_C,
        KC_V,
        KC_B,
        KC_N,
        KC_M,
        KC_COMM,
        KC_DOT,
        KC_SLSH,
        KC_RSFT,
        KC_UP,

        //space row
        MO(MAC_FN),
        KC_LOPTN,
        KC_LCMMD,
        KC_SPC,
        KC_RCMMD,
        KC_RCTL,
        MO(MAC_FN),
        KC_LEFT,
        KC_DOWN,
        KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_82(
        //f row
        KC_TRNS,
        KC_F1,
        KC_F2,
        KC_F3,
        KC_F4,
        KC_F5,
        KC_F6,
        KC_F7,
        KC_F8,
        KC_F9,
        KC_F10,
        KC_F11,
        KC_F12,
        KC_TRNS,
        KC_TRNS,

        //numbers row
        KC_TRNS,
        BT_HST1,
        BT_HST2,
        BT_HST3,
        NK_TOGG,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,

        //tab row
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        EXIT_MAC_MACRO,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        RGB_HUI,

        //caps_row
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        LEFT_DESKTOP_MAC_MACRO,
        RIGHT_DESKTOP_MAC_MACRO,
        KC_TRNS,
        KC_LEFT,
        KC_DOWN,
        KC_UP,
        KC_RGHT,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        RGB_HUD,

        //shift row
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        BAT_LVL,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_PGUP,

        //space row
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_HOME,
        KC_PGDN,
        KC_END),

    [WIN_BASE] = LAYOUT_ansi_82(
        //f row
        KC_ESC,
        KC_F1,
        KC_F2,
        KC_F3,
        KC_F4,
        KC_F5,
        KC_F6,
        KC_F7,
        KC_F8,
        KC_F9,
        KC_F10,
        KC_F11,
        KC_F12,
        KC_DEL,
        SSHOT_WIN_MACRO,

        //numbers row
        KC_GRV,
        KC_1,
        KC_2,
        KC_3,
        KC_4,
        KC_5,
        KC_6,
        KC_7,
        KC_8,
        KC_9,
        KC_0,
        KC_MINS,
        KC_EQL,
        KC_BSPC,
        RGB_TOG,

        //tab row
        KC_TAB,
        KC_Q,
        KC_W,
        KC_E,
        KC_R,
        KC_T,
        KC_Y,
        KC_U,
        KC_I,
        KC_O,
        KC_P,
        KC_LBRC,
        KC_RBRC,
        KC_BSLS,
        RGB_MOD,

        //caps row
        MO(WIN_FN),
        KC_A,
        KC_S,
        KC_D,
        KC_F,
        KC_G,
        KC_H,
        KC_J,
        KC_K,
        KC_L,
        KC_SCLN,
        KC_QUOT,
        KC_ENT,
        RGB_RMOD,

        //shift row
        KC_LSFT,
        KC_Z,
        KC_X,
        KC_C,
        KC_V,
        KC_B,
        KC_N,
        KC_M,
        KC_COMM,
        KC_DOT,
        KC_SLSH,
        KC_RSFT,
        KC_UP,

        //space row
        MO(WIN_FN),
        KC_LGUI,
        KC_LCTL,
        KC_SPC,
        KC_LALT,
        KC_LCTL,
        MO(WIN_FN),
        KC_LEFT,
        KC_DOWN,
        KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        //f row
        KC_TRNS,
        KC_BRID,
        KC_BRIU,
        KC_TASK,
        KC_FILE,
        RGB_VAD,
        RGB_VAI,
        KC_MPRV,
        KC_MPLY,
        KC_MNXT,
        KC_MUTE,
        KC_VOLD,
        KC_VOLU,
        KC_TRNS,
        KC_TRNS,

        //numbers row
        KC_TRNS,
        BT_HST1,
        BT_HST2,
        BT_HST3,
        NK_TOGG,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,

        //tab row
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        EXIT_WIN_MACRO,
        KC_TRNS,
        KC_TRNS,
        CTRL_Y_WIN_MACRO,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_UP,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        RGB_HUI,

        //caps row
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        LEFT_DESKTOP_WIN_MACRO,
        RIGHT_DESKTOP_WIN_MACRO,
        KC_TRNS,
        KC_LEFT,
        KC_DOWN,
        KC_UP,
        KC_RGHT,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        RGB_HUD,

        //shift row
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        BAT_LVL,
        KC_DOWN,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_PGUP,

        //space row
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_TRNS,
        KC_HOME,
        KC_PGDN,
        KC_END)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [MAC_FN] = {ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [WIN_FN] = {ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT)}
};
#endif // ENCODER_MAP_ENABLE
