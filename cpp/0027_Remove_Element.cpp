class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
   int i = 0;
    int n = nums.size();
    while (i < n) {
        if (nums[i] == val) {
            std::swap(nums[i], nums[n - 1]);
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
    }
};
