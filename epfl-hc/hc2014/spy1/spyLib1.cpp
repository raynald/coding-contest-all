/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "spyLib1.hpp"

#define SCAN 123u
#define TEST 124u

typedef union _b8 {
    unsigned long long int integer;
    unsigned char byte[8];
} _b8;

typedef union _s9 {
	struct {
		_b8 id;
		unsigned char key;
	} parts;
	unsigned char str[12];
} _s9;

static int pim[2], pih[2];
static unsigned int M, remainingHints;

unsigned int get_N(){
	return M;
}

void send_hint(unsigned char info){
	if (!remainingHints){
		close(pih[0]);
		close(pim[1]);
		printf("Heidi sent too many hints\n");
		exit(0);
	}
	_s9 buf;
	buf.parts.key = SCAN;
	buf.parts.id.byte[0] = info;
	write( pim[1], buf.str, sizeof(buf.str) );
	remainingHints = remainingHints - 1;
}

static unsigned char test_marmot(unsigned long long int id, unsigned char sol){
	_s9 buf;
	buf.parts.key = TEST;
	buf.parts.id.integer = id;
	write( pim[1], buf.str, sizeof(buf.str) );
    read( pih[0], buf.str, sizeof(buf.str) );
    return ( buf.parts.key == sol );
}

static void marmots(){
	_s9 buf;
    while ( read( pim[0], buf.str, sizeof(buf.str) ) > 0 ){
    	if ( buf.parts.key == SCAN )
    		receive_hint( buf.parts.id.byte[0] );
    	if ( buf.parts.key == TEST ){
    		buf.parts.key = is_spy( buf.parts.id.integer ) ? 1 : 0;
    		write( pih[1], buf.str, sizeof(buf.str) );
    	}
    }
}

static void heidi(){
	FILE *fin;
	unsigned int T, op, i;
	unsigned char sol;
	unsigned long long int id;
	fin = fopen("testdata.in","r");
	fscanf(fin,"%u %u",&M,&T);
	remainingHints = M*2;
	for (i=0; i<M+T; i++){
		fscanf( fin, "%u %llu %hhu", &op, &id, &sol);
		if (op)
			scan_marmot( id );
		else{
			if ( !test_marmot( id, sol ) ) {
				close(pih[0]);
				close(pim[1]);
				printf("Marmot confused spy and loyal fellow\n");
				exit(0);
			}
		}				
	}
	close(pih[0]);
	close(pim[1]);
	printf("CORRECT\n");
}	

int main(){
	pipe(pim);
	pipe(pih);
   	int childpid = fork();
          
 	if(childpid == 0){
 		close(pih[0]);
		close(pim[1]);
		marmots();
	}
	else{
        close(pih[1]);
        close(pim[0]);
        heidi();
	}
	return 0;
}
