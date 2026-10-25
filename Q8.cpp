
#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp)
{
    int output[8];
    int count[10] = {0};

    // Count digit frequencies
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Calculate cumulative counts
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Place elements in sorted order for this digit
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int radixSort(int arr[], int n)
{
    int maximum = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > maximum)
            maximum = arr[i];

    int passes = 0;

    for (int exp = 1; maximum / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
        passes++;

        cout << "After pass " << passes << " (exp = "
             << exp << "): ";

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    return passes;
}

int main()
{
    int arr[] = {94, 802, 7, 1234, 56, 321, 405, 18};
    int n = 8;

    int passes = radixSort(arr, n);

    cout << "\nSorted tracking IDs: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTotal passes required: " << passes << endl;

    return 0;
}

