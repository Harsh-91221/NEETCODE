class Solution
{
public:
    int n;
    vector<int> prevSmallerElement(vector<int> &heights)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr)
            {
                s.pop();
            }
            // CHOTA ELEMENT MIL GAYA STORE IN ANS
            ans[i] = s.top();
            // PUSH KARDO CURR KO
            s.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int> &heights)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr)
            {
                s.pop();
            }
            // CHOTA ELEMENT MIL GAYA STORE IN ANS
            ans[i] = s.top();
            // PUSH KARDO CURR KO
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        n = heights.size();
        vector<int> prev = prevSmallerElement(heights);
        vector<int> next = nextSmallerElement(heights);
        int maxarea = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int length = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            int area = length * width;
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};