///////////////////////////////////////////
// THIS IS THE ONLY FILE YOU WILL SUBMIT //
///////////////////////////////////////////

#include"quarantineLib3.hpp"

struct TreeNode {
    int left;
    int right;
    bool val;
    TreeNode() {
        val = 0;
    }
};

class STree {
    private:
        TreeNode Tree[1010];
    public:
        STree() {
        }
        void build(int TreeNum, int left, int right) {
            if(left==right) {
                Tree
            }
            memset(Tree, 0, sizeof(Tree));
        }
        void update(int num, int left, int right) {
            if(Tree[num].left == Tree[num].right) {
                Tree[num].val = !Tree[num].val;
            } else {
                int mid = (Tree[num].left + Tree[num].right)/2;
                if(left > mid) {
                    update(2*num+1, left, right);
                } else if(mid<=right) {
                    update(2*num, left, right);
                } else {
                    update(num*2, left, mid);
                    update(num*2+1, mid+1, right);
                }
            }
        }
};

STree s;


void load_picture(int N){
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            mat[i][j] = 0;
        }
    }
}

bool query(int r, int c){
	return mat[r][c];
}

void toggle(int r1, int c1, int r2, int c2){
    for(int i=r1;i<r2;i++) {
        for(int j=c1;j<c2;j++) {
            mat[i][j] = !mat[i][j];
        }
    }
}

