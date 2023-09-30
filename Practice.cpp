class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int len=nums.size();
        set<int> s;
        for(int i=1;i<=k;i++)
        {
            s.insert(i);
        }
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            int val=nums.get(i); 
            if(h.contains(val))
            {
                h.remove(val);
            }
            count++;
            if(h.size()==0)
            {
                break;
            }
        }
        return count;
    }
};