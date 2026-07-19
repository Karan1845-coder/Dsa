class Solution {
public:
    string simplifyPath(string path) {

        vector<string> st;
        string cur = "";

        for (int i = 0; i <= path.size(); i++) {

            if (i == path.size() || path[i] == '/') {

                if (cur == "" || cur == ".") {
                    // Ignore
                }
                else if (cur == "..") {
                    if (!st.empty())
                        st.pop_back();
                }
                else {
                    st.push_back(cur);
                }

                cur = "";
            }
            else {
                cur += path[i];
            }
        }

        if (st.empty())
            return "/";

        string ans = "";

        for (string dir : st)
            ans += "/" + dir;

        return ans;
    }
};