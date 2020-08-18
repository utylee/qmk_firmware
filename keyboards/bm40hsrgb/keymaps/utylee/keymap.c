/* Copyright 2020 tominabox1
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
  _QWERTY,
  _MAC,
  _WOW,
  _ARROW,
  _SPACE_FN,
  _LOWER,
  _RAISE,
  _LOWER_WOW,
  _RAISE_WOW,
  _ADJUST,
  _ADJUST_WOW
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  MAC,
  WOW,
  ARROW	
  /*
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER ,
  //RAISE = LT(_RAISE, KC_RALT),
  RAISE ,
  BACKLIT,
  EXT_PLV,
  S,
  N,
  D,
  PLAYER,
  KEYPAD,
  MYPWD1,
  MYPWD2,
  GAME
  */
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LOWER_WOW MO(_LOWER_WOW)
#define RAISE_WOW MO(_RAISE_WOW)

#define SPACE_FN LT(_SPACE_FN, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    _______, KC_LALT, KC_LGUI, LOWER,   SPACE_FN, SPACE_FN, SPACE_FN, RAISE,   KC_RALT, _______,   _______
),

/* MAC    qwerty에서 한글키만 일단 바꾸기로
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * | _______| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |_______ |
 * `-----------------------------------------------------------------------------------'
 */
[_MAC] = LAYOUT_planck_mit(
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,
  /*{KC_LCTL,  KC_A,    KC_S,    KC_D,    LT(_S, KC_F),    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},*/
  _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
  _______, _______, _______, _______, _______,   _______,  _______,  _______, KC_F18, _______,   _______
),

/* WOW    wow 등 게임용 숫자를 간편하게 누를수있는 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * | _______| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |_______ |
 * `-----------------------------------------------------------------------------------'
 */
[_WOW] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    _______, RAISE_WOW, KC_LALT, LOWER_WOW, LOWER_WOW,   KC_SPC,  RAISE_WOW,   KC_RALT, KC_DOWN, _______,   _______
),
/*
[_WOW] = LAYOUT_planck_mit(
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,
  _______, RAISE_WOW, _______, _______, LOWER_WOW,   KC_SPC, RAISE_WOW,  KC_RALT, LOWER, RAISE,   _______
),
*/


/* Arrow  방향키를 편하게 누를수 있기 위한 레이어 입니다
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * | _______| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |_______ |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROW] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_PGUP,    KC_PGDN,    KC_P,    KC_BSPC,
    CTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,  XXXXXXX ,    KC_HOME,    KC_END, _______, KC_ENT,
    KC_ENT, KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_B,    KC_N,    KC_LEFT,    KC_DOWN, KC_UP,  KC_RGHT, KC_ENT,
    _______, KC_LALT, KC_LGUI, LOWER,   SPACE_FN, SPACE_FN, SPACE_FN, RAISE,KC_DOWN, _______,   _______
),
/*
[_ARROW] = LAYOUT_planck_mit(
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
  _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,  KC_END, _______,
  _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, KC_PGDN,  KC_PGUP, _______ ,
  _______, _______, _______, _______, _______,   _______,  _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
*/

  /* Space fn
  * ,-----------------------------------------------------------------------------------.
  * |PRNT SC|      |  UP  |      |      |      |      |      |      |      |      |SLEEP |
  * |-------+------+------+------+------+-------------+------+------+------+------+------|
  * |       | LEFT | DOWN | RIGHT|      |      |      | LEFT | DOWN |  UP  | RIGHT|      |
  * |-------+------+------+------+------+------|------+------+------+------+------+------| 
  * |       |      |      |      |      |      |      |      |      |      |      |      |
  * |-------+------+------+------+------+------+------+------+------+------+------+------|
  * |       |      |      |      |      |             |      | MUTE |VOLDWN|VOL UP|      |
  * `-----------------------------------------------------------------------------------'
  */
  [_SPACE_FN] = LAYOUT_planck_mit(
      KC_PSCR,  _______, KC_UP,    WOW,   WOW,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_PGUP,  KC_PGDN,     XXXXXXX,    _______, 
      XXXXXXX,  KC_LEFT, KC_DOWN,  KC_RIGHT,  QWERTY,  QWERTY,  QWERTY,  KC_LEFT, KC_DOWN,  KC_UP,       KC_RIGHT,   _______, 
      XXXXXXX,  KC_PSCR, KC_PSCR,  XXXXXXX,   ARROW, ARROW , _______, _______, KC_HOME,  KC_END,     XXXXXXX,    XXXXXXX, 
      XXXXXXX,  KC_MPRV, KC_MPLY,  KC_MNXT,   _______,  _______,  _______, KC_MUTE, KC_VOLD, KC_VOLU,  XXXXXXX
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  INS |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_INSERT,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_DEL,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_ASTR,  KC_7, KC_8,  KC_9, KC_0, KC_MINUS, KC_PLUS,
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_EQL,   KC_4, KC_5,  KC_6, KC_EQL, KC_LBRC, KC_RBRC,
    _______, KC_F9,   KC_F10,   KC_F11,   KC_F12,  _______, KC_1, KC_2,  KC_3, XXXXXXX, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower WOW
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  INS |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER_WOW] = LAYOUT_planck_mit(
    _______, KC_1, KC_2,   KC_3, KC_4,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_5,   KC_6,   KC_7,   KC_8,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_9,   KC_0,   KC_0,   KC_DEL,  KC_DEL,  ARROW,  ARROW, S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, _______
),

/* Raise WOW
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE_WOW] = LAYOUT_planck_mit(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_ASTR,  KC_7, KC_8,  KC_9, KC_0, KC_MINUS, KC_PLUS,
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_EQL,   KC_4, KC_5,  KC_6, KC_EQL, KC_LBRC, KC_RBRC,
    _______, KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_F11, _______, _______,  KC_3, KC_UP, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______ ,
    _______, _______, _______, WOW, WOW, _______, _______, QWERTY,  QWERTY,  _______, MAC, MAC,

   _______, _______, _______, _______, _______, _______, _______, KC_PSCR,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),
[_ADJUST_WOW] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______ ,
    _______, _______, _______, WOW, WOW, MAC, MAC, QWERTY,  QWERTY,  MAC, _______, MAC,

   _______, _______, _______, _______, _______, _______, _______, KC_PSCR,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
	state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    //state = update_tri_layer_state(state, _LOWER_WOW, _RAISE_WOW, _ADJUST_WOW);
	switch (get_highest_layer(state)) {
		case _QWERTY:
			//rgblight_setrgb (0x00,  0xFF, 0x00);
			rgblight_sethsv(15, 15 , 15);
			break;
		case _MAC:
			rgblight_sethsv(25, 125 , 10);
			//rgblight_setrgb (0xFF,  0x00, 0x00);
			break;
		case _RAISE:
			rgblight_sethsv(125, 125 , 25);
			//rgblight_setrgb (0x00,  0x00, 0xFF);
			break;
		case _LOWER:
			//rgblight_setrgb (0xFF,  0x00, 0x00);
			rgblight_sethsv(64, 64 , 25);
			break;
		case _ADJUST:
			rgblight_sethsv(255, 255 , 50);
			//rgblight_setrgb (0x7A,  0x00, 0xFF);
			break;
		default: //  for any other layers, or the default layer
			//rgblight_setrgb (0xFF,  0x00, 0x00);
			rgblight_sethsv(15, 15 , 15);
			break;
		}
	return state;
	//return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
		dprint("come into qwerty\n");
      if (record->event.pressed) {
        dprint("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case MAC:
		dprint("come into mac\n");
      if (record->event.pressed) {
        dprint("mode just switched to mac and this is a huge string\n");
        set_single_persistent_default_layer(_MAC);
      }
      return false;
      break;
    case ARROW:
		dprint("come into arrow\n");
      if (record->event.pressed) {
        dprint("mode just switched to arrow and this is a huge string\n");
        set_single_persistent_default_layer(_ARROW);
      }
      return false;
      break;
    case WOW:
		dprint("come into wow\n");
      if (record->event.pressed) {
        dprint("mode just switched to wow and this is a huge string\n");
        set_single_persistent_default_layer(_WOW);
      }
      return false;
      break;
	  /*
    case LOWER_WOW:
      if (record->event.pressed) {
		dprint("lowerwow down\n");
        layer_on(_LOWER_WOW);
	  update_tri_layer(_LOWER_WOW, _RAISE_WOW, _ADJUST);
      } else {
		dprint("lowerwow up\n");
        layer_off(_LOWER_WOW);
	  update_tri_layer(_LOWER_WOW, _RAISE_WOW, _ADJUST);
      }
      return false;
      break;
    case RAISE_WOW:
      if (record->event.pressed) {
		dprint("raisewow down\n");
        layer_on(_RAISE_WOW);
	  update_tri_layer(_LOWER_WOW, _RAISE_WOW, _ADJUST);
      } else {
		dprint("raisewow up\n");
        layer_off(_RAISE_WOW);
	  update_tri_layer(_LOWER_WOW, _RAISE_WOW, _ADJUST);
      }
      return false;
      break;
	  */
	  /*
    case LOWER:
      if (record->event.pressed) {
		dprint("lower down\n");
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
		dprint("lower up\n");
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
		dprint("raise down\n");
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
		dprint("raise up\n");
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
	  */
	  /*
    case GAME:
		print("come into game\n");
      if (record->event.pressed) {
        print("mode just switched to game and this is a huge string\n");
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case S:
      if (record->event.pressed) {
        layer_on(_S);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_S);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case N:
      if (record->event.pressed) {
        layer_on(_N);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_N);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case D:
      if (record->event.pressed) {
        layer_on(_D);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_D);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
	  
    case PLAYER:
      if (record->event.pressed) {
        print("mode just switched to player and this is a huge string\n");
        set_single_persistent_default_layer(_PLAYER);
      }
      return false;
      break;
    case KEYPAD:
      if (record->event.pressed) {
        print("mode just switched to keypad and this is a huge string\n");
        set_single_persistent_default_layer(_KEYPAD);
      }
      return false;
      break;
	 
	 */ 

	  /*
=======
>>>>>>> upstream/master
*/
	  /*
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
	  */
	  /*
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
	// 매크로 
	case MYPWD1:
	  if (record->event.pressed) {
		  SEND_STRING("sksmsqnwk11");
	  }

	  return false;
	case MYPWD2:
	  if (record->event.pressed) {
		  SEND_STRING("sksmsqnwk1!");
	  }

	  return false;
	  */
	/*
	case SHFTPSCR:
	  //SEND_STRING(SS_DOWN(KC_LSFT)SS_TAP(X_PSCREEN)SS_UP(KC_LSFT));
	  //SEND_STRING(SS_LSFT()SS_TAP(X_PSCREEN));
	  //SEND_STRING(SS_DOWN(KC_LSFT)""SS_TAP(X_PSCREEN));
	  //SEND_STRING(SS_TAP(X_PSCREEN));
	  //SEND_STRING(SS_TAP(X_PSCREEN));
	  //
	  //
      if (record->event.pressed) {
		SEND_STRING("fucker");
		}

	  return false;
	  */

	  /*
	default:
	  print("hi");
	  */

  }
  return true;
}

