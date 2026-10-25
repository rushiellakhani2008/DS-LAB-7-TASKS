
#include <iostream>
using namespace std;

int comparisons = 0;
int partitionCount = 0;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];  // First element is pivot

    cout << "\nPivot = " << pivot << endl;

    int i = low + 1;
    int j = high;

    while (true)
    {
        while (i <= high)
        {
            comparisons++;
            if (arr[i] > pivot)
                break;
            i++;
        }

        while (j > low)
        {
            comparisons++;
            if (arr[j] <= pivot)
                break;
            j--;
        }

        if (i >= j)
            break;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    partitionCount++;

    cout << "Array after partition: ";
    for (int k = 0; k < 7; k++)
        cout << arr[k] << " ";

    cout << endl;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {55, 25, 75, 15, 65, 35, 45};
    int n = 7;

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTotal comparisons: " << comparisons;
    cout << "\nTotal partition operations: " << partitionCount << endl;

    return 0;
}

