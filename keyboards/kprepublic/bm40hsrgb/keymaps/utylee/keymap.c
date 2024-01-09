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
  _ABLETON,
  _NUM,
  _SPACE_FN2,
  _SPACE_FN2_MAC,
  _FUNC,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LOWER_WOW,
  _RAISE_WOW
  /*
  _ADJUST_WOW
   */
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  MAC,
  WOW, 
  ABLETON,
  /*
  ARROW	
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
//#define NUM MO(_NUM)

#define LOWER_WOW MO(_LOWER_WOW)
#define RAISE_WOW MO(_RAISE_WOW)

//#define NUM LT(_NUM, KC_SCLN)
#define NUM LT(_FUNC, KC_SCLN)
#define SPACE_FN LT(_NUM, KC_SPC)
#define SPACE_FN2 LT(_SPACE_FN2, KC_BSPC)
#define SPACE_FN2_R LT(_SPACE_FN2, KC_SPC) // backspace가 아닌 이름대로 space로 동작합니다
#define SPACE_FN2_MAC LT(_SPACE_FN2_MAC, KC_BSPC)
#define ESC_FN2 LT(_SPACE_FN2, KC_ESC)
/* #define SPACE_FN2 LT(_SPACE_FN2, KC_SPC) */

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

/* [_QWERTY] = LAYOUT_planck_mit( */
/*     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/*     CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, */
/*     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, LT(_FUNC, KC_COMM), KC_DOT,  KC_SLSH, SFT_T(KC_QUOT), */
/*     _______, KC_LALT, KC_LGUI, LOWER,   SPACE_FN, SPACE_FN2, SPACE_FN, RAISE,   KC_RALT, KC_RCTRL,   _______ */
/* ), */

[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC),  LALT_T(KC_A),    LSFT_T(KC_S),    LGUI_T(KC_D),    LCTL_T(KC_F),    KC_G,    KC_H,   LCTL_T(KC_J),  RGUI_T(KC_K),   RSFT_T(KC_L),   RALT_T(KC_SCLN), KC_ENT,
    /* KC_LSFT, KC_Z,    KC_X,    KC_C,    LT(_NUM, KC_V),    KC_B,    KC_N,    LT(_FUNC, KC_M), KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, */
    /* KC_LSFT, KC_Z,    KC_X,    KC_C,    LT(_NUM, KC_V),    KC_B,    KC_N,    LT(_FUNC, KC_M), KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, */
	KC_LSFT, KC_Z,    KC_X,    KC_C,    LT(_NUM, KC_V),    KC_B,    KC_N,    LT(_FUNC, KC_M), LT(_FUNC, KC_COMM), KC_DOT,  RCTL_T(KC_SLSH), RSFT_T(KC_QUOT),
    /* _______, KC_LALT, KC_LGUI, LOWER,   CTL_T(KC_SPC), SPACE_FN2, SPACE_FN, RAISE,   KC_RALT, LALT_T(KC_RCTRL),   _______ */
    _______, KC_LALT, KC_LCTRL, LOWER,   CTL_T(KC_SPC), SPACE_FN2, SPACE_FN, RAISE,   KC_LCTRL, KC_LALT,   _______
),

/* [_QWERTY] = LAYOUT_planck_mit( */
/*     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/*     CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NUM, KC_ENT, */
/*     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, */
/*     _______, KC_LALT, KC_LGUI, LOWER,   KC_SPC, SPACE_FN2, KC_SPC, RAISE,   KC_RALT, KC_RCTRL,   _______ */
/* ), */
    
/* [_QWERTY] = LAYOUT_planck_mit( */
/*     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/*     CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NUM, KC_ENT, */
/*     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, LT(_FUNC, KC_COMM), KC_DOT,  KC_SLSH, KC_QUOT, */
/*     _______, KC_LALT, KC_LGUI, LOWER,   KC_SPC, SPACE_FN2, KC_SPC, RAISE,   KC_RALT, KC_RCTRL,   _______ */
/* ), */

/* [_QWERTY] = LAYOUT_planck_mit( */
/*     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/*     CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NUM, KC_ENT, */
/*     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, LT(_FUNC, KC_COMM), KC_DOT,  KC_SLSH, KC_QUOT, */
/*     _______, KC_LALT, KC_LGUI, LOWER,   KC_SPC, NUM, KC_SPC, RAISE,   KC_RALT, KC_RCTRL,   _______ */
/* ), */


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
  _______, _______, _______, _______, _______,   SPACE_FN2_MAC,  _______,  _______, KC_F18, KC_RGUI,   _______
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
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    RGUI_T(KC_K),   RSFT_T(KC_L),    RALT_T(KC_SCLN), KC_ENT,
    /* KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, LT(_FUNC, KC_COMM), LGUI_T(KC_DOT),  LCTL_T(KC_SLSH), SFT_T(KC_QUOT), */
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, LT(_FUNC, KC_COMM), LGUI_T(KC_DOT),  RCTL_T(KC_SLSH), SFT_T(KC_QUOT),
    _______, KC_LALT, RAISE_WOW, LOWER_WOW, KC_SPC, SPACE_FN2_R , SPACE_FN ,  RAISE,   KC_RCTRL, KC_RALT, _______   
    /* _______, KC_LALT, RAISE_WOW, LOWER_WOW, KC_SPC, SPACE_FN2_R , ESC_FN2 ,  RAISE,   KC_RALT, KC_LGUI, _______ */   
    /* CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, */

),
    /* _______, KC_LALT, KC_LALT, LOWER_WOW, KC_SPC, SPACE_FN2, KC_SPC ,  RAISE,   KC_RALT, KC_LGUI, _______ */   
    /* _______, KC_LALT, KC_LALT, LOWER_WOW, KC_SPC, SPACE_FN2, NUM ,  RAISE,   KC_RALT, KC_LGUI, _______ */   



/* ABLETON    ableton 등 유틸용 간편하게 누를수있는 
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
[_ABLETON] = LAYOUT_planck_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    /* KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, LT(_FUNC, KC_COMM), LGUI_T(KC_DOT),  LCTL_T(KC_SLSH), SFT_T(KC_QUOT), */
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, LT(_FUNC, KC_COMM), LGUI_T(KC_DOT),  RCTL_T(KC_SLSH), SFT_T(KC_QUOT),
    _______, KC_LALT, KC_LCTRL, LOWER_WOW, KC_SPC, SPACE_FN2 , SPACE_FN ,  RAISE,   KC_LCTRL, KC_LALT, _______   
    /* _______, KC_LALT, RAISE_WOW, LOWER_WOW, KC_SPC, SPACE_FN2_R , ESC_FN2 ,  RAISE,   KC_RCTRL, KC_LALT, _______ */   
    /* _______, KC_LALT, RAISE_WOW, LOWER_WOW, KC_SPC, SPACE_FN2_R , ESC_FN2 ,  RAISE,   KC_RALT, KC_LGUI, _______ */   
    /* CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, */

),
    /* _______, KC_LALT, KC_LALT, LOWER_WOW, KC_SPC, SPACE_FN2, KC_SPC ,  RAISE,   KC_RALT, KC_LGUI, _______ */   
    /* _______, KC_LALT, KC_LALT, LOWER_WOW, KC_SPC, SPACE_FN2, NUM ,  RAISE,   KC_RALT, KC_LGUI, _______ */   



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
// auto-shift를 위한 메모리 확보를 위해 잠시 제거해놓습니다
/* [_ARROW] = LAYOUT_planck_mit( */
/*     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_PGUP,    KC_PGDN,    KC_P,    KC_BSPC, */
/*     CTL_T(KC_ESC),  KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,    KC_G,    KC_H,  KC_PGUP ,    KC_HOME,    KC_END, KC_PGDN, KC_ENT, */
/*     KC_ENT, KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_B,    KC_N,    KC_LEFT,    KC_DOWN, KC_UP,  KC_RGHT, KC_ENT, */
/*     _______, KC_LALT, KC_LGUI, LOWER,   NUM, SPACE_FN2, NUM, RAISE,KC_DOWN, _______,   _______ */
/* ), */
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

  /* [_SPACE_FN] = LAYOUT_planck_mit( */
  /*     KC_PSCR,  KC_1, KC_2,    KC_3,   XXXXXXX,  WOW,  MAGIC_TOGGLE_NKRO ,KC_HOME, KC_PGDN,  KC_PGUP, KC_END,    _______, */ 
  /*     XXXXXXX,  KC_4, KC_5,  KC_6,  QWERTY,  QWERTY,  KC_PGDN,  KC_LEFT, KC_DOWN,  KC_UP,       KC_RIGHT,   _______, */ 
  /*     XXXXXXX,  KC_7, KC_8,  KC_9,   KC_0, KC_BRK , KC_BRK, _______, XXXXXXX,XXXXXXX  ,     XXXXXXX,    XXXXXXX, */ 
  /*     XXXXXXX,  KC_MPLY, KC_MPRV, KC_MNXT,   ARROW,  XXXXXXX,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,  XXXXXXX */
/* ), */
// space_fn 오타때문에 다른 기능은 다 빼고 브라켓과 -+쪽만 입력하도록 변경합니다

  /* [_SPACE_FN] = LAYOUT_planck_mit( */
  /*     KC_PSCR,  KC_SPC, KC_SPC,    KC_SPC,   KC_SPC,  KC_SPC,  KC_SPC ,KC_SPC, KC_SPC,  KC_SPC, KC_MINUS,KC_PLUS, */ 
  /*     KC_SPC,  KC_SPC, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC, KC_SPC,  KC_SPC,KC_LBRC,KC_RBRC, */
  /*     KC_SPC,  KC_SPC, KC_SPC,  KC_SPC,   KC_SPC, KC_SPC ,KC_SPC,KC_SPC, KC_SPC,KC_SPC  ,KC_SPC, KC_SPC, */ 
  /*     XXXXXXX,  KC_MPLY, KC_MPRV, KC_MNXT,   ARROW,  XXXXXXX,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,  XXXXXXX */
/* ), */

[_NUM] = LAYOUT_planck_mit(
    KC_PSCR,  KC_7, KC_8,    KC_9,   KC_0,  WOW,KC_ASTR,KC_7, KC_8,  KC_9, KC_0,KC_BSPC, 
    KC_SPC,  KC_4, KC_5,  KC_6,  KC_SPC,  QWERTY,  KC_MINUS,  KC_4, KC_5, KC_6,KC_PLUS,KC_ENT,
    KC_SPC,  KC_1, KC_2,  KC_3,   KC_SPC, KC_SPC ,KC_EQL,KC_1, KC_2,KC_3  ,KC_SPC, KC_SPC, 
    XXXXXXX,  KC_MPLY, KC_MPRV, KC_MNXT,   XXXXXXX,  XXXXXXX,  KC_0, KC_MUTE, KC_VOLD, KC_VOLU,  XXXXXXX
),

// wow 제거 이전 원래 버전입니다
/* [_NUM] = LAYOUT_planck_mit( */
/*     KC_PSCR,  KC_1, KC_2,    KC_3,   KC_4,  WOW,  WOW ,KC_7, KC_8,  KC_9, KC_0,KC_BSPC, */ 
/*     KC_SPC,  KC_SPC, KC_SPC,  KC_SPC,  KC_SPC,  QWERTY,  MAC,  KC_4, KC_5, KC_6,KC_PLUS,KC_ENT, */
/*     KC_SPC,  KC_SPC, KC_SPC,  KC_SPC,   KC_SPC, KC_SPC ,KC_EQL,KC_1, KC_2,KC_3  ,KC_SPC, KC_SPC, */ 
/*     XXXXXXX,  KC_MPLY, KC_MPRV, KC_MNXT,   ARROW,  XXXXXXX,  KC_0, KC_DOWN, KC_UP, KC_RIGHT,  XXXXXXX */
/* ), */

  /* Space fn 2
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
  [_SPACE_FN2] = LAYOUT_planck_mit(
      KC_PSCR,  KC_F1, KC_F2,    KC_F3,   KC_F4, WOW ,ABLETON , KC_HOME,KC_PGDN,  KC_PGUP, KC_END    ,    _______, 
      KC_ENTER,  KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT,  QWERTY,  MAC,  KC_LEFT, KC_DOWN,  KC_UP,       KC_RIGHT,   _______, 
      XXXXXXX,   WOW, WOW,  _______,   QWERTY, MAC , KC_INS, KC_DEL, KC_DEL,  KC_INS,     KC_INS,    XXXXXXX, 
      XXXXXXX,  _______, _______,  _______,   _______,  XXXXXXX,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,  XXXXXXX
),

//wow 레이어 제거전 원래 버전입니다
  /* [_SPACE_FN2] = LAYOUT_planck_mit( */
  /*     KC_PSCR,  KC_F1, KC_F2,    KC_F3,   KC_F4,  WOW,  WOW , KC_HOME,KC_PGDN,  KC_PGUP, KC_END    ,    _______, */ 
  /*     KC_ENTER,  KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT,  QWERTY,  MAC,  KC_LEFT, KC_DOWN,  KC_UP,       KC_RIGHT,   _______, */ 
  /*     XXXXXXX,   KC_F5, KC_F6,  KC_F7,   KC_F8, KC_INS , KC_INS, KC_DEL, KC_DEL,  KC_INS,     KC_INS,    XXXXXXX, */ 
  /*     XXXXXXX,  KC_F9, KC_F10,  KC_F11,   KC_F12,  XXXXXXX,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,  XXXXXXX */
/* ), */


  /* Space fn 2 MAC 
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
  [_SPACE_FN2_MAC] = LAYOUT_planck_mit(
      KC_PSCR,  KC_F1, KC_F2,    KC_F3,   KC_F4, WOW ,WOW , KC_HOME,KC_PGDN,  KC_PGUP, KC_END    ,    _______, 
      KC_ENTER,  KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT,  QWERTY,  MAC,  KC_LEFT, KC_DOWN,  KC_UP,       KC_RIGHT,   _______, 
      /* XXXXXXX,   _______, _______,  _______,   _______, KC_F19 , KC_F19, KC_DEL, KC_DEL,  KC_F19,     KC_F19,    XXXXXXX, */ 
      XXXXXXX,   WOW, WOW,  _______,   QWERTY, MAC , KC_F19, KC_DEL, KC_DEL,  KC_F19,     KC_F19,    XXXXXXX, 
      XXXXXXX,  _______, _______,  _______,   _______,  XXXXXXX,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,  XXXXXXX
),
  // insert가 없어서 가상으로 F19에 할당한 레이어입니다

/* FUNCTION
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
[_FUNC] = LAYOUT_planck_mit(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_ASTR,  KC_7, KC_8,  KC_9, KC_0, KC_MINUS, KC_PLUS,
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_EQL,   KC_4, KC_5,  DT_DOWN, DT_UP, DT_PRNT, KC_RBRC,
    _______, KC_F9,   KC_F10,   KC_F11,   KC_F12,  _______, KC_1, KC_2,  KC_3, XXXXXXX, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______,  _______, KC_MPRV, KC_MNXT, KC_MPLY, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  INS |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      layer d |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_INSERT,   _______,   KC_UNDS,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_BRK,   KC_DEL,  _______,  _______,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
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
    KC_GRV,  KC_1, KC_2,   KC_3,   KC_4, KC_5,  KC_6,  KC_7, KC_8,  KC_9, KC_0, KC_BSPC,
    KC_DEL,  _______,   _______,   _______,   _______,  _______, KC_MINUS,KC_MINUS, KC_EQL,  KC_LBRC, KC_RBRC, KC_ENT,
    _______, _______,   _______,   _______,   _______,  _______,KC_TAB,KC_1, KC_2,  KC_3, KC_BSLS, KC_BSLS,
    _______, _______, _______, _______, _______, _______, KC_DOT, _______, _______, _______, _______
),
//숫자키를 한칸씩 오른쪽으로 옮기고, eql키도 위치를 변경합니다
/* [_RAISE] = LAYOUT_planck_mit( */
/*     KC_GRV,  _______,   _______,   _______,   _______, _______,  KC_ASTR,  KC_7, KC_8,  KC_9, KC_0, KC_0, */
/*     KC_DEL,  _______,   _______,   _______,   _______,  _______, KC_EQL,KC_4, KC_5,  KC_6, KC_EQL, KC_ENT, */
/*     _______, _______,   _______,   _______,   _______,  _______,KC_0,KC_1, KC_2,  KC_3, KC_BSLS, KC_BSLS, */
/*     _______, _______, _______, _______, _______, _______, KC_DOT, _______, _______, _______, _______ */
/* ), */


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
    KC_GRV, KC_1, KC_2,   KC_3, KC_4,  KC_5, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    _______,  KC_4,   KC_5,   KC_6,   KC_7,   KC_INS,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_7,   KC_8,   KC_9,   KC_0,  KC_DEL,  _______,  _______, S(KC_NUBS), KC_HOME, KC_END,  _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_MNXT,    KC_VOLD, KC_VOLU, XXXXXXX
),
    /* _______, KC_7,   KC_8,   KC_9,   KC_0,  KC_DEL,  ARROW,  ARROW, S(KC_NUBS), KC_HOME, KC_END,  _______, */

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
    KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_ASTR,  KC_7, KC_8,  KC_9, KC_0, KC_MINUS, KC_PLUS,
    KC_ESC,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_EQL,   KC_4, KC_5,  KC_6, KC_EQL, KC_LBRC, KC_RBRC,
    /* _______, KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_F11, _______, _______,  KC_3, KC_UP, KC_BSLS, KC_DEL, */
	/* Finals 에서 F11전체화면 을 막기위해 F11은 제거합니다 */
    _______, KC_F9,   KC_F10,   XXXXXXX,   KC_F12,  XXXXXXX, _______, _______,  KC_3, KC_UP, KC_BSLS, KC_DEL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
    _______, _______, _______, _______,_______, MAGIC_TOGGLE_NKRO, MAGIC_TOGGLE_NKRO, QWERTY,  QWERTY,  _______, MAC, MAC,

   _______, _______, _______, _______, _______, _______, _______, KC_PSCR,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

//auto-shift 메모리 부족문제로 wow를 제거해놓습니다
/* [_ADJUST] = LAYOUT_planck_mit( */
/*     _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______ , */
/*     _______, _______, _______, WOW, WOW, MAGIC_TOGGLE_NKRO, MAGIC_TOGGLE_NKRO, QWERTY,  QWERTY,  _______, MAC, MAC, */

/*    _______, _______, _______, _______, _______, _______, _______, KC_PSCR,  _______,  _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______ */
/* ), */

/* [_ADJUST_WOW] = LAYOUT_planck_mit( */
/*     _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______ , */
/*     _______, _______, _______, WOW, WOW, _______, _______, QWERTY,  QWERTY,  _______,MAC, MAC, */

/*    _______, _______, _______, _______, _______, _______, _______, KC_PSCR,  _______,  _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______ */
/* ) */

};

void matrix_init_user(void) {
    /* backlight_level(200); */
    //rgblight_disable_noeeprom();  // 여기서 추가하면 전체 끌수 있습니다

}

// #define TAPPING_TERM_PER_KEY 를 제거해서 아래 함수가 불려질 것 같진 않은데
// 아직 잘 모르겠습니다

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		/*	
        case SFT_T(KC_SPC):
            return TAPPING_TERM + 1250;
        case LT(1, KC_GRV):
            return 130;
		*/
		/*
		case SPACE_FN:
			return 200;
			break;	
		case RAISE_WOW:
			return 50;
			break;
		// lower 나 raise같은 mod tap에서는 적용안됩니다. 커스텀 tap를 위한 딜레이입니다 
		case LOWER_WOW:
			return 50;
			break;	
		*/

    /* CTL_T(KC_ESC),  KC_A,    LSFT_T(KC_S),    LGUI_T(KC_D),    LCTL_T(KC_F),    KC_G,    KC_H,   RCTL_T(KC_J),  RGUI_T(KC_K),   RSFT_T(KC_L),   NUM, KC_ENT, */

		//case SFT_T(KC_QUOT):
        // quot에서 shift를 제거하고 slash키쪽으로 기능을 이전합니다
		/* case SFT_T(KC_SLSH): */
		/* 	//return 250;         //다소 길어도 holdonotherkey press에 의해 r shift로 잘 인식됩니다 */
		/* 	return 300;         //좀불편한 것 같아 초기설정으로 세팅해봅니다 */
		/* 	break; */

        // Lefties
        case LALT_T(KC_A):
			/* return 220; */
			/* return 190; */

			/* DYNAMIC_TAPPING_TERM_ENABLE	을 사용하기에 */
			/* TAPPING_TERM이 아닌 g_tapping_term을 사용하여야 합니다 */
			return g_tapping_term ;  //190
			break;
        case LSFT_T(KC_S):
			/* return 210; */
			/* return 190; */
			return g_tapping_term ;
			break;
		case LGUI_T(KC_D):
			/* return 210; */
			/* return 190; */
			return g_tapping_term ;
			break;
		case LCTL_T(KC_F):
			/* return 280; */
			/* return 190; */
			return g_tapping_term ;
			break;

  
        // Righties
        case RCTL_T(KC_J):
			/* return 280; */  
			/* return 190; */  
			return g_tapping_term ;
			break;
        case RGUI_T(KC_K):
			/* return 210; */ 
			/* return 190; */ 
			return g_tapping_term ;
			break;
        case RSFT_T(KC_L):
			/* return 210; */
			/* return 190; */
			return g_tapping_term ;
			break;
        case RALT_T(KC_SCLN):
			/* return 210; */
			/* return 190; */
			return g_tapping_term ;
			break;

        // V Number mod
		case LT(_NUM, KC_V):
			return 230;
			break;

		case CTL_T(KC_ESC):
			/* return 100; */   
			/* return 150; */   
			return 200;   
			break;

		case RCTL_T(KC_SLSH):
			return 250;
			break;

		/* case LCTL_T(KC_SLSH): */
		/* 	/1* return 200; *1/ */   
		/* 	return 100; */   
		/* 	break; */

		case NUM:
			return 200;         
			break;
		case SPACE_FN:
			return g_tapping_term;
			/* 아무리낮아도 retro tapping 옵션을 설정하기에 스페이스는 반납됩니다 */
			/* return 70; */
			/* return 140; */
			break;

		case SPACE_FN2:
			//return 50;
			//return 140;
			return 800;			// holdonotherkey으로 등록했기에 길어도 됩니다
								// retrotapping을 꺼놓았기에 좀 길게해야 할 것 같습니다  
			break;
        default:
            /* return TAPPING_TERM; */
            return g_tapping_term;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case CTL_T(KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
		case CTL_T(KC_SPC):
            // Immediately select the hold action when another key is pressed.
            return true;
		case SPACE_FN2:
            // Immediately select the hold action when another key is pressed.
            return true;
		case SPACE_FN2_R:
            // Immediately select the hold action when another key is pressed.
            return true;
		case SPACE_FN2_MAC:
            // Immediately select the hold action when another key is pressed.
            return true;
		case NUM:
            // Immediately select the hold action when another key is pressed.
            return false;
		case SPACE_FN:
            // Immediately select the hold action when another key is pressed.
            return false;
            
		//case SFT_T(KC_QUOT):
		//case SFT_T(KC_SLSH):
            // Immediately select the hold action when another key is pressed.
            //return true;
        case LT(_FUNC, KC_COMM):
            return false;

        //comma 의 _FUNC와 space_fn는 바로 동작하지는 않게 안 넣어줍니다 

        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// 아무키도 안 눌리면 먹통이 아닌 기존 키를 반납하는 기능입니다
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPACE_FN:
            return true;

		// 느린 tapping term에도 영향없게끔 하려고 추가해봤으나 esc가
		// 중요한 부분이 꽤 있었습니다. 예) 일지 작성 사진 업로드 창
		/* case CTL_T(KC_ESC): */
            /* return true; */
        // 아무래도 브라우저 탐색중리스크 발생 가능성이 높아보여 다시 제거하기로 했습니다
        case SPACE_FN2:
            return false;
        default:
            return false;
    }
}

// 모드 키를 연속 누를 때 모드 기능이 꺼지고 반복모드가 되는 것을 구분하는 코드입니다
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPACE_FN2:
            return true;
		/* 오른손 모드 키들은 tapping_force_hold를 적용하지 않습니다. */
        case LCTL_T(KC_J):
            return false;
        case RGUI_T(KC_K):
            return false;
        case RSFT_T(KC_L):
            return false;
        case RALT_T(KC_SCLN):
            return false;
        default:
            return true;
    }
}

// auto-shift에서 그룹별 동작정의 함수입니다
/* uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) { */
/*     switch(keycode) { */
/*         case AUTO_SHIFT_NUMERIC: */
/*             return 2 * get_generic_autoshift_timeout(); */
/*         case AUTO_SHIFT_SPECIAL: */
/*             return get_generic_autoshift_timeout() + 50; */
/*         case AUTO_SHIFT_ALPHA: */
/*         default: */
/*             return get_generic_autoshift_timeout(); */
/*     } */
/* } */

/*
// auto-shift에서 커스텀 동작 정의입니다
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_DOT:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_M:
            register_code16((!shifted) ? KC_M : KC_1);
            break;
        case KC_COMM:
            register_code16((!shifted) ? KC_COMM : KC_2);
            break;
        case KC_DOT:
            register_code16((!shifted) ? KC_DOT : KC_3);
            break;
        case KC_J:
            register_code16((!shifted) ? KC_J : KC_4);
            break;
        case KC_K:
            register_code16((!shifted) ? KC_K: KC_5);
            break;
        case KC_L:
            register_code16((!shifted) ? KC_L : KC_6);
            break;
        case KC_U:
            register_code16((!shifted) ? KC_U : KC_7);
            break;
        case KC_I:
            register_code16((!shifted) ? KC_I: KC_8);
            break;
        case KC_O:
            register_code16((!shifted) ? KC_O : KC_9);
            break;
        case KC_P:
            register_code16((!shifted) ? KC_P : KC_0);;
            break;

        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
            //register_code16(keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_M:
            unregister_code16((!shifted) ? KC_M : KC_1);
            break;
        case KC_COMM:
            unregister_code16((!shifted) ? KC_COMM : KC_2);
            break;
        case KC_DOT:
            unregister_code16((!shifted) ? KC_DOT : KC_3);
            break;
        case KC_J:
            unregister_code16((!shifted) ? KC_J : KC_4);
            break;
        case KC_K:
            unregister_code16((!shifted) ? KC_K: KC_5);
            break;
        case KC_L:
            unregister_code16((!shifted) ? KC_L : KC_6);
            break;
        case KC_U:
            unregister_code16((!shifted) ? KC_U : KC_7);
            break;
        case KC_I:
            unregister_code16((!shifted) ? KC_I: KC_8);
            break;
        case KC_O:
            unregister_code16((!shifted) ? KC_O : KC_9);
            break;
        case KC_P:
            unregister_code16((!shifted) ? KC_P : KC_0);;
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
            //unregister_code16(keycode & 0xFF );
    }
}
*/
//<-----auto-shift


/*
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case CTL_T(KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
		case SPACE_FN2:
            // Immediately select the hold action when another key is pressed.
            return true;
		// case SPACE_FN: 
		case NUM: 
             // Immediately select the hold action when another key is pressed. 
             return true; 
		//case SFT_T(KC_QUOT):
		case SFT_T(KC_SLSH):
            // Immediately select the hold action when another key is pressed.
            return true;

        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
*/


layer_state_t layer_state_set_user(layer_state_t state) {
	state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    //state = update_tri_layer_state(state, _LOWER_WOW, _RAISE_WOW, _ADJUST_WOW);
	//switch (get_highest_layer(state)) {
	switch (biton32(state)) {
		case _QWERTY:
			/* rgblight_sethsv_noeeprom(0, 0 , 10); */
            
			//rgblight_setrgb (0x00,  0xFF, 0x00);
			//rgblight_sethsv(15, 15 , 15);
            //rgblight_disable_noeeprom();       // 여기서도 되는 것 같긴한데 다른 레이어는
                                                // 안 먹히던 것 같습니다. 저 state관련 문제인듯
			break;
		/* case _WOW: */
		/* 	//rgblight_setrgb (0x00dfa  0xFF, 0x00); */
		/* 	rgblight_sethsv_noeeprom(30, 218 , 15); */
		/* 	break; */
        case _MAC:
			/* rgblight_sethsv_noeeprom(170, 255 , 50); */

            //rgblight_set_layer_state(_MAC, 0);
            //rgblight_disable_noeeprom();      // 여기서도 되는 것 같긴한데 다른 레이어는
                                                // 안 먹히던 것 같습니다. 저 state관련 문제인듯

			//rgblight_setrgb (0xFF,  0x00, 0x00);
			break;
		case _RAISE:
			/* rgblight_sethsv_noeeprom(0, 0 , 25); */

			//rgblight_setrgb (0x00,  0x00, 0xFF);
			break;
		case _LOWER:
			/* rgblight_sethsv_noeeprom(0, 0 , 25); */

			//rgblight_setrgb (0xFF,  0x00, 0x00);
			//rgblight_sethsv_noeeprom(64, 64 , 25);
			break;
		case _ADJUST:
			/* rgblight_sethsv_noeeprom(255, 255 , 50); */

			//rgblight_setrgb (0x7A,  0x00, 0xFF);
			break;
		/* case _ADJUST_WOW: */
		/* 	rgblight_sethsv_noeeprom(255, 255 , 15); */
		/* 	//rgblight_setrgb (0x7A,  0x00, 0xFF); */
		/* 	break; */
		//case _SPACE_FN:
		case _NUM:
			/* rgblight_sethsv_noeeprom(255, 255 , 100); */

            break;
		default: //  for any other layers, or the default layer
			/* rgblight_sethsv_noeeprom(170, 255 , 50); */
            
			//rgblight_setrgb (0xFF,  0x00, 0x00);
			//rgblight_sethsv_noeeprom(15, 15 , 15);
			//rgblight_setrgb (0xFF,  0x00, 0x00);
			break;
		}
	return state;
	//return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
		/* dprint("come into qwerty\n"); */
      if (record->event.pressed) {
        /* dprint("mode just switched to qwerty and this is a huge string\n"); */
        set_single_persistent_default_layer(_QWERTY);
        /* rgblight_enable_noeeprom(); */
      }
      return false;
      break;
    case MAC:
		/* dprint("come into mac\n"); */
      if (record->event.pressed) {
        /* dprint("mode just switched to mac and this is a huge string\n"); */
        set_single_persistent_default_layer(_MAC);
        /* rgblight_disable_noeeprom(); */
      }
      return false;
      break;
      
    /* case ARROW: */
		/* // dprint("come into arrow\n"); */ 
    /*   if (record->event.pressed) { */
    /*     //dprint("mode just switched to arrow and this is a huge string\n"); */ 
    /*     set_single_persistent_default_layer(_ARROW); */
    /*   } */
    /*   return false; */
    /*   break; */
    case WOW:
		/* dprint("come into wow\n"); */
      if (record->event.pressed) {
        /* dprint("mode just switched to wow and this is a huge string\n"); */
        set_single_persistent_default_layer(_WOW);
        /* rgblight_enable_noeeprom(); */
      }
      return false;
      break;
    case ABLETON:
		/* dprint("come into wow\n"); */
      if (record->event.pressed) {
        /* dprint("mode just switched to wow and this is a huge string\n"); */
        set_single_persistent_default_layer(_ABLETON);
        /* rgblight_enable_noeeprom(); */
      }
      return false;
      break;
	  /*
    case LOWER_WOW:
      if (record->event.pressed) {
		//dprint("lowerwow down\n");
        layer_on(_LOWER_WOW);
	  update_tri_layer(_LOWER_WOW, _RAISE_WOW, _ADJUST);
      } else {
		//dprint("lowerwow up\n");
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

