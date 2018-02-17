#include <iostream>

__globab__ void mykernel(void) {
}

int main(void) {
	mykernet<<<1,1>>>();
	printf("Hello World !!\n");
	return 0;
}
