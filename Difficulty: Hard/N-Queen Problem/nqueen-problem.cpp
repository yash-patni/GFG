//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
      vector<int> temp;
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n; row++) {
            if (board[row][col] == 1) {
                temp.push_back(row + 1); // Store 1-based row index
                
            }
        }
    }
    ans.push_back(temp);
}
    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        int x= row;
        int y= col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        x= row;
        y= col;
        //checking for the diognal
        while(x>=0 and y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        //check for the another diognal;
        x= row;
        y= col;
        while(x<n and y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
            
        }
        return true;
    }
    void solve(int col, int n , vector<vector<int>> &board, vector<vector<int>> &ans){
     if(col==n){
         addSolution(ans, board, n);
         return;
     }  
     
     for (int row= 0; row<n; row++){
         if(isSafe(row, col, board, n)){
             board[row][col]=1;
             solve(col+1, n, board, ans);
            board[row] [col]= 0;
         }
     }
    }
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int> (n, 0));
        vector<vector<int>> ans;
        solve(0, n, board, ans); 
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

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends