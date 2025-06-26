class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        priority_queue<int>pq;
        for(auto pai:mp){
            pq.push(pai.second);
        }
        while(k--){
            int x = pq.top();
            pq.pop();
            if(x > 1)pq.push(x-1);
        }
        int val = 0;
        while(!pq.empty()){
            val += pq.top()*pq.top();
            pq.pop();
        }
        return val;
    }
};