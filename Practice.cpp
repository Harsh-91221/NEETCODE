class Solution
{
public:
    vector<int> memLeak(int memory1, int memory2)
    {
        int crash = 1;
        while (true)
        {
            if (memory1 == memory2 && memory1 >= crash)
            {
                memory1 -= crash;
                crash++;
            }
            else if (memory1 > memory2 && memory1 >= crash)
            {
                memory1 -= crash;
                crash++;
            }
            else if (memory1 < memory2 && memory2 >= crash)
            {
                memory2 -= crash;
                crash++;
            }
            else
            {
                break;
            }
        }
        return {crash, memory1, memory2};
    }
};