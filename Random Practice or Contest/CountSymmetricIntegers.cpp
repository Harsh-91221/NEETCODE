class Solution
{
public:
    bool isvalid(int num)
    {
        string numstr = to_string(num);
        int n = numstr.size();
        if (n % 2 != 0)
        {
            return false;
        }
        int leftsum = 0;
        int rightsum = 0;
        int i = 0;
        int mid = n / 2;
        for (i = 0; i < mid; i++)
        {
            leftsum += numstr[i] - '0';
        }
        for (; i < n; i++)
        {
            rightsum += numstr[i] - '0';
        }
        return leftsum == rightsum;
    }
    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;
        for (int i = low; i <= high; i++)
        {
            if (isvalid(i))
            {
                count++;
            }
        }
        return count;
    }
};