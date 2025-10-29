#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
      return i;
  }
  return -1;
}

int main()
{
  int n, key, pos;
  clock_t start, end;
  double cpu_time_used;
  int repetitions = 10000;

  printf("Elements\tTimeTaken(ms)\n");

  for (n = 1000; n <= 50000; n += 5000)
  {
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr)
    {
      printf("Memory allocation failed\n");
      return 1;
    }

    for (int i = 0; i < n; i++)
    {
      arr[i] = rand() % n;
    }

    key = -1; // Worst case (element not present)

    start = clock();
    for (int r = 0; r < repetitions; r++)
    {
      pos = linearSearch(arr, n, key);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    cpu_time_used /= repetitions; // taking average

    printf("%d\t\t%f\n", n, cpu_time_used);

    free(arr);
  }

  return 0;
}