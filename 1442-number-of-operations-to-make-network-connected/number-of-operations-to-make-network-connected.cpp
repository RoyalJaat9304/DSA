class DisJointSet{
    public:
    vector<int>rank,parent,size;
    DisJointSet(int n ){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node == parent[node])
        return node;
         return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u ,int v){
        int ulp_u = findUPar(u);
        int ulp_v=findUPar(v);
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u]=ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v]=ulp_u;
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        int cnt=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u) == ds.findUPar(v))
            cnt++;
            else{
                ds.unionByRank(u,v);
            }
        }
        int component=0;
        for(int it=0;it<n;it++){
            if(ds.parent[it] == it)
            component++;
        }
        if(component-1 <= cnt)return component-1;
        return -1;
    }
};