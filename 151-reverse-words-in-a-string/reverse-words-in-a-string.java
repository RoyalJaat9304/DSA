class Solution {
    public String reverseWords(String s) {
        StringBuilder ans=new StringBuilder();
        StringBuilder word=new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(i==0 && s.charAt(i) == ' ')
            continue;
            else if(s.charAt(i) == ' ' && s.charAt(i-1) == ' ')
            continue;
            else if(s.charAt(i) == ' '){
                ans.insert(0,word).insert(0," ");
                word.setLength(0);
            }
            else{
                word.append(s.charAt(i));
            }
        }
        if(word.length() != 0)
        ans.insert(0,word).insert(0," ");
        return ans.substring(1);
    }
}