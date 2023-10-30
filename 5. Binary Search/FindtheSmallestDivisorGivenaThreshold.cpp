// Brute force
// T.C - O(n^2)
// S.C - O(1)
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int maxi = *max_element(nums.begin(), nums.end());
        for (int s = 1; s <= maxi; s++)
        {
            int sum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += ceil((double)nums[i] / (double)s);
            }
            if (sum <= threshold)
            {
                return s;
            }
        }
        return -1;
    }
};
// Optimal
// T.C - O(logn)
// S.C - O(1)
class Solution
{
public:
    // Function to calculate the sum of ceil(nums[i] / threshold) for all elements in the array
    int sumD(vector<int> &nums, int threshold)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / (double)threshold);
        }
        return sum;
    }
    // Function to find the smallest divisor for which the sumD is less than or equal to the given threshold
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (sumD(nums, mid) <= threshold)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
};
