/* Not matching yet: BYTES 22/152 (tools/try_func.py func_01EF6D7C --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G8 -mno-split-addresses */
extern void func_01F0C090(const char *name, int code);
extern unsigned int D_0019CC98[];

typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    unsigned char pad8[0x10];
    float unk18;
    float unk1C;
    float unk20;
    unsigned char pad24[0x8];
    unsigned int unk2C;
    unsigned char pad30[0x50];
    void **unk80;
    unsigned char pad84[0x1C];
    unsigned int unkA0;
    unsigned char padA4[0x10];
    float unkB4;
    float unkB8;
    float unkBC;
} Args;

typedef struct {
    void **vtable;
} Obj;

typedef void (*Fn)(void *self, unsigned int a1, unsigned int a2, unsigned int a3,
                   float f12, float f13, float f14, float f15, float f16, float f17);

void func_01EF6D7C(Args *arg0) {
    Obj *s1 = *(Obj **)arg0->unk80;

    if (s1 == 0) {
        func_01F0C090((const char *)D_0019CC98, 0x41);
    }
    if (arg0->unk0 == 0) {
        func_01F0C090((const char *)D_0019CC98, 0x42);
    }
    ((Fn *)s1->vtable)[3](s1, arg0->unk4, arg0->unk2C, arg0->unkA0,
                          arg0->unk18, arg0->unk1C, arg0->unkB4,
                          arg0->unkB8, arg0->unk20, arg0->unkBC);
}
