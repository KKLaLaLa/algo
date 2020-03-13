#include<stdio.h>

#define LEN sizeof(struct Student)

struct Student
	{
	char data;

	struct Student *next;

	};



struct Student*creat();
void print(struct Student *head);
void print1(struct Student *head);
void resolve(struct Student *head, struct Student *letter, struct Student *digit, struct Student *other);
struct Student* link(struct Student *letter, struct Student *digit, struct Student *other);