#include <stdio.h>
#include <string.h>

#define pid_t int

int main(int argc, char* argv[]){
	char* sendArgs[3];
	sendArgs[2] = NULL; //null-terminated for slave to use as argv
	int i, loopCount = 2*(argc-2), sizeNums = argc-1; //loopCount equates to how many times the loop needs to be entered given i increases by 2 each iteration

	int nums[20]; //nums contains original numbers and resulting sums
	for(i = 0; i < argc-1; ++i){ //argc/argv offset to avoid filename
		nums[i] = atoi(argv[i+1]);
	}

	for(i = 0; i < loopCount; ++i){ //i is used to find where to grab the next numbers from in nums[]
		int childTest = fork();

		if(childTest == 0){
			//child, so convert nums to char* and send to slave
			char numOne[5];
			char numTwo[5];
			sprintf(numOne, "%d", nums[i]);
			sprintf(numTwo, "%d", nums[i+1]);
			sendArgs[0] = &numOne[0];
			sendArgs[1] = &numTwo[0];
			execvp("./slave", sendArgs);
		}else{
			//parent, so wait for child to return sum and add it to nums[]
			int status;
			waitpid(childTest, &status, 0);
			status = status >> 8; //bit-shift result to extract sum
			printf("Sum: %d, storing in array\n", status);
			nums[sizeNums] = status; //sizeNums points to current "end" of nums[]
			++sizeNums;
			++i; //incrementing i to have it increase by 2 each iteration since working with pairs of numbers
		}
	}
	return 0;
}
