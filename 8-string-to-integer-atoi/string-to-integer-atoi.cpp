class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long ans=0;

        while(s[i] == ' ')
        s.erase(s.begin());
        
        bool sign=false;
        if(s[i] == '-'){
            i=i+1;
            sign=true;
        }
        else if(s[i] == '+')
            i++;
        else
        i=0;

        while(isdigit(s[i]) && i<s.size()){
            ans=ans*10 + (s[i]-'0');
            if(ans>INT_MAX && sign == true)
            return INT_MIN;
            if(ans>INT_MAX && sign == false)
            return INT_MAX;
            i=i+1;
        }
        if(sign==true)
        return -1*ans;
        return ans;    
    }
};