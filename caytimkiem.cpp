#include <stdio.h>
#include <conio.h>
struct nut{
	int info;
	nut *left,*right;
}; 
typedef nut node;
node *goc;

void khoitao(node *&goc)
{
	goc==NULL;
}
void mocnut(node *&goc, int x)
{
	if(goc==NULL)
	{
		goc=new node;
		goc->info=x;
		goc->left=NULL;
		goc->right=NULL;
	}
	else 
		if(goc->info>=x)
			mocnut(goc->left,x);
		else mocnut(goc->right,x);
}
void taocay(node *&dau)
{
	int tam;
	do{
		printf("please enter, 0 to stop"); 
		scanf("%d",&tam);
		if(tam==0)
		mocnut(goc,tam);
	}
	while(tam!=0)
}
void duyetcaydq(node *dau)
	{
		if(dau!=NULL)
		{
			printf("%3d",dau->info);
			duyetcaydq(dau->right);
		}
	}
main()
{
	khoitao(dau);
	printf("Nut ban dau la 4 nhe %d",mocnut(dau,4));
	taocay(dau);
	duyetcaydq(dau);
}
