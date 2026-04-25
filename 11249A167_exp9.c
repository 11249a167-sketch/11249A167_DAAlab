#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
int t = *a; *a = *b; *b = t;
}

int partition(int a[], int low, int high) {
int pivot = a[high], i = low;
for (int j = low; j < high; j++)
if (a[j] <= pivot)
swap(&a[i++], &a[j]);
swap(&a[i], &a[high]);
return i;
}

int randomPartition(int a[], int low, int high) {
int r = low + rand() % (high - low + 1);
swap(&a[r], &a[high]);
return partition(a, low, high);
}

void quicksort(int a[], int low, int high) {
if (low < high) {
int p = randomPartition(a, low, high);
quicksort(a, low, p - 1);
quicksort(a, p + 1, high);
}
}

int main() {
int a[] = {6, 4, 12, 8, 15, 16}, n = 6;

srand(time(NULL));

for (int i = 0; i < n; i++) printf("%d ", a[i]);
printf("\n");

quicksort(a, 0, n - 1);

for (int i = 0; i < n; i++) printf("%d ", a[i]);

return 0;
}
