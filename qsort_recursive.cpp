#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;

int partition(int array[], int begin, int end)
{
    int pivot = array[(begin + end) / 2];
    while (begin < end)
    {
        while (array[begin] < pivot)
        {
            begin++;
        }

        while (array[end] > pivot)
        {
            end--;
        }

        if (begin < end)
        {
            swap(array[begin], array[end]);
            begin++;
            end--;
        }
    }
    
    return end;
}

void qsort(int array[], int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int new_end = partition(array, begin, end);
#ifdef DEBUG
    for (int i = 0; i < 15; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << "======================================" << endl;
#endif
    qsort(array, begin, new_end);
    qsort(array, new_end + 1, end);
}

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

int main()
{
    int array[] = {1,15, 28, 2, 6, 3, 9, 10, 5, 7, 10, 4, 13, 8, 20};
    qsort(array, 0, sizeof(array) / sizeof(int));
//	quickSort(array, 0, sizeof(array) / sizeof(int));

    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


