class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> mp;

        int i = 0;
        int j = 0;
        int ans = 0;
        int n = s.size();

        while(i < n){

            while(mp.find(s[i]) != mp.end()){
                mp.erase(s[j]);
                j++;
            }

            mp[s[i]] = 1;

            ans = max(ans, i - j + 1);

            i++;
        }

        return ans;
    }
};