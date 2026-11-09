/* Not matching yet: BYTES 3/188 (tools/try_func.py func_004BF718 --diff). Not part of the build. */
s32 func_00505B20(void);

typedef struct {
    u8 *f0;
    u8 *f4;
    u8 *f8;
    u8 pad[0xC];
} Type2;

typedef struct {
    u8 pad0[0x34];
    Type2 *f34;
    u8 pad38[0x18];
    s32 f50;
    s32 f54;
} Type1;

static inline Type2 *func_004BF718_entry(Type1 *list, s32 i)
{
    if (i < 0) {
        i = list->f54;
        if (i < 0) {
            return 0;
        }
    }
    return &list->f34[i];
}

typedef struct {
    u8 pad[0x1EC];
    Type1 f1EC;
    u8 pad2[0x258 - 0x1EC - sizeof(Type1)];
} Type3;

extern Type3 D_0030B358[];

// Return the index of the first list entry whose record starts with two zero bytes (-1 if none).
s32 func_004BF718(void)
{
    Type3 *obj;
    Type1 *list;
    s32 i;
    s32 found;
    s32 first;
    u8 *rec;

    obj = &D_0030B358[func_00505B20()];
    found = -1;
    first = 1;
    list = &obj->f1EC;
    for (i = 0; i < list->f50; i++) {
        rec = func_004BF718_entry(&obj->f1EC, i)->f8;
        if (rec[1] == 0 && rec[0] == 0 && first) {
            found = i;
            first = 0;
        }
    }
    return found;
}
