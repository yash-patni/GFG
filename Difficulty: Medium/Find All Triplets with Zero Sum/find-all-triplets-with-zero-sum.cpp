//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void solve(int i, int n, vector<int>& arr, vector<int>& ds, vector<vector<int>>&ans, int sum){
        
        if(ds.size()==3){
            if(sum==0){
                ans.push_back(ds);
            }
            return;
        }
        if(i==n) return;
        ds.push_back(i);
        solve(i+1, n, arr, ds, ans, sum+arr[i]);
        ds.pop_back();
        solve(i+1, n, arr, ds, ans, sum);
        
    }
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>> ans;
        vector<int> ds;
        // sort(arr.begin(), arr.end());
        solve(0, arr.size(), arr, ds, ans, 0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends