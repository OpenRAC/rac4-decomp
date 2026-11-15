/* Not matching yet: 16/18 (88.89%) relocation-masked positional words; 72/72 candidate/target bytes. Global store addressing differs; forwarded callback interface remains uncertain. Reproduce: python tools/check_func.py --version pal func_L01_005883D8 nonmatching/pal/l01_dreadzone_station/func_L01_005883D8.c --diff. Not part of the build. */
/* cflags: -O2 -G0 -Wuninitialized */
#include "common.h"
extern s32 D_0021EC58;
extern s32 func_L01_00588328(void);
extern void func_L00_005D1D58(s32, s32);
extern void func_L01_006589D8(s32, s32);
s32 func_L01_005883D8(s32 arg0) {
    u8 *p;
    D_0021EC58 = arg0;
    p = (u8 *)func_L01_00588328();
    func_L00_005D1D58(p[0x18], 0);
    func_L01_006589D8(*(s32 *)p, 0);
    return 1;
}
