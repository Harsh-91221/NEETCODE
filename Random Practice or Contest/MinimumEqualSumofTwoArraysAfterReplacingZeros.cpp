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
        // Calculate sum1 and count zeros in nums1
        for (int i = 0; i < len1; i++)
        {
            sum1 += nums1[i];
            if (nums1[i] == 0)
            {
                // If the element is zero, increment sum1 by 1 and update zero1
                sum1++;
                zero1++;
            }
        }
        // Calculate sum2 and count zeros in nums2
        for (int i = 0; i < len2; i++)
        {
            sum2 += nums2[i];
            if (nums2[i] == 0)
            {
                // If the element is zero, increment sum2 by 1 and update zero2
                sum2++;
                zero2++;
            }
        }
        // Check if sums are equal
        if (sum1 == sum2)
        {
            // If sums are equal, return any of them
            return sum1;
        }
        else
        {
            // If sum1 is less than sum2
            if (sum1 < sum2)
            {
                // Check if there are zeros in nums1
                if (zero1 > 0)
                {
                    // If there are zeros in nums1, return sum2
                    return sum2;
                }
                else
                {
                    // If there are no zeros in nums1, return -1
                    return -1;
                }
            }
            // If sum2 is less than sum1
            else
            {
                // Check if there are zeros in nums2
                if (zero2 > 0)
                {
                    // If there are zeros in nums2, return sum1
                    return sum1;
                }
                else
                {
                    // If there are no zeros in nums2, return -1
                    return -1;
                }
            }
        }
    }
};
