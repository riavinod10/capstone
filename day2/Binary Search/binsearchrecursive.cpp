#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);
    else
        return binarySearch(arr, low, mid - 1, target);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 5;

    int result = binarySearch(arr, 0, arr.size() - 1, target);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}