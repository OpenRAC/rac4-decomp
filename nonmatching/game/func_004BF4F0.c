/* Not matching yet: BYTES 38/360 (tools/try_func.py func_004BF4F0 --diff). Not part of the build. */
extern s32 func_004BFA60(u32 kind);
extern s32 func_004C0CD0(s32 arg0);
extern s32 func_004C0DD0(s32 arg0);
extern s32 func_004C0E80(u32 arg0);
extern s32 func_004C0F78(u32 value);
extern s32 func_00505B20(void);
extern s32 D_0021DE10;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_0021F198;
extern u8 D_0030B358[];

static inline s32 func_004BF4F0_entry(s32 aux, s32 index)
{
    if (index < 0) {
        index = *(s32 *)(aux + 0x54);
        if (index < 0) {
            return 0;
        }
    }
    return *(s32 *)(aux + 0x34) + index * 0x18;
}

/* Finds the entry index in the current slot's list matching the active kind. */
s32 func_004BF4F0(void)
{
    s32 result;
    s32 first;
    s32 object;
    s32 kind;
    s32 have;
    s32 need;
    s32 aux;
    s32 i;
    s32 p;
    s32 v;

    result = -1;
    first = 1;
    object = (s32)(D_0030B358 + func_00505B20() * 0x258);
    kind = func_004BFA60(D_0021F198);
    if (kind == -1) {
        need = func_004C0DD0(D_0021DE10);
        have = func_004C0CD0(D_0021DE10);
    } else {
        need = func_004C0F78(kind);
        have = func_004C0E80(kind);
    }
    aux = object + 0x1EC;
    if (have < need) {
        for (i = 0; i < *(s32 *)(aux + 0x50); i++) {
            p = *(s32 *)(func_004BF4F0_entry(aux, i) + 8);
            if (*(s32 *)(p + 8) == 0) {
                v = *(s32 *)(p + 4);
                if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
                    v += 0x14;
                }
                if (v == D_0021DE10) {
                    result = i;
                }
            } else if (*(s32 *)(p + 4) == kind && first) {
                result = i;
                first = 0;
            }
        }
    }
    return result;
}
