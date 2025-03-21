//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        vector<int>dp1(n,0);
        dp1[0]=arr[0];
        for(int i=1;i<n-1;i++)
        {
            if(i==1)
            {
                dp1[i]=max(dp1[i-1],arr[i]);
            }
            else
            {
                dp1[i]=max(dp1[i-1],dp1[i-2]+arr[i]);
            }
        }
        vector<int>dp2(n,0);
        for(int i=1;i<n;i++)
        {
            if(i==1)
            {
                dp2[i]=arr[i];
            }
            if(i==2)
            {
               dp2[i]=max(dp2[i-1],arr[i]); 
            }
            else
            {
                dp2[i]=max(dp2[i-1],arr[i]+dp2[i-2]);
            }
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends