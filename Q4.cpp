
#include <iostream>
using namespace std;

int partitionCount = 0;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Last element is pivot

    cout << "\nPartition call: low = " << low
         << ", high = " << high << endl;

    cout << "Pivot = " << pivot << endl;

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    int pivotIndex = i + 1;

    partitionCount++;

    cout << "Array after partition: ";
    for (int k = 0; k < 7; k++)
        cout << arr[k] << " ";

    cout << "\nPivot index = " << pivotIndex << endl;

    return pivotIndex;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int arr[] = {40, 20, 70, 10, 60, 30, 50};
    int n = 7;

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    quickSort(arr, 0, n - 1);

    cout << "\n\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTotal partition operations: "
         << partitionCount << endl;

    return 0;
}

