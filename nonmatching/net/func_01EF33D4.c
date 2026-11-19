/* Not matching yet: BYTES 5/156 (tools/try_func.py func_01EF33D4 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
extern s32 func_00121FA0(s8 *arg0, s8 *arg1);

void *func_01EF33D4(s32 arg0, void *arg1)
{
  s32 n = 0;
  void *list;
  void **p;
  void **slot;
  void *e;
  void *obj;
  s8 *(*fp)(void *);
  s8 *r;
  list = (obj = *((void **) (((u8 *) arg1) + 0x6358)));
  p = (void **) (((u8 *) list) + 8);
  e = *p;
  if (e != 0)
  {
    slot = p;
    do
    {
      e = *slot;
      slot++;
      obj = *((void **) (((u8 *) e) + 0xB0));
      fp = *((s8 *(**)(void *)) (((u8 *) obj) + 0x3C));
      r = fp(e);
      if (func_00121FA0(r, (s8 *) arg0) == 0)
      {
        return e;
      }
      n++;
    }
    while (((*slot) != 0) && (n < 0x100));
  }
  return 0;
}
