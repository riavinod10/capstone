#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, i = 0, right = n - 1;

        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);
                left++;
                i++;
            }
            else if (nums[i] == 1) {
                i++;
            }
            else {
                swap(nums[i], nums[right]);
                right--;
            }
        }
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    obj.sortColors(nums);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}