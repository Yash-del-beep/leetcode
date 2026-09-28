class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;

    bool isPal(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string &s, int i, int n) {
        if (i == n) {
            ans.push_back(curr);
            return;
        }

        for (int j = i; j < n; j++) {
            if (isPal(s, i, j)) {
                string str = s.substr(i, j - i + 1);

                curr.push_back(str);

                solve(s, j + 1, n);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        solve(s, 0, n);

        return ans;
    }
};