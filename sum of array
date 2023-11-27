#include <stdio.h>
void main() {
  int arr[50], n, *ptr, i;
  int sum = 0;
  printf("Enter the size of array \n");
  scanf("%d", &n);
  printf("Enter the array elements \n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  ptr = arr;
  for (i = 0; i < n; i++) {
    sum = sum + (*ptr);
  }
  printf("sum of the array using pointer:%d\n", sum);
}
