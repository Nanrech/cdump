#include <stdio.h>

int add(int a, int b) {
    return a + b;
}


void print(){
	printf("Hello world");
}

int main() {
	int (*add_ptr) (int, int);
	add_ptr = add;
	
	void (*print_ptr) (void);
	print_ptr = print;
	
	int a = 5;
	int b = 10;
	
	int total = (*add_ptr)(a, b);
	printf("%d\n", total);
	
	struct Class{
		char name[4];
		void print = (*add_ptr) (a, b);
	};
	

    return 0;
}

