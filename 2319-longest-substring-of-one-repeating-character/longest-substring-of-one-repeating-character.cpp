class Solution {
public:
    struct Node {
        int pre, suf, mx, len;
        char lc, rc;
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        Node c;
        c.len = a.len + b.len;
        c.lc = a.lc;
        c.rc = b.rc;

        c.pre = a.pre;
        c.suf = b.suf;
        c.mx = max(a.mx, b.mx);

        if (a.rc == b.lc) {
            c.mx = max(c.mx, a.suf + b.pre);

            if (a.pre == a.len)
                c.pre = a.len + b.pre;

            if (b.suf == b.len)
                c.suf = b.len + a.suf;
        }

        return c;
    }

    void build(int i, int l, int r) {
        if (l == r) {
            tree[i] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int m = (l + r) / 2;

        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);

        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[i] = {1, 1, 1, 1, ch, ch};
            return;
        }

        int m = (l + r) / 2;

        if (pos <= m)
            update(2 * i, l, m, pos, ch);
        else
            update(2 * i + 1, m + 1, r, pos, ch);

        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        this->s = s;

        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1,
                   queryIndices[i], queryCharacters[i]);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};