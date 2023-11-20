void insertatbottom(stack<int> &s, int element)
{
    if (s.empty())
    {
        s.push(element);
        return;
    }
    int ans = s.top();
    s.pop();
    insertatbottom(s, element);
    s.push(ans);
}
void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertatbottom(stack, num);
}