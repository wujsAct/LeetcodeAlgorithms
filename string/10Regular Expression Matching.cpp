#2016/10/29 日
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        #注意此处数组的初始化方式！
        vector<vector<bool>> dp (slen+1,vector<bool> (plen+1,false));
        dp[0][0] = true;
        int i,j;
        for(i=0;i<slen+1;i++){
            for(j=1;j<=plen+1;j++){
                if(p[j-1] !='*'){
                    dp[i][j]= i>0 && dp[i-1][j-1] &&(s[i-1]==p[j-1] || p[j-1]=='.');
                }
                #注意当 '*'时可以不取的呢，或者可以取多次，这是我之前那个算法没有考虑到的问题！
                else{
                    dp[i][j]= dp[i][j-2] ||(i>0 && dp[i-1][j] && (s[i-1]==p[j-2] ||p[j-2]=='.'));
                }
            }
        }
        return dp[slen][plen];
    }
};
