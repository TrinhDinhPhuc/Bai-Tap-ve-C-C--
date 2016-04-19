#include <iostream>  
#include <stdio.h>  
#include <conio.h>  
#include <graphics.h>  
#include <malloc.h>  
// khai bao cau truc cua mot nut
struct node
{
   int data;//Noi dung cua nut
   node *letf , *right;//Dia chi nut trai , nut phai
};
typedef node *nodeptr
//khoi tao cay
void init_tree(nodeptr &root)
{
   root = NUll;
} 
//kiem tra cay rong
int empty_tree(nodeptr root)
{
   if(root == NULL)   return 1;

   else return 0;
}
//tao mot nut cho cay
nodeptr make_node(int x)
{
   noteptr p = new node; 
   p->data = x;
   p->left = p->right = NULL;
   return p;
}
//chen mot nut vao cay co san
nodeptr insert_node(nodeptr &root , int x)
{
   nodeptr p =make_node(x) ;
   nodeptr q,f;
   if(root == NULL)
   {
      root = p;
   }
   else
   {
      root = q;
      f=NULL;
      while(q!=NULL)
      {
         f = q;
         if(x < q ->data)
         {
            q = q->left;
         }
         else
         {
            q = q->right;
         }
      }
      if(x < f->data)
      {
         f->left = p;
      }
      else
      {
         f->right = p;
      }
   }
   return p;
}
//tim kiem
nodeptr search_node(nodeptr root , int x)
{
   nodeptr p = root;
   while(p!=NULL)
   {
      if(p->data == x)          return p;
      else if(x < p->data)           p = p->left;
               else          p = p->right;
   }
   return NULL;
}
//huy 1 nut thuoc cay
int del_node(nodeptr &root, int x)
{
   nodeptr p, q, f;
   p = root;
   f = NULL;
   while(p!=NULL)
   {
      if(p->data == x)     break;
      else
      {
         f = p;
         if(x<p->data)          p = p->left;
         else          p = p->right;
      }
   }
   if(p==NULL)         return 0;
   else
   {
      if(p->left !=NULL && p->right!=NULL)
      {
         q = p->right;
         f = p;
         while(q->left!=NULL)
         {
            f = q;
            q = q->left;
         }
         p->data = q->data;
         p = q;
      }
      if(p->left!=NULL)          q = p->left;
      else          q = p->right;
      if(p==root)         root = q;
      else
      {
          if(p=f->left)         f->left = q;
         else          f->right = q;
      }
      delete p;
      return 1;
   }
}
//ham nhap du lieu vao cay
void input_tree(nodeptr &root)
{
   int n,x;
   root = NULL;
   printf("\nSo phan tu: ");
   scanf("%d", &n);
   for(int i=1; i<=n; i++)
   {
      printf("Phan tu thu %d: ",i);
      scanf("%d", &x);
      insert_node(root, x);
   }
}
// duyet cay theo node left right
void NLR(nodeptr root)
{
   if(root!=NULL)
   {
      printf("%d", root->data);
      NLR(root->left);
      NLR(root->right);
   }
}
//ham huy cay
void del_tree(nodeptr &root)
{
   if(root!=NULL)
   {
      del_tree(root->left);
      del_tree(root->right);
      delete root;
      root = NULL;
   }
}

