//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int n = arr.size();
        int l = 0,h = n-1;
        vector<int> ans(n,0);
        for(int i = 0; i < n;i++){
            if(arr[i] && arr[i] == arr[i+1]){
                ans[l++] = arr[i]*2;
                ans[h--] = 0;
                i++;
            }
            else if(arr[i])
                ans[l++] = arr[i];
            else if(arr[i] == 0)
                ans[h--] = 0;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends