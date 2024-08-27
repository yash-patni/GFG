//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                left[i]=arr[i-1];
            }
            else{
                int j=i-1;
                while(j>=0){
                    if(left[j]<arr[i]){
                        left[i]=left[j];
                        break;
                    }
                    j--;
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                right[i]=arr[i+1];
            }
            else{
                int j=i+1;
                while(j<n){
                    if(right[j]<arr[i] ){
                        right[i]=right[j];
                        break;
                    }
                    j++;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans, abs(left[i]-right[i]));
        }
        return ans;
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
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends