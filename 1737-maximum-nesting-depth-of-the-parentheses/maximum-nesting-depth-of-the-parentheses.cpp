class Solution {
public:
    int maxDepth(string s) {
     int maxx = INT_MIN;
    int counter = 0;
    for (auto ch : s)
    {
        if (ch == '(')
        {
            counter++;
        }
        else if (ch == ')')
        {
            counter--;
        }
        maxx = max(maxx, counter);
    }
    return maxx;
    }
};