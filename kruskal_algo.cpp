#include<bits/stdc++.h>
using namespace std;

int adge=5;
vector<vector<int>>v_(adge,vector<int>(3,0));
vector<int>rank_(adge,0);                        
vector<int>parent_(adge);

bool sort_by_column(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];
}
int find_parent(int node)
{
    if(parent_[node] == node)
    {
        return node;
    }
    parent_[node]=find_parent(parent_[node]);      //********
    return parent_[node];
}
void make_union(int u,int v)
{
    int a=find_parent(u);
    int b=find_parent(v);
    if(rank_[a] == rank_[b])
    {
        parent_[b]=a;
        rank_[a]++;
    }
    else if(rank_[a]>rank_[b])         //no need to increase the rank: big graph(parent) -connect to-> small graph(node) =no depth increased
    {
        parent_[b]=a;
    }
    else                                    //no need to increase the rank 
    {
        parent_[a]=b;
    }
}
int minimun_spaning_tree()
{
    int ans=0;
    for(int i=0;i<adge;i++)
    {
        int a=find_parent(v_[i][0]);
        int b=find_parent(v_[i][1]);
        if(a!=b)                                //if both parent of both the node are same no need for union(already graph me hai)
        {
            make_union(v_[i][0],v_[i][1]);
            ans=ans+v_[i][2];
        }
    }
    return ans;
}
int main()
{
    int u,v,w;//w ==weight
    for(int i=0;i<adge;i++)                        //first node starting from == 0
    {                                              // pre-define
        parent_[i]=i;
    }
    for(int i=0;i<adge;i++)                         //input
    {
        cin>>w>>v>>u;
        v_[i][0]=u;
        v_[i][1]=v;
        v_[i][2]=w;
    }
    sort(v_.begin(),v_.end(),sort_by_column);       //sort by weight
    cout<<"minimun_spaning_tree="<<minimun_spaning_tree()<<endl;
    return 0;
}