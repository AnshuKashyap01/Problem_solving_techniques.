class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char it : s) {

            // Opening brackets
            if (it == '(' || it == '[' || it == '{') {
                st.push(it);
            }

            // Closing brackets
            else {
                if (st.empty())
                    return false;

                if (it == ')' && st.top() != '(')
                    return false;

                if (it == ']' && st.top() != '[')
                    return false;

                if (it == '}' && st.top() != '{')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};