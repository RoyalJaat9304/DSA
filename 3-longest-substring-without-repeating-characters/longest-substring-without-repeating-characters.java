class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans=0;
        int[] hash = new int[256];
        Arrays.fill(hash,-1);
        int st=0;
        for(int i=0;i<s.length();i++){
            if(hash[s.charAt(i)] >= st){
                st = hash[s.charAt(i)]+1;
            }
            hash[s.charAt(i)] = i;
            ans = Math.max(ans,i-st+1);
        }
        return ans;
    }
}