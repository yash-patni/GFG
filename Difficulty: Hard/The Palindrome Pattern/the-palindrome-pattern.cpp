//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPalindrome(vector<int>& arr){
        int sz=arr.size();
        int st=0;
        int ed=sz-1;
        while(st<ed) {
            if (arr[st]!=arr[ed]) return false;
            st++;
            ed--;
        }
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int m=arr.size();
        int n=arr[0].size();
        string ans="-1";
        for(int i=0; i<m; i++){
            if(isPalindrome(arr[i])){
                ans = to_string(i)+" R"; 
                return ans;
            }
        }
        for(int j=0; j<n; j++) {
            vector<int> col;
            for(int i=0; i<m; i++){
                col.push_back(arr[i][j]);
            }
            if(isPalindrome(col)){
                ans = to_string(j)+" C"; 
                return ans;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends