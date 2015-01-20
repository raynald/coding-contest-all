/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include <cstdio>
#include <cstdlib>
#include "cryptoLib1.hpp"

using namespace std;

int main(){
    int N; // number of test cases
    int i, correct_ans;
    int password_to_check;

    scanf("%u",&N);

    for (i=0; i<N; i++){
        scanf("%d %d", &password_to_check, &correct_ans);
        
        if (is_password_correct(password_to_check) != correct_ans) {
            printf("INCORRECT\n");
            exit(0);
        }

    }
    printf("Looks pretty good\n");
    return 0;
}
