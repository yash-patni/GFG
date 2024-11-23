//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &a) {
        // code here...
        int sum = 0;
        int ans = 0;
        int maxi = a[0];// Initialize with the first element
        int n=a.size();
        for (int i = 1; i < n; ++i) {
            maxi = max(maxi, (int)a[i]);  // Find the overall maximum element
        }

        if (maxi < 0) {
            return maxi;  // If all elements are negative, return the maximum (which is the minimum negative element)
        }

        for (int i = 0; i < n; i++) {
            sum = sum + a[i];
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;  // Reset sum to 0 if it becomes negative
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends