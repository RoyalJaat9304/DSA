class Solution {
    public boolean isPalindrome(String s) {
        String temp="";
        for(int i=0;i<s.length();i++){
            if((s.charAt(i) >= 'a' && s.charAt(i) <='z') || (s.charAt(i) >= 'A' && s.charAt(i) <='Z'))
            temp+=Character.toLowerCase(s.charAt(i));
            else if(s.charAt(i) <= '9' && s.charAt(i) >= '0')
            temp+=s.charAt(i);
        }
        int i=0,j=temp.length()-1;
        while(i<j){
            if(temp.charAt(i) != temp.charAt(j))
            return false;
            i++;
            j--;
        }
        return true;
    }
}