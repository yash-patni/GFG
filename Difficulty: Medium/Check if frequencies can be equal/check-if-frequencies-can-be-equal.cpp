class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        int Freq[26]={};
        int num_of_ele = 0;
        
        for(int i = 0;i<s.size();i++){
            Freq[s[i]-'a']++;
        }
        
        set<int> se;
        for(int i = 0;i<26;i++){
            if(Freq[i]>0){
                num_of_ele++;
                se.insert(Freq[i]);
            }
        }
        
        if(se.size() == 1)return true;
        
        if(se.size() == 2){
            if(*next(se.begin(),0) == 1 or 
               *next(se.begin(),1) == 1 or 
               abs(*next(se.begin(),0)-*next(se.begin(),1)) == 0){
                return true;
            }
            
            if((abs(*next(se.begin(),0)-*next(se.begin(),1)) == 1)){
                if(num_of_ele == 2){
                    return true;
                }
                else{
                    return false;
                }
            }
            
            return false;
        }
        
        return false;
        
    }
};