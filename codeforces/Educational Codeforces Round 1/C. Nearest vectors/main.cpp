#include <iostream>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<pair<long double,int>> v;
#define PI 3.14159265359

int main()
{
    long double minn=5*PI;
    pair<int,int> res;
    int i,n,x,y;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>x>>y;
        v.push_back({atan2((long double)y,(long double)x),i});
        if(v.back().first<0) v.back().first+=2*PI;
    }

    sort(v.begin(),v.end());
    v.push_back(v.front());
    v.back().first+=2*PI;

    for(i=1;i<v.size();++i)
        if(v[i].first-v[i-1].first<minn)
        {
            minn=v[i].first-v[i-1].first;
            res={v[i].second,v[i-1].second};
        }

    cout<<res.first<<' '<<res.second;

    return 0;
}
