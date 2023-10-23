class Solution
{
public:
    // Static comparison function to be used for sorting strings
    static bool comp(string &a, string &b)
    {
        // Compare the lengths of strings
        if (a.size() != b.size())
        {
            // If lengths are different, return true if the length of 'a' is less than 'b'
            return a.size() < b.size();
        }
        // If lengths are the same, use lexicographical comparison (dictionary order)
        return a < b;
    }
    string kthLargestNumber(vector<string> &nums, int k)
    {
        // Sort the vector of strings using the 'comp' comparison function
        sort(nums.begin(), nums.end(), comp);
        // Return the kth largest number, which is at the (size - k) index
        return nums[nums.size() - k];
    }
};
