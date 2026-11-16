/* Not matching yet: BYTES 20/160 (tools/try_func.py func_01EEF358 --diff) (tools/try_func.py func_01EEF358 --diff). Not part of the build. */
/* cflags: -Os */
typedef struct VTable VTable;
typedef struct Obj Obj;
struct VTable { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 (*unk10)(Obj *, s32); };
struct Obj { VTable *vt; };
extern s32 func_01EE7C34(s32);
extern Obj ***func_01EF2CC4(void);
void func_01EEF358(s32 arg0, s32 arg1)
{
    s32 r;
    Obj ***p;
    Obj ***q;
    Obj *o;
    s32 i = 0;
    r = func_01EE7C34(arg1);
    p = func_01EF2CC4();
    if (r != 0 && *p != 0) {
        q = p;
loop:
        o = *q;
        q++;
        r = o->vt->unk10(o, arg1);
        i++;
        if (i < 0x80) {
            if (r != 0) {
                if (*q != 0)
                    goto loop;
            }
        }
    }
}
