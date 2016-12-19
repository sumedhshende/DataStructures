#include <stdio.h>
#include <assert.h>

#define STACK_SIZE  20

int arr[STACK_SIZE];
static int stacktop = -1;

void push(int item) {
	assert(stacktop < STACK_SIZE);
	arr[++stacktop] = item;
}
int pop() {
	assert(stacktop != -1);
	return arr[stacktop--];
}
void print() {
	
}

int main(void) {
/*	push(10);
	printf("%d -->%d\n", stacktop, arr[stacktop]);
	push(20);
	printf("%d -->%d\n", stacktop, arr[stacktop]);
	push(30);
	printf("%d -->%d\n", stacktop, arr[stacktop]);
	
	printf("%d -- %d\n", pop(), arr[stacktop]);
	printf("%d -- %d\n", pop(), arr[stacktop]);
	printf("%d -- %d\n", pop(), arr[stacktop]);
	printf("%d -- %d\n", pop(), arr[stacktop]);
*/
	for(int i=0; i<STACK_SIZE; i++)
		push(i*10);

	for(int j=0; j<STACK_SIZE; j++){ 
		printf("%d --> ", stacktop);
		printf("%d\n",pop());
	}
		

	return 0;
}
