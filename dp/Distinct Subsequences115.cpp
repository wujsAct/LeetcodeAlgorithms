/**
@time:2016/10/23
@funtion 
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
@need to attention： 特殊情况讨论slent==0 || tlent == 0
@利用DP去解决问题，将问题分解成2个小问题,基础的DP问题.
dp[slent,tlent]=dp[slent-1][tlent]
注意:i=1;j=1下标开始的
dp[i][j] = dp[i-1][j]
if S[i-1]==T[j-1]:
  dp[i][j] += dp[i-1][j-1]
**/

class Solution {
public:
    int numDistinct(string s, string t) {
        int slent = s.size();
        int tlent = t.size();
        if(slent==0 || tlent == 0)
            return 0;
        int dp[slent+1][tlent+1];
        int i,j;
        //initialize
        for (i=0;i<=slent;i++){
            dp[i][0]=1;
        }
        
        for(i = 1;i<=slent;i++){
            for(j=1;j<=tlent;j++){
                dp[i][j]=dp[i-1][j];
                //cout <<s[i-1]<<endl;
                //cout <<s[j-1]<<endl;
                if (s[i-1]==t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[slent][tlent];
     }
};