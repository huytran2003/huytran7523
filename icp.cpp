#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

const int MOD = 998244353;
#define SQR(x) (1LL * (x) * (x))
void add(int &x, const int &y) {
    x += y;
    while (x >= MOD) x -= MOD;
}
void sub(int &x, const int &y) {
    x -= y;
    while (x < 0) x += MOD;
}

#define BLACK   false
#define WHITE   true
struct Node {
    // general
    Node *parent, *child[2];
    // itself
    bool color;
    int length; // without MOD
    // subtree
    int result, prefixLength, suffixLength; // with MOD
    bool prefixColor, suffixColor, solid;
    long long totalLength; // without MOD
    // lazy
    bool flipped;

    Node(int _length = 0, bool _color = BLACK) {
        parent = child[0] = child[1] = nullptr;
        this->color = _color;
        prefixColor = _color;
        suffixColor = _color;
        length = totalLength = _length;
        prefixLength = suffixLength = length % MOD;
        result = SQR(length) % MOD;
        solid = true;
        flipped = false;
    }

    int getDir(Node *p) const {
        if (p == child[0]) return 0;
        if (p == child[1]) return 1;
        assert("not a child" && false);
    }

    void pushUp(void) {
        totalLength = length;
        result = 0;
        solid = true;
        REP(i, 2) if (child[i] != nullptr) {
            totalLength += child[i]->totalLength;
            add(result, child[i]->result);
            solid &= child[i]->solid && child[i]->color == color;
        }
        prefixColor = child[0] == nullptr ? color : child[0]->prefixColor;
        suffixColor = child[1] == nullptr ? color : child[1]->suffixColor;
        prefixLength = child[0] == nullptr ? 0 : child[0]->prefixLength;
        if (child[0] == nullptr || (child[0]->solid && color == prefixColor)) {
            add(prefixLength, length);
            if (child[1] != nullptr && child[1]->prefixColor == prefixColor)
                add(prefixLength, child[1]->prefixLength);
        }
        suffixLength = child[1] == nullptr ? 0 : child[1]->suffixLength;
        if (child[1] == nullptr || (child[1]->solid && color == suffixColor)) {
            add(suffixLength, length);
            if (child[0] != nullptr && child[0]->suffixColor == suffixColor)
                add(suffixLength, child[0]->suffixLength);
        }
        int L = child[0] != nullptr && child[0]->suffixColor == color ? child[0]->suffixLength : 0;
        int R = child[1] != nullptr && child[1]->prefixColor == color ? child[1]->prefixLength : 0;
        result = (result - SQR(L) - SQR(R) + SQR(0LL + L + R + length)) % MOD;
        if (result < 0) result += MOD;
    }

    void pushDown(void) {
        if (!flipped) return;
        REP(i, 2) if (child[i] != nullptr) {
            child[i]->color ^= 1;
            child[i]->prefixColor ^= 1;
            child[i]->suffixColor ^= 1;
            child[i]->flipped ^= 1;
        }
        flipped = false;
    }
};

class SplayTree {
private:
    Node *root;

    void link(Node *a, Node *b, int dir) {
        if (a == nullptr) {
            root = b;
            if (root != nullptr) root->parent = nullptr;
            return;
        }
        a->child[dir] = b;
        if (b != nullptr) b->parent = a;
    }

    void rotate(Node *a, int dir) {
        Node *p = a->parent;
        Node *b = a->child[dir];
        int pdir = p == nullptr ? -1 : p->getDir(a);
        link(a, b->child[dir ^ 1], dir);
        link(b, a, dir ^ 1);
        link(p, b, pdir);
    }

    void splay(Node *a) {
        a->pushDown();
        while (a->parent != nullptr) {
            int dir = a->parent->getDir(a);
            if (a->parent->parent == nullptr) {
                rotate(a->parent, dir);
                a->child[dir ^ 1]->pushUp();
            } else {
                int parDir = a->parent->parent->getDir(a->parent);
                if (parDir == dir) {
                    rotate(a->parent->parent, parDir);
                    rotate(a->parent, dir);
                    a->child[dir ^ 1]->child[parDir ^ 1]->pushUp();
                    a->child[dir ^ 1]->pushUp();
                } else {
                    rotate(a->parent, dir);
                    rotate(a->parent, parDir);
                    REP(i, 2) a->child[i]->pushUp();
                }
            }
            a->pushUp();
        }
    }

    void merge(const SplayTree &t, int dir) {
        if (t.root == nullptr) return;
        if (root == nullptr) {
            root = t.root;
            return;
        }
        Node *p = root;
        while (p->child[dir] != nullptr) {
            p->pushDown();
            p = p->child[dir];
        }
        splay(p);
        link(p, t.root, dir);
        p->pushUp();
    }

    SplayTree splitLeft(long long x) {
        if (x == 0) return SplayTree();
        assert(root != nullptr);
        if (x == root->totalLength) {
            Node *p = root;
            root = nullptr;
            return SplayTree(p);
        }

        Node *p = root;
        while (true) {
            p->pushDown();
            long long left = p->child[0] == nullptr ? 0 : p->child[0]->totalLength;
            if (left >= x) p = p->child[0];
            else if (left + p->length < x) {
                x -= left + p->length;
                p = p->child[1];
            } else {
                x -= left;
                splay(p);
                break;
            }
        }
        if (x == p->length) {
            p->pushDown();
            Node *right = p->child[1];
            right->parent = p->child[1] = nullptr;
            p->pushUp();
            root = right;
            return SplayTree(p);
        } else {
            p->pushDown();
            Node *left = p->child[0];
            Node *right = p->child[1];
            bool color = p->color;
            Node *other = new Node(p->length - x, color);
            *p = Node(x, color);
            root = other;
            link(other, right, 1);
            link(p, left, 0);
            other->pushUp();
            p->pushUp();
            return SplayTree(p);
        }
    }

public:
    SplayTree(Node *root = nullptr) {
        this->root = root;
        if (root != nullptr) root->parent = nullptr;
    }

    void init(const string &s) {
        vector<int> sta, fin;
        REP(i, s.size()) {
            if (i == 0 || s[i] != s[i - 1]) sta.push_back(i);
            if (i + 1 == (int)s.size() || s[i] != s[i + 1]) fin.push_back(i);
        }
        REP(i, sta.size()) {
            Node *node = new Node(fin[i] - sta[i] + 1, s[sta[i]] == 'B' ? BLACK : WHITE);
            merge(SplayTree(node), 1);
        }
    }

    void insert(long long x, int k, bool color) {
        SplayTree left = splitLeft(x);
        Node *node = new Node(k, color);
        merge(SplayTree(node), 0);
        merge(left, 0);
    }

    void remove(long long x, long long k) {
        SplayTree left = splitLeft(x - 1);
        splitLeft(k);
        merge(left, 0);
    }

    void flipColor(long long x, long long k) {
        SplayTree left = splitLeft(x - 1);
        SplayTree mid = splitLeft(k);
        if (mid.root != nullptr) {
            mid.root->flipped ^= 1;
            mid.root->color ^= 1;
            mid.root->prefixColor ^= 1;
            mid.root->suffixColor ^= 1;
        }
        merge(mid, 0);
        merge(left, 0);
    }

    int calcResult(long long x, long long k) {
        SplayTree left = splitLeft(x - 1);
        SplayTree mid = splitLeft(k);
        int res = mid.root == nullptr ? 0 : mid.root->result;
        merge(mid, 0);
        merge(left, 0);
        return res;
    }
};

char input[200200];
void process(void) {
    int n, q; scanf("%d%d", &n, &q);
    scanf("%s", input);

    SplayTree tree;
    tree.init(string(input, input + n));

    REP(love, q) {
        char type[3];
        memset(type, 0, sizeof type);
        long long x, k;
        scanf("%s", type);
        scanf("%lld%lld", &x, &k);
        if (type[0] == 'I') {
            char col[3];
            memset(col, 0, sizeof col);
            scanf("%s", col);
            tree.insert(x, k, col[0] == 'B' ? BLACK : WHITE);
        } else if (type[0] == 'D') tree.remove(x, k);
        else if (type[0] == 'F') tree.flipColor(x, k);
        else printf("%d\n", tree.calcResult(x, k));
    }
}

int main(void) {
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
