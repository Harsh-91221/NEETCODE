// Brute force
// T.C - O(n^3)
// S.C - O(1)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int mul = 1;
                for (int k = i; k <= j; k++)
                {
                    mul = mul * nums[k];
                }
                maxi = max(maxi, mul);
            }
        }
        return maxi;
    }
};

// Better
// T.C - O(n^2)
// S.C - O(1)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int mul = 1;
            for (int j = i; j < nums.size(); j++)
            {
                mul = mul * nums[j];
                maxi = max(maxi, mul);
            }
        }
        return maxi;
    }
};

// Optimal
// T.C - O(n)
// S.C - O(1)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int prefix = 1;
        int suffix = 1;
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
            {
                prefix = 1; // Reset prefix to 1 if it becomes 0.
            }
            if (suffix == 0)
            {
                suffix = 1; // Reset suffix to 1 if it becomes 0.
            }
            prefix = prefix * nums[i];             // Calculate the prefix product.
            suffix = suffix * nums[n - i - 1];     // Calculate the suffix product.
            maxi = max(maxi, max(prefix, suffix)); // Update the maximum product.
        }
        return maxi; // Return the maximum product.
    }
};
