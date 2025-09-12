class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

        if(n==1)
        return 1;
        
        int ans=INT_MAX;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        q.push({1,{0,0}});

        while(!q.empty()){
            auto p=q.front();
            int d=p.first;
            int r=p.second.first;
            int c=p.second.second;
            q.pop();

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=r+i;int nc=j+c;
                    if(nr>=0 && nr<n && nc<n && nc>=0 && grid[nr][nc] == 0){
                        if(dist[nr][nc] > d+1){
                        dist[nr][nc] = d+1;
                        q.push({d+1,{nr,nc}});
                        }
                        if(nr == n-1 && nc==n-1)
                        return d+1;
                    }
                }
            }
        }
        return -1;
    }
};