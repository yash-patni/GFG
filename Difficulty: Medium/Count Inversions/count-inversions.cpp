//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    void merge(vector<int> &arr,int left,int mid,int right,int &count)
    {
        int j = mid+1;
        for(int i=left;i<=mid;i++)
        {
            while(j<=right && arr[i] > arr[j])
                j++;
            count +=(j-(mid+1));
        }
        sort(arr.begin()+left,arr.begin()+right+1);
    }
    
    void mergeSort(vector<int> &arr,int start,int end,int &count)
    {
        if(start >= end) return;
        
        int mid = start + (end - start)/2;
        mergeSort(arr,start,mid,count);
        mergeSort(arr,mid+1,end,count);
        merge(arr,start,mid,end,count);
    }
    
    int inversionCount(vector<int> &arr) {
        int count = 0;
        mergeSort(arr,0,arr.size()-1,count);
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends