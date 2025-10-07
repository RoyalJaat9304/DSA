class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans=1;
        int up=m+n-2;
        int down=min(m,n)-1;
        for(int i=0;i<down;i++){
            ans=ans*(up-i)/(i+1);
        }
        return ans;
    }
};