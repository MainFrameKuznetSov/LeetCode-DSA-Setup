#include<bits/stdc++.h>
using namespace std;
class DisjointSetUnion
{
public:
    vector<int>prnt,size;
    DisjointSetUnion(int n)
    {
        prnt.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;++i)
            prnt[i]=i;
    }
    int findUPar(int u)
    {
        if(prnt[u]==u)
            return u;
        else
            return prnt[u]=findUPar(prnt[u]);
    }
    void UnionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
            return ;
        if(size[ulp_u]>size[ulp_v])
        {
            prnt[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else
        {
            prnt[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

int main()
{
    DisjointSetUnion dsu(7);
    dsu.UnionBySize(0,1);
    dsu.UnionBySize(2,1);
    dsu.UnionBySize(2,5);
    dsu.UnionBySize(2,3);
    dsu.UnionBySize(1,3);
    dsu.UnionBySize(3,5);
    dsu.UnionBySize(3,7);
    dsu.UnionBySize(4,6);
    if(dsu.findUPar(2)==dsu.findUPar(6))
        cout<<"Same component.\n";
    else    
        cout<<"Not Same.\n";
    dsu.UnionBySize(2,4);
    if(dsu.findUPar(2)==dsu.findUPar(6))
        cout<<"Same component.\n";
    else    
        cout<<"Not Same.\n";
}
