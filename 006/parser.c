#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0

char stack[25];
int pointer = -1;

int isStackEmpty(){
	if (pointer == -1){
		return true;
	}
	return false;
}

int isStackFull(){
	if (pointer == sizeof(stack)/sizeof(char)){
		return true;
	}
	return false;
}

void pushElement(char c){
	if (!isStackFull()){
		stack[++pointer] = c;
	}
}

char peekElement(){
	if (isStackEmpty()){
		return stack[pointer];
	}
	return '\0';
}

char popElement(){
	if (!isStackEmpty()){
		return stack[pointer--];
	}
	return '\0';
}

int main(int argc, char *argv[]){
	char expression[] = "2 1 3 + *";

	int length_of_expression = sizeof(expression)/sizeof(char)-1;
	int result;

	for (int i = 0; i < length_of_expression; i++){
		char c = expression[i];
		if (isdigit(c)){
			pushElement(c);
		}
		// Otherwise, mathematical operations
		// Find out why I can't assign n_1 and n_2 out here..
		// I think it has to do with how I'm not getting references
		else if (!isdigit(c) && !isalpha(c)){
			if (c == '+'){
				int n_1 = popElement() - '0';
				int n_2 = popElement() - '0';
				pushElement(n_1 + n_2 + '0');
			} else if (c == '*'){
				int n_1 = popElement() - '0';
				int n_2 = popElement() - '0';
				pushElement(n_1 * n_2 + '0');

			} else if (c == '-'){
				int n_1 = popElement() - '0';
				int n_2 = popElement() - '0';
				pushElement(n_1 - n_2 + '0');

			} else if (c == '/'){
				int n_1 = popElement() - '0';
				int n_2 = popElement() - '0';
				pushElement(n_1 / n_2 + '0');

			}
		} else {
			printf("Invalid element!\n");
		}
	}

	result = popElement() - '0';
	printf("The result is %i\n", result);
}
