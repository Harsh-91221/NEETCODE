class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1;
        long long result = 0;
        int i = 0;
        // Step 1: Ignore leading whitespace
        while (s[i] == ' ')
        {
            i++;
        }
        // Step 2: Check for a sign character
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }
        // Step 3: Read and convert digits
        while (s[i] - '0' >= 0 && s[i] - '0' <= 9)
        {
            result = result * 10 + (s[i] - '0');
            // Check for overflow
            if (result * sign < INT_MIN)
            {
                return INT_MIN;
            }
            else if (result * sign > INT_MAX)
            {
                return INT_MAX;
            }
            i++;
        }
        // Step 4: Apply sign and handle overflow
        return result * sign;
    }
};
