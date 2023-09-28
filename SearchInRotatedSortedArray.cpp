/*
    Given array after some possible rotation, find if target is in nums
    Ex. nums = [4,5,6,7,0,1,2] target = 0 -> 4 (value 0 is at index 4)

    Modified binary search, if low <= mid left sorted, else right sorted

    Time: O(log n)
    Space: O(1)
*/
class Solution
{
public:
    int pivot(vector<int> &nums, int s, int e)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (s == e)
            {
                return s;
            }
            if (mid - 1 >= s && nums[mid] < nums[mid - 1])
            {
                return mid - 1;
            }
            if (mid <= e && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            if (nums[s] >= nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid;
            }
        }
        return s;
    }
    int binary(vector<int> &nums, int target, int s, int e)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int pivotindex = pivot(nums, 0, nums.size() - 1);
        int ans = 0;
        //*IMPORTANT POINT*
        //WE HAVE TO COMPARE TARGET FROM THE FIRST ELEMENT
        if (target >= nums[0] && target <= nums[pivotindex])
        {
            ans = binary(nums, target, 0, pivotindex);
        }
        else
        {
            ans = binary(nums, target, pivotindex + 1, nums.size() - 1);
        }
        return ans;
    }
};