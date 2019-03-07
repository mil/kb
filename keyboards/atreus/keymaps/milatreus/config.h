#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"
#define MIDI_ENABLE_STRICT 1
#define MIDI_BASIC
#define MIDI_ADVANCED
#define MIDI_TONE_KEYCODE_OCTAVES 6


#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION
#define MANUFACTURER    mil
#define PRODUCT         milatreus
#define DESCRIPTION     mils atreus.. if found: miles@userbound.com

#define RETRO_TAPPING
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200 
#define DEBOUNCE_DELAY 10



#endif
