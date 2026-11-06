/* cflags: -fno-opt-stack */
#include "common.h"
struct Type0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 padC[4];
    f32 unk10;
    u8 pad14[0x24];
    f32 unk38;
    f32 unk3C;
};
struct Type1 { s32 unk0; s32 unk4; s32 unk8; u8 padC[4]; f32 unk10; };
struct Type2 { s32 unk0; f32 unk4; f32 unk8; f32 unkC; f32 unk10; u8 unk14[0x20]; };
struct Type3 { f32 unk0; f32 unk4; };
extern s32 func_00148698(f32);
extern s32 func_001486F8(f32, f32, f32);
extern void func_00148790(s32, void *, void *, f32);
extern void func_00149928(void *, void *, s32, f32);
extern s32 func_0014C2B8(f32);
extern f32 func_0014C368(s32);

void func_00148800(struct Type1 *arg0, struct Type0 *arg1, struct Type2 *arg2) {
    s32 temp_v0;
    s32 temp_v0_2;
    struct Type3 *temp_s3 = (struct Type3 *)((u8 *)arg2 + 8);
    temp_v0 = func_001486F8(arg1->unk38, arg2->unk4, temp_s3->unk4);
    arg0->unk4 = temp_v0;
    func_00148790(temp_v0, &arg2->unk4, &arg2->unkC, arg1->unk38);
    temp_v0_2 = func_0014C2B8(arg2->unk8);
    arg0->unk8 = temp_v0_2;
    arg2->unk8 = func_0014C368(temp_v0_2);
    arg0->unk0 = func_00148698(arg2->unk10);
    func_00149928(&arg2->unk14, (u8 *)arg0 + 0xC, 0xC, temp_s3->unk4);
    arg1->unk38 = temp_s3->unk4;
    arg1->unk3C = arg2->unk8;
}
