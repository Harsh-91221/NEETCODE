/*
    Given array of heights, find max water container can store
    Ex. height = [1,8,6,2,5,4,8,3,7] -> 49, (8 - 1) x min(8, 7)

    2 pointers outside in, greedily iterate pointer w/ lower height

    Time: O(n)
    Space: O(1)
*/

// BRUTE FORCE
//  Time: O(n^2)
//  Space: O(1)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxarea = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int width = j - i;
                int minheight = min(height[i], height[j]);
                int area = minheight * width;
                if (maxarea < area)
                {
                    maxarea = area;
                }
            }
        }
        return maxarea;
    }
};
// OPTIMAL SOLUTION
//  Time: O(n)
//  Space: O(1)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int start = 0;
        int end = height.size() - 1;
        int maxarea = 0;
        while (start < end)
        {
            int min_height = min(height[start], height[end]);
            int width = end - start;
            int area = min_height * width;
            maxarea = max(area, maxarea);
            if (height[start] < height[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return maxarea;
    }
};
