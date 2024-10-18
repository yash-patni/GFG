//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==1) return arr[0];
        sort(arr.begin(), arr.end());
        int curr=arr[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(arr[i]==curr){
                count++;
            }
            else{
                if(count%2==1) return arr[i-1];
                count=1;
                curr=arr[i];
            }
        }
        if(count%2==1) return arr[n-1];
        return -1;
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
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends