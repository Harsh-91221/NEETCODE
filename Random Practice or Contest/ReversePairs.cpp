class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> ans;
        int left = low;
        int right = mid + 1;
        // Merge two sorted subarrays into a single sorted array
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                ans.push_back(nums[left]);
                left++;
            }
            else
            {
                ans.push_back(nums[right]);
                right++;
            }
        }
        // Add remaining elements from the left subarray, if any
        while (left <= mid)
        {
            ans.push_back(nums[left]);
            left++;
        }
        // Add remaining elements from the right subarray, if any
        while (right <= high)
        {
            ans.push_back(nums[right]);
            right++;
        }
        // Update the original array with the sorted values
        for (int i = low; i <= high; i++)
        {
            nums[i] = ans[i - low];
        }
    }
    int countpairs(vector<int> &nums, int low, int mid, int high)
    {
        int count = 0;
        int right = mid + 1;
        // Count pairs with the left and right subarrays
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && nums[i] > 2 * (long long)nums[right])
            {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }
    int mergesort(vector<int> &nums, int low, int high)
    {
        int count = 0;
        if (low >= high)
        {
            return count;
        }
        int mid = (low + high) / 2;
        // Recursively split, sort, and count pairs in subarrays
        count += mergesort(nums, low, mid);
        count += mergesort(nums, mid + 1, high);
        count += countpairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int> &nums)
    {
        return mergesort(nums, 0, nums.size() - 1);
    }
};
