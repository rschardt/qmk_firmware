#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define BASE 0 // default layer / VIM
#define ARW 1 // arrow layer / Terminal
#define DIAK 2 // diakritika layer
#define BRACK 3 // brackets layer
#define SYMBOLS 4 // symbols layer
#define NUMPAD 5 // numpad layer
#define MEDIA 6 // media keys / Mouse-Navigation

enum keycodes {
    DYNAMIC_MACRO_RANGE,
};

// this include needs to be here: https://docs.qmk.fm/#/feature_dynamic_macros
#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer / VIM 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  | /    |           | ?    |   6  |   7  |   8  |   9  |   0  | Numpad |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   P  |   U  | Dia-L|   ,  |   Q  |      |           |      |   V  |   C  |   L  |   M  |   B  | Media  |
 * |--------+------+------+------+------+------| str-D|           |str-U |------+------+------+------+------+--------|
 * | Symbols|   H  |   I  |   E  |   A  |   O  |------|           |------|   D  |   T  |   R  |   N  |   S  | ARW    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   K  |   Y  |   .  |   '  |   X  | ^    |           | $    |   J  |   G  |   Z  |   W  |   F  | RShift | 
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | M1Rec| M2Rec|M1Play|M2Play| Hypr |                                       |   H  |   J  |   K  |   L  | MStop| 
 *   `----------------------------------'                                       `----------------------------------'
 * LShift is Tab on Click                                                                                             
 *                                                                                                            
 *                                        ,-------------.       ,-------------.
 *                                        | Ctrl |CrlShf|       | Meh  | Alt  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |str+a |       |str+c |        |      |
 *                                 | Brack| Space|------|       |------|  Enter |BSpace| 
 *                                 | -Lay |/shift| Tab/ |       |      |        |      |
 *                                 |      |	 |  GUI	|       | ESC  |        |      |
 *                                 `--------------------'       `----------------------'
 *                                 GUI is one shot
 *                                 str + a is for tmux etc.
 *                                 str + c is for stopping programs
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
                     KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, DE_SLSH,
          KC_NO, DE_P, DE_U, OSL(DIAK), DE_COMM, DE_Q, LCTL(DE_D),
        OSL(SYMBOLS), DE_H, DE_I, DE_E, DE_A, DE_O,
    	SFT_T(KC_TAB), DE_K, DE_Y, DE_DOT, DE_QUOT, DE_X, DE_CIRC,
        DYN_REC_START1, DYN_REC_START2, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, OSM(MOD_HYPR),
        

	// left hand thumb-cluster
	        KC_LCTRL, OSM(MOD_LCTL | MOD_LSFT),
		                        LCTL(DE_A),
	OSL(BRACK), SFT_T(KC_SPACE), GUI_T(KC_TAB),


        // right hand
        DE_QST, KC_6, KC_7, KC_8, KC_9, KC_0, TG(NUMPAD),
        LCTL(DE_U), DE_V, DE_C, DE_L, DE_M, DE_B, TG(MEDIA),
                  DE_D, DE_T, DE_R, DE_N, DE_S, TG(ARW),
        DE_DLR, DE_J, DE_G, DE_Z, DE_W, DE_F, KC_RSFT,
                         KC_H, KC_J, KC_K, KC_L, DYN_REC_STOP,

	// right thumb-cluster
        OSM(MOD_MEH), KC_LALT,
        LCTL(DE_C),
        KC_ESCAPE, KC_ENTER, KC_BSPACE
),


/* Keymap 1: Arrow Layer / Terminal
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |P-Down|           | P-Up |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |  	     |
 * |--------+------+------+------+------+------| Home |           | End  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Left | Bot  | Top  | Right|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Arrows
[ARW] = LAYOUT_ergodox(
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDOWN,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_PGUP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       	         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS 
),


/* Keymap 2: Diakritika Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   Ü  |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |   Ä  |   Ö  |------|           |------|      |      |      |      |   ß  |  	     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Diakritika
[DIAK] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, DE_UE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_AE, DE_OE,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       	           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_SS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS 
),


/* Keymap 3: Brackets Layer 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   (  |   {  |   [  |      |------|           |------|      |  ]   |  }   |  )   |      |  	     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// BRACK
[BRACK] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, DE_LPRN, DE_LCBR, DE_LBRC, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       	         KC_TRNS, DE_RBRC, DE_RCBR, DE_RPRN, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS 
),


/* Keymap 4: Symbol Layer
 *
 *
 * Original:
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           | F7   |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  ²   |  °   |  ~   |  @   |  !   |      |           |      |  ?   |  &   |  §   |  "   |  ³   |        |
 * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
 * |        |  ´   |  '   |  :   |  ^   |  <   |------|           |------|  >   |  $   |  ;   |  |   |  `   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  €   |  +   |  =   |  *   |  /   |   {  |           |  }   |  \   |  %   |  #   |  -   |  _   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 */
// SYMBOLS
[SYMBOLS] = LAYOUT_ergodox(
       // left hand
        KC_TRNS,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6, 
       KC_TRNS,DE_SQ2, DE_RING, DE_TILD, DE_AT,   DE_EXLM, DE_LPRN,
       KC_TRNS,DE_ACUT,DE_QUOT, DE_COLN, DE_CIRC, DE_LESS,
       KC_TRNS,DE_EURO,DE_PLUS, DE_EQL,  DE_ASTR, DE_SLSH, DE_LCBR,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,

                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,

       // right hand
       //DE_RBRC, 
       KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_TRNS,
       DE_RPRN, DE_QST,  DE_AMPR, DE_PARA, DE_DQOT,  DE_SQ3,  KC_TRNS,
                DE_MORE, DE_DLR,  DE_SCLN, DE_PIPE,  DE_GRV,  KC_TRNS,
       DE_RCBR, DE_BSLS, DE_PERC, DE_HASH, DE_MINS,  DE_UNDS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 5: Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | 7    | 8    | 9    |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | 4    | 5    | 6    |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | 1    | 2    | 3    |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | 0    | ,    | =    |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | *    |Delete|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | /    |      |      |
 *                                 |      |      |------|       |------| Enter| +    |
 *                                 |      |      |      |       | -    |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NUMPAD
[NUMPAD] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,
                          KC_0, KC_COMM, KC_EQL, KC_TRNS, KC_TRNS,
       KC_ASTR, KC_DELETE,
       KC_SLSH,
       KC_MINS, KC_ENT, KC_PLUS 
),

/* Keymap 6: Media and mouse keys 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |WheelD|           |WheelU|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |Speed1|Speed2|Speed3|      |------|           |------|      |MsLeft|MsDown| MsUp |MsRght|        |
 * |--------+------+------+------+------+------| Prev |           | Next |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Stop | VolDn| VolUp| Play | Mute |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | RGB_-| RGB_+|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Btn4 |      |      |
 *                                 |      |      |------|       |------| Lclk | Rclk |
 *                                 |      |      |      |       | Btn3 |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
// MEDIA AND MOUSE
[MEDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D,
       KC_TRNS, KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,
       KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
       KC_WH_U,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
       KC_MNXT,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                          KC_MPLY, KC_VOLD, KC_VOLU, KC_MSTP, KC_MUTE,
       RGB_HUD, RGB_HUI,
       KC_BTN4,
       KC_BTN3, KC_BTN1, KC_BTN2
),
};

// enables dynamic macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
    return true;
}

// runs constantly in the background, in a loop.
/* Ergodox Infinity
void matrix_scan_user_keyboard(void) {
    ergodox_board_led_on();
    ergodox_led_all_on();
} 
*/

// runs just one time when the keyboard initializes.
// Ergodox EZ
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_3
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
};

// runs whenever there is a layer state change.
// Ergodox EZ
uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);
  switch (layer) {

      case 1:
        ergodox_right_led_1_on();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;

      case 6:
        ergodox_right_led_1_off();
	ergodox_right_led_2_on();
	ergodox_right_led_3_off();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;

      default:
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
	break;
  }

  return state;
};
