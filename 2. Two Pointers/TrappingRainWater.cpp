/*
    Given elevation map array, compute trapped water
    Ex. height = [0,1,0,2,1,0,1,3,2,1,2,1] -> 6

    2 pointers, outside in, track max left/right
    For lower max, curr only dependent on that one
    Compute height of these, iterate lower one

    Time: O(n)
    Space: O(1)
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxleft = 0;
        int maxright = 0;
        int result = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= maxleft)
                {
                    maxleft = height[left];
                }
                else
                {
                    // height[left] is the current element here used for finding the trapped water by removing the black part that is smallest in that block
                    result += maxleft - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= maxright)
                {
                    maxright = height[right];
                }
                else
                {
                    // height[right] is the current element here used for finding the trapped water by removing the black part that is smallest in that block
                    result += maxright - height[right];
                }
                right--;
            }
        }
        return result;
    }
};