/* Not matching yet: BYTES 68/496. Both 68 (p33) and 85 (p18) need -fno-thread-jumps, which
   has 0 precedent in src/ -- a search artifact. Plain profile: p18 536/496, p33 544/496. */
/* cflags: -ffast-math -fno-thread-jumps */
#include "common.h"
typedef struct { u8 pad0[0x2B0]; u8 f2b0[0x18]; f32 f2c8[4]; f32 f2d8[4]; } State;
extern void func_L00_005E9F38(f32 *a, f32 *b, f32 c, f32 d, f32 e, f32 f);
void func_L01_004EF298(s32 arg0, State *s, s32 idx)
{
  f32 flag;
  f32 a;
  f32 b;
  f32 c;
  f32 f0;
  f32 d;
  f32 *p;
  u8 flagbyte;
  flagbyte = s->f2b0[idx];
  flag = 0.0f;
  if (flagbyte != 0)
  {
    flag = 0.34906584f;
  }
  if ((flagbyte == 0) || (s->f2d8[idx] > 0.0f))
  {
    a = 0.0012411231f;
    b = 0.009928985f;
    c = 0.29786953f;
  }
  else
  {
    a = 0.00019392547f;
    b = 0.000096962736f;
    c = 0.0058177644f;
  }
  d = s->f2d8[idx];
  if ((d > 0.0f) || (s->f2c8[idx] < flag))
  {
    if (s->f2c8[idx] < flag)
    {
      f0 = d + a;
      f0 = (f0 < c) ? (f0) : (c);
    }
    else
    {
      f0 = d - b;
      f0 = (f0 > (-c)) ? (f0) : (-c);
    }
    p = s->f2d8 + idx;
    *p = f0;
    if (s->f2d8[idx] > 0.0f)
    {
      s->f2c8[idx] += s->f2d8[idx];
    }
    else
    {
      func_L00_005E9F38(&s->f2c8[idx], &s->f2d8[idx], flag, a, b, c);
    }
  }
  else
  {
 do { } while (0);
    func_L00_005E9F38(&s->f2c8[idx], &s->f2d8[idx], flag, a, b, c);
  }
  if (s->f2c8[idx] > 0.6981317f)
  {
    s->f2c8[idx] = 0.6981317f;
    if (s->f2d8[idx] > 0.0f)
    {
      s->f2d8[idx] = 0.0f;
    }
  }
  else
    if (s->f2c8[idx] < 0.0f)
  {
    s->f2c8[idx] = 0.0f;
    if (s->f2d8[idx] < 0.0f)
    {
      s->f2d8[idx] = 0.0f;
    }
  }
}
