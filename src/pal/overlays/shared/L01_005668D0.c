/* cflags:  */
typedef int s128 __attribute__((mode(TI)));
typedef struct { char pad0[0x30]; s128 value; float x; char pad1[0x1c]; float y; char pad2[0x70]; float a; float b; } Type1;
extern float func_00454328(float, float);
extern void func_L01_00522BE0(int, s128);
extern void func_L01_00522C48(int, void *);
void func_L01_005668D0(Type1 *p, int n) {
    float v[4];
    v[0] = 0.0f;
    v[1] = p->y;
    v[2] = p->x;
    v[3] = 0.0f;
    v[1] = func_00454328(v[1], p->a);
    v[2] = func_00454328(v[2], p->b);
    func_L01_00522BE0(n, p->value);
    func_L01_00522C48(n, v);
}
