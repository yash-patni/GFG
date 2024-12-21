//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int minR = 0;
        int maxR = mat.size()-1;
        int minC = 0;
        int maxC = mat[0].size()-1;
        int matsize = (maxR+1)*(maxC+1), count = 0;
        
        while(count<matsize){
            for(int j = minC; j<=maxC && count<matsize; j++){
                if(mat[minR][j]==x) return true;
                count++;
            }
            
            minR++;
            
            for(int i = minR; i<=maxR && count<matsize;i++){
                if(mat[i][maxC]==x) return true;
                count++;
            }
            
            maxC--;
            
            for(int j = maxC; j>=minC && count<matsize;j--){
                if(mat[maxR][j]==x) return true;
                count++;
            }
            
            maxR--;
            
            for(int i = maxR; i>=minR && count<matsize ;i--){
                if(mat[i][minC]==x) return true;
                count++;
            }
            
            minC++;
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends