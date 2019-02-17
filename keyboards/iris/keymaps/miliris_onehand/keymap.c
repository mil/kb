#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define SECOND 1
#define MIDI 2
#define LPSWITCH 3
#define _ _______


const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0,5}, {1,5}, {2,5}, {3,5}, {4,5}, {5,5}},
    {{0,6}, {1,6}, {2,6}, {3,6}, {4,6}, {5,6}},
    {{0,7}, {1,7}, {2,7}, {3,7}, {4,7}, {5,7}},
    {{0,8}, {1,8}, {2,8}, {3,8}, {4,8}, {5,8}},
    {{0,9}, {1,9}, {2,9}, {3,9}, {4,9}, {5,9}},

    /* Right hand, matrix positions */
    // e.g. 6-0/y-p maps directly 1-5/q-t like a bank
    {{0,0}, {5,0}, {4,0}, {3,0}, {2,0}, {1,0}},
    {{0,1}, {5,1}, {4,1}, {3,1}, {2,1}, {1,1}},
    {{0,2}, {5,2}, {4,2}, {3,2}, {2,2}, {1,2}},
    {{0,3}, {5,3}, {4,3}, {3,3}, {2,3}, {1,3}},
    {/*ig*/{5,4}, {4,4}, {3,4}/*ig*/, {3,4}, {4,4}, {5,4}},
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     //KC_GRV, //KC_BSPC,
     // KC_TAB,

  [BASE] = LAYOUT(
     KC_ESC,
     KC_1, KC_2, KC_3, KC_4, KC_5,
     KC_6, KC_7, KC_8, KC_9, KC_0,
     KC_ESC,

     KC_BSPC,
     KC_Q, KC_W, KC_E, KC_R, KC_T,
     KC_Y, KC_U, KC_I, KC_O, KC_P,
     KC_BSPC,

     KC_TAB,
     LT(SECOND, KC_A), LT(SECOND, KC_S), LT(SECOND,KC_D), LT(SECOND, KC_F), LT(SECOND, KC_G),
     LT(SECOND, KC_H), LT(SECOND, KC_J), LT(SECOND,KC_K), LT(SECOND, KC_L), LT(SECOND, KC_SCLN),
     KC_TAB,

     KC_LCTL,
     MT(MOD_LALT, KC_Z), MT(MOD_LALT, KC_X), MT(MOD_LALT, KC_C), MT(MOD_LALT, KC_V), MT(MOD_LCTL, KC_B),
     _, _, 
     MT(MOD_LALT, KC_N), MT(MOD_LALT, KC_M), MT(MOD_LALT, KC_COMM), MT(MOD_LALT, KC_DOT), MT(MOD_LCTL, KC_SLSH),
     KC_LCTL,

     /*KC_LALT*/ 
     KC_ENT,  LSFT_T(KC_SPC), SH_MON, 
     SH_MON,  RSFT_T(KC_SPC), KC_ENT
  ),

  [SECOND] = LAYOUT(
     KC_TILD,
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, 
     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
     KC_BSPC,

     KC_BSLS,  
     KC_QUOT, KC_GRV, KC_SLSH, KC_LBRC, KC_RBRC, 
     KC_QUOT, KC_GRV, KC_SLSH, KC_LBRC, KC_RBRC, 
     KC_BSLS,
     
     KC_EQL,
     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_MINS,
     KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT, KC_MINS,
     KC_EQL,


     KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
     KC_TRNS,
     KC_TRNS, 
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
     KC_TRNS,

     KC_TRNS, KC_TRNS, KC_TRNS, 
     KC_TRNS,  KC_TRNS, KC_TRNS
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

