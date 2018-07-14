#include <stdio.h>
#include <stdlib.h>
#include "hotel-ll.c"

PNode readfile()//读取数据库中的数据并形成链表
{
	
	FILE * pfile = fopen("hotel.db","r");
	if (pfile==NULL)
	{
		printf("Failed to open the hotel.db\n");
		exit(-1);
	}
	PNode phead=createlist();
	PNode p=phead;
	while (true)
	{
		int index=0;
		char content[30]="";
		content[29]='\0';
		char c;
		while (true)
		{
		c= getc(pfile);
		if (c =='\n' || c=='#' || c == EOF )
			break;
		content[index]=c;
		index++;
		}

		if (c == EOF)
			break;
		addnode(p,content);
		p=p->next;
	}
	fclose(pfile);
	return phead;
}
void writefile(PNode head)//将当前链表写入数据库
{
	PNode q=head->next;
	FILE *pfile =  fopen("hotel.db","w");
	while (q!=NULL)
	{
		fputs(q->content,pfile);
		fputc('\n',pfile);
		q=q->next;
	}
	fclose(pfile);
}

PNode searchroom(PNode head,int room)//在当前链表寻找index为room的node 并返回此node
{
	char room_in[30]="[room ";
	char room_ind[4];
	itoa(room,room_ind,10);
	strcat(room_in,room_ind);
	strcat(room_in,"]");
	PNode room_=searchNode(head,room_in,10);
	return room_;
}
void addbreakfasts(PNode room_node)//将room_node 这个node下的breakfast值+1
{

	PNode bf=searchNode(room_node,"breakfast",9);
	int number=0;
	for (int i=0;bf->content[i]!='\0';i++)
	{
		if (bf->content[i]<='9' && bf->content[i]>=0)
			number=number*10+bf->content[i]-'0';
	}
	number+=1;
	char num_str[3];
	itoa(number,num_str,10);
	char content[30]={"breakfast="};
	strcat(content,num_str);
	strcpy(bf->content,content);
}
void addnight(PNode room_node)//将room_node 这个node下所属的night值+1
{
	PNode ni=searchNode(room_node,"night",5);
	int number=0;
	for (int i=0;ni->content[i]!='\0';i++)
	{
		if (ni->content[i]<='9' && ni->content[i]>=0)
			number=number*10+ni->content[i]-'0';
	}
	number+=1;
	char num_str[3];
	itoa(number,num_str,10);
	char content[30]={"night="};
	strcat(content,num_str);
	strcpy(ni->content,content);
}
void minusnight(PNode room_node)//将room_node 这个node下所属的night值-1
{
	PNode ni=searchNode(room_node,"night",5);
	int number=0;
	for (int i=0;ni->content[i]!='\0';i++)
	{
		if (ni->content[i]<='9' && ni->content[i]>=0)
			number=number*10+ni->content[i]-'0';
	}
	number-=1;
	char num_str[3];
	itoa(number,num_str,10);
	char content[30]={"night="};
	strcat(content,num_str);
	strcpy(ni->content,content);
}
void adjustprice(PNode room_node, int price)//修改房间的价格
{
	PNode pr=searchNode(room_node,"price",5);
	char content[30]={"price="};
	char num_str[6];
	itoa(price,num_str,10);
	strcat(content,num_str);
	strcpy(pr->content,content);
}
void setdate(PNode room_node,char *date)//设置到达时间
{
	PNode arv=searchNode(room_node,"arrival",7);
	char content[30]={"arrival="};
	strcat(content,date);
	strcpy(arv->content,content);
}
bool whetherfull(PNode head,int room)//判断是否有人住满
{
	PNode room_1= searchroom(head,room);
	PNode room_type=searchNode(room_1,"type",4);
	PNode room_va=searchNode(room_1,"vacant",6);
	if (room_type->content[7]=='r')
	{
		return room_va->content[7]=='3';
	}
	return (room_va->content[7]=='1');
}
bool whetherfull1(PNode head,PNode room_1)//判断是否住满 使用room_node
{
	PNode room_type=searchNode(room_1,"type",4);
	PNode room_va=searchNode(room_1,"vacant",6);
	if (room_type->content[7]=='r')
	{
		return room_va->content[7]=='3';
	}
	return (room_va->content[7]=='1');
}