//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int row,int col,int index,vector<vector<int>>& vis,vector<vector<char>>& mat,string word){
        int n = mat.size();
        int m = mat[0].size();
        
        if(index==word.size()) return true;
        if(row<0 || row>=n || col<0 || col>=m || vis[row][col] || mat[row][col] != word[index]) return false;
        vis[row][col] = 1;
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];
            if(dfs(nrow,ncol,index+1,vis,mat,word)){
                return true;
            }
        }
        
        vis[row][col] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                    if(dfs(i,j,0,vis,mat,word)) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends