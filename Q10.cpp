
#include <iostream>
using namespace std;

const int N = 10;

void countingSort(int arr[], int n, int exp)
{
    int output[N];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

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
    int max = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int passes = 0;

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
        passes++;

        cout << "After pass " << passes << ": ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    return passes;
}

int main()
{
    int arr[N] = {
        7314, 314, 731, 34, 3147,
        147, 47, 7314, 4, 314
    };

    cout << "Original array: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    int passes = radixSort(arr, N);

    cout << "\nSorted array: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    cout << "\nTotal passes: " << passes << endl;

    return 0;
}

