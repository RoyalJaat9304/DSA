class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || k <= 0) return new int[0];

        Deque<Integer> dq = new ArrayDeque<>();
        int n=nums.length-k+1;
        int[] ans = new int[n];
        for(int i=0;i<nums.length;i++){
            
            // while (!dq.isEmpty() && dq.peekFirst() <= i - k) {
            //     dq.pollFirst();
            // }

            while(!dq.isEmpty() && nums[dq.peekLast()] < nums[i]){
                dq.pollLast();
            }
            if(!dq.isEmpty() && dq.peekFirst() <= i-k)
            dq.poll();

            dq.add(i);
            if(i >= k-1)
            ans[i-k+1]=nums[dq.peek()];
        }
        return ans;
    }
}