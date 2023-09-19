class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // INITIALLY AT FIRST POSITION
        int slow = nums[0];
        int fast = nums[0];
        // WE MOVED SLOW BY ONE STEP
        slow = nums[slow];
        // FAST IS MOVED BY TWO STEPS
        fast = nums[nums[fast]];
        // DETECT CYCLE
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // AGAIN START SLOW FROM FIRST AND INCREASE SLOW AND FAST BY ONE STEP
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};