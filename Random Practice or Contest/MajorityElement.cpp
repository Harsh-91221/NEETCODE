class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        // Initialize the candidate and count
        int candidate = arr[0];
        int count = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            // If the current element is the same as the candidate
            if (arr[i] == candidate)
            {
                count++;
            }
            else // If the current element is different from the candidate
            {
                count--;
            }
            // If count becomes zero, update the candidate
            if (count == 0)
            {
                candidate = arr[i];
                count = 1;
            }
        }
        // Return the majority element
        return candidate;
    }
};
