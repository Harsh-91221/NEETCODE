class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int deficit = 0;
        int start = 0;
        int balance = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            balance += gas[i] - cost[i]; // Calculate the difference between gas and cost at each station
            // If the balance becomes negative (not enough gas to reach this station)
            if (balance < 0)
            {
                deficit += balance; // Accumulate the deficit
                start = i + 1;      // Update the potential start to the next station
                balance = 0;        // Reset the balance for the new start
            }
        }
        // If the total balance along with the deficit is non-negative, return the starting index
        if (deficit + balance >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};
