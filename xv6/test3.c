#include "types.h"
#include "user.h"

int n = 10;

int main(int argc, char *argv[]){

	printf(1, "before fork!!\n\n");
	printf(1, "num_free_pages : %d\n\n", getNumFreePages());

	printf(1, "fork!!\n\n");
	int pid = fork();

	if (pid == 0){
		printf(1, "child============\n\n");
		printf(1, "num_free_pages : %d\nn : %d\n\n", getNumFreePages(), n);
		n = 0;
		printf(1, "change num!\n\n");
		printf(1, "num_free_pages : %d\nn : %d\n\n", getNumFreePages(), n);
		exit();
	}
	else{
		wait();
		n++;
		printf(1, "parent===========\n\n");
		printf(1, "num_free_pages : %d\nn : %d\n\n", getNumFreePages(), n);
	}

	exit();
}
