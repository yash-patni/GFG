//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int, int> mpp;
        int n=arr.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int key=arr[i];
            auto it=mpp.find(key);
            if(it==mpp.end()){
                mpp[key]=i;
            }
        }
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi, i-mpp[arr[i]]);
        }
        return maxi;
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends