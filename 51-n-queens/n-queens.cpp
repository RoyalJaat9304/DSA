class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s="";
        for(int i=0;i<n;i++)
        s+='.';
        vector<string>board(n,s);
        vector<int> lr(n,0),ld(2*n-1,0),ud(2*n-1,0);
        helper(0,n,ans,board,lr,ld,ud);
        return ans;
    }
    void helper(int c,int n,vector<vector<string>>& ans,vector<string>& board, vector<int>&lr , vector<int>& ld, vector<int>& ud){
        if(c==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(lr[i] == 0 && ld[i-c+n-1] == 0 && ud[i+c] == 0){
                lr[i] = 1;
                ld[i-c+n-1] = 1;
                ud[i+c] = 1;
                board[i][c] = 'Q';
                helper(c+1,n,ans,board,lr,ld,ud);
                lr[i] = 0;
                ld[i-c+n-1] = 0;
                ud[i+c] = 0;
                board[i][c] = '.';
            }
        }
    }
};