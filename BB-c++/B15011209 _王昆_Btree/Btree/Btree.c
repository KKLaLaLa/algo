#include "stdio.h" 
#include "stdlib.h" 
#include "Btree.h"
/*************************************
************建立二叉树****************
**************************************/
BT *CreatBT() 
{
    BT *t;
    int x;
    scanf("%d",&x);
    //getchar();
    if(x==0)
    {
        t=NULL;
    }
    else
    {
        t=(BT*)malloc(sizeof(BT));
        t->data=x;
        printf("\n请输入%d结点的左子结点:",t->data );
        t->lchild=CreatBT();
        printf("\n请输入%d结点的右子结点:",t->data );
        t->rchild=CreatBT();
    }
    return t;
}
/*****************************************
************ //打印二叉树*****************
******************************************/
void show(BT *T)   
{  
{
    if(T==NULL) return;
    else
    {
        printf("%3d",T->data);
        show(T->lchild);
        show(T->rchild);
    }
}
 }
/*******************************************
********求取树的高度************************
********************************************/
int height(BT *T)   
{ 
	int lh,rh,h=0;
	if(T==NULL)
		h=0;
	else
	{
		lh=height(T->lchild);
		rh=height(T->rchild);
		h=(lh>rh ? lh:rh)+1;
	}
	return h;
 } 
/*******************************************
************删除一棵二叉树******************
********************************************/
void DeleteBiTree(BT* root)    
{
	if(root==NULL)
	return;
	DeleteBiTree(root->lchild);
	DeleteBiTree(root->rchild);
	root=NULL;
	return;
}
/*******************************************
**********求取二叉树中的叶子节点数**********
********************************************/
int leaf(BT *T)
{
	if(T==NULL)
    return 0;

	else
		if(T->lchild==NULL && T->rchild==NULL)

    return 1;

	else 
		return leaf(T->lchild)+leaf(T->rchild);
}
/*******************************************
**********复制一棵二叉树********************
********************************************/
BT *CopyTree(BT *root)
{
   BT * newnode;                        
   if ( root == NULL )                   
      return NULL;
   else
   {
      newnode = ( BT* ) malloc(sizeof(BT));
      newnode->data = root->data;        
      newnode->lchild = CopyTree(root->lchild);
      newnode->rchild = CopyTree(root->rchild);
      return newnode;
   }
}
/*******************************************
************交换二叉树的左右子树************
********************************************/
void exchange(BT *rt)
{
	BT *temp = NULL;
		if(rt->lchild == NULL && rt->rchild == NULL)
		     return;
		else{
			  temp = rt->lchild;
			   rt->lchild = rt->rchild;
			   rt->rchild = temp;
			}
		if(rt->lchild)
		     exchange(rt->lchild);
		if(rt->rchild)
		    exchange(rt->rchild);
}
