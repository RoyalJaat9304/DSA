class Solution {
    public String reverseWords(String s) {
        String ans="";
        String word="";
        for(int i=0;i<s.length();i++){
            if(i==0 && s.charAt(i) == ' ')
            continue;
            else if(s.charAt(i) == ' ' && s.charAt(i-1) == ' ')
            continue;
            else if(s.charAt(i) == ' '){
                ans = word+" "+ans;
                word="";
            }
            else{
                word+=s.charAt(i);
            }
        }
        if(word.length() != 0)
        ans = word+" "+ans;
        return ans.substring(0,ans.length()-1);
    }
}