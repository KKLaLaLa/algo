#include "stdio.h" 
#include "stdlib.h" 


struct BT
 {    
	int data;  
	struct BT *lchild,*rchild;
 };
typedef struct BT BT;


BT *CreatBT( );

void show(BT *T);
int height(BT *T);
int leaf(BT *T);
BT *CopyTree(BT *root);
void exchange(BT *rt);

void DeleteBiTree(BT* root);