/*
    Given array of temps, return an array w/ # of days until warmer
    Ex. temperature = [73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]

    Monotonic decr stack, at each day, compare incr from prev days

    Time: O(n)
    Space: O(n)
*/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = temperatures[i];
            while (!s.empty() && temperatures[s.top()] <= curr)
            {
                s.pop();
            }
            if (s.empty())
            {

                ans[i] = 0;
            }
            else
            {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }
        return ans;
    }
};