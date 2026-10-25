
#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp)
{
    int output[7];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert frequency to cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Traverse backwards to maintain stability
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    cout << "After pass (exp = " << exp << "): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void radixSort(int arr[], int n)
{
    int maximum = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > maximum)
            maximum = arr[i];

    for (int exp = 1; maximum / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int arr[] = {91, 8, 1024, 56, 305, 7, 120};
    int n = 7;

    radixSort(arr, n);

    cout << "Final sorted IDs: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}

