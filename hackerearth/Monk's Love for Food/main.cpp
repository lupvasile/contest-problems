#include <iostream>
#include <stack>

using namespace std;

stack <int> st;
int q,x;
int main()
{
    cin>>q;
    for(; q; --q)
    {
        cin>>x;
        if(x==1)
        {
            if(!st.empty())
            {
                cout<<st.top()<<'\n';
                st.pop();
            }
            else cout<<"No Food\n";
        }
        else
        {
            cin>>x;
            st.push(x);
        }
    }
    return 0;
}
