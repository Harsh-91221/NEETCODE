/*
    Given unsorted array, return length of longest consecutive sequence
    Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,2,3,4]

    Store in hash set, only check for longer seq if it's the beginning

    Time: O(n)
    Space: O(n)
*/
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int longest = 1;
        if (nums.empty())
        {
            return 0;
        }
        for (auto a : s)
        {
            if (s.find(a - 1) == s.end())
            {
                int count = 1;
                int x = a;
                while (s.find(x + 1) != s.end())
                {
                    count++;
                    x++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
}

// Time: O(nlog(n))
// Space: O(1)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.empty())
        {
            return 0;
        }
        int leastsmaller = INT_MIN;
        int longest = 1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - 1 == leastsmaller)
            {
                count++;
                leastsmaller = nums[i];
            }
            else if (nums[i] != leastsmaller)
            {
                // RESET THE COUNT IF THE SEQUENCE IS BREAKED
                count = 1;
                leastsmaller = nums[i];
            }
            longest = max(longest, count);
        }
        return longest;
    }
}

// Time: O(n^2)
// Space: O(1)
class Solution
{
public:
    bool linear(vector<int> &nums, int x)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
            {
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int longest = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            int count = 1;
            while (linear(nums, x + 1) == true)
            {
                x++;
                count++;
            }
            longest = max(longest, count);
        }
        return longest;
    }
}