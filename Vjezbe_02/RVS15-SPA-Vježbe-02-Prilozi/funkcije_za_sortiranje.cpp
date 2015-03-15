#include <iostream>
using namespace std;

void bubble_sort(int* arr, int n) {
      bool swapped = true;
      int j = 0;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                        swap(arr[i], arr[i + 1]);
                        swapped = true;
                  }
            }
      }
}

void quick_sort(int* arr, int left, int right) {
      int i = left, j = right;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
				swap(arr[i], arr[j]);
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quick_sort(arr, left, j);
      if (i < right)
            quick_sort(arr, i, right);
}

void quick_sort(int* arr, int n) {
	quick_sort(arr, 0, n - 1);
}