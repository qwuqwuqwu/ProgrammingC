// ASCII test

#include <stdio.h>
int main(void)
{
    // a:97~z:122
    // A:65~Z:90
	char ch;
	for (ch = 'A'; ch <= 'Z'; ch++) {
		printf("The ASCII value for %c is %d.\n", ch, ch);
	}
	for (ch = 'a'; ch <= 'z'; ch++) {
		printf("The ASCII value for %c is %d.\n", ch, ch);
	}
	
	return 0; 
}