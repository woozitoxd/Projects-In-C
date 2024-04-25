#include <stdio.h>

int main()
{
    int a;
    printf("int vale = %d\n",sizeof(a));
    char b;
    printf("char vale = %d\n",sizeof(b));
    printf("suma de bytes = %d\n",sizeof(a)+sizeof(b));
    float r;
    r= sizeof(a)+sizeof(b);
    printf("division a+b/2 = %.1f\n",  r/2);
    return 0;
}
