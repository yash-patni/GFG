class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
         vector<int> ans;
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int curr = n;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]>=x){
                curr = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        int i = curr-1;
        int j = curr;
        if(j<n &&arr[j] == x){
            j++;
        }
        while(ans.size()<k){
            if(i<0){
                if(j<n){
                    ans.push_back(arr[j]);
                    j++;
                }
                else{
                    break;
                }
            }
            else if(j>=n){
                if(i>=0){
                    ans.push_back(arr[i]);
                    i--;
                }
                else{
                    break;
                }
            }
            else{
                int r;
                if(arr[i]>x){
                    r = arr[i]-x;
                }
                else{
                    r = x-arr[i];
                }
                int y ;
                if(arr[j]>x){
                    y = arr[j]-x;
                }
                else{
                    y = x-arr[j];
                }
                if(r>=y){
                    ans.push_back(arr[j]);
                    j++;
                }
                else{
                    ans.push_back(arr[i]);
                    i--;
                }
            }
        }
        return ans;
    }
};