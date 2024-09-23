//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int rep=-1, miss=-1;;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                rep=arr[i];
                break;
            }
        }
        vector<bool> pres(n+1, 0);
        for(int i=0;i<n;i++){
            pres[arr[i]]=1;
        }
        for(int i=1;i<=n;i++){
            if(!pres[i]){
                miss=i;
                break;
            }
        }
        return {rep, miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends