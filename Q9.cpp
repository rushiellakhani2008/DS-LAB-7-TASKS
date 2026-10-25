
#include <iostream>
using namespace std;

const int N = 12;

void countingSort(int arr[], int n, int exp)
{
    int output[N];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    cout << "\nFrequency count: ";
    for (int i = 0; i < 10; i++)
        cout << count[i] << " ";

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    cout << "\nCumulative count: ";
    for (int i = 0; i < 10; i++)
        cout << count[i] << " ";

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    cout << "\nOutput array: ";
    for (int i = 0; i < n; i++)
        cout << output[i] << " ";

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    cout << "\nArray after copying: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
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
        passes++;
        cout << "\nPass " << passes << endl;
        countingSort(arr, n, exp);
    }

    return passes;
}

int main()
{
    int arr[N] = {
        4721, 305, 472, 89, 3005, 721,
        1000, 305, 9999, 42, 870, 100
    };

    cout << "Original array: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    int passes = radixSort(arr, N);

    cout << "\n\nSorted array: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    cout << "\nTotal passes: " << passes << endl;

    return 0;
}

