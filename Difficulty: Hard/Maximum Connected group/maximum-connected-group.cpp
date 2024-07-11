//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dfs(int ind,int i,int j,vector<vector<int>>&grid){
      if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==ind){
          return 0;
      }
      grid[i][j] = ind;
      int a = dfs(ind,i+1,j,grid);
      int b = dfs(ind,i,j+1,grid);
      int c = dfs(ind,i-1,j,grid);
      int d = dfs(ind,i,j-1,grid);
      return 1 + a+ b+ c+ d;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
         int  n = grid.size();
         int ans =0;
         map<int,int>mpp;
         int ind = 2;
         for(int i=0;i<n;i++){
             for(int j =0;j<n;j++){
                 if(grid[i][j]==1){
                     int grp = dfs(ind,i,j,grid);
                     mpp[ind] = grp;
                     ind ++;
                     ans = max(ans,grp);
                 }
             }
         }
         // ans == max_area without converting from 0 to 1
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if(grid[i][j]==0){
                     int maxi = 0;
                     set<int>st;
                     if(i>0)st.insert(grid[i-1][j]);
                     if(j>0)st.insert(grid[i][j-1]);
                     if(i<n-1)st.insert(grid[i+1][j]);
                     if(j<n-1)st.insert(grid[i][j+1]);
                     for(auto it:st){
                         maxi += mpp[it];
                     }
                     maxi++;
                     ans = max(ans,maxi);
                 }
             }
         }
         return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends