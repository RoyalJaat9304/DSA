class Solution {
public:
    int fun(vector<int>& nums,int i,vector<int>& dp){
        if( i == 0 || i == 1)
        return nums[i];

        if(dp[i] != -1)
        return dp[i];

        int fs=fun(nums,i-2,dp) + nums[i];
        int ss=INT_MIN;
        if(i > 2)
        ss=fun(nums,i-3,dp) + nums[i];

        return dp[i] = max(fs,ss);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        if(nums.size() == 1)
        return nums[0];
        
        return max(fun(nums,n-1,dp),fun(nums,n-2,dp));
    }
};