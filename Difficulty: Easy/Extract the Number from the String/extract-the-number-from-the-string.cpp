//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {
        int i=0;
        long long ans=INT_MIN;
        string temp;
        bool check=false;
        while(i<s.size()){
            check=false;
            while(i<s.size() && !(s[i]>='0' && s[i]<='9')) i++;
            while(i<s.size() && s[i]>='0' && s[i]<='9'){
                  if(s[i]=='9'){
                      check = true;
                  }
                  temp.push_back(s[i]);
                  i++;
            }
            if(!check && !temp.empty()){
                 ans = max(ans,stoll(temp));
            }
            temp="";
        }
        if(ans==INT_MIN) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends