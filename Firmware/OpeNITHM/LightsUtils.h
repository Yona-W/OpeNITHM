#ifndef __HELPERCLASS_h
#define __HELPERCLASS_h

#include "Config.h"

/**
 * Simple helper class to make it easier to deal with the slider RGB strip,
 * since we support both lighted and non-lighted separators (aka 16 vs 31 LEDs)
 */
class LightsUtils
{
  public:

    // Zero index, range 0 to 15
    static int getLedIndex(int i) {
      if (i < 0)
        i = 0;
      else if (i > 15)
        i = 15;
#ifndef LED_REVERSE
#ifndef KEY_DIVIDERS
      return i;
#else
      return i * 2;
#endif
#else
#ifndef KEY_DIVIDERS
      return 15 - i;
#else
      return 30 - (i * 2);
#endif
#endif
    };

#ifdef KEY_DIVIDERS
    // Zero index, range 0 to 14
    static int getDividerIndex(int i) {
      if (i < 0)
        i = 0;
      else if (i > 14)
        i = 14;
#ifndef LED_REVERSE
      return 1 + i * 2;
#else
      return 29 - (i * 2);
#endif
    };
    #endif
};

#endif
