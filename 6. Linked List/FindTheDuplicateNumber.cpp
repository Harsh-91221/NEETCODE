/*
    Given int array, return the one repeated number
    Ex. nums = [1,3,4,2,2] -> 2, nums = [3,1,3,4,2] -> 3

    If there's duplicate, must be a cycle, find meeting point
    Take 1 back to start, they'll intersect at the duplicate

    Time: O(n)
    Space: O(1)
*/

// BRUTE FORCE
// T.C - O(n)
// S.C - O(n)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto a : nums)
        {
            mp[a]++;
        }
        for (auto a : mp)
        {
            if (a.second > 1)
            {
                return a.first;
            }
        }
        return 0;
    }
};

// OPTIMAL
//  Time: O(n)
//  Space: O(1)

// We will just go to index given by number and traverse
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