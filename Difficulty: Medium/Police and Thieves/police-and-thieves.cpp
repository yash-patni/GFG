class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int>Pidx,Tidx;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='T'){
                Tidx.push_back(i);
            }
            else{
                Pidx.push_back(i);
            }
        } 
        int j=0;
        for(int i=0;i<Pidx.size();i++){
            if(j>=Tidx.size())break;
            if(Pidx[i]-Tidx[j]>=0){
                if(Pidx[i]-Tidx[j]<=k){
                    // cout<<Pidx[i]<<" "<<Tidx[j]<<'\n';
                    ans++;
                    j++;
                }
                else{
                while(j<Tidx.size() and Tidx[j]<Pidx[i]-k)
                        j++;
                    if(j<Tidx.size() and Pidx[i]-Tidx[j]<=k){
                        ans++;
                        j++;
                    }
                }
            }
            else{
                if(abs(Pidx[i]-Tidx[j])<=k){
                    // cout<<Pidx[i]<<" "<<Tidx[j]<<'\n';
                   ans++;
                   j++; 
                }   
                else{
                    // move i and check
                }
            }
        }
        return ans;
    }
};