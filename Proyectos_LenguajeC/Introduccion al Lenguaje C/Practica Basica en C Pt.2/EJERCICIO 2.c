#include <stdio.h>


float main()

{    float A,B,C;
     A= 3.8;
     printf("%.1f\n", A);
     B= 20.77;
     printf("%.2f\n", B);
     C= A+B;
     printf("%f\n", C);
     B= A+B;
     printf("%f\n", B);
     A=B;
     printf("%f\n", A);
     return 0;
}
