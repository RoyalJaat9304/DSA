class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        if(nums.size() == 1)
        return nums[0];

        dp[0]=nums[0];
        dp[1]=nums[1];

        for(int i=2;i<n;i++){
            int fs=dp[i-2]+nums[i];
            int ss=INT_MIN;
            if(i>2)
            ss=dp[i-3]+nums[i];

            dp[i] = max(fs,ss);
        }
        return max(dp[n-1],dp[n-2]);
    }
};