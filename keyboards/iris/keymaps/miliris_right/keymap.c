#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define SECOND 1
#define MIDI 2
#define LPSWITCH 3
#define _ _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     //KC_GRV, //KC_BSPC,
     // KC_TAB,

  [BASE] = LAYOUT(
     _, _, _, _, _, _,
     KC_Q, KC_W, KC_E, KC_R, KC_T, KC_D,

     _, _, _, _, _, _,
     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_S,

     _, _, _, _, _, _,
     KC_H, KC_J, LT(SECOND, KC_K), KC_L, KC_A, KC_F,

     _, _, _, _, _, _,
     _, _, 
     MT(MOD_LCTL, KC_N), MT(MOD_LCTL, KC_M), KC_G, KC_C, KC_V, KC_B,

     /*KC_LALT*/ 
     _,  _, _, 
     RSFT_T(KC_SPC), LT(SECOND, KC_X),   MT(MOD_LALT, KC_Z)
  ),

  [SECOND] = LAYOUT(
     _, _, _, _, _, _,
     KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC,

     _, _, _, _, _, _,
     KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,


     _, _, _, _, _, _,
     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_BSLS, KC_TAB,
     _, _, 

     _, _, _, _, _, _,
     KC_GRV, KC_QUOT, KC_SCLN, KC_COMM, KC_DOT, KC_SLSH,

     _, _, _,
     KC_ENT, KC_MINS, KC_EQL
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

