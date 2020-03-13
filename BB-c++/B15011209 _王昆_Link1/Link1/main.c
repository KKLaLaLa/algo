#include<stdio.h>
#include<malloc.h>
#include "head.h"
void main()
{
	
	struct Student *head, *letter, *digit, *other;
	
	printf("please input your character,end with #\n");
	head=creat();

	print(head);
	letter=(struct Student*)malloc(LEN);
	letter->next = letter;
	digit=(struct Student*)malloc(LEN);
	digit->next = digit;
	other=(struct Student*)malloc(LEN);
	other->next = other;

	resolve(head,letter,digit,other);
	
	printf(" 输出的字母:\n");
	print(letter);
	printf(" 输出的数字:\n");
	print(digit);
	printf(" 输出的其他字符:\n");
	print(other);

	link(letter,digit,other);
	printf("link end");
	print1(letter);
}

