class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans=0;
        Map<Character,Integer> mpp = new HashMap<>();
        int st=0;
        for(int i=0;i<s.length();i++){
            if(mpp.containsKey(s.charAt(i)) && mpp.get(s.charAt(i)) >= st){
                st=mpp.get(s.charAt(i))+1;
            }
            mpp.put(s.charAt(i) , i);
            ans=Math.max(ans,i-st+1);
        }
        return ans;
    }
}