/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int leftsubarray(int target, MountainArray &mountainArr, int peak)
    {
        int s = 0;
        int e = peak;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) > target)
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
    int rightsubarray(int target, MountainArray &mountainArr, int peak)
    {
        int s = peak;
        int e = mountainArr.length() - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) < target)
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
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int s = 0;
        int e = n - 1;
        while (s < e)
        {
            int mid = s + (e - s) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        int leftresult = leftsubarray(target, mountainArr, s);
        if (leftresult != -1)
        {
            return leftresult;
        }
        int rightresult = rightsubarray(target, mountainArr, s);
        if (rightresult != -1)
        {
            return rightresult;
        }
        return -1;
    }
};