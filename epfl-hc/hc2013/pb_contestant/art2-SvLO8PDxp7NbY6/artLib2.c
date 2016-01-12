/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "artLib2.h"

const int CODE_FIRST_COLOR_NOT_ONE = -3;
const int CODE_NO_CONNECTION = -4;
const int CODE_TOO_LONG_DIST = -5;
const int CODE_TOUR_EXCESS = -6;

typedef struct {
	int a, b;
} connection;

static int checkSolution(int n, int m, int* a, int* b, const int* teamColors, const int* teamTour) {
	return 0;
}

int* answer(const int teamColors[], const int teamTour[], int N) {
	int* solution = calloc(1+N+3*N, sizeof(int));
	assert(solution);
	solution[0] = N;
	memcpy(solution+1, teamColors, N*sizeof(int));
	memcpy(solution+N+1, teamTour, 3*N*sizeof(int));
	return solution;
}

int main() {
	int numOfCases;
	int n, m;
	scanf("%d",&numOfCases);
	int tt;
	for (tt = 0; tt < numOfCases; tt++) {
		scanf("%d", &n);
		scanf("%d", &m);
		int* schemeA = calloc(m, sizeof(int));
		assert(schemeA);
		int* schemeB = calloc(m, sizeof(int));
		assert(schemeB);
		int i;
		for (i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d",&a, &b);
			schemeA[i] = a;
			schemeB[i] = b;
		}
		int* teamAnswer = draw_literate_painting(n, m, schemeA, schemeB);
		assert(teamAnswer[0] == n);
		
		int checkResult = checkSolution(n, m, schemeA, schemeB, teamAnswer+1, teamAnswer+1+n);
		free(teamAnswer);
		if (checkResult) {
			printf ("INCORRECT - Test case %d: ", tt+1);
			if (checkResult == CODE_FIRST_COLOR_NOT_ONE)
				printf("color of the first vertex in tour is not 1");
			else if (checkResult == CODE_NO_CONNECTION)
				printf("tour includes nonexistent connection");
			else if (checkResult == CODE_TOO_LONG_DIST)
				printf("distance between some pair of colors is bigger than 3 (tour is illiteral)");
			else if (checkResult == CODE_TOUR_EXCESS)
				printf("tour is too long, should be shorter");
			else if (checkResult > 0)
				printf("didn't find color %d", checkResult % n);
			else
				printf("unknown code error");
			printf("\n");
			exit(0);
		}
		free(schemeA);
		free(schemeB);
	}
	printf("COULD BE CORRECT\n");
	return 0;
}
