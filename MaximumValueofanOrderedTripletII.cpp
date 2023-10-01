#include <iostream>
#include <vector>
#include <climits>
using namespace std;
long long maximumTripletValue(vector<int> &nums)
{
    long long max1 = 0;
    long long max2 = INT_MIN;
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = max(ans, max2 * (nums[i]));
        max2 = max(max2, max1 - nums[i]);
        max1 = max(max1, (long long)(nums[i]));
    }
    return ans;
}
int main()
{
    vector<int> nums = {12, 6, 1, 2, 7};
    long long result = maximumTripletValue(nums);
    cout << "Maximum Triplet Value: " << result << endl;
    return 0;
}
// int n=nums.size();
// vector<int> prefix(n);
// vector<int> suffix(n);
// prefix[0]=nums[0];
// for(int i=1;i<n;i++)
// {
//     prefix[i]=max(prefix[i-1],nums[i]);
// }
// suffix[n-1]=nums[n-1];
// for(int i=n-2;i>=0;i--)
// {
//     suffix[i]=max(suffix[i+1],nums[i]);
// }
// long long ans=0;
// for(int i=1;i<n-1;i++)
// {
//     long long triplet=(long long)(prefix[i-1]-nums[i])*suffix[i+1];
//     ans=max(ans,triplet);
// }
// if(ans<=0)
// {
//     return 0;
// }
// return ans;