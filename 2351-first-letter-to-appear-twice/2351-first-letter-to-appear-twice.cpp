class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> freq;
        for(char ch:s){
            freq[ch]++;
            if(freq[ch]==2){
                return ch;
            }
        }
        return -1;
    }
};