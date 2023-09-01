// BRUTE FORCE
// T.C -> O(nlong(n))
// S.C -> O(1)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
                break;
            }
        }
        return false;
    }
};

// ANOTHER SOLUTION USING SET
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        int se = s.size();
        if (n == se)
        {
            return false;
        }
        return true;
    }
};
// OPTIMIZED SOLUTION USING MAP
// T.C -> O(n)
// S.C -> O(n)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto a : nums)
        {
            mp[a]++;
        }
        for (auto a : mp)
        {
            if (a.second > 1)
            {
                return true;
            }
        }
        return false;
    }
};
