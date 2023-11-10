class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        long long sum1 = 0;
        long long sum2 = 0;
        int zero1 = 0;
        int zero2 = 0;
        for (int i = 0; i < len1; i++)
        {
            sum1 += nums1[i];
            if (nums1[i] == 0)
            {
                sum1++;
                zero1++;
            }
        }
        for (int i = 0; i < len2; i++)
        {
            sum2 += nums2[i];
            if (nums2[i] == 0)
            {
                sum2++;
                zero2++;
            }
        }
        if (sum1 == sum2)
        {
            return sum1;
        }
        else
        {
            if (sum1 < sum2)
            {
                if (zero1 > 0)
                {
                    return sum2;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if (zero2 > 0)
                {
                    return sum1;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
};