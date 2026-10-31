/* cflags: -O2 -G8 */
extern int func_L01_004E6A70(void *);
extern int func_L01_004E6AD8(void *);
extern void func_L00_00621818(void *, int, int);
extern int func_L01_004E6E08(void *);
extern void func_00474368(void *, int, int);
extern void func_004E2EF0(int, int, void *);
extern void func_004778A8(void *, int, int, int);
extern void func_L01_004E6BF0(void *);

/* Update the object according to its current state. */
void func_L01_004E6990(unsigned char *p)
{
    int changed;
    if (func_L01_004E6A70(p)) return;
    if (func_L01_004E6AD8(p)) return;
    switch (p[0x20]) {
    case 2: {
        func_L00_00621818(p, 17, -1);
        if (func_L01_004E6E08(p)) func_00474368(p, 3, -1);
    break; }
    case 3: {
        if ((p[0xbe] ^ 1) & 1) {
            p[0xbe] |= 1;
            changed = 1;
        } else changed = 0;
        if (changed) {
            func_004E2EF0(0, 0, p);
            func_004778A8(p, 4, 0, 0);
        }
    }
    }
    func_L01_004E6BF0(p);
}
