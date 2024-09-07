//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int ans=0;
        int n=arr.size();
        int i=0;
        int mx=INT_MIN;
        int ind=0;
        while(i<n){
            mx=INT_MIN;
            ans++;
            if(arr[i]>=n-1)
             return ans;
            for(int j=i+1;j<n && j<=i+arr[i];j++){
                if(j+arr[j]>=n-1)
                 return ans+1;
                if(arr[j+arr[j]]!=0){
                    if(mx<=(arr[j+arr[j]])){
                        ind=j+arr[j];
                        mx=arr[ind];
                    }
                }
            }
            if(mx==INT_MIN)
             return -1;
            
            i=ind;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends