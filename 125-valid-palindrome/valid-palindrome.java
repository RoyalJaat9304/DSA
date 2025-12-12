class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder temp = new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(Character.isLetterOrDigit(s.charAt(i)))
            temp.append(Character.toLowerCase(s.charAt(i)));
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