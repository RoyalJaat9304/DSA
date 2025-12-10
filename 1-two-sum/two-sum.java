class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer , Integer> mpp = new HashMap<>();
        int[] ans = new int[2];
        for(int i=0;i<nums.length;i++){
            if(mpp.containsKey(target - nums[i])){
                ans[0] = i;
                ans[1] = mpp.get(target - nums[i]);
            }
            else
            mpp.put(nums[i] , i);
        }
        return ans;
    }
}