#include <stdio.h>
int data[] = {2, 5, 10, 15, 17, 24, 25, 28, 32, 35};
void find(int n, int left, int right);

int main(void)
{
  int number;
  printf("Enter a number between 1 and 40 you want to find:\n");
  scanf("%d", &number);
  find(number, 0, 9);
}

void find(int number, int left, int right)
{
  int middle= left + (right - left) / 2;
  if (left > right) {
    printf("%d is not in the data.\n", number);
  } else if (data[middle] == number) {
    printf("%d is at position %d.\n", number, middle);
  } else if (data[middle] > number) {
    find(number, left, middle - 1);
  } else {
    find(number, middle + 1, right);
  }

}