//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& nums) {
        // Your code here
        int n=nums.size();
        if(n==0 || n==1) return n;
        sort(nums.begin(), nums.end());
        int ls=INT_MIN;
        int maxi=1;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]-1==ls){
                count++;
                ls=nums[i];
            }
            else if(nums[i]!=ls){
                count=1;
                ls=nums[i];
            }
            maxi=max(maxi, count);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends