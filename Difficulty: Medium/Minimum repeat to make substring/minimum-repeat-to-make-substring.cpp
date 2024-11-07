//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:

    int minRepeats(string A, string B) {

       string t=A;

       int c=1;

       while(t.length()<B.length()){

           t+=A;

           c++;

       }

       while(t.find(B)==string::npos){

           if(t.length()>2*B.length())return -1;

           t+=A;

           c++;

       }

       return c;

       

    }

};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends