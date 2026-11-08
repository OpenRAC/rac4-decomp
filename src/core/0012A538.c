/* cflags: @ee29 -O2 -G0 */
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
typedef struct {
    u8 pad[0x14];
    void *paddr;
    s32 rpc_id;
    void *client;
    s32 rno;
} Pkt_12A538;
typedef struct {
    s32 attr;
    s32 option;
    s32 init_count;
    s32 max_count;
    s32 numWaitThreads;
    void *name;
} Sema_12A538;
extern u8 D_001A7AC0[];
extern char D_00192FF8[];
extern Pkt_12A538 *func_00129F58(void *);
extern s32 func_00126BA0(Sema_12A538 *);
extern s32 func_00126BB0(s32);
extern void func_00126BE0(s32);
extern s32 func_00129B18(s32, s32, s32, s32, s32, s32);
extern void func_0012A000(Pkt_12A538 *);

/* from rac3-decomp's func_00122630 */
s32 func_0012A538(Cd_12A538 *cd, s32 rno, s32 mode) {
    Pkt_12A538 *pkt;
    Sema_12A538 sp;
    cd->x10 = 0;
    cd->server = 0;
    pkt = func_00129F58(D_001A7AC0);
    if (pkt == 0) {
        return -1;
    }
    cd->pkt = pkt;
    cd->rpc_id = pkt->rpc_id;
    pkt->rno = rno;
    pkt->paddr = pkt;
    pkt->client = cd;
    if (!(mode & 1)) {
        sp.option = 1;
        sp.name = D_00192FF8;
        sp.init_count = 0;
        cd->sema = func_00126BA0(&sp);
        if (cd->sema < 0) {
            func_0012A000(pkt);
            return -3;
        }
        if (func_00129B18(0x80000009, (s32)pkt, 0x40, 0, 0, 0) == 0) {
            func_0012A000(pkt);
            func_00126BB0(cd->sema);
            return -2;
        }
        func_00126BE0(cd->sema);
        func_00126BB0(cd->sema);
        return 0;
    }
    cd->sema = -1;
    if (func_00129B18(0x80000009, (s32)pkt, 0x40, 0, 0, 0) == 0) {
        func_0012A000(pkt);
        return -2;
    }
    return 0;
}
