class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,long long>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,1e18);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            int node=pq.top().second;
            long long d=pq.top().first;
            pq.pop();

            if(d > dist[node]) continue; 

            for(auto it:adj[node]){
                int nnode=it.first;
                long long wt=it.second;
                if(d + wt < dist[nnode]){
                    dist[nnode]=d+wt;
                    ways[nnode] = ways[node];
                    pq.push({d+wt,nnode});
                }
                else if(d+wt == dist[nnode]){
                    ways[nnode] =(ways[nnode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};