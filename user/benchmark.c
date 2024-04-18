#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]) {
	uint64 start = 0, end = 0;
	uint64 elapsed;
	int child = fork();
	if (child == -1) {
		printf("fork failed\n");
	} 
	else if (child == 0) {
		start = clock();
		exec(argv[1], &argv[1]);
		printf("exec %s failed\n", argv[1]);
		exit(-1);
	} 
	else {
		int status;
		int count;
		wait2(&status, &count);
		end = clock();
		elapsed = end - start;
		printf("Benchmark Complete\nTime Elapsed: %d ms\n", elapsed);	
		printf("System Calls: %d\n", count);
	}
	exit(0);
}
