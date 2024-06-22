//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int GCD(int a,int b){
        if(a==0) return b;
        
        if(a==b) return a;
        
        if(b==0) return a;
        
        return GCD(b,a%b);
    }

    long long int InternalCount(long long int p[], long long int q[], long long int r[]) {
        // code here
        long long int area = abs(p[0]*(q[1]-r[1])+q[0]*(r[1]-p[1])+r[0]*(p[1]-q[1]))/2;
        
        long long b1=GCD(abs(p[0]-q[0]), abs(p[1] - q[1]));
        long long b2=GCD(abs(q[0]-r[0]), abs(q[1] - r[1]));
        long long b3=GCD(abs(r[0]-p[0]), abs(r[1] - p[1]));
          
        long long bp=b1+b2+b3;
        
        long long ans=area-bp/2+1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends