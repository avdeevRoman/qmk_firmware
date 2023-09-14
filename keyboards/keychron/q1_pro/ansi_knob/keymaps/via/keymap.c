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
    CTRL_Y_WIN_MACRO
};

// clang-format off
enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case SSHOT_MAC_MACRO:
                SEND_STRING(SS_LGUI(SS_LSFT("4")));
                return false;
            case SSHOT_WIN_MACRO:
                SEND_STRING(SS_LGUI(SS_LSFT("s")));
                return false;
            case EXIT_MAC_MACRO:
                SEND_STRING(SS_LGUI(SS_LCTL("q")));
                return false;
            case EXIT_WIN_MACRO:
                SEND_STRING(SS_LGUI("l"));
                return false;
            case LEFT_DESKTOP_MAC_MACRO:
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
                return false;
            case LEFT_DESKTOP_WIN_MACRO:
                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
                return false;
            case RIGHT_DESKTOP_MAC_MACRO:
                SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
                return false;
            case RIGHT_DESKTOP_WIN_MACRO:
                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                return false;
            case CTRL_Y_WIN_MACRO:
                SEND_STRING(SS_LCTL("y"));
                return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [MAC_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,                KC_LPAD,                 RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_DEL,            SSHOT_MAC_MACRO,
        KC_GRV,   KC_1,     KC_2,     KC_3,                   KC_4,                    KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,           RGB_TOG,
        KC_TAB,   KC_Q,     KC_W,     KC_E,                   KC_R,                    KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,           RGB_MOD,
        KC_LCTL,  KC_A,     KC_S,     KC_D,                   KC_F,                    KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,            RGB_RMOD,
        KC_LSFT,            KC_Z,     KC_X,                   KC_C,                    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        MO(MAC_FN), KC_LOPTN, KC_LCMMD,                                                          KC_SPC,                                 KC_LCMMD, KC_RCTL,  MO(MAC_FN), KC_LEFT,  KC_DOWN, KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_82(
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,                  KC_F4,                   KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_TRNS,            KC_TRNS,
        KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,                KC_TRNS,                 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  EXIT_MAC_MACRO,         KC_TRNS,                 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,            RGB_HUI,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  LEFT_DESKTOP_MAC_MACRO, RIGHT_DESKTOP_MAC_MACRO, KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS,  KC_TRNS,              KC_TRNS,            RGB_HUD,
        KC_TRNS,            KC_TRNS,  KC_TRNS,                KC_TRNS,                 KC_TRNS,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_PGUP,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                                             KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_HOME,  KC_PGDN, KC_END),

    [WIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,     KC_F1,    KC_F2,    KC_F3,                  KC_F4,                   KC_F5,    KC_F6,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_DEL,             SSHOT_WIN_MACRO,
        KC_GRV,     KC_1,     KC_2,     KC_3,                   KC_4,                    KC_5,     KC_6,             KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,            RGB_TOG,
        KC_TAB,     KC_Q,     KC_W,     KC_E,                   KC_R,                    KC_T,     KC_Y,             KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,            RGB_MOD,
        MO(WIN_FN), KC_A,     KC_S,     KC_D,                   KC_F,                    KC_G,     KC_H,             KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             RGB_RMOD,
        KC_LSFT,              KC_Z,     KC_X,                   KC_C,                    KC_V,     KC_B,             KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        MO(WIN_FN), KC_LGUI,  KC_LCTL,                                                             KC_SPC,                                         KC_LALT,  KC_LCTL,  MO(WIN_FN), KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        KC_TRNS,    KC_BRID,  KC_BRIU,  KC_TASK,                KC_FILE,                 RGB_VAD,  RGB_VAI,          KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_TRNS,            KC_TRNS,
        KC_TRNS,    BT_HST1,  BT_HST2,  BT_HST3,                KC_TRNS,                 KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,            KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  EXIT_WIN_MACRO,         KC_TRNS,                 KC_TRNS,  CTRL_Y_WIN_MACRO, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,    KC_TRNS,            RGB_HUI,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  LEFT_DESKTOP_WIN_MACRO, RIGHT_DESKTOP_WIN_MACRO, KC_TRNS,  KC_LEFT,          KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS,  KC_TRNS,              KC_TRNS,            RGB_HUD,
        KC_TRNS,              KC_TRNS,  KC_TRNS,                KC_TRNS,                 KC_TRNS,  BAT_LVL,          KC_DOWN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_PGUP,
        KC_TRNS,    KC_TRNS,  KC_TRNS,                                                             KC_TRNS,                                        KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_HOME,  KC_PGDN,  KC_END)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [MAC_FN] = {ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [WIN_FN] = {ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT)}
};
#endif // ENCODER_MAP_ENABLE
