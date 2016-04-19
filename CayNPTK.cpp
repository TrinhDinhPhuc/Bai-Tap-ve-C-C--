#include <stdio.h>
#include <conio.h>
struct nut {
	int info;
	nut *left, *right;
};
typedef nut Node;
Node *goc;

void khoitao(Node *goc)
{
	goc=NULL;
}

void mocnut(Node *&goc, int x)
{
	if (goc==NULL)
		{
		goc=new Node;
		goc->info=x;
		goc->left=NULL;
		goc->right=NULL;
		}
	else 
		if(goc->info>x)
			mocnut(goc->left,x);
		else	
			mocnut(goc->right,x);	
}

void taocay(Node*&goc)
{
	int tam;
	do
		{
			printf("Nhap so nguyen, 0 dung:");
			scanf("%d",&tam);
			if(tam!=0)
				mocnut(goc,tam);
		}
		while (tam!=0);
}

void duyetLRN(Node *goc)
{
	if (goc!=NULL)
		{
			duyetLRN(goc->left);
			printf("%2d",goc->info);
			duyetLRN(goc->right);
		
		}
}

int tong(Node*goc)
{
	if (goc==NULL)
		return 0;
	else 
		return goc->info + tong(goc->left) + tong(goc->right);	
}

int max(int a, int b)
{
	if(a>b)
		return a;
	else
	 return b;	
}

int chieucao(Node *goc)
{
	if (goc==NULL)
		return 0;
	else
		if ((goc->left==NULL)&&(goc->right==NULL))
			return 1;
		else 
			return 1+max(chieucao(goc->left),chieucao(goc->right));	
}
int tongle(Node *goc)
{
	if (goc==NULL)
		return 0;
	else
		if (goc->info %2!=0)
			return goc->info + tongle(goc->left)+tongle(goc->right);
		else
			return tongle(goc->left)+tongle(goc->right);		
}

int tongnutla(Node *goc)
{
	if(goc==NULL)
		return 0;
	else 
		if ((goc->left==NULL)&&(goc->right==NULL))
			return goc->info;
		else 
			return tongnutla(goc->left)+tongnutla(goc->right);		
}
int tongnhanh(Node*goc)
{
	if(goc==NULL)
		return 0;
	else 
		return tong(goc) - tongnutla(goc);	
}
int main()
{
	khoitao(goc);
	taocay(goc);
	duyetLRN(goc);
	printf("\nTong cac nut:%2d", tong(goc));
	printf("\nChieu cao cua cay:%2d",chieucao(goc));
	printf("\nTong nut le:%2d",tongle(goc));
	printf("\nTong nut la:%2d",tongnutla(goc));
	printf("\nTong nut nhanh:%2d",tongnhanh(goc));
	getch();
	return 0;
}
