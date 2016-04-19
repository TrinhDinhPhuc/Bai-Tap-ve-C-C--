#include <stdio.h>
#include <conio.h>
#include <string.h>
struct nut{
	char MSSV[5];
	char Holot[30];
	char Ten[10];
	float DTB;
	nut *tiep;
};
typedef nut Node;
Node *dau;
void khoitao(Node*&dau)
{
	dau==NULL;
	
}
void nhap(Node*&dau)
{
	Node *p, *q;
	char tam[5];
	do {
	 printf("nhap ma SV, enter:dung\t");
	 fflush(stdin);
	 gets(tam);
	 if (strcmp(tam,"\0")!=0)
	 	{p=new Node;
	 	strcpy(p->MSSV,tam);
	 	
	 	printf("nhap ho lot\t");
	 	fflush(stdin);
	 	gets(p->Holot);
	 	
	 	printf("nhap ten\t");
	 	fflush(stdin);
	 	gets(p->Ten);
	 	
	 	printf("nhap DTB\t");
	 	scanf("%f",&p->DTB);
	 	p->tiep=NULL;
	 	if (dau==NULL)
	 		dau=p;
	 	else
		 	q->tiep=p;
			 q=p;	
	 	}
}
	while (strcmp(tam,"\0")!=0);
}
void duyetds(Node *dau)

{
	if(dau!=NULL)
		{			
		printf("\n%s",dau->MSSV);
		printf("\n%s",dau->Holot);
		printf("\n%s",dau->Ten);
		printf("\n%0.2f",dau->DTB);
		duyetds(dau->tiep);
		}
}
float DTBcn(Node *dau)
{
	float DC=0;
	Node *p;
		p=dau;
	if(p->DTB>DC)	
		DC=p->DTB;
		p=p->tiep;
	return DC;	
	
}
void DSSVCN(Node*dau)
{
	Node*p;
		p=dau;
		float DC=DTBcn(dau);
	while(p!=NULL)
	{
		if(p->DTB==DC)
			{
				printf("\n%s",p->MSSV);
				printf("\n%s",p->Holot);
				printf("\n%s",p->Ten);				
			}
			p=p->tiep;
	}	
}


int main()
{
	khoitao(dau);
	nhap(dau);
	duyetds(dau);
	DSSVCN(dau);
	getch();
}

