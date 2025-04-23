//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int n=arr.size();
        for(int i=0; i<n-1;i++){
            if(arr[i]!=arr[i+1]){
                ans.push_back(arr[i]);
            }
            else if(arr[i]==arr[i+1]){
                i+=1;
            }
            if(ans.size()==2) {
                break;
            }
        }
        if(arr[n-1]!=arr[n-2]) ans.push_back(arr[n-1]);
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends