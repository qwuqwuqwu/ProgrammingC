#include <stdio.h>
#include <ctype.h>

int cal(void)
{
  int ans, op1, op2;
  char c = getchar();
  if (c == ' ') {
		return cal();
	} else if (isdigit(c)) {
    ungetc(c, stdin);
    scanf("%d", &ans);
    return ans;
  } else if(c == '+') {
  	op1 = cal();
    op2 = cal();
		return op1 + op2;
	} else if(c == '-') {
  	op1 = cal();
    op2 = cal();  
		return op1 - op2;
	} else if(c == '*') {
  	op1 = cal();
    op2 = cal();
		return op1 * op2;
	}
}

int main(void)
{
  printf("%d\n", cal());
  return 0;
}