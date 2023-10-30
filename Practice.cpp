class Solution
{
public:
    int sumD(vector<int> &nums, int threshold)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / (double)threshold);
        }
        return sum;
    }
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