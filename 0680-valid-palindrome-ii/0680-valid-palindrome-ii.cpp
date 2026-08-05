class Solution {
public:
    bool pal(int i,int j,string& s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else {
                bool  f1=pal(i+1,j,s);
                bool f2=pal(i,j-1,s);
                return f1||f2;
            }
        }
        return true;
    }
};