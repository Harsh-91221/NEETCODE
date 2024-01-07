class Solution
{
public:
    int maximumSetSize(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        unordered_set<int> s1, s2, common;
        for (auto a : nums1)
        {
            s1.insert(a);
        }
        for (auto a : nums2)
        {
            s2.insert(a);
            if (s1.find(a) != s1.end())
            {
                common.insert(a);
            }
        }
        int n1 = s1.size(), n2 = s2.size(), c = common.size();
        return min(n, min(n1 - c, n / 2) + min(n2 - c, n / 2) + c);
    }
};