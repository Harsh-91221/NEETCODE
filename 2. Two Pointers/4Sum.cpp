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

// Better Solution
// T.C - O(n^3)*log(n)
// S.C - O(n)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                set<long long> s;
                for (int k = j + 1; k < nums.size(); k++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if (s.find(fourth) != s.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    s.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};

// Optimal
// T.C - O(n^3)
// S.C - O(1)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sort the input array in ascending order.
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicate values for the first element.
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (j != (i + 1) && nums[j] == nums[j - 1]) // Skip duplicate values for the second element.
                {
                    continue;
                }
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp); // Found a valid quadruplet.

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1]) // Skip duplicate values for the third element.
                        {
                            k++;
                        }

                        while (k < l && nums[l] == nums[l + 1]) // Skip duplicate values for the fourth element.
                        {
                            l--;
                        }
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans; // Return the list of unique quadruplets that sum to the target.
    }
};
