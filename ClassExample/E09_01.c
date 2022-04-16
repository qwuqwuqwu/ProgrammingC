#include <stdio.h>
void binary(unsigned int i)
{
  if (i > 0) {
		binary(i/2); 
    printf("%u", i%2);
  }
}

int main(void)
{
    unsigned int n;
    scanf("%u", &n);
    binary(n);
    return 0;
}