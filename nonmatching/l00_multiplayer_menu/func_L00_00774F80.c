/* Not matching yet: BYTES 8/140 (tools/try_func.py func_L00_00774F80 --diff). Not part of the build. */
extern void func_0011A9EC(void *, void *);
extern s32 func_0011AB04(u8 *);

s32 func_L00_00774F80(u8 *arg0)
{
  u8 *base = arg0;
  unsigned short new_var;
  u8 *p = arg0 + 4;
  s32 i = 0;
  s32 off = 4;
  do
  {
    void *a1 = ((new_var = i) > 4) ? (arg0 + off) : (0);
    if (a1 != p)
    {
      func_0011A9EC(p, a1);
    }
    i++;
    off += 0x18;
    p += func_0011AB04(p) + 1;
  }
  while (i < 5);
  return p - base;
}
