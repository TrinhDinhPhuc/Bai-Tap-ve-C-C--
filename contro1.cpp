#include <stdio.h>
#include <conio.h>
struct node{
	int value;
	node *next;
   
};
	 node *head;
void khoitao(node *head)
{
	head=NULL;
}
void nhapds(node *&head)
{
	node *p,*q;
	int temp;
	do{
		printf("Please Enter,If you enter is 0 and that STOP:  \t \n \t");
		scanf("%d",&temp);
		if (temp!=0)
		 {
		 	// create new nope
		 	p=new node;
		 	p->value=temp;
		 	p->next=NULL;
		 	// add nope to list  
		 	if(head==NULL)
		 	head=p;
		 	else 
		 	q->next=p;
		 	q=p;
		 }
		}
		while(temp!=0);
}
void duyetdq(node *head)
	{
		if(head!=NULL)
		{
			printf("%3d",head->value);
			duyetdq(head->next);
		}
	}
int sumdevide(node *head)
{
	if(head==NULL)
	{
		return 0;
	}
	else 
		if(head->value%5==0)
			return 	head->value+sumdevide(head->next);
		else return sumdevide(head->next);
}
int  sumfirstlast (node *head)
{	node *p;
	if(head==NULL)
	return 0;
	else
	p=head;
	while (p->next!=NULL)
	p=p->next;
	return head->value+p->value;	
}
void clearhead(node *&head)
{
	node *p;
	if(head!=NULL) 
	{
		p=head;
		head=head->next;
		delete p;
	}	
}
void clearfoot(node *&head)
{
	node *p;
	node *q;
	if(head!=NULL)
	q=NULL;
	p=head;
	while(p->next!=NULL)
	{	q=p;
		p=p->next;
	}
	if(head==p) clearhead(head);
	else
	q->next=NULL;	delete p;	
}
void insertxhead(int x, node *&head)
{
	node *q,*p;
	p=new node;
	p->value=x;
	p->next=head;
	head=p;	
}
void insertxfoot(int x, node *&head)
{
	node *q,*p;
	p=new node;
	p->value=x;
	p->next=NULL;
	q=head;
	while(q->next!=NULL)
	q=q->next;
	if(head==NULL) head=p;
	else 
	q->next=p;
}

void sortlowtohight(node *&head)
{
	node *q,*p;
	int temp;
	p=head;
	while(p->next!=NULL)
	{
		q=p->next;
		while (q!=NULL)
		{
			if(q->value<p->value)
			{
				temp=q->value;
				q->value=p->value;
				p->value=temp;
				
			}
			q=q->next;
		}
		p=p->next;
	}
}
int main()
{
	khoitao(head);
	nhapds(head);
	duyetdq(head);
	printf("\n $umdevide 5: %d ",sumdevide(head));
	printf("\n $umdaucuoi: %d",sumfirstlast(head));
	clearhead(head); 	printf("\n \t Clearhead: ");
	duyetdq(head);
	clearfoot(head); printf("\n \t Cleafoot: ");
	duyetdq(head);
	insertxhead(69,head); 	 printf("\n \t INSERTHEAD: "); duyetdq(head);
	insertxfoot(77,head); 	 printf("\n \t INSERTfOOT: "); duyetdq(head);
	sortlowtohight(head); printf("\n \t Sort: "); duyetdq(head);
	getch();
	return 0;
	
}

