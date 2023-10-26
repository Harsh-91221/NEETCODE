// T.C - O(nlogn)
// S.C - O(n)
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> mergeinterval;
        if (intervals.size() == 0)
        {
            return mergeinterval; // Return an empty vector if no intervals to merge.
        }
        sort(intervals.begin(), intervals.end()); // Sort the intervals based on the start values.
        vector<int> temp = intervals[0];          // Initialize a temporary interval with the first one.
        for (auto it : intervals)
        {
            if (it[0] <= temp[1]) // If the current interval overlaps with the temporary one.
            {
                temp[1] = max(it[1], temp[1]); // Merge by updating the end value of the temporary interval.
            }
            else
            {
                mergeinterval.push_back(temp); // If no overlap, add the merged interval to the result.
                temp = it;                     // Start a new temporary interval.
            }
        }
        mergeinterval.push_back(temp); // Add the last merged interval to the result.
        return mergeinterval;
    }
};
