//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n=arr.size();
        // int sum=(n+1)*(n+2)/2;
        // int suma=0;
        // for(int i=0;i<n;i++){
        //     suma+=arr[i];
        // }
        // return sum-suma;
        
        int xorr=n+1;
        for(int i=0;i<n;i++){
            xorr^=arr[i];
            xorr^=i+1;
        }
        return xorr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNum(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends