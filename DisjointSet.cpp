class DisjointSet {
    vector<int>rank,size,prnt;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        prnt.resize(n+1);
        for(int i=0;i<=n;++i)
            prnt[i]=i;
    }

    int findUPar(int u)
    {
        if(u==prnt[u])
            return u;
        return prnt[u]=findUPar(prnt[u]);
    }

    bool find(int u, int v) {
        return findUPar(u)==findUPar(v);
    }

    void unionByRank(int u, int v) {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
            return ;
        if(rank[ulp_u]<rank[ulp_v])
            prnt[ulp_u]=ulp_v;
        else if(rank[ulp_u]>rank[ulp_v])
            prnt[ulp_v]=ulp_u;
        else
        {
            prnt[ulp_v]=ulp_u;
            ++rank[ulp_u];
        }
    }

    void unionBySize(int u, int v) {
       int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v)    
                return ;
            if(size[ulp_u]<size[ulp_v])
            {
                prnt[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else
            {
                prnt[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
    }
};
