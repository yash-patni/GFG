//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if(n==1) return "1";
       string temp = "1";
       while(--n)
        {
            string ans = "";
            int first = 0;
            for(int i=1;i<=temp.size();i++)
                {
                    if(i!=temp.size() && temp[i]==temp[i-1])
                        {
                            continue;
                        }
                    else
                    {
                        char val = temp[i-1];
                        int count = i-first;
                        ans.push_back(count+'0');
                        ans.push_back(val);
                        first = i;
                    }
                    
                }
            temp = ans;
                
            
        }
    return temp;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends