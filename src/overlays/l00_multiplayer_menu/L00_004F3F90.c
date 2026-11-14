/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_L00_004F4008(void);
extern void func_L00_004F4830(void);
extern void func_L00_004F4E78(void);
extern void func_L00_004F50B8(void);
extern void func_L00_004F5150(void);
extern void func_L00_004F51F8(void);
extern void func_L00_004F5370(void);
extern void func_L00_004F54D0(void);
extern void func_L00_004F5A78(void);

/* fills a table of callbacks */
s32 func_L00_004F3F90(void **arg0) {
    arg0[0] = func_L00_004F4008;
    arg0[1] = func_L00_004F4830;
    arg0[2] = func_L00_004F4E78;
    arg0[3] = func_L00_004F50B8;
    arg0[4] = func_L00_004F5150;
    arg0[5] = func_L00_004F51F8;
    arg0[6] = func_L00_004F5370;
    arg0[7] = func_L00_004F54D0;
    arg0[8] = func_L00_004F5A78;
    return 0;
}
