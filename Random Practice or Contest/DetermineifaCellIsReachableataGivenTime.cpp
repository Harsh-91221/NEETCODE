class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        // WE WILL FIND THE SHORTEST PATH TO THE DESTINATION TO ENSURE IT REACHES THE DESTINATION ON TIME
        int xdiff = abs(sx - fx);
        int ydiff = abs(sy - fy);
        // EDGE CASE
        // IF THE START AND DESTINATION POSITION ARE SAME AND TIME IS 1 THEN IF WE MOVE IT CANNOT REACH
        if (xdiff == 0 && ydiff == 0 && t == 1)
        {
            return false;
        }
        // FIRST WE FIND THE MINIMUM COMMON PART DIAGONALLY REACHED BY POINTS
        int common_part = min(xdiff, ydiff);
        // THEN WE CALCULATED THE REMAINING PART THAT CAN'T BE REACHED DIAGONALLY
        int remaining_part = abs(xdiff - ydiff);
        // IF THE SUM IS SMALLER OR EQUAL TO TIME THEN IT CAN REACH
        if (common_part + remaining_part <= t)
        {
            return true;
        }
        return false;
    }
};