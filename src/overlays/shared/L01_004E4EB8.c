/* cflags:  */
extern int func_L01_004E4F78(void *);
extern int func_00568E30(int);
extern void *func_00588670(int, int, int);
extern char *D_00222D14;
typedef struct { char pad[0x80]; void *f80; short f84; short f86; short f88; } State;
typedef struct { char pad[0xac]; State *state; } Actor;
int func_L01_004E4EB8(Actor *actor, int a1, int a2) {
    State *s = actor->state;
    char *p;
    void *v;
    int result;
    if (!func_L01_004E4F78(actor)) return 0;
    p = D_00222D14 + ((unsigned int)*(int *)((unsigned int)s + ((unsigned int)s->f86 << 3)) << 8);
    v = func_00588670(func_00568E30(*(short *)(p + 0xbc)), 11, 16);
    s->f80 = v;
    result = (*(int (**)(char *, int, int))v)(p, a1, a2);
    s->f88 = result;
    return ((unsigned int)result << 16) != 0;
}
