/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include "surveillanceLib2.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>

namespace {

const int MAX_N = 1000;
int vis[MAX_N];

bool dfs(const std::vector<std::vector<int> > &adjacency_list, int node, int clr) {
  if (vis[node] != -1) {
    return vis[node] != -2 && vis[node] != clr;
  }
  vis[node] = clr;
  for (size_t i = 0; i < adjacency_list[node].size(); ++i) {
    if (dfs(adjacency_list, adjacency_list[node][i], clr)) return true;
  }
  return false;
}

}  // anonymous amespace

int main() {
    int N;
    
    int tests;
    std::scanf("%d", &tests);

    while (tests-- > 0) {
      std::scanf("%d", &N);
      std::vector<std::vector<int> > adjacency_list(N);
      for (int i = 0; i < N; ++i) {
        int neighbors;
        std::scanf("%d", &neighbors);
        adjacency_list[i].reserve(neighbors);
        while (neighbors-- > 0) {
          int node = -1;
          std::scanf("%d", &node);
          adjacency_list[i].push_back(node);
        }
      }
      std::vector<int> friends;
      int friends_cnt = 0;
      std::scanf("%d", &friends_cnt);
      friends.reserve(friends_cnt);
      while (friends_cnt-- > 0) {
        int node = -1;
        std::scanf("%d", &node);
        friends.push_back(node);
      }
      std::vector<int> solution = nodes_to_monitor(adjacency_list, friends);
      int to_print = solution.size();
      std::set<int> friends_set(friends.begin(), friends.end());
      memset(vis, -1, sizeof(vis));
      for (size_t i = 0; i < solution.size(); ++i) {
        if (friends_set.count(solution[i])) to_print = -1;
        vis[solution[i]] = -2;
      }
      for (size_t i = 0; to_print >= 0 && i < friends.size(); ++i) {
        if (dfs(adjacency_list, friends[i], i)) {
          to_print = -1;
        }
      }
      std::printf("%d\n", to_print);
    }

    return 0;
}
