#include "cryptoLib2.hpp"
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

// Returns a key such that applying the key twice to encrypt the plaintext
// results in the cyphertext.

string find_key(string plaintext, string cyphertext) {
    int n = plaintext.length();
    int p,q;
    int k[n+10];
    bool vis[n+10];
    bool flag;
    int kk[n+10];
    int x;
    vector<int> v;
    vector<vector<int> > vv;

    for(int i=n-1;i>=0;i--) {
        if(plaintext[i]=='_') p = 0; else p = plaintext[i] - 'a'+1;
        if(cyphertext[i]=='_') q = 0; else q = cyphertext[i] - 'a'+1;
        kk[p] = q;
    }
    memset(vis,0,sizeof(vis));
    memset(k,-1,sizeof(k));
    vv.clear();
    for(int i=0;i<=26;i++) {
        if(vis[i]) continue;
        x = i;
        v.clear();
        v.push_back(i);
        vis[i] = 1;
        while(kk[x]!=i) {
            x = kk[x];
            vis[x] = 1;
            v.push_back(x);
        }
        if(v.size()%2) {
            for(int i=0;i<v.size();i++ ) {
                int bs;
                bs = v[(i+(v.size()+1)/2)%v.size()];
                k[v[i]] = bs;
            }
        }
        else {
            flag = 0;
            for(int i=0;i<vv.size();i++) {
                if(vv[i].size()==v.size()) {
                    for(int j=0;j<v.size()-1;j++) {
                        k[vv[i][j]]=v[j];
                        k[v[j]] = vv[i][j+1];
                    }
                    k[vv[i][v.size()-1]] = v[v.size()-1];
                    k[v[v.size()-1]] = vv[i][0];
                    vv[i].clear();
                    flag = 1;
                    break;
                }
            }
            if(!flag) vv.push_back(v);
        }
    }
    string ans = "";
    for(int i=0;i<=26;i++) {
        if(k[i]==0) ans+='_';
        else ans += char(k[i]+'a'-1);
    }
    return ans;
}
