#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;


/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include "hhkb.h"

#define BASE 0
#define SECOND 1
#define MIDI 2
#define LPSWITCH 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(  
      // Row 1
      KC_GRV,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,
      KC_0,     KC_MINS,  KC_EQL,    KC_BSLS,  KC_GRV,

      // Row 2
      KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  
      KC_I,    KC_O, KC_P,     KC_LBRC,  KC_RBRC,   KC_BSPC, 

      // Row 3
      MT(MOD_LCTL, KC_ESC),  LT(SECOND,KC_A),  KC_S,  LT(SECOND,KC_D),  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,
      KC_SCLN,  KC_QUOT,  KC_ENT, 

      // Row 4
      KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  LT(SECOND, KC_N),  
      KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  MO(SECOND),

      // Row 5
      KC_LCTL,  KC_LALT,  LT(/*SECOND*/MIDI, KC_SPC),      /*MO(SECOND)*/ KC_LALT,  /*KC_RCTL*/ TO(MIDI)
  ),

  [SECOND] = LAYOUT(
      KC_TRNS, KC_F1,   KC_F2,   KC_F3,         KC_F4,       KC_F5,   KC_F6,    KC_F7,    KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_D, KC_WH_U, KC_TRNS, KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(LCTL(KC_DEL)),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,     KC_TRNS, KC_LEFT,  KC_DOWN,  KC_UP,KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_INS,  KC_PGDN, KC_PGUP,       KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS
  ),

  [MIDI] = LAYOUT( 
      // row 1
      KC_TRNS, 
      MI_C, MI_Cs,  MI_D, MI_Ds, //lh
      MI_Gs_4,    MI_A_4, // midkeys
      MI_E,    MI_F,    MI_Fs,  MI_G,  //rh
      MI_E_5, MI_F_5, MI_Fs_5, MI_G_5, //ctrl

      // row 2
      MO(LPSWITCH), 
      MI_E_1,    MI_F_1,    MI_Fs_1,  MI_G_1,  //lh
      MI_As_4,    MI_B_4, //midkeys
      MI_Gs_1,    MI_A_1,    MI_As_1,  MI_B_1,  //rh
      MI_Gs_5, MI_A_5, MI_As_5, //ctrl
      
      // row 3
      TO(BASE), 
      MI_Gs_2,    MI_A_2,    MI_As_2,  MI_B_2,  //lh
      MI_C_5,    MI_Cs_5, //midkeys
      MI_C_3, MI_Cs_3,  MI_D_3, MI_Ds_3, //rh
      MI_B_5,   KC_PENT, //ctrl

      // row 4
      MO(LPSWITCH), 
      MI_C_4,  MI_Cs_4, MI_D_4, MI_Ds_4, //lh
      MI_D_5, MI_Ds_5, //midkeys
      MI_E_4,    MI_F_4,    MI_Fs_4,  MI_G_4,  //rh
      KC_DOWN,  KC_TRNS,  

      // row 5
      KC_TRNS, MI_Cs_2,  KC_TRNS, MI_Cs_2, KC_TRNS
  ),

  [LPSWITCH] = LAYOUT( 
      KC_TRNS, 
      MI_Gs, MI_A, MI_As, MI_B, MI_C_1, MI_Cs_1, MI_D_1, MI_Ds_1,
      MI_VEL_1, MI_VEL_2,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS
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
