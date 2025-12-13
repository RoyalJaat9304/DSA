class Solution {
    public int secondHighest(String s) {
        char first='0'-1,second='0'-1;
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(c <= '9' && c>='0'){
                if(c > first){
                    second=first;
                    first=c;
                }
                else if(c > second && c < first){
                    second = c;
                }
            }
        }
        int ans=second-'0';
        return ans;
    }
}