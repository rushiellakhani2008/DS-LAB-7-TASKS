
#include <iostream>
using namespace std;

int comparisons = 0;
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

    cout << "\nLeft subarray: ";
    for (int i = 0; i < n1; i++)
        cout << L[i] << " ";

    cout << "\nRight subarray: ";
    for (int j = 0; j < n2; j++)
        cout << R[j] << " ";

    cout << endl;

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        comparisons++;

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

    cout << "Merged array: ";
    for (int x = left; x <= right; x++)
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
    int arr[] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
    int n = 8;

    mergeSort(arr, 0, n - 1);

    cout << "\nFinal sorted prices: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTotal comparisons: " << comparisons << endl;
    cout << "Total merge operations: " << mergeCount << endl;

    return 0;
}

