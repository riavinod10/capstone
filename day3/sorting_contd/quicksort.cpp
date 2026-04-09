#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low + 1 && arr[j] > pivot) j--;

        if (i < j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 3, 7};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}