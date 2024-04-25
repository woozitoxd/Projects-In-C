#include <stdio.h>
#define X 15
#define Y 30
#define Z Y-X

int main()

{
     int var;
     var= X;
     printf("%d\n", X);
     var= Y;
     printf("%d\n", Y);
     var= Y-X;
     printf("%d\n", Z);
     return 0;
}
