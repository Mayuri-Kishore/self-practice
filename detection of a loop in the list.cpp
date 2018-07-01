#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	struct node *next;
	int data;
};
struct node* newnode(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
}
// code for detecting loop
int detect_loop(struct node* list)
{
	
	struct node *p = list, *q = list;
	while(p&&q&&q->next)
	{
		p = p->next;
	    q = q->next->next;
	    if(p == q)
		{	
	    printf("There is a loop");
	    return 1;
	    }
	}
	return NULL;
}

int main()
{
	struct node* loop_node, *head,*p = NULL,*q;
	
	p = newnode(1);
	p->next = newnode(2);
	p->next->next = newnode(3);
	p->next->next->next = newnode(4);
	p->next->next->next->next = newnode(5);
	p->next->next->next->next->next = newnode(6);
	p->next->next->next->next->next->next = newnode(8);
	p->next->next->next->next->next->next->next = newnode(9);
	p->next->next->next->next->next->next->next->next = newnode(10);
	
	//loop for testing
	p->next->next->next->next->next->next->next->next = p->next->next->next;
	
	detect_loop(p);
	//printlist(p);
	
}
