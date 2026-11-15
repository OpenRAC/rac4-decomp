/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* Set the flag when one of the six entries is 2. */
int func_L01_004B5780(u8 *a1)
{
  u8 *base = *(u8 **)(a1 + 172);
  u8 *cursor;
  int value;
  int two = 2;
  int one = 1;
  int count = 5;

  base[1669] = 0;
  cursor = base + 1148;
  do {
    value = *cursor;
    count--;
    if (value) {
      if (value == two)
        base[1669] = one;
    }
    ++cursor;
  } while (count >= 0);
  return value;
}
