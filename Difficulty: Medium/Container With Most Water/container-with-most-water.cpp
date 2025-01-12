//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0;
        int h=n-1;
        
        long long maxWater = 0;
        
        while(l<h){
        
        long long width = h-l;
        
        long long ht = min(arr[l],arr[h]);
            
        long long currWater = width * ht;
        
        maxWater = max(currWater,maxWater);
        
        arr[l] < arr[h] ? l++ : h--;
        }
        
        return maxWater;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends