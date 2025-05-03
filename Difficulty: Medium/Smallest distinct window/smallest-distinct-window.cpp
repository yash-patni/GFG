//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_map<char,int> m;
        set<char> s;
        for(auto i:str) s.insert(i);
        
        int i=0,j=0;
        int n = str.size();
        int ans = n;
        for(int j=0;j<n;j++){
            m[str[j]]++;
            while(i<=j && m.size() == s.size()){
                m[str[i]]--;
                if(m[str[i]] == 0) m.erase(str[i]);
                ans = min(ans , j - i + 1);
                i++;
            }
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends