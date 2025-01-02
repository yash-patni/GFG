//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        
        //BRUTE FORCE TC : O(N^3)
        // int n=arr.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int sum=0;
        //         for(int k=i; k<=j;k++){
        //             sum+=arr[k];
        //         }
        //         if(sum==k) count++;
        //     }
        // }
        // return count;
        
        //Approach 2 TC: O(n^2)
        // int n=arr.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=arr[j];
        //         if(sum==k) count++;
        //     }
        // }
        // return count;
        
        //Approach 3 Prefix sum method TC:
        int n=arr.size();
        int count=0;
        unordered_map<int, int> mpp;
        int prefSum=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            prefSum+=arr[i];
            int remove = prefSum-k;
            count+=mpp[remove];
            mpp[prefSum]+=1;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends