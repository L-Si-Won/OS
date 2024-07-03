#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){

	int n = 0;

	int arg = argv[1][0] - '0';

	int pid = fork();

	if (pid != 0){
		set_proc_priority(pid, arg);
		wait();
	}
	else{
		for (int j = 0; j < 70000000000; j++)
			n += 1 + 2;
		exit();
	}

	exit();
}
