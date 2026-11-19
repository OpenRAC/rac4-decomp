/* Not matching yet: SIZE ours 160 / retail 168 (tools/try_func.py func_0012EB98 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
typedef struct Node {
    struct Node *next;
    s32 id;
} Node;

extern Node *D_1ACE00;
extern s32 func_0012D420(void);
extern s32 func_0012D470(void);
extern s32 func_0012E548(s32 id);

s32 func_0012EB98(u32 arg0)
{
    Node *a;
    Node *b;
    s32 flag;
    s32 old;

    a = (Node *)((arg0 >> 8) << 4);
    b = (Node *)((arg0 >> 8) << 4);
    flag = func_0012D420();
    if ((s32)arg0 < 0 || ((arg0 ^ a->id) & 0xFF)) {
        if (flag != 0) {
            func_0012D470();
        }
        return 0x80008002;
    }
    func_0012E548(b->id);
    old = (s32)D_1ACE00;
    D_1ACE00 = a;
    a->next = (Node *)old;
    a->id = 0;
    if (flag != 0) {
        func_0012D470();
    }
    return 0;
}
