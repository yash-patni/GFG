//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        
        // Vector to store the result.
        vector<int> ans(n);
        
        // The last element will always have -1 as its next greater element.
        ans[n-1] = -1;
        
        // Push the last element onto the stack.
        st.push(arr[n-1]);
        
        // Traverse the array from the second last element to the first.
        for(int i = n-2; i >= 0; --i) {
            // Pop elements from the stack until the top is greater than the current element.
            while(!st.empty() and st.top() <= arr[i]) {
                st.pop();
            }
            
            // If the stack is empty, no greater element exists.
            if(st.empty()) {
                ans[i] = -1;
            } else {
                // The top of the stack is the next greater element.
                ans[i] = st.top();
            }
            
            // Push the current element onto the stack for future comparisons.
            st.push(arr[i]);
        }
        
        // Return the result vector.
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends