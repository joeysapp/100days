// https://en.wikipedia.org/wiki/Hamming_weight
// https://stackoverflow.com/questions/8871204/count-number-of-1s-in-binary-representation
// https://stackoverflow.com/questions/15233121/calculating-hamming-weight-in-o1/15233569

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int count_bits(uint64_t x){
	int num = 0;
	while (x){
		printf("num: %i\n", x);
		x = x & x - 1;
		num++;
	}
	return num;
}

int to_binary(uint64_t t_num){
	if (t_num == 0){
		return 0;
	} else if (t_num == 1){
		return 1;
	}
	return (t_num % 2) + (10 * to_binary(t_num/2));
}

int main(int argc, char *argv[]){
	//uint64_t num = atoi(argv[1]);
	//uint64_t binary_rep = to_binary(num);
	uint64_t binary_rep = 0b1100101;

	printf("The answer is: %i\n", count_bits(binary_rep));
}
