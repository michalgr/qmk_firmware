/* Copyright 2021 Shulin Huang <mumu@x-bows.com>
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

enum layers {
  BASE,
  CONFIG,
  DIGITS,
  ARROWS,
  MOUSE,
  CODING,
  EMPTY
};

#define MO_CONF MO(CONFIG)
#define LTDI(KEY) LT(DIGITS, KC_ ## KEY)
#define LTAR(KEY) LT(ARROWS, KC_ ## KEY)
#define LTMO(KEY) LT(MOUSE, KC_ ## KEY)
#define LTCO(KEY) LT(CODING, KC_ ## KEY)

#define CTL_SPC CTL_T(KC_SPC)
#define SFT_ESC SFT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap VANILLA: (Base Layer) Default Layer
   *
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Esc |  F1  |  F2  |  F3  |  F4  |      F5  |  F6  |  F7  |  F8  |      F9  |  F10 |  F11 |  F12 |   Delete   |    Prtsc    |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |  ~  |     1   |   2   |   3   |   4   |    5      |       6    |    7    |    8   |   9  |   0  |   -  |  =  |  Backspace  |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Tab |   Q    |    W   |   E  |   R  |   T  |            |    Y   |    U   |    I  |   O  |   P  |   [  |  ]  |   \  | PgUp |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Ctl |   A   |   S   |   D  |   F  |   G  |      Bksp      |    H  |    J   |   K  |   L  |   ;  |  '"  |    Enter   | PgDn |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Shift|   Z  |   X  |   C  |   V  |   B  |       Enter       |    N  |    M   |  ,  |   .  |  /?  | Shift|      |  Up |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Ctrl | GUI |     Alter   |    Space   |   Ctrl   |   Shift   |     Space     |    Alter   |  FN  | Ctrl | Lft  |  Dn |  Rig |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   */
  [BASE] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_DEL,          KC_PSCR,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,      KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_RSFT, KC_PGUP,
    KC_CAPS, KC_A,    LTMO(S), LTCO(D), LTAR(F), LTDI(G),     KC_BSPC,      LTDI(H), KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      KC_ENT,      KC_PGDN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_ENT,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,          KC_UP,
    KC_LCTL, KC_LGUI,     KC_LALT,         CTL_SPC,       KC_LGUI, KC_RALT,     SFT_ESC,          KC_RALT,      MO_CONF, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [CONFIG] = LAYOUT(
    QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CALC, KC_MYCM, KC_MSEL, KC_MAIL,      NK_TOGG,         EEP_RST,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_NLCK,
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,
    KC_TRNS, RGB_SPD, RGB_VAD, RGB_SPI, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_END,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,          KC_VOLU,
    KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,      KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS,     KC_TRNS, KC_MPLY, KC_MPRV, KC_VOLD, KC_MNXT
  ),
  [DIGITS] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,          KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_PSLS, KC_PAST, KC_PMNS, KC_NO,   KC_NO,       KC_NO,
    KC_NO,   KC_EXLM, KC_AT,   KC_PAST, KC_PSLS, KC_LT,                     KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_HASH, KC_DLR,  KC_PPLS, KC_PMNS, KC_GRV,    KC_BSPC,        KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PCMM, KC_NO,        KC_NO,       KC_NO,
    KC_NO,   KC_PERC, KC_CIRC, KC_PIPE, KC_BSLS, KC_GT,     KC_ENT,         KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,            KC_NO,
    KC_NO,   KC_NO,       KC_NO,             KC_SPC,      KC_NO,   KC_NO,         KC_P0,           KC_PDOT,     KC_PENT, KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  [ARROWS] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,          KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_PGUP, KC_UP,   KC_HOME, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_LALT, KC_NO,   KC_NO,   KC_NO,        KC_DEL,      KC_P0,   KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,  KC_NO,        KC_NO,       KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,       KC_NO,   KC_PGDN, KC_ENT,  KC_END,  KC_NO,   KC_NO,            KC_NO,
    KC_NO,   KC_NO,       KC_NO,             KC_LCTL,     KC_LGUI,   KC_NO,       KC_NO,            KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  [MOUSE] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,          KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,       KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,        KC_NO,       KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,       KC_NO,   KC_WH_U, KC_NO,   KC_WH_D, KC_NO,   KC_NO,            KC_NO,
    KC_NO,   KC_NO,       KC_NO,             KC_NO,       KC_NO,   KC_NO,         KC_NO,            KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  [CODING] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,          KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_LBRC, KC_RBRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,       KC_LPRN, KC_RPRN, KC_MINS, KC_DOT,  KC_EQL,  KC_NO,        KC_NO,       KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,       KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_DLR,  KC_NO,            KC_NO,
    KC_NO,   KC_NO,       KC_NO,             KC_NO,       KC_NO,   KC_NO,         KC_NO,            KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
  [EMPTY] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,          KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,       KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
    KC_NO,   KC_NO,       KC_NO,             KC_NO,       KC_NO,   KC_NO,         KC_NO,            KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
};
