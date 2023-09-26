#include <bits/stdc++.h>
using namespace std;
vector<int> segmentTree;
void buildSegmentTree(int start, int end, int currentIndex, vector<int> &array)
{
    if (start == end)
    {
        segmentTree[currentIndex] = array[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildSegmentTree(start, mid, 2 * currentIndex + 1, array);
    buildSegmentTree(mid + 1, end, 2 * currentIndex + 2, array);
    segmentTree[currentIndex] = segmentTree[2 * currentIndex + 1] & segmentTree[2 * currentIndex + 2];
}
int query(int start, int end, int currentIndex, int queryStart, int queryEnd)
{
    if (queryStart <= start && queryEnd >= end)
        return segmentTree[currentIndex];
    if (queryStart > end || queryEnd < start)
        return INT_MAX;
    int mid = start + (end - start) / 2;
    int leftResult = query(start, mid, 2 * currentIndex + 1, queryStart, queryEnd);
    int rightResult = query(mid + 1, end, 2 * currentIndex + 2, queryStart, queryEnd);
    return leftResult & rightResult;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int arraySize;
        cin >> arraySize;
        vector<int> array(arraySize);
        for (int i = 0; i < arraySize; ++i)
        {
            cin >> array[i];
        }
        int queries;
        cin >> queries;
        segmentTree.resize(4 * arraySize);
        buildSegmentTree(0, arraySize - 1, 0, array);
        while (queries--)
        {
            int startRange, kValue;
            cin >> startRange >> kValue;
            startRange--;
            int high = arraySize - 1;
            int low = startRange;
            int answer = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                int currentResult = query(0, arraySize - 1, 0, startRange, mid);
                if (currentResult >= kValue)
                {
                    low = mid + 1;
                    answer = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if (answer >= 0)
                answer += 1;
            cout << answer << " ";
        }
        cout << "\n";
    }
    return 0;
}
