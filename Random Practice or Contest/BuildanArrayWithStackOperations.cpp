// Brute Force
// T.C - O(n^2)
// S.C - O(1)
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;
        int current = 1;
        ;
        for (int i = 0; i < target.size(); i++)
        {
            while (current < target[i])
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                current++;
            }
            ans.push_back("Push");
            current++;
        }
        return ans;
    }
};

// Optimal
// T.C - O(n)
// S.C - O(1)
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;

        int targetindex = 0;

        for (int i = 1; i <= n; i++)
        {
            if (targetindex == target.size()) // If we have already processed all elements in the 'target' array, exit the loop.
            {
                break;

                if (target[targetindex] == i) // If the current element matches the target element at the 'targetindex'.
                {
                    ans.push_back("Push"); // Add "Push" to the answer vector.
                    targetindex++;         // Move to the next target element.
                }
                else
                {
                    ans.push_back("Push"); // Add "Push" to simulate pushing an element.
                    ans.push_back("Pop");  // Add "Pop" to simulate popping an element (since it's not the target element).
                }
            }
        }
        return ans;
    }
};
