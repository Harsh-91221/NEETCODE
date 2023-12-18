#include <iostream>
using namespace std;
class Heap
{
public:
    int size;
    int a[101];
    Heap()
    {
        size = 0;
    }
    void insert(int value)
    {
        size = size + 1;
        int index = size;
        a[index] = value;
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (a[index] > a[parentIndex])
            {
                swap(a[index], a[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
};
int main()
{
    Heap h;
    h.a[0] = -1;
    h.a[1] = 100;
    h.a[2] = 50;
    h.a[3] = 60;
    h.a[4] = 40;
    h.a[5] = 45;
    h.size = 5;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.a[i] << " ";
    }
    cout << endl;
    h.insert(110);
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.a[i] << " ";
    }
    cout << endl;
}