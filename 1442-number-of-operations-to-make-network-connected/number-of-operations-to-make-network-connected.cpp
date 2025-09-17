class Solution {
public:
    int findpar(int i,vector<int>& parent){
        if(parent[i] == i)return i;
        return parent[i]=findpar(parent[i],parent);
    }
    void Union(int u,int v,vector<int>& parent,vector<int>& rank){
        int pu=findpar(u,parent);
        int pv=findpar(v,parent);
        if(pu == pv){
            return;
        }
        if(rank[pu] < rank[pv])
        parent[pu] = pv;
        else if(rank[pu] > rank[pv])
        parent[pv] = pu;
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
        return -1;
        vector<int>parent(n),rank(n,0);
        int e=connections.size();
        for(int i=0;i<n;i++)
        parent[i]=i;
        for(int i=0;i<e;i++){
            Union(connections[i][0] , connections[i][1] , parent,rank);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(findpar(i,parent) == i)
            cnt++;
        }
        return cnt-1;
    }
};