class Solution {
    public int maxSubArray(int[] nums) {
        int cursum=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<nums.length;i++){
            
            if(cursum < 0)
            cursum = 0;
            cursum += nums[i];
            maxsum = Math.max(cursum,maxsum);


        }
        return maxsum;
    }
}