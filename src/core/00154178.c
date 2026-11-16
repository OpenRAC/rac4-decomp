/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    void *pkt;
    s32 rpc_id;
    s32 sema;
    s32 xC;
    s32 x10;
    s32 buff;
    s32 gp;
    void *end_func;
    void *end_param;
    s32 server;
} Cd_12A538;

extern Cd_12A538 D_1BCC28;
extern void func_0011A518(void *, s32, s32);
extern void func_00129D90(s32);
extern s32 func_0012A538(Cd_12A538 *cd, s32 rno, s32 mode);

s32 func_00154178(void)
{
    s32 i;
    s32 end;

    func_00129D90(0);
    func_0011A518(&D_1BCC28, 0, 0x28);
    for (;;) {
        if (func_0012A538(&D_1BCC28, 0x61766973, 0) < 0) {
            for (;;)
                ;
        }
        if (D_1BCC28.server != 0)
            break;
        end = -1;
        i = 0xFFFF;
        while (i != end)
            i -= 4;
    }
    return 0;
}
