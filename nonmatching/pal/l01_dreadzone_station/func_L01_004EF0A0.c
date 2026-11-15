/* Not matching yet: 10/13 (76.92%) relocation-masked positional words; 52/52 candidate/target bytes. Fallback instruction scheduling differs; field types are hypotheses. Reproduce: python tools/check_func.py --version pal func_L01_004EF0A0 nonmatching/pal/l01_dreadzone_station/func_L01_004EF0A0.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#define FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
f32 func_L01_004EF0A0(void *arg0) {
 void *p = FIELD(FIELD(arg0, void *, 0xac), void *, 0x2f4);
 f32 v = 0.5f; if (p) return FIELD(p, f32, 0x18) - FIELD(FIELD(p, void *, 0xac), f32, 0x18); return FIELD(arg0, f32, 0x18) - v;
}
