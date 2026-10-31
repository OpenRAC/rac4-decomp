/* cflags:  */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int u128 __attribute__((mode(TI)));
extern int func_L01_004970E8(void *);
extern int func_L01_00497058(void *);
extern void func_L01_00496778(void *);
extern void func_L01_00497090(void *);
extern int func_L01_005B2560(void *);
extern void func_00477AD0(void *, int);
extern void func_004E2EF0(int, int, void *);
extern int func_00483D30(void *);
extern void func_00474368(void *, int, int);
extern void func_L00_00621818(void *, int, int);
extern void func_L01_005A5EB0(void *);
extern void func_L00_005F3FC8(void *);
extern void func_00453D20(void *);
void func_L01_00496500(void *arg) {
    u8 *p = (u8 *)arg;
    u8 *q = *(u8 **)(p + 0xac);
    if (func_L01_004970E8(arg)) {
        if (q[0x458] && q[0x45a] && func_L01_00497058(arg)) {
            func_L01_00496778(arg);
            func_L01_00497090(arg);
        }
    } else {
        float f = *(float *)(q + 0x280);
        int v = func_L01_005B2560(arg);
        func_00477AD0(arg, 0);
        if (!v && *(float *)(q + 0x280) < f) func_004E2EF0(20, 0, arg);
        if ((u32)(p[0x69] - 6) >= 2 && func_00483D30(arg)) func_00474368(arg, 19, 6);
        func_L00_00621818(arg, 5, -1);
        func_L01_005A5EB0(arg);
        func_L00_005F3FC8(arg);
        q[0x482] = 0;
        if (!q[0x4d8] && *(int *)(q + 0x140)) {
            *(u128 *)(q + 0x490) = *(u128 *)(p + 0x10);
            q[0x4d8] = 1;
        }
        func_00453D20(q + 0x4d4);
    }
}
