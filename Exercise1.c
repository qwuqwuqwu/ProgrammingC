#include <stdio.h>
#include <string.h>

int main(void)
{
   int i = 1, word_len;
   char word[40];
   scanf("%s", word);

   word_len = strlen(word);

   while (i <= word_len) {
      printf("%*.*s\n", word_len, i, word);
      i++;
   }

   return 0;
}