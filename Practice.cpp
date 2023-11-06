class SeatManager
{
public:
    vector<int> t;
    int N;
    SeatManager(int n)
    {
        N = n;
        t.resize(N + 1, -1);
    }

    int reserve()
    {
        for (int i = 1; i <= N; i++)
        {
            if (t[i] == -1)
            {
                t[i] = 1;
                return i;
            }
        }
        return -1;
    }

    void unreserve(int seatNumber)
    {
        t[seatNumber] = -1;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */