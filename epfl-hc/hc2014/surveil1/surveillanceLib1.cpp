/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include "surveillanceLib1.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>

const int MAX_N = 10000;
using namespace std;

int main() {
    int N;
    
    int tests;
    scanf("%d", &tests); // test cases

    // denotes if whole solution is correct
    bool correct = true;

    for (int t = 0; t < tests; ++t) {
        //cerr << endl;
        //cerr << "Test: " << t << endl;
        // read graph adjacency list
        scanf("%d", &N); // graph size
        std::vector<std::vector<int> > adjacency_list(N);
        //cerr << "N nodes: " << N << "; " << adjacency_list.size() << endl;
        for (int i = 0; i < N; ++i) {
            int neighbors;
            scanf("%d", &neighbors);
            //cerr << "node " << i << "; neighbors: " << neighbors;
            adjacency_list[i].reserve(neighbors);
            for (int nbr = 0; nbr < neighbors; ++nbr) {
                int node = -1;
                scanf("%d", &node);
                adjacency_list[i].push_back(node);
            }
            //cerr << "; " << adjacency_list[i].size() << endl;
        }

        // read terminals
        int heidi = -1, Friend = -1;
        scanf("%d %d", &heidi, &Friend);

        // desired output
        int desired_output = -1;
        scanf("%d", &desired_output);

        // run contestant's solution
        bool solution = is_call_possible(adjacency_list, heidi, Friend);

        if (!((desired_output && solution) || (!desired_output && !solution))) {
            correct = false;
            break;
        }
    }

    if (correct) {
        printf("CORRECT\n");
    } else {
        printf("NOT CORRECT\n");
    }

    return 0;
}
