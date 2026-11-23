/* Not matching yet: BYTES 5/84 (tools/try_func.py func_L01_00626740 --diff) (tools/try_func.py func_L01_00626740 --diff). Not part of the build. */
/* Not matching yet: BYTES 7/84 (tools/try_func.py func_L01_00626740 --diff). Not part of the build. */
extern u8 D_1D24C0[];

s32 func_L01_00626740(s32 arg0, s32 arg1)
{
  u8 *v1;
  s32 a3;
  s32 i;
  v1 = D_1D24C0;
  a3 = 0;
  for (i = 0; i < 0x34; i++)
  {
    a3 = 0x80;
    if ((arg1 != 0) && (arg1 != (*((s32 *) (v1 + 0x1C)))))
    {
      v1 += a3;
      continue;
    }
    if (arg0 == (*((s16 *) (v1 + 0xA))))
    {
      a3 = 1;
      break;
    }
    v1 += a3;
  }

  return a3;
}
