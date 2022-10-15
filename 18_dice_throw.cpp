#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>v{0};
int  f(ll x,ll m,ll n)
{
    if(x==0)
    {
        v[0]++;
        return 1;
    }
    else if(n==0)
    {
        return 1;
    }
    else if (n>0)
    {
        for(ll i=1;(i<=x)&&(i<=m);i++)
        {
            f(x-i,m,n-1);
        }
        return 1;
    }
    return 1;
}
int main()
{
    ll n,m,x;
    cout<<"m=";cin>>m;cout<<"\nn=";cin>>n;cout<<"\nx=";cin>>x;
    f(x,m,n);
    cout<<v[0];
    return 0;
}