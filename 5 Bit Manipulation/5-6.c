#include <stdio.h>

int main()
{
int i=0xAAAAAAAA,j=0x55555555;
int c=10;
printf("After Swapping Bits : %d ==> %d\n",c,(((c&i)>>1)|((c&j)<<1)));
}
