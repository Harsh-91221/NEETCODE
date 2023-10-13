class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size();
        long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += chalk[i];
        }
        // if k is larger than the total sum, it effectively starts over from student 0. Hence maintaining cyclic nature
        k = k % sum;
        for (int i = 0; i < n; i++)
        {
            // there are not enough chalk pieces to solve the problem
            if (k - chalk[i] < 0)
            {
                // student at index i will need to replace the chalk
                return i;
            }
            else
            {
                // indicating that these pieces have been used
                k -= chalk[i];
            }
        }
        return n - 1;
    }
};