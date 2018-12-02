#include <stdio.h>

void PrintHeader();

int main()
{
  PrintHeader();
  getchar();
  return 0;
}
void PrintHeader()
{
  printf("%c", (char)201);
  for (int i = 0; i < 5; i++)
  {
    printf("%c", (char)205);
  }
  printf("%c", (char)187);
}