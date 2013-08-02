class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.size(), n = L.size(), len = L[0].size();
        map<string, int> ids;

        vector<int> need(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!ids.count(L[i])) ids[L[i]] = i;
            need[ids[L[i]]]++;
        }

        vector<int> s(m, -1);
        for (int i = 0; i < m - len + 1; ++i) {
            string key = S.substr(i, len);
            s[i] = ids.count(key) ? ids[key] : -1;
        }

        vector<int> ret;
        for (int offset = 0; offset < len; ++offset) {
            vector<int> found(n, 0);
            int count = 0, begin = offset;
            for (int i = offset; i < m - len + 1; i += len) {
                if (s[i] < 0) {
                    // recount
                    begin = i + len;
                    count = 0;
                    found.clear();
                    found.resize(n, 0);
                } else {
                    int id = s[i];
                    found[id]++;
                    if (need[id] && found[id] <= need[id])
                        count++;

                    if (count == n)
                        ret.push_back(begin);

                    // move current window
                    if ((i - begin) / len + 1 == n) {
                        id = s[begin];
                        if (need[id] && found[id] == need[id])
                            count--;
                        found[id]--;
                        begin += len;
                    }
                }
            }
        }
        return ret;
    }
};
