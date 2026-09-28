class Solution {
public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        if (!st.count(endWord))
            return ans;

        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int sz = q.size();
            unordered_set<string> levelVisited;

            while (sz--) {

                string word = q.front();
                q.pop();

                string temp = word;

                for (int i = 0; i < temp.size(); i++) {

                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == original)
                            continue;

                        temp[i] = c;

                        if (!st.count(temp))
                            continue;

                        // First time seeing this word
                        if (!visited.count(temp)) {
                            visited.insert(temp);
                            levelVisited.insert(temp);
                            q.push(temp);

                            parent[temp].push_back(word);
                        }

                        // Another shortest parent
                        else if (levelVisited.count(temp)) {
                            parent[temp].push_back(word);
                        }

                        if (temp == endWord)
                            found = true;
                    }

                    temp[i] = original;
                }
            }

            // Remove only after completing the level
            for (auto& word : levelVisited) {
                st.erase(word);
            }
        }

        if (!found)
            return ans;

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, parent, path, ans);

        return ans;
    }

private:
    void dfs(
        string word,
        string beginWord,
        unordered_map<string, vector<string>>& parent,
        vector<string>& path,
        vector<vector<string>>& ans
    ) {

        if (word == beginWord) {

            vector<string> temp = path;
            reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            return;
        }

        for (auto& p : parent[word]) {

            path.push_back(p);

            dfs(p, beginWord, parent, path, ans);

            path.pop_back();
        }
    }
};