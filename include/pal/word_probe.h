#ifndef PAL_WORD_PROBE_H
#define PAL_WORD_PROBE_H

#include "common.h"

/* The first eight bytes are opaque. Slots contain interleaved 32-bit
 * key/value words. Zero ends the search; marker-valued slots are skipped. */
static inline s32 pal_word_probe(void *table,s32 key,s32 marker_address) {
  s32 position;
  s32 count;
  s32 value;
  u8 *keys;
  u8 *values;
  s32 offset;
  s32 sentinel;
  values = ((u8 *) table) + 12;
  keys = ((u8 *) table) + 8;
  count = 0;
  sentinel = (s32) (marker_address);
  position = key & 7;
  do
  {
    offset = (position & 7) * 8;
    value = *((s32 *) (values + offset));
    if (value == 0)
    {
      return 0;
    }
    if (((*((s32 *) (keys + offset))) == key) && (value != sentinel))
    {
      return value;
    }
    count += 1;
    position += 1299827;
  }
  while (count < 8);
  return 0;
}
#endif
