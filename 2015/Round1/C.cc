#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

typedef int ll;

const ll BIG = ll(1e9+7);

ll f[2001][2001][2];

int main() {
    int T;
    int a, b;

    scanf("%d", &T);
    memset(f, 0, sizeof(f));
    f[0][0][1] = f[0][0][0] = 0;
    for(int i=1;i<=2000;i++) {
        f[i][0][0] = 1;
        f[i][0][1] = 0;
        for(int j=1;j<i;j++) {
            f[i][j][0] = f[i][j-1][0];
            if (i>j+1) f[i][j][0] = (f[i][j][0] + f[i-1][j][0]) % BIG;
            f[i][j][1] = f[j+1][j-1][0];
        }
    }
    for(int testcase = 1;testcase <= T; testcase++) {
        scanf("%d-%d", &a, &b);
        printf("Case #%d: %d %d\n", testcase, f[a][b][0], f[a][b][1]);
    }
    return 0;
}
