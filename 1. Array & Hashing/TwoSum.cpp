/*
    Given int array & target, return indices of 2 nums that add to target
    Ex. nums = [2,7,11,15] & target = 9 -> [0,1], 2 + 7 = 9

    At each num, calculate complement, if exists in hash map then return

    Time: O(n)
    Space: O(n)
*/
// BRUTE FORCE
//  T.C -> O(n^2)
//  S.C -> O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// OPTIMIZED METHOD USING MAP
//  T.C -> O(nlog(n))
//  S.C -> O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            // SEARCHING
            if (mp.find(complement) != mp.end())
            {
                return {mp[complement], i};
            }
            // FILLING HASHMAP
            mp[nums[i]] = i;
        }
        return {};
    }
};