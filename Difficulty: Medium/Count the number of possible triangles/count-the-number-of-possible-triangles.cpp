//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& a) {
        // code here
        int ans=0;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                int p=lower_bound(a.begin()+j,a.end(),a[i]+a[j])-a.begin();
                if(p-1-j>0)ans+=p-1-j;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
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
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends