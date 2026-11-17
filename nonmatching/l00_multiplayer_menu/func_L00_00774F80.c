/* Not matching yet: BYTES 8/140 (default profile -- which is what every neighbour of this
   function in L00 uses). A -Os body reproduces retail's instruction stream exactly at
   16/140 (only $s1/$s2 transposed) but -Os is a search artifact with no neighbour behind it;
   it is kept at build/try/func_L00_00774F80/os16_body.c. Not part of the build. */
extern s32 func_0011AB04(u8 *);

s32 func_L00_00774F80(u8 *arg0)
{
  u8 *base = arg0;
  u8 *p = arg0 + 4;
  s32 i = 0;
  s32 off = 4;
  do
  {
    void *a1 = ((i - 1) >= 4) ? (arg0 + off) : (0);
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
