class Solution {
public:
    bool isPalindrome(string s) {
        string filter;
         for(char ch:s){
            if(isalnum(ch)){
                filter+=tolower(ch);
            }
         }
            int left=0;
            int right=filter.size()-1;
            while(left<=right){
                if(filter[left]!= filter[right]){
                    return false;


                }
                left++;
                right--;
            }
         
         return true;
        
    }
};