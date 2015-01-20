//////////////////////
// SUBMIT THIS FILE //
//////////////////////

#include "surveillanceLib1.hpp"
#include<cstring>

#include <vector>

/*
 *
 * INPUT:
 * -> network
 *  This is the graph (or network) represented as adjacency list. First index
 *  to this array is node number, which means that nodes are numbered in the 
 *  interval 0..network.size()-1. If first index is 'i', then second index is
 *  used to access all the neighbours of node 'i'. 
 *
 *  -> terminal_heidi
 *  Index of heidi's (terminal) node
 *
 *  -> terminal_friend
 *  Index of friend's (terminal) node
 *
 *  OUTPUT:
 *  true if the call is possible
 *  false if the call is not possible
 *
 */

int p, q;
std::vector<std::vector<int> > n;
bool v[1010];

bool search(int x) {
    int t;
    for(int i = 0;i<n[x].size();i++) {
        t = n[x][i];
        if(v[t]) continue;
        v[t] = 1;
        if(t==q) return 1;
        if(search(t)) return 1;
    }
    return 0;
}
bool is_call_possible(const std::vector<std::vector<int> >& network,
                    int terminal_heidi, int terminal_friend) {
    n = network;
    p = terminal_heidi;
    q = terminal_friend;
    memset(v,0,sizeof(v));
    v[p] = 1;
    return search(p);
}

