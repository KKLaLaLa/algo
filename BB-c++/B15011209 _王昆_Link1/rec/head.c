#include<stdio.h>
#include<malloc.h>
#include "head.h"

/***********************************
********************************
***************************
**************************************/

struct Student*head;
int n;

/**********************************************
*************************************

*************************************
*********************************************/
struct Student*creat()
{
	struct Student*head;
	struct Student*p1,*p2;
	char x;

	head=(struct Student*)malloc(sizeof(LEN));
	p2 = head;

	while((x=getchar())!='#')
	{
	p1=(struct Student*)malloc(sizeof(LEN));
		p1->data=x;
		p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	return(head);
}
/*****************************************
******************************************
******************************************
******************************************/
void print(struct Student *head)
{
	struct Student *p = head->next;
	printf("\nNow,These data are:\n",n);
		
	while(p!=NULL)
		{
			printf("%c",p->data);
			p=p->next;
		}
	printf("\n\n");
}
void print1(struct Student *head)
{
	struct Student *p = head->next;
	printf("\nNow,These data are:\n",n);
		
	while(p!=head)
		{
			printf("%c",p->data);
			p=p->next;
		}
	printf("\n\n");
}



/********************************************
********* *********************************
********************************************/
void resolve(struct Student *head, struct Student *letter, struct Student *digit, struct Student *other)
{
	struct Student*pa,*pb,*pc,*Student;

	pa = letter;
	pb = digit;
	pc = other;
	Student = head->next;
	while(Student!=NULL)
	{
		if((('a'<=Student->data)&&(Student->data<='z'))||(('A'<=Student->data)&&(Student->data<='Z')))
		{
			pa -> next = Student;
			pa = Student;
			Student = Student -> next;
		}
		else if(('0'<=Student->data)&&(Student->data<='9'))
		{
			pb -> next = Student;
			pb = Student;
			Student = Student -> next;
		}
			else
			{
				pc -> next = Student;
				pc = Student;
				Student = Student -> next;
			}
	}

	pa -> next = NULL;
	pb -> next = NULL;
	pc -> next = NULL;
}


struct Student*link(struct Student *letter, struct Student *digit, struct Student *other)
{
		struct Student *p = letter;
		struct Student *q = digit;
		struct Student *m = other;

		while(p->next!=NULL)
		{
			p = p->next;		
		}
		p->next = digit->next;
		free(digit);
	
				while(p->next!=NULL)
			{
				p = p->next;		
			}
				p->next = other->next;
				free(other);
					while(p->next!=NULL)
				{
					p = p->next;		
				}
					p->next = letter;
				
			return letter;
	/*				while(m!=NULL)
				{
					m=m->next;
				}
				m = letter;*/
				
}