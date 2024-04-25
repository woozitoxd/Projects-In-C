#include <stdio.h>

long main()
{
    long A,B,C,D;
    A= 1;
    printf("%d\n", A);
    B= 4;
    printf("%d\n", B);
    C= A+B;
    printf("%d\n", C);
    D= A-B;
    printf("%d\n", D);
    A= C+2*B;
    printf("%d\n", A);
    B= C+B;
    printf("%d\n", B);
    C= A*B;
    printf("%d\n", C);
    D= B+D;
    printf("%d\n", D);
    A= D+C;
    printf("%d\n", A);
    return 0;

}

