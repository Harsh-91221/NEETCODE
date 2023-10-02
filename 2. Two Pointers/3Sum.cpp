/*
    Given int array, return all unique triplets that sum to 0
    Ex. nums = [-1,0,1,2,-1,-4] -> [[-1,-1,2],[-1,0,1]]

    Sort, for each i, have j & k go outside in, check for 0 sums

    Time: O(n^2)
    Space: O(n)
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
}
// Time: O(n^2log(n))
// Space: O(n)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++)
        {
            set<int> hashset;
            for (int j = i + 1; j < nums.size(); j++)
            {
                int third = -(nums[i] + nums[j]);
                if (hashset.find(third) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};