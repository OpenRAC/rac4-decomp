#include "common.h"
#include "pal/l01_0046DD08.h"

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
} Rule;

typedef struct {
    s32 f00;
    s32 f04;
} ClassPair;

typedef struct {
    u8 pad00[0x14];
    s32 (*condition)(void);
} RuleCallback;

typedef struct {
    u8 pad00[0xBC];
    u16 classId;
} SceneObject;

extern s32 func_0045D6C0(s32 id);
extern s32 func_0054C100(s32 id, s32 *value);
extern s32 func_L01_005969A0(void *object, s32 to, s32 from);
extern s32 D_0021DE98;
extern s32 D_L01_0021EC58;
extern ClassPair D_L01_003BADC8[];
extern Rule D_L01_003BAE20[];
s32 D_L01_0021E8A4 = 0;
s32 D_L01_0021E8A8 = 0;

void func_L01_0056B7C8(SceneObject *object)
{
    RuleCallback *callback;
    s32 found;
    s32 i;
    s32 t;

    callback = func_0046DD08(0x20A3, 0x10, 0x1C);
    if (callback != NULL && callback->condition != NULL && callback->condition() != 0)
        return;
    if (object->classId == 0x2726 || object->classId == 0x2727)
        return;
    found = 0;
    i = 0;
    func_0045D6C0((s16)object->classId);
    for (; D_L01_003BAE20[i].f00 != -1; i++) {
        Rule *rule = &D_L01_003BAE20[i];
        if ((s16)object->classId == D_L01_003BADC8[rule->f00].f00) {
            t = rule->f04;
            if (D_L01_0021E8A4 == 0 && D_L01_0021E8A8 == 1 ? D_0021DE98 - 0x14 == t : D_0021DE98 == t) {
                if (rule->f08 == 0 || func_0054C100(rule->f08, NULL) == D_L01_0021EC58) {
                    found = 1;
                    break;
                }
            }
        }
    }
    if (found)
        func_L01_005969A0(object, D_L01_003BADC8[D_L01_003BAE20[i].f00].f04,
                          D_L01_003BADC8[D_L01_003BAE20[i].f00].f00);
}
