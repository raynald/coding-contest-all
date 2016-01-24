#include<bits/stdc++.h>

using namespace std;

struct cmp {
    int x;
    int y;
};

int T;
int N;
map<int, vector<cmp> > m;
vector<cmp> v;
vector<cmp> tmp;
long long ans;

const int Maxn = 1e6 + 10;
const int MAXN = 1e9 + 7;

bool comp(const cmp &p, const cmp &q) {
    return p.x < q.x;
}

class SegmentTree {
private:
    struct TreeNode {
        int left, right;
        int max;
    };
    TreeNode tree[Maxn];
    
public:
    SegmentTree() { }
    
    void clear() {
        memset(tree, 0, sizeof(tree));
    }

    void Build(int node_num, int left_branch, int right_branch) {
        tree[node_num].left = left_branch;
        tree[node_num].right = right_branch;
        //cerr << "node:" << node_num << " " << tree[node_num].left << " " << tree[node_num].right << " " << left_branch<<" " << right_branch<< endl;
        if (right_branch - left_branch >= 1) {
            int mid = (left_branch + right_branch) >> 1;
            tree[node_num].left = left_branch;
            Build(2 * node_num + 1, left_branch, mid);
            tree[node_num].right = right_branch;
            Build(2 * node_num + 2, mid + 1, right_branch);
            tree[node_num].max = max(tree[2*node_num+1].max, tree[2*node_num+2].max);
        } else {
            tree[node_num].left = tree[node_num].right = left_branch;
            tree[node_num].max = v[left_branch].y;
        }
    }
    
    int Query(int node_num, int left_branch, int right_branch) {
        //cerr << "node:" << node_num << " " << tree[node_num].left << " " << tree[node_num].right << " " << left_branch<<" " << right_branch<< endl;
        if (tree[node_num].left == left_branch && tree[node_num].right == right_branch) {
            return tree[node_num].max;
        }
        int mid = (tree[node_num].left + tree[node_num].right)/2;
        if (left_branch > mid) {
            return Query(2 * node_num + 2, left_branch, right_branch);
        } else if (right_branch <= mid) {
            return Query(2 * node_num + 1, left_branch, right_branch);
        } else {
            return max(Query(2 * node_num + 1, left_branch, mid), Query(2 * node_num + 2, mid + 1, right_branch));
        }
    }
};

SegmentTree s;

long long calc(vector<cmp> &in) {
    /*
    for(int i=0;i<in.size();i++) {
        cerr<<i<<" " << in[i].y<<endl;
    }
    */
    long long sum = 0, ta = 0;
    for(int i = 0;i < in.size();i ++) {
        for(int j = i+1;j < in.size();j ++) {
            ta = in[j].y - in[i].y;
            sum = (sum + ta * ta) % MAXN;
        }
    }
    return sum;
}

int main() {
    int a, b;

    ios::sync_with_stdio(false);

    cin >> T;
    tmp.clear();
    for (int testcase = 1;testcase <= T;testcase ++) {
        cin >> N;
        m.clear();
        v.clear();
        for(int i=0;i<N;i++) {
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end(), comp);
        /*
        for(int i= 0;i<N;i++) {
            cerr << i << " " << v[i].x << " " << v[i].y << endl;
        }
        */
        s.clear();
        s.Build(0, 0, N - 1);
        ans = 0;
        for (int i = 0;i<N;i++) {
            //cerr << "i" << i << endl;
            int now = v[i].y;
            auto pnt = m.find(now);
            if (pnt == m.end() || s.Query(0, m[now].back().x, i) > now) {
                if(pnt != m.end()) {
                    ans = (ans + calc(m[now])) % MAXN;
                    m[now].clear();
                } else {
                    m[now] = tmp;
                }
            } 
            m[now].push_back({i, v[i].x});
            //cerr << m[now].size() << endl;
        }
        for (auto p = m.begin(); p != m.end(); p++) {
            ans = (ans + calc(p->second)) % MAXN;
        }
        cout << "Case #" << testcase << ": " <<  ans << endl;
    }

    return 0;
}
