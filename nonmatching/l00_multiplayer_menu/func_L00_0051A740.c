/* Not matching yet: SIZE ours 108 / retail 116 (tools/try_func.py func_L00_0051A740 --diff). Not part of the build. */
extern void func_004FAD28(void *);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);
extern s32 func_L00_00540E78(void *);

void *func_L00_0051A740(void) {
    u8 *obj;

    obj = func_L00_004FACD8(0x10);
    if (obj != NULL) {
        *(s32 *)(obj + 0x0) = 0;
        *(s32 *)(obj + 0xC) = 0;
        *(s32 *)(obj + 0x8) = 0;
        if (func_L00_00540E78(obj) != 0) {
            return obj;
        }
    }
    if (obj != NULL) {
        func_004FAD28(obj);
    }
    func_L00_004F84C8(6, 0x75, 0x21, 0, 0);
    return NULL;
}
