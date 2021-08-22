#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	
	while (1){
		fork();
		system("ps -aux| wc -l >> process.txt");
		system("sleep 2");
	}
	return 0;
}
