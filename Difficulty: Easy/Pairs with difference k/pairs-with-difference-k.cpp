//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> freq;
        int count = 0;

        for (int num : arr) {
            freq[num]++;
        }

        for (int num : arr) {
            // Check for num + k
            if (freq.find(num + k) != freq.end()) {
                count += freq[num + k];
            }
            // Check for num - k
            if (freq.find(num - k) != freq.end()) {
                count += freq[num - k];
            }
            // Decrement the frequency to avoid double counting
            freq[num]--;
        }

        return count;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends