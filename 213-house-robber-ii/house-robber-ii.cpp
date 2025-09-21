class Solution {
public:
    int robhelper(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        
        if(nums.size() == 1)
        return nums[0];
        
        for(int i = 0;i<nums.size();i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=nums.size()-1)temp2.push_back(nums[i]);
        }
        return max(robhelper(temp1),robhelper(temp2));
    }
};