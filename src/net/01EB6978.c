/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *f[35]; } T1;
extern void *D_00167F3C[];
extern T1 D_1B6770[];
extern void func_01EB6B80(void);
extern void func_01EB6F70(void);
extern void func_01EB70F0(void);
extern void func_01EB7160(void);
extern void func_01EB7220(void);
extern void func_01EB7288(void);
extern void func_01EB72B0(void);
extern void func_01EB72D8(void);
extern void func_01EB7300(void);
extern void func_01EB7560(void);
extern void func_01EB7770(void);
extern void func_01EB7798(void);
extern void func_01EB7868(void);
extern void func_01EB7B68(void);
extern void func_01EB7DB8(void);
extern void func_01EB7ED0(void);
extern void func_01EB7EE0(void);
extern void func_01EB7F88(void);
extern void func_01EB81C0(void);
extern void func_01EB83D8(void);
extern void func_01EB8488(void);
extern void func_01EB84B8(void);
extern void func_01EB84E0(void);
extern void func_01EB84F8(void);
extern void func_01EB8608(void);
extern void func_01EB87A0(void);
extern void func_01EB8908(void);
extern void func_01EB89E0(void);
extern void func_01EB8B08(void);
extern void func_01EB8B60(void);
extern void func_01EB8BE0(void);
extern void func_01EBC458(void);
extern void func_01EBC550(void);
extern void func_01EBC970(void);
extern void func_01EBCE60(void);

// Fills the handler table at D_1B6770, then publishes the table through D_00167F3C.
void func_01EB6978(void)
{
    void **g = D_00167F3C;
    T1 *t = D_1B6770;
    t->f[0] = (void *)func_01EB6B80;
    t->f[1] = (void *)func_01EB6F70;
    t->f[2] = (void *)func_01EB70F0;
    t->f[3] = (void *)func_01EB7160;
    t->f[4] = (void *)func_01EB7220;
    t->f[5] = (void *)func_01EB7288;
    t->f[6] = (void *)func_01EB72B0;
    t->f[7] = (void *)func_01EB72D8;
    t->f[8] = (void *)func_01EB7300;
    t->f[9] = (void *)func_01EB7560;
    t->f[10] = (void *)func_01EB7770;
    t->f[11] = (void *)func_01EB7798;
    t->f[12] = (void *)func_01EB7868;
    t->f[13] = (void *)func_01EB7B68;
    t->f[14] = (void *)func_01EB7DB8;
    t->f[15] = (void *)func_01EB7ED0;
    t->f[16] = (void *)func_01EB7EE0;
    t->f[17] = (void *)func_01EB7F88;
    t->f[18] = (void *)func_01EB81C0;
    t->f[19] = (void *)func_01EB83D8;
    t->f[20] = (void *)func_01EB8488;
    t->f[21] = (void *)func_01EB84B8;
    t->f[22] = (void *)func_01EB84E0;
    t->f[23] = (void *)func_01EB84F8;
    t->f[24] = (void *)func_01EB8608;
    t->f[25] = (void *)func_01EB87A0;
    t->f[26] = (void *)func_01EB8908;
    t->f[27] = (void *)func_01EB89E0;
    t->f[29] = (void *)func_01EB8B60;
    t->f[28] = (void *)func_01EB8B08;
    t->f[30] = (void *)func_01EB8BE0;
    t->f[31] = (void *)func_01EBC458;
    t->f[32] = (void *)func_01EBC550;
    t->f[33] = (void *)func_01EBC970;
    t->f[34] = (void *)func_01EBCE60;
    g[0] = (void *)t;
}
