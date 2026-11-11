/* cflags: -O2 -G8 */
extern int func_L01_004E4AB8(void *);
extern int func_L01_004E4B20(void *);
extern void func_005A85F8(void *, int, int);
extern int func_L01_004E4E50(void *);
extern void func_00473A88(void *, int, int);
extern void func_004E1F90(int, int, void *);
extern void func_00476F88(void *, int, int, int);
extern void func_L01_004E4C38(void *);

void func_L01_004E49D8(unsigned char *p)
{
    int changed;
    if (func_L01_004E4AB8(p)) return;
    if (func_L01_004E4B20(p)) return;
    switch (p[0x20]) {
    case 2: {
        func_005A85F8(p, 17, -1);
        if (func_L01_004E4E50(p)) func_00473A88(p, 3, -1);
    break; }
    case 3: {
        if ((p[0xbe] ^ 1) & 1) {
            p[0xbe] |= 1;
            changed = 1;
        } else changed = 0;
        if (changed) {
            func_004E1F90(0, 0, p);
            func_00476F88(p, 4, 0, 0);
        }
    }
    }
    func_L01_004E4C38(p);
}
