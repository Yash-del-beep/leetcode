class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string final;
        int n=max(word1.size(),word2.size());
        
        for(int p=0;p<n;p++){
            if(p<word1.length()){
                final+=word1[p];
            }if(p<word2.length()){
                final+=word2[p];
            }
        }
        return final;
        
    }
};