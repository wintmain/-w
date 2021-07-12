#include <stdio.h>
int main()
{
    int a = 10, b = 20, c = 30, d = 40;
    int a1 = ++a, b1 = b++, c1 = --c, d1 = d--;
   
    printf("a=%d, a1=%d\n", a, a1);
    printf("b=%d, b1=%d\n", b, b1);
    printf("c=%d, c1=%d\n", c, c1);
    printf("d=%d, d1=%d\n", d, d1);
   
    return 0;
}