class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        reverse(tasks.begin(), tasks.end());
        int k = 0;
        int ans = 0;
        for (int i = 0; i < processorTime.size(); i++)
        {
            // Assingning 4 tasks for every processorTime and finding maximum
            for (int j = 0; j < 4; j++)
            {
                ans = max(ans, processorTime[i] + tasks[k]);
                k++;
            }
        }
        return ans;
    }
};