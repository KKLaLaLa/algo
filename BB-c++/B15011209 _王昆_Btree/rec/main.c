#include "stdio.h" 
#include "stdlib.h" 
#include "Btree.h"

int main()
{
	BT *T;
	printf("请输入二叉树的根节点,并用0表示该节点为空\n");
	T=CreatBT();
	show(T);
	printf("\n\nThis tree's high is: %d\n\n",height(T));
	printf("\n\nThis tree's leaf is: %d\n\n",leaf(T));
	CopyTree(T);
	exchange(T);
	show(T);
	printf("\n");
	DeleteBiTree(T);
	printf("\n");
	return 0;
}