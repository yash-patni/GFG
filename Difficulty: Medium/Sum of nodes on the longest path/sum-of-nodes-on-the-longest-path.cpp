/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void store(Node* root,vector<pair<int,int>>& ans, int len , int sum){
      if( root ==NULL){
          return;
      }
      sum += root-> data;
      if(root-> left == NULL && root-> right == NULL){
          ans.push_back({len,sum}) ;
      }
      store(root->left, ans,len+1,sum);
      store(root-> right,ans, len+1, sum);
  }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        vector<pair<int,int>> ans;
        store(root, ans, 0 ,0) ;
        int maxi = 0 ;
        int sum = 0;
        
        for(int i = 0 ;i< ans.size();i++){
            if(ans[i].first>maxi){
                maxi=max(maxi,ans[i].first) ;
                sum= ans[i].second;
            }
            if(ans[i].first==maxi){
                sum=max(ans[i].second,sum) ;
            }
        }
        return sum ;
    }
};