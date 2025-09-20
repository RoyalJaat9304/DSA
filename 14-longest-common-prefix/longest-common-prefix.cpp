class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int cnt=0,n=strs.size();
        for(int i=0;i<strs[0].size();i++){
            if(strs[0][i] == strs[n-1][i])
            cnt++;
            else
            break;
        }
        return strs[0].substr(0,cnt);
    }
};