//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int s = 0; 
        int e=arr.size()-1;
        while(s <= e){
            int mid = (s+e)/2;
            if(arr[mid]==key){
                return mid;
            }
            if(arr[s] <= arr[mid]){
                if(key >= arr[s] && key < arr[mid]){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }else{
                if(key > arr[mid] && key <= arr[e]){
                    s = mid+1;
                }else{
                    e = mid-1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends