class CustomStack
{
public:
    vector<int> s;
    int size;
    CustomStack(int maxSize)
    {
        this->size = maxSize;
    }

    void push(int x)
    {
        if (s.size() < size)
        {
            s.push_back(x);
        }
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        else
        {
            int temp = s.back();
            s.pop_back();
            return temp;
        }
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < k && i < s.size(); i++)
        {
            s[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */