/* cflags: -O2 -G8 -Wa,-G0 */
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned long u64;
typedef struct Data { u128 a; u128 b; u128 c; char p30[4]; int x34,x38; float x3c; char p40[4]; float x44; } Data;
extern void *func_0046C1F0(int, int);
void *func_L01_004AC708(char *owner, u128 a, u128 b, float x, float y) {
 char *o = func_0046C1F0(0xd1b, 0x80);
 if (o) {
  Data *d;
  *(unsigned char *)(o+0x30)=255; *(unsigned short *)(o+0x32)=255; *(unsigned char *)(o+0x31)=1; o[0x20]=0; *(char **)(o+0xb8)=owner;
  d = *(Data **)(o+0xac); *(u64 *)(o+0x38)=*(u64 *)(owner+0x38); *(u128 *)(o+0x10)=d->a;
  d->x44=y*0.020000001f; d->a=a; d->c=b; d->x3c=x; d->x38=0; d->x34=0;
 }
 return o;
}
