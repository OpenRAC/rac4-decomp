/* cflags: -O2 -G8 -Wuninitialized */
void func_L41_0040F008(int, int);
void func_00506B70(int);
int func_00506BB8(void);

void func_L41_0040F680(int a)
{
    int i;
    int saved;

    i = 0;
    saved = func_00506BB8();
    func_00506B70(a);
    do {
        func_L41_0040F008(a, i);
        i++;
    } while (i < 4);
    func_00506B70(saved);
}
