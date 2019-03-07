#include QMK_KEYBOARD_H

#define BASE 0
#define UPPER 1
#define MIDI 2

#define _ KC_TRNS

enum {
  TD_SLSH = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SLSH]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,

    MT(MOD_LCTL, KC_A),    KC_S,    KC_D,    KC_F,    KC_G,
    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,

    MT(MOD_LCTL, KC_Z),    KC_X,    KC_C,    LT(UPPER, KC_V),    LT(UPPER, KC_B),
    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(TD_SLSH),

    MT(MOD_LSFT, KC_ESC), KC_MINS, KC_EQL, KC_QUOT, MT(MOD_LALT, KC_TAB),

    MT(MOD_LCTL, KC_ESC), 
    LT(UPPER, KC_SPC), 

    //midi
    LT(MIDI, KC_GRV), KC_LBRC, KC_RBRC,   KC_BSPC, KC_ENT
  ),

  //KC_QUOT

  [UPPER] = LAYOUT( 
    KC_1, KC_2,   KC_3,   KC_4, KC_5,         
    _, _, _, _, _,          
    
    KC_6, KC_7,    KC_8,   KC_9, KC_0,
    KC_LEFT, KC_DOWN,    KC_UP,   KC_RIGHT, _,

    _, _, _, _, _,         
    _,  _,  _, _, _,

    _, _,  _, _, _, 
    _, _,
    RALT(KC_TAB),  RALT(KC_M), LCTL(LALT(KC_DEL)), _, RESET
    
    ),

    [MIDI] = LAYOUT(
      MI_C, MI_Cs,  MI_D, MI_Ds, //lh
      KC_TRNS, KC_TRNS, 
      MI_E,    MI_F,    MI_Fs,  MI_G,  //rh

      MI_E_1,    MI_F_1,    MI_Fs_1,  MI_G_1,  //lh
      KC_TRNS, KC_TRNS, 
      MI_Gs_1,    MI_A_1,    MI_As_1,  MI_B_1,  //rh
      
      MI_Gs_2,    MI_A_2,    MI_As_2,  MI_B_2,  //lh
      KC_TRNS, KC_TRNS, 
      MI_C_3, MI_Cs_3,  MI_D_3, MI_Ds_3, //rh

      MI_C_4,  MI_Cs_4, MI_D_4, MI_Ds_4, //lh
      TO(MIDI), TO(BASE), 
      TO(MIDI), MI_Cs_2, 
      MI_E_4,    MI_F_4,    MI_Fs_4,  MI_G_4  //rh
    )
};

const uint16_t PROGMEM fn_actions[] = {

};
