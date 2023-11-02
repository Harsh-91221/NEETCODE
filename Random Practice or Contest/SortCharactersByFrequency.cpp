class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        // Create a priority_queue to store characters by their frequency in descending order.
        // The priority_queue is a max-heap by default.
        priority_queue<pair<int, char>> pq;
        string ans = "";
        for (auto a : s)
        {
            mp[a]++;
        }
        // Populate the priority_queue with pairs of character frequency and character itself.
        for (auto a : mp)
        {
            pq.push({a.second, a.first});
        }
        // Build the sorted string based on character frequency.
        while (!pq.empty())
        {
            auto temp = pq.top();
            int freq = temp.first; // Get the frequency of the character.
            char ch = temp.second; // Get the character itself.

            ans += string(freq, ch); // Append 'freq' copies of 'ch' to the result string.
            pq.pop();                // Remove the processed character from the priority_queue.
        }
        return ans;
    }
};
