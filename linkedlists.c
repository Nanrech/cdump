#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	int age;
	struct Person *nextInLine;
};

struct Person *getNewPerson(const int age) {
	struct Person *newPerson = NULL;
	newPerson = malloc(sizeof(struct Person));
	
	if (newPerson == NULL) {
		printf("Allocation failure.\n");
		return newPerson;
	}
	
	newPerson->age = age;
	newPerson->nextInLine = NULL; 
	
	printf("Created new person at %p\n", newPerson);
	
	return newPerson;
}

void printPerson(const struct Person *person, const char *comment) {
	if (person == NULL) {
		printf("%s is NULL\n", comment);
	}
	else {
		printf("%s: Age: %d Address: %p Next in line: %p\n", comment, person->age, person, person->nextInLine);
	}
}

void printList(const struct Person *list) {
	const struct Person *t;
	t = list;
	
	if (t == NULL) {
		printf("List is empty\n");
	}
	else {
		while (t) {
			printPerson(t, "t");
			t = t->nextInLine;
		}
	}
}

void cleanUp(struct Person *list) {
	struct person *next;
	while (list) {
		next = list->nextInLine;
		printf("Cleaning up '%d'\n", list->age);
		free(list);
		list = next;
	}	
}

int main() {
	struct Person *first = NULL;
	struct Person *added = NULL;
	
	char command[64];
	int age;
	
	while (1) {
		printf("Enter a command or value: ");
		fgets(command, 64, stdin);
			
		if (strcmp("q\n", command) == 0) {
			printf("Quitting...\n");
			break;
		}
		else if (strcmp("print\n", command) == 0) {
			printf("Printing...\n");
			printList(first);
		}
		else if (sscanf(command, "%d", &age) != 0) {
			printf("Adding sPerson with age %d\n", age);
			if (first == NULL) {
				first = getNewPerson(age);
				if (first != NULL) {
					added = first;
				}
			}
			else {
				added->nextInLine = getNewPerson(age);
				if (added->nextInLine != NULL) {
					added = added->nextInLine;
				}
			}
		}
	}
	
	cleanUp(first);
	first = NULL;
	added = NULL;
	
	return 0;
}
