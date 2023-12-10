class Solution
{
public:
    long long countSubarrays(vector<int> &arr, int k)
    {
        long long n = arr.size();
        long long maxi = *max_element(arr.begin(), arr.end());
        long long i = 0, j = 0;
        long long count = 0, result = 0;
        while (j < n)
        {
            if (arr[j] == maxi)
            {
                count++;
            }
            if (count >= k)
            {
                while (count >= k)
                {
                    result += n - j;
                    if (arr[i] == maxi)
                    {
                        count--;
                    }
                    i++;
                }
            }
            j++;
        }
        return result;
    }
     
};