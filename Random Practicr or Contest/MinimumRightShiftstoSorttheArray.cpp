class Solution
{
public:
    int minimumRightShifts(vector<int> &nums)
    {
        // WE CAN OBSERVE AN INCREASING SLOPE IN ARRAY
        int pivotindex = 0;
        int pivotcount = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            // TO FIND THE DROP IN ARRAY
            if (nums[i - 1] > nums[i])
            {
                pivotindex = i;
                pivotcount++;
            }
        }
        // IF THERE IS MORE THAN ONE DROP THEN WE CAN'T SORT
        if (pivotcount > 1)
        {
            return -1;
        }
        // IF THERE IS NO DROP
        if (pivotindex == 0)
        {
            return 0;
        }
        // IF FIRST ELEMENT IS SMALLER THAN THE LAST ELEMENT THEN WE CAN'T SORT
        if (nums[n - 1] > nums[0])
        {
            return -1;
        }
        return n - pivotindex;
    }
};