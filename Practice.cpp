sort(nums.begin(), nums.end());
        int maxSum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxSum >= n)
            {
                return ans;
            }
            while (maxSum + 1 < nums[i])
            {
                ans++;
                maxSum += maxSum + 1;
                if (maxSum >= n)
                {
                    return ans;
                }
            }
            if (maxSum + 1 >= nums[i])
            {
                maxSum += nums[i];
            }
        }
        while (maxSum < n)
        {
            ans++;
            maxSum += maxSum + 1;
        }
        return ans;