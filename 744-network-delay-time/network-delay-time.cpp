class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v , wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        dist[k]=0;

        pq.push({0,k});

        while(!pq.empty()){
            auto p=pq.top();
            int node=p.second;
            int d=p.first;
            pq.pop();

            for(auto it:adj[node]){
                int wt=it.second;
                int nn=it.first;
                if(dist[nn] > wt+d){
                    dist[nn] = wt+d;
                    pq.push({wt+d,nn});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        if(ans==1e9)return -1;
        return ans;
    }
};