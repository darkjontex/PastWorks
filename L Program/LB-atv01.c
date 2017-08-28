#include <stdio.h>

int main() {
  char c = 32;
  do printf("[%d] %c\n", c, c);
  while (++c <= 126);
}
