//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        long exp = e; 
        if (exp < 0) {
            b = 1 / b;
            exp = -exp;
        }
        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= b;
            }
            b *= b;
            exp /= 2;
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends