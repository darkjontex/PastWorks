/* qsort example */
#include <stdio.h>
#include <stdlib.h>

int values[] = { 40, 10, 100, 90, 20, 25, 255, 156, 1, 8, 10 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
  qsort (values, 11, sizeof(int), compare);
  for (n=0; n<11; n++)
     printf ("%d ",values[n]);
  return 0;
}
