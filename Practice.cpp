// Calculate the frequency of elements and add the sum of their frequency in the pairs of 3 and if there is any remaining element then add 1 to the ans
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        for (auto a : nums)
        {
            mp[a]++;
        }
        for (auto a : mp)
        {
            if (a.second == 1)
            {
                return -1;
            }
            ans += a.second / 3;
            if (a.second % 3)
            {
                ans++;
            }
        }
        return ans;
        //  unordered_map<int,int> mp;
        //     for(auto a:nums)
        //     {
        //         mp[a]++;
        //     }
        //     int result=0;
        //     for(auto a:mp)
        //     {
        //         if(a.second<2)
        //         {
        //             return -1;
        //         }
        //         result+=(a.second+2)/3;
        //     }
        //     return result;
    }
};