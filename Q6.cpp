
#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int maximum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maximum)
            maximum = arr[i];
    }

    return maximum;
}

void countingSort(int arr[], int n, int exp)
{
    int output[7];
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    cout << "\nFrequency count: ";
    for (int i = 0; i < 10; i++)
        cout << count[i] << " ";

    // Calculate cumulative counts
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    cout << "\nCumulative count: ";
    for (int i = 0; i < 10; i++)
        cout << count[i] << " ";

    // Place elements in stable order
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    cout << "\nOutput array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void radixSort(int arr[], int n)
{
    int maximum = getMax(arr, n);

    for (int exp = 1; maximum / exp > 0; exp *= 10)
    {
        cout << "\n--- Pass for ";
        if (exp == 1)
            cout << "units digit ---";
        else if (exp == 10)
            cout << "tens digit ---";
        else
            cout << "hundreds digit ---";

        countingSort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {329, 457, 657, 839, 436, 720, 355};
    int n = 7;

    radixSort(arr, n);

    cout << "\nFinal sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}

