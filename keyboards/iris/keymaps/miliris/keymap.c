#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define SECOND 1
#define MIDI 2
#define LPSWITCH 3
#define _ _______


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
     KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,
     KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,

     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,

     KC_ESC, KC_A, KC_S, LT(SECOND,KC_D), KC_F, KC_G,
     KC_H, KC_J, LT(SECOND,KC_K), KC_L, KC_SCLN, KC_QUOT,

     KC_LSFT, MT(MOD_LCTL,KC_Z), MT(MOD_LCTL,KC_X), KC_C, KC_V, KC_B, 
     _______, _______,
     KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

     KC_LALT, KC_ENT, KC_LCTL, 
     KC_SPC,  KC_ENT, KC_LALT
  ),

  [SECOND] = LAYOUT(
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, 
     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,

     _,   _,    _,    _,    _,    _,
     _,    _,    _,   KC_MINS, KC_PLUS, _,
     

     _,  _, _, _, _,   _,                           
     _, _,   _,   KC_LBRC, KC_RBRC, KC_PIPE,


     BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
  ),

  [MIDI] = LAYOUT( 
      // row 1
      KC_TRNS, MI_C, MI_Cs,  MI_D, MI_Ds, //lh
      MI_Gs_4,    MI_A_4, // midkeys
      MI_E,    MI_F,    MI_Fs,  MI_G,  //rh
      KC_TRNS,

      // row 2
      MO(LPSWITCH), 
      MI_E_1,    MI_F_1,    MI_Fs_1,  MI_G_1,  //lh
      MI_As_4,    MI_B_4, //midkeys
      MI_Gs_1,    MI_A_1,    MI_As_1,  MI_B_1,  //rh
      KC_TRNS,
      
      // row 3
      TO(BASE), 
      MI_Gs_2,    MI_A_2,    MI_As_2,  MI_B_2,  //lh
      MI_C_5,    MI_Cs_5, //midkeys
      MI_C_3, MI_Cs_3,  MI_D_3, MI_Ds_3, //rh
      KC_TRNS,

      // row 4
      MO(LPSWITCH), 
      MI_C_4,  MI_Cs_4, MI_D_4, MI_Ds_4, //lh
      MI_D_5, MI_Ds_5, //midkeys
      MI_E_4,    MI_F_4,    MI_Fs_4,  MI_G_4,  //rh
      KC_TRNS,

      KC_TRNS,
      KC_TRNS,

      // row 5
      KC_TRNS, MI_Cs_2,  KC_TRNS, MI_Cs_2, KC_TRNS, KC_TRNS
  )
};


const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

