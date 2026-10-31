/* cflags: -O2 -G8 -Wa,-G0 */
typedef struct { char a[0x20]; unsigned char state; char b[0x8b]; void *data; char c[0xe]; unsigned char flags; } Obj;
typedef struct { char a[0x128]; int count; float rate; float value; } Data;
extern int func_L05_003E6D78(Obj *);
extern int func_L00_005DF8D8(Obj *);
extern int func_L05_003E70D0(Obj *);
extern void func_004E2EF0(int,int,Obj *);
extern int func_00453CE8(int *);
extern float func_004744E8(float,float,float);
extern int func_L01_0062B6C0(int,Obj *);
extern void func_00474368(Obj *,int,int);
extern void func_004E2938(int,Obj *);
extern void func_L05_003E6F70(Obj *);
static inline int enter(Obj *o) { if ((o->flags ^ 1) & 1) { o->flags |= 1; return 1; } return 0; }
void func_L05_003E6AE0(Obj *o) {
 Data *d = (Data *)o->data;
 if (func_L05_003E6D78(o)) return;
 if (func_L00_005DF8D8(o)) return;
 switch(o->state) {
 case 1:
  if (enter(o)) d->value=0.0f;
  if (func_L05_003E70D0(o)) func_00474368(o,2,-1);
  break;
 case 2:
  if (enter(o)) { d->count=25; d->rate=0.04f; func_004E2EF0(0,0,o); }
  func_00453CE8(&d->count);
  d->value=func_004744E8(1.0f,0.0f,(float)d->count*d->rate);
  if (d->value>=1.0f) func_00474368(o,3,-1);
  break;
 case 3:
  if (enter(o)) { d->count=50; d->value=1.0f; }
  if (!func_L01_0062B6C0(2,o)) func_004E2EF0(2,4,o);
  if (func_00453CE8(&d->count) && !func_L05_003E70D0(o)) func_00474368(o,4,-1);
  break;
 case 4:
  if (enter(o)) { d->count=25; d->rate=0.04f; func_004E2938(2,o); func_004E2EF0(1,0,o); }
  func_00453CE8(&d->count);
  d->value=func_004744E8(0.0f,1.0f,(float)d->count*d->rate);
  if (d->value<=0.0f) func_00474368(o,1,-1);
  break;
 case 5: break;
 }
 func_L05_003E6F70(o);
}
