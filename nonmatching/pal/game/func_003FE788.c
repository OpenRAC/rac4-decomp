/* Not matched: PAL SCES_532.85.
 * SIZE ours 64 / disc 68 at main and level_00; no relocations.
 * A typed pointer-entry loop removes the old duplicate failure epilogue.
 * The native unreachable NOP at +0x2C is absent; later branch distances
 * and instruction positions consequently differ. No native bytes are trimmed.
 * Raw positional comparison: 45/68 bytes equal, not correctness confidence.
 * Pointer keys/output, zero-count guard and hit-only output store are retained.
 * Original complete types and runtime bounds are not asserted.
 * Reproduce: python3 tools/check_func.py --version pal func_003FE788 nonmatching/pal/game/func_003FE788.c --diff
 */
#include "common.h"

s32 func_003FE788(void *input, void **out, void *key)
{
  u32 count;
  u32 index;
  void **cursor;

  count = *(u32 *)((u8 *)input + 0xC);
  index = 0;
  if (count != 0)
  {
    cursor = *(void ***)((u8 *)input + 0x10);
    do
    {
      index += 1;
      if (cursor[0] == key)
      {
        *out = cursor[1];
        return 0;
      }
      cursor += 2;
    }
    while (index < count);
  }
  return 0x217;
}
