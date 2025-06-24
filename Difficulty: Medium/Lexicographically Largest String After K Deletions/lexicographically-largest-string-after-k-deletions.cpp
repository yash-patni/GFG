class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<char> st;
        int n = s.size();
        int count = k;
        
        for(auto i : s){
            if(st.empty()){
                st.push(i);
            }else{
                while(!st.empty() && count>0 && st.top() < i){
                    st.pop();
                    count--;
                }
                st.push(i);
            }
        }
        
        while(st.size() > n-k){
            st.pop();
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
