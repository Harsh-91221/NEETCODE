// BRUTE FORCE
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] < nums[j])
                {
                    for (int k = j + 1; k < nums.size(); k++)
                    {
                        if (nums[i] < nums[k] && nums[k] < nums[j])
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

// BETTER
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int num_i = nums[0];
        for (int j = 1; j < nums.size(); j++)
        {
            num_i = min(num_i, nums[j]);
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (num_i < nums[k] && nums[k] < nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// OPTIMAL
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int nums3 = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < nums3)
            {
                return true;
            }
            while (!st.empty() && st.top() < nums[i])
            {
                nums3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};