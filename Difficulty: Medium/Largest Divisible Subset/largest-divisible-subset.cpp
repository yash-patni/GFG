class Solution {
  public:
    vector<int> largestSubset(vector<int>& nums) {
        // Code here
        sort(nums.rbegin(),nums.rend());
        int n = nums.size();
        vector<int> dp(n,1),hash(n,0);
        int maxi = 0;
        int lastind=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(1 + dp[j] > dp[i] && (nums[i]%nums[j]==0 || nums[j]%nums[i]==0)){
                    dp[i]=1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastind = i;
            }
        }
        vector<int> lds;
        lds.push_back(nums[lastind]);
        while(hash[lastind] != lastind){
            lastind = hash[lastind];
            lds.push_back(nums[lastind]);
        }
        return lds;
    }
};