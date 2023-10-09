class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        // Handling all possible edge cases
        if (n == 1)
        {
            return nums[0];
        }
        if (nums[0] != nums[1])
        {
            return nums[0];
        }
        if (nums[n - 1] != nums[n - 2])
        {
            return nums[n - 1];
        }
        int s = 1;
        int e = n - 2;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            // Checking if there is odd even pair index for left portion elemination
            else if (mid % 2 == 1 && nums[mid] == nums[mid - 1] || mid % 2 == 0 && nums[mid] == nums[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return -1;
    }
};