class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            // Check if the current price is higher than the previous day's price
            if (prices[i] > prices[i - 1])
            {
                // If it is, calculate the profit by selling and buying on consecutive days
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};
