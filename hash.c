#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
	char name[MAX_NAME];
	int age;
} person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
	int length = strlen(name);
	int hash_value = 0;
	for (int i = 0; i < length; i++) {
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
	}
	return hash_value;
}

bool init_hash_table() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hash_table[i] = NULL;
	}
}

void print_table() {
	printf("*** TABLE BEGIN ***\n\n");
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hash_table[i] == NULL) {
			printf("%i\t---\n", i);
		}
		else {
			printf("%i\t%s\n", i, hash_table[i]->name);
		}
	}
	printf("\n*** TABLE END ***\n\n");
}

person* hash_table_lookup(char *name) {
	int index = hash(name);
	if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
		return hash_table[index];
	}
	else {
		return NULL;
	}
}

person* hash_table_delete(char *name) {
	int index = hash(name);
	if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
		person* temp = hash_table[index];
		hash_table[index] = NULL;
		return temp;
	}
	else {
		return NULL;
	}
}

bool hash_table_insert(person *p) {
	if (p == NULL) {
		return false;
	}
	int index = hash(p->name);
	for (int i = 0; i < TABLE_SIZE; i++) {
		int try = (i + index) % TABLE_SIZE;
		if (hash_table[try] == NULL) {
			hash_table[try] = p;
			return true;
		}
	}
	return false;
}

int main() {
	
	init_hash_table();
	print_table();
	
	person jacob = {.name="Jacob", .age=10};
	person david = {.name="David", .age=10};
	person marcos = {.name="Marcos", .age=10};
	person jesus = {.name="Jesús", .age=10};
	
	hash_table_insert(&jacob);
	hash_table_insert(&david);
	hash_table_insert(&marcos);
	hash_table_insert(&jesus);
	
	print_table();
	
	/*
	printf("Jacob => %u\n", hash("Jacob"));
	printf("David => %u\n", hash("David"));
	printf("Marcos => %u\n", hash("Marcos"));
	printf("Jesús => %u\n", hash("Jesús"));
	printf("Martin => %u\n", hash("Martin"));
	*/
	return 0;
}
