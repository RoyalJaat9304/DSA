class Solution {
public:
    int lengthstr(string s,int st,int end){
        while(st >= 0 && end < s.length() && s[st] == s[end] ){
            st--;
            end++;
        }
        return end-st-1;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int maxlen=0,first;
        for(int i=0;i<n;i++){
            int odd = lengthstr(s,i,i);
            int even=lengthstr(s,i,i+1);
            int l = max(odd , even);
            if(l > maxlen){
                maxlen=l;
                first = i- (l-1)/2;
            }
        }
        return s.substr(first, maxlen);
    }
};