// Brute Force
// T.C - O(n^4)
// S.C - O(n)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                for (int k = j + 1; k < nums.size() - 1; k++)
                {
                    for (int l = k + 1; l < nums.size(); l++)
                    {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                        {
                            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
            sort(ans.begin(), ans.end());
            for (auto a : ans)
            {
                st.insert(a);
            }
        }
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};

//Better Solution
