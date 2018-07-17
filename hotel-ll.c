
#include "hotel-ll.h"

void itoa_1 (int n,char s[],int k)
{
int i,sign;
if((sign=n)<0)//记录符号
n=-n;//使n成为正数
i=0;
do{
       s[i++]=n%10+'0';//取下一个数字
}
while ((n/=10)>0);//删除该数字
if(sign<0)
s[i++]='-';
s[i]='\0';
}
PNode createlist()
{
	//int len;
	//char content[30];
	PNode Phead = (PNode) malloc(sizeof(node_t));
	if (Phead==NULL)
	{
		printf("Failed to allocate the space !\n");
		return NULL;
	}
	PNode PTail = Phead;
	PTail->next=NULL;
	return Phead;
}
void addnode(PNode n,char content[30])
{

	PNode newNode=(PNode) malloc(sizeof(node_t));
	strcpy(newNode->content,content);
	newNode->next=n->next;
	n->next=newNode;
}
void deleteNode(PNode n)
{
	if (!n)
	{
		return;
	}
	if (n->next!=NULL)
	{
		PNode q=n->next;
		n->next=q->next;
	}
}
PNode searchNode(PNode head,const char *value,int len)
{
	PNode p=head->next;
	while (p!=NULL)
	{
		bool flag=true;
		for (int i=0;i<len;i++)
		{
			if (value[i]!=p->content[i])
			{
				flag=false;
				break;
			}
		}
		if (flag)
			return p;
		p=p->next;
	}
	return NULL;
}