#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int deterministicPartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; ++j)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

int randomizedPartition(vector<int> &arr, int low, int high)
{
    int pivot = low + rand() % (high - low + 1);
    swap(arr[pivot], arr[low]);
    return deterministicPartition(arr, low, high);
}

void deterministicQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = deterministicPartition(arr, low, high);
        cout << "Pivot element is: " << arr[pivot] << endl;
        cout << "Array after partitioning with " << arr[pivot] << ": ";
        for (int val : arr)
            cout << val << " ";
        cout << "\n\n";

        deterministicQuickSort(arr, low, pivot - 1);
        deterministicQuickSort(arr, pivot + 1, high);
    }
}

void randomizedQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = randomizedPartition(arr, low, high);
        cout << "Pivot element is: " << arr[pivot] << endl;
        cout << "Array after partitioning with " << arr[pivot] << ": ";
        for (int val : arr)
            cout << val << " ";
        cout << "\n\n";

        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> arrCopy = arr;

    cout << string(50, '*') << endl;
    clock_t start = clock();
    deterministicQuickSort(arr, 0, n - 1);
    clock_t end = clock();
    double deterministicTime = double(end - start) / CLOCKS_PER_SEC;
    cout << "Deterministic Quick Sort Time: " << deterministicTime << " seconds" << endl;

    cout << string(50, '*') << endl;
    start = clock();
    randomizedQuickSort(arrCopy, 0, n - 1);
    end = clock();
    double randomizedTime = double(end - start) / CLOCKS_PER_SEC;
    cout << "Randomized Quick Sort Time: " << randomizedTime << " seconds" << endl;

    return 0;
}
