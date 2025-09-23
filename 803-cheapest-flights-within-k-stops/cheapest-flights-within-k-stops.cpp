class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }

        queue<pair<int,pair<int,int>>>q;

        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{0,src}});

        while(!q.empty()){
            auto p=q.front();q.pop();
            int stop=p.first;
            int node=p.second.second;
            int d=p.second.first;
            
            if(stop>k || node==dst)continue;

            for(auto it:adj[node]){
                int wt=it.second;
                int nn=it.first;
                int newd=d+wt;
                if(dist[nn] > newd){
                    dist[nn] = newd;
                    q.push({stop+1,{newd,nn}});
                }
            }
        }
        if(dist[dst] == INT_MAX)
        return -1;
        return dist[dst];
    }
};