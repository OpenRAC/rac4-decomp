/* Not matching yet: BYTES 4/84 (permuter --legal 900 s; best body). Not part of the build. */
extern s32 func_L00_006FF400(u8 *o, s32 i);

s32 func_L00_006CB920(u8 *player)
{
  s32 flag;
  s32 result;
  result = 0;
  if (func_L00_006FF400(*((s32 *) (player + 0x26E4)), player[0x2F10]) != 0)
  {
    flag = (*((s32 *) (player + 0x25D4))) != 0x14;
    result = (unsigned short) flag;
  }
  return result;
}
