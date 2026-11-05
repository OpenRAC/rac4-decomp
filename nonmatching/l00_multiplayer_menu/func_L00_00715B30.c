/* Not matching yet: BYTES 15/1160 (tools/try_func.py func_L00_00715B30 --diff). Not part of the build. */
typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
    char _p8[0xC];
    s32 f14;
    char _p18[0x50];
    s32 f68;
    s32 f6C[0x40];
    char f16C[0x20][0x50];
    s32 fB6C;
    s32 fB70;
    s32 fB74;
    char *fB78;
    char fB7C[0x400];
    s32 fF7C;
};

extern void func_0011A9EC(void *, void *);
extern u32 func_0011AB04(void *);
extern void func_0011AFC8(void *, void *, s32);
extern s32 func_0069CC48(s32, s32, s32);
extern void func_0069D318(s32, void *);
extern void func_0069D408(s32, s32);
extern s32 func_0069D6C0(s32, s32);
extern s32 func_L00_005BD768(void *, u32, s32 *);
extern s32 func_L00_005E6358(s32, s32, s32, s32, s32, s32);

/* Lays out the visible lines of a text box into its line widgets. */
void func_L00_00715B30(Type1 *arg0) {
    char buf[0x50];
    s32 c;
    s32 color;
    s32 i;
    s32 j;
    s32 m;
    u32 k;
    u32 len2;
    u32 len;
    char *base;
    char *p;

    c = 0;
    if (arg0->f4 != 0) {
        if (arg0->fB6C - arg0->f68 < arg0->fB70) {
            arg0->fB70 = arg0->fB6C - arg0->f68;
        }
        if (arg0->fB70 < 0) {
            arg0->fB70 = 0;
        }
        color = 0x80D6CBBE;
        if (arg0->f4 == 3) {
            color = 0x80808080;
        } else if (arg0->f4 == 5) {
            color = func_L00_005E6358(0x80D6CBBE, 0x66A6BEFA, 0x2D, 1, 0, 1);
        } else if (arg0->f4 == 6) {
            color = 0x66A6BEFA;
        }
        if (arg0->f14 != 0) {
            func_0069CC48(arg0->f14, 1, 0);
        }
        for (j = 0; j < arg0->f68; j++) {
            func_0069D6C0(arg0->f6C[j], 2);
        }
        if (arg0->fB6C == 0) {
            for (m = 0; m < arg0->f68; m++) {
                func_0069CC48(arg0->f6C[m], 1, 0);
            }
            return;
        }
        base = arg0->fB78;
        if (base == 0) {
            base = arg0->fB7C;
        }
        p = base;
        for (i = 0; i < arg0->fB70; i++) {
            func_0011AFC8(buf, p, 0x4F);
            buf[0x4F] = 0;
            len = func_0011AB04(buf);
            for (k = 0; k < len; k++) {
                s32 n = func_L00_005BD768(buf, k, &c);
                if (c == 1 || c == 10 || c == 13) {
                    buf[k] = 0;
                    len = k;
                    break;
                }
                k += n;
            }
            p += len;
            if ((u32)p < (u32)(base + arg0->fF7C - 1)) {
                s32 c1 = 0;
                s32 c2 = 0;
                s32 w;
                w = func_L00_005BD768(p, 0, &c1) + 1;
                if ((u32)(p + w) < (u32)(base + arg0->fF7C - 1)) {
                    func_L00_005BD768(p, w, &c2);
                    if ((c1 == 10 && c2 == 13) || (c1 == 13 && c2 == 10)) {
                        p++;
                    }
                }
            }
            p++;
        }
        for (i = 0; i < arg0->f68; i++) {
            func_0069D408(arg0->f6C[i], color);
            if (arg0->fB70 + i < arg0->fB6C) {
                func_0011AFC8(buf, p, 0x4F);
                buf[0x4F] = 0;
                len2 = func_0011AB04(buf);
                for (k = 0; k < len2; k++) {
                    s32 n = func_L00_005BD768(buf, k, &c);
                    if (c == 1 || c == 10 || c == 13) {
                        buf[k] = 0;
                        len2 = k;
                        break;
                    }
                    k += n;
                }
                p += len2;
                func_0011A9EC(arg0->f16C[i], buf);
                func_0069D318(arg0->f6C[i], arg0->f16C[i]);
                func_0069CC48(arg0->f6C[i], 1, 1);
                if ((u32)p < (u32)(base + arg0->fF7C - 1)) {
                    s32 c3 = 0;
                    s32 c4 = 0;
                    s32 w;
                    w = func_L00_005BD768(p, 0, &c3) + 1;
                    if ((u32)(p + w) < (u32)(base + arg0->fF7C - 1)) {
                        func_L00_005BD768(p, w, &c4);
                        if ((c3 == 10 && c4 == 13) || (c3 == 13 && c4 == 10)) {
                            p++;
                        }
                    }
                }
                p++;
            } else {
                func_0069CC48(arg0->f6C[i], 1, 0);
            }
        }
    }
}
