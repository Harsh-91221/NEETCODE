class Solution
{
public:
    long long ispossible(vector<int> &time, long long giventime, long long totalTrips)
    {
        long long actualtime = 0;
        for (int i = 0; i < time.size(); i++)
        {
            actualtime += giventime / time[i];
        }
        return actualtime >= totalTrips;
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long n = time.size();
        long long s = 1;
        long long e = (long long)*min_element(time.begin(), time.end()) * totalTrips;
        while (s < e)
        {
            long long mid = s + (e - s) / 2;
            if (ispossible(time, mid, totalTrips))
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
};