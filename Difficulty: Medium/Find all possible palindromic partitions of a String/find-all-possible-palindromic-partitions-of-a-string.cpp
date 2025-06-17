class Solution {
  private:
    bool isPalindrome(string &s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void solve(string &s, vector<string>&output, int index, vector<vector<string>>&ans){
        if(index >= s.size()){
            ans.push_back(output);
            return;
        }
        
        string str = "";
        for(int i=index; i<s.size(); i++){
            str += s[i];
            if(isPalindrome(s, index, i)){
                output.push_back(str);
                solve(s, output, i+1, ans);
                output.pop_back();
            }
        }
        
    }

  public:
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>>ans;
        vector<string>output;
        int index = 0;
        solve(s, output, index, ans);
        return ans;
    }
};