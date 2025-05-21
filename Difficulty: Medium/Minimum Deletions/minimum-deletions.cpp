class Solution {
  public:
    int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
         if(i<0||j<0)return 0;
        int take=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return 1+f(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    }
    int lcs(string s,string t){
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(n-1,n-1,s,t,dp);
        
    } 
    int lps(string s){
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        return lcs(s,t);
    }
    int minDeletions(string s) {
        // code here
        return s.size()-lps(s);
    }
};