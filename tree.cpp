struct nut{
	int info;
	nut *left,*right;
};
typedef nut node; node *goc;

void khoitao(node *&goc)
{
	goc=NULL;
	
}
void mocnut(node *&goc, int x)
{
	if(goc==NULL)
	{
		goc= new node;
		goc->info=x;
		goc->left=NULL;
		goc->right=NULL;
	}
	else 
}
