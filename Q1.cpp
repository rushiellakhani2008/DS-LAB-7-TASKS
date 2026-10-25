
#include <iostream>
using namespace std;

int mergeCount = 0;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    mergeCount++;

    cout << "After merge " << mergeCount << ": ";
    for (int x = 0; x < 8; x++)
        cout << arr[x] << " ";
    cout << endl;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {78, 45, 92, 63, 45, 88, 51, 70};

    cout << "Original array: ";
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";

    cout << "\n\n";

    mergeSort(arr, 0, 7);

    cout << "\nSorted array: ";
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";

    cout << "\nTotal merge operations: " << mergeCount << endl;

    return 0;
}

