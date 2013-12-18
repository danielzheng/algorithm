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

int stack[100];
void qsort(int array[], int begin, int end)
{
    int top = 0;
    stack[top++] = begin;
    stack[top++] = end;

    while(top != 0)
    {
        int j = stack[--top];
        int i = stack[--top];
        cout << "partition range: " << i << " " << j << endl;
        int new_end = partition(array, i, j);
        cout << "new_end = " << new_end << endl;
        if (i < new_end)
        {
            stack[top++] = i;
            stack[top++] = new_end;
        }
        if (new_end + 1 < j)
        {
            stack[top++] = new_end + 1;
            stack[top++] = j;
        }
    }

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


