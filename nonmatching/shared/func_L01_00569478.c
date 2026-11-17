/* Not matching yet: BYTES 191/1128 (retail's size, 191 differing bytes; permuter output-256-2, re-checked with tools/try_func.py). Not part of the build. */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 func_L00_00500CE0(s32);
extern s32 func_L00_005E6560();
extern s32 func_L00_005F1208(u128, s32);
extern s32 func_L01_0056D850(s32);
extern s32 func_L01_0056D9B0(s32);
extern f32 func_L01_0056DF50(s32);
extern void func_L01_0056DFC0(s32, s32 *, s32 *, s32 *, f32);
extern f32 func_L01_005A5928(s32);

extern u8 *D_222D14;
extern u8 *D_222BF4;
extern s32 D_222D60;
extern u8 *D_28BFE0[];
extern u8 *D_3660F8[];

s32 func_L01_00569478(u8 *object, s32 arg1)
{
  s32 above;
  s32 below;
  s32 total;
  s32 r;
  s32 flag;
  s32 found;
  s32 n;
  s32 unk38;
  s32 i;
  s32 id;
  s32 key;
  u8 **slot;
  u8 *cur;
  u8 *p;
  int new_var;
  u8 *q;
  u8 *base;
  f32 f0;
  f32 f1;
  if (object == 0)
  {
    return 0;
  }
  if ((*((s32 *) (object + 0x00))) != (-1))
  {
    if ((*((s32 *) (object + 0x04))) != (-1))
    {
      if (func_L00_005F1208(*((u128 *) ((D_222D14 + ((*((s32 *) (object + 0x04))) << 8)) + 0x10)), *((s32 *) (object + 0x00))) != ((*((u8 *) (object + 0x40))) & 1))
      {
        return 0;
      }
    }
    else
    {
      if ((*((u8 *) (object + 0x40))) == 0)
      {
        if (func_L01_0056D850(*((s32 *) (object + 0x00))) != 0)
        {
          return 0;
        }
      }
      if ((*((u8 *) (object + 0x40))) == 1)
      {
        if (func_L01_0056D9B0(*((s32 *) (object + 0x00))) == 0)
        {
          return 0;
        }
      }
      if ((*((u8 *) (object + 0x40))) == 2)
      {
        if (func_L01_0056D9B0(*((s32 *) (object + 0x00))) != 0)
        {
          return 0;
        }
      }
      if ((*((u8 *) (object + 0x40))) == 3)
      {
        if (func_L01_0056D850(*((s32 *) (object + 0x00))) != 0)
        {
          return 0;
        }
      }
    }
  }
  unk38 = *((s32 *) (object + 0x38));
  if (unk38 != (-1))
  {
    key = *((s32 *) ((D_222BF4 + (unk38 << 5)) + 0x10));
    found = 0;
    slot = D_3660F8;
    p = D_3660F8[0];
    n = 9;
    do
    {
      slot++;
      if ((p != 0) && ((*((s32 *) (p + 0x4A0))) == key))
      {
        found = 1;
      }
      n--;
      p = *slot;
    }
    while (n >= 0);
    if (found == 0)
    {
      return 0;
    }
  }
  if ((*((s32 *) (object + 0x08))) != (-1))
  {
    if ((*((s16 *) (object + 0x36))) == (-2))
    {
      func_L01_0056DFC0(*((s32 *) (object + 0x08)), &above, &below, &total, 1.0f);
      r = below != 0;
      if ((*((u8 *) (object + 0x44))) == 0)
      {
        r = below == 0;
      }
      if (r != 0)
      {
        return 0;
      }
    }
    if ((*((s16 *) (object + 0x36))) == (-1))
    {
      func_L01_0056DFC0(*((s32 *) (object + 0x08)), &above, &below, &total, 0.02f);
      r = above == 0;
      if ((*((u8 *) (object + 0x44))) == 0)
      {
        r = above != 0;
      }
      if (r != 0)
      {
        return 0;
      }
    }
    if ((*((s16 *) (object + 0x36))) >= 0)
    {
      func_L01_0056DFC0(*((s32 *) (object + 0x08)), &above, &below, &total, 1.0f);
      r = above < (*((s16 *) (object + 0x36)));
      if ((*((u8 *) (object + 0x44))) == 0)
      {
        new_var = above >= (*((s16 *) (object + 0x36)));
        r = new_var;
      }
      if (r != 0)
      {
        return 0;
      }
    }
  }
  id = *((s32 *) (object + 0x0C));
  if (id != (-1))
  {
    if (func_L00_005E6560(D_222D14 + (id << 8)) != (*((u8 *) (object + 0x41))))
    {
      return 0;
    }
  }
  id = *((s32 *) (object + 0x48));
  if (id >= 0)
  {
    f1 = func_L01_005A5928(D_222D14 + (id << 8));
    f0 = *((f32 *) (object + 0x4C));
    if (f1 < f0)
    {
      return 0;
    }
    if (f1 >= 1.0f)
    {
      *((s32 *) (object + 0x48)) = -2;
    }
  }
  if ((*((s32 *) (object + 0x10))) != (-1))
  {
    p = D_28BFE0[*((s32 *) (object + 0x10))];
    flag = 0;
    for (;;)
    {
      if (((*((s32 *) (object + 0x10))) & 0xFF) == 0xFF)
      {
        break;
      }
      if (D_222D60 < (*((s32 *) (object + 0x10))))
      {
        break;
      }
      if (p == 0)
      {
        break;
      }
      if (((*((s16 *) (p - 2))) < 0) && (p != D_28BFE0[*((s32 *) (object + 0x10))]))
      {
        break;
      }
      base = D_222D14 + (((*((u16 *) p)) & 0x7FFF) << 8);
      if (base == 0)
      {
        break;
      }
      if (func_L00_005E6560(base) == 0)
      {
        flag = 1;
        break;
      }
      p += 2;
    }

    if ((*((u8 *) (object + 0x42))) == flag)
    {
      return 0;
    }
  }
  p = object + 0x24;
  cur = object + 0x14;
  q = object + 0x3C;
  for (i = 0; i < 4; i++)
  {
    id = *((s32 *) cur);
    if (id != (-1))
    {
      f1 = func_L01_0056DF50(D_222D14 + (id << 8));
      if (q[i] != 0)
      {
        if (f1 < (*((f32 *) p)))
        {
          return 0;
        }
      }
      else
        if ((*((f32 *) p)) <= f1)
      {
        return 0;
      }
    }
    p += 4;
    cur += 4;
  }

  id = *((s16 *) (object + 0x34));
  if (id == 0xFF)
  {
    return 1;
  }
  if (arg1 == 0)
  {
    return 1;
  }
  if ((*((u8 *) (object + 0x43))) == 0)
  {
    r = func_L00_00500CE0(arg1);
    if ((i = *((s16 *) (object + 0x34))) < r)
    {
      return 0;
    }
    if ((*((u8 *) (object + 0x43))) == 0)
    {
      return 1;
    }
  }
  r = func_L00_00500CE0(arg1);
  if (i < r)
  {
    return 1;
  }
  return 0;
}
