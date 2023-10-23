bool comp(string &a,string &b)
{
    if(a.size()!=b.size())
    {
        return a.size()<b.size();
    }
    return a<b;
}