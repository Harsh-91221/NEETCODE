#include <bits/stdc++.h>
using namespace std;
void sortedInsertion(stack<int> &st, int element)
{
    if (st.empty() || st.top() < element)
    {
        st.push(element);
        return;
    }
    int top_element = st.top();
    st.pop();
    // recursive call
    sortedInsertion(st, element);
    st.push(top_element);
}

void sortStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }
    int element = st.top();
    st.pop();
    // recursive call
    sortStack(st);
    sortedInsertion(st, element);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        stack<int> st;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int ele;
            cin >> ele;
            st.push(ele);
        }
        sortStack(st);
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    return 0;
}