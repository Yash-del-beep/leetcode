class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;
        

        for(char ch:s){
            freq[ch]++;
        }
        for(char ch:t){
            freq[ch]--;
        }
        for(auto count:freq){
            if(count.second!=0){
                return false;
            }
        }
        return  true;
        
    }
};