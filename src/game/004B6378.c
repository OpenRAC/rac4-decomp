#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 (*f8)(s32);
} Type3;

extern s32 func_0045E038(s32);
extern Type3 *func_0046D428(s32 arg0, s32 arg1, s32 arg2);
extern void func_004A01F0(s32 arg0, s32 arg1);
extern void func_004B5DF8(s32 arg0);
extern void func_004B5E18(s32 arg0, s32 arg1, void *arg2, s32 arg3);
extern void func_004B5E70(s32 arg0, void *arg1, s32 arg2);

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad8[0x1F0];
} Type1;

extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern Type1 D_003098F0[];
extern char func_004B6BA0[];
extern char func_004B6FD0[];
extern char func_004B7028[];
extern char func_004B7080[];
extern char func_004B70D8[];
extern char func_004B7130[];
extern char func_004B71D0[];

void func_004B6378(s32 arg0) {
    Type3 *obj;

    func_004A01F0(arg0, D_003098F0[arg0].f4);
    func_004B5DF8(arg0);
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        s32 flag = 0;
        s32 text;
        void *cb;
        s32 flag2;
        s32 text2;
        void *cb2;

        obj = func_0046D428(0x2120, 0, 0xC);
        text = func_0045E038(0x30F9);
        cb = func_004B6FD0;
        if (obj == NULL || obj->f8 == NULL || obj->f8(0) == 0) {
            flag = 1;
        }
        func_004B5E18(arg0, text, cb, flag);
        flag2 = 0;
        text2 = func_0045E038(0x30FA);
        cb2 = func_004B7028;
        if (obj == NULL || obj->f8 == NULL || obj->f8(1) == 0) {
            flag2 = 1;
        }
        func_004B5E18(arg0, text2, cb2, flag2);
    } else {
        s32 flag = 0;
        s32 text;
        void *cb;

        obj = func_0046D428(0x2120, 0, 0xC);
        text = func_0045E038(0x2F24);
        cb = func_004B6FD0;
        if (obj == NULL || obj->f8 == NULL || obj->f8(0) == 0) {
            flag = 1;
        }
        func_004B5E18(arg0, text, cb, flag);
    }
    func_004B5E18(arg0, func_0045E038(0x2F25), func_004B7080, 1);
    func_004B5E18(arg0, func_0045E038(0x143), func_004B70D8, 1);
    func_004B5E18(arg0, func_0045E038(0x144), func_004B7130, 1);
    func_004B5E18(arg0, func_0045E038(0x239B), func_004B71D0, 1);
    func_004B5E18(arg0, func_0045E038(0x362D), func_004B6BA0 + 8, 1);
    func_004B5E70(arg0, func_004B6BA0 + 8, func_0045E038(0x107));
}
