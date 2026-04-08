#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> arr = nums;

    sort(arr.begin(), arr.end());

    int x = 0, y = 0;
    int i = 0, j = arr.size() - 1;

    while (i < j) {
        if (arr[i] + arr[j] == target) {
            x = arr[i];
            y = arr[j];
            break;
        } else if (arr[i] + arr[j] > target) {
            j--;
        } else {
            i++;
        }
    }

    vector<int> result;
    for (int k = 0; k < nums.size(); k++) {
        if (nums[k] == x || nums[k] == y) {
            result.push_back(k);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}