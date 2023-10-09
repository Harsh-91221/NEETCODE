class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int maxsum = sum;

        // START SLIDING WINDOW
        int startIndex = 0;
        int endIndex = k;
        while (endIndex < nums.size())
        {
            // REMOVE PREVIOUS ELEMENT
            sum -= nums[startIndex];
            startIndex++;

            // ADD NEXT ELEMENT
            sum += nums[endIndex];
            endIndex++;
            // UPDATE MAX
            maxsum = max(maxsum, sum);
        }
        return (double)maxsum / k;
    }
};