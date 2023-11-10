class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int result = 0;
        // Iterate through all possible subarrays starting from index 'i'
        for (int i = 0; i < nums.size(); i++)
        {
            set<int> s; // Set to store distinct elements in the current subarray
            for (int j = i; j < nums.size(); j++)
            {
                s.insert(nums[j]);
                int count = s.size();    // Count of distinct elements in the set
                result += count * count; // Add the square of count to the result
            }
        }
        return result;
    }
};
