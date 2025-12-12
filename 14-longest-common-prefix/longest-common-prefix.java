class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        int cnt=0,n=strs.length;
        for(int i=0;i<Math.min(strs[0].length() , strs[n-1].length());i++){
            if(strs[0].charAt(i) != strs[n-1].charAt(i))
            break;
            cnt++;
        }
        return strs[0].substring(0,cnt);
    }
}