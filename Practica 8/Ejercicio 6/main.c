#include <stdio.h>
#include <stdlib.h>

int maximos[2];

void dos_max(int[], int);

int main(void)
{
  maximos[0] = maximos[1] = -1;
  int arr[] = {4, 5, 3, 0, 1, 7};
  const int len = 6;
  dos_max(arr, len);
  printf("%d %d\n", maximos[0], maximos[1] );
  return 0;
}

void dos_max(int l[], int len)
{
  if( len == 1)
  {
    int posMin;
    if( maximos[0] > maximos[1])
      posMin = 1;
    else
      posMin = 0;
    if(l[0] > maximos[posMin])
      maximos[posMin] = l[0];
    return;
  }
  if( len > 1)
  {
    int mid = len / 2;
    dos_max(l, mid);
    dos_max(l + mid, len - mid);
  }
}
