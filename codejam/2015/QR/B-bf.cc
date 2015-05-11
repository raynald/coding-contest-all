#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int p[6];
int a, maxx;
int D;
int T;

bool op(int x, int y) {
    return x>y;
}

int search(int x[]) {
    int ans = 2000;
    int temp;
    int y[6];
    if(x[0] == 0) return 0;
    else {
        for(int i=0;i<6;i++) {
            if(x[i]>0) y[i] = x[i]-1; else y[i] = 0;
        }
        sort(y,y+6, op);
        temp = search(y)+1;
        if(temp<ans) ans = temp;
        else {
        }
    }
}

void init() {
    cin >> T;
    for(int testcase=1;testcase<=T;testcase++) {
        cin >> D;
        memset(p,0,sizeof(p));
        for(int i=0;i<D;i++) {
            cin >>p[i]; 
        }
        sort(p,p+6,op);
        cout << "Case #" << testcase << ": " << search(p) << endl;
    }
}

int main() {
    init();
}
