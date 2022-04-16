#include <stdio.h> 

int table[50]; 

int fib(int i)
{
  if (table[i] != 0) {
		return table[i]; 
	}
  if (i == 0) {
    return 0;
  }
  else if (i == 1) {
  	return 1;
	} else {
    table[i] = fib(i-1) + fib(i-2); 
    return table[i];
  }
}

int main(void)
{
  int n;
  scanf("%d", &n);
  printf("%d\n", fib(n));
  return 0;
}