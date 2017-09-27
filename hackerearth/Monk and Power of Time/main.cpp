#include <iostream>
#include <queue>

using namespace std;

queue <int> q;

int n,x,i,step;

int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>x;
        q.push(x);
    }

    for(i=1;i<=n;++i)
    {
        cin>>x;
        while(q.front()!=x)
        {
            q.push(q.front());
            q.pop();
            ++step;
        }
        q.pop();
        ++step;
    }
    cout<<step;
    return 0;
}
