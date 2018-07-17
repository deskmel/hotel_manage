
#include "hotel-ll.h"
#include "hotel-db.h"
#include "hotel-mt.h"

PNode addvisitors(PNode p,struct visitor s,int i)
{

	char content[30]="name";
	char num[3];
	itoa_1(i,num,10);
	strcat(content,num);
	strcat(content,"=");
	strcat(content,s.name);
	addnode(p,content);
	p=p->next;
	char content1[30]="id";
	strcat(content1,num);
	strcat(content1,"=");
	strcat(content1,s.ID);
	addnode(p,content1);
	return p->next;

}
PNode find_next(PNode room)
{
	if (room==NULL)
		return NULL;
	PNode p=room->next;
	if (p==NULL)
		return NULL;
	if (p->content[0]=='[')
	{
		return p;
	}
	return find_next(p);
}
void alter_room(PNode head,int room_index,struct room s)
{
	PNode room_1=searchroom(head,room_index);
	PNode room_2=find_next(room_1);
	room_1->next=room_2;
	char room_in[30]={"[room "};
	char index[4];
	itoa_1(room_index,index,10);
	strcat(room_in,index);
	strcat(room_in,"]");


	char room_type[30]="type=";
	strcat(room_type,s.room_type);

	char room_vacant[30]="vacant=";
	strcat(room_vacant,"3");

	char room_arri[30]="arrival=";
	strcat(room_arri,s.arrival_data);
	char v[3]="";
	itoa_1(s.vistors,v,10);
	char room_visitors[30]="vistors=";
	strcat(room_visitors,v);

	char k[2]="";
	itoa_1(s.keys,k,10);
	char room_keys[30]="keys=";
	strcat(room_keys,k);

	char bf[2]="";
	itoa_1(s.breakfast,bf,10);
	char room_bf[30]="breakfast=";
	strcat(room_bf,bf);
	
	char night_[4]="";
	itoa_1(s.nights,night_,10);
	char night[30]="night=";
	strcat(night,night_);

	char p[6]="";
	itoa_1(s.price,p,10);
	char price[30]="price=";
	strcat(price,p);


	addnode(room_1,price);
	//PNode tail=room_1->next;
	addnode(room_1,night);
	addnode(room_1,room_bf);
	addnode(room_1,room_keys);
	addnode(room_1,room_visitors);
	addnode(room_1,room_arri);
	addnode(room_1,room_vacant);
	addnode(room_1,room_type);
}
PNode initia_room(PNode head,int room_index,const char *type)
{
	char room_in[30]={"[room "};
	char index[4];
	itoa_1(room_index,index,10);
	strcat(room_in,index);
	strcat(room_in,"]");
	char room_type[30]="type=dorm";
	char room_vacant[30]="vacant=0";
	char room_arri[30]="arrival=01/01/1999";
	char room_visitors[30]="vistors=0";
	char room_keys[30]="keys=2";
	char room_bf[30]="breakfast=0";
	char night[30]="night=1";
	char price[30]="price=0";
	addnode(head,price);
	PNode tail=head->next;
	addnode(head,night);
	addnode(head,room_bf);
	addnode(head,room_keys);
	addnode(head,room_visitors);
	addnode(head,room_arri);
	addnode(head,room_vacant);
	addnode(head,room_type);
	addnode(head,room_in);
	return tail;
}
PNode initialize(int floor,int num)/////////是否直接加数值
{
	PNode head=createlist();
	PNode p=head;
	for (int i=1;i<=floor;i++)
	{
		for (int j=0;j<=num;j++)
		{
			p=initia_room(p,i*100+j,"dorm");
		}
	}
	writefile(head);
	return head;
	 
}
void check_in(PNode head)
{
	int number;
	printf("------------------------------------------------------\n");
	printf("Please enter the room number you want to or select to find all Available room(-1).\n");
	scanf("%d",&number);
	while (number<0)
	{
		ava_room(head);
		printf("Enter room number~\n");
		scanf("%d",&number);
	}
	while (whetherfull(head,number))
	{
		printf("This room has no place!Please select another!\n");
		scanf("%d",&number);
	}
	printf("OK!\n");
	PNode room=searchroom(head,number);
	room_t bookroom={number,"dorm","",2,0,0,0,300};
	char date[11];

	printf("Please enter the data you arrive(in the format-- 01/02/1999)\n");
	PNode p=searchNode(room,"arrival",7);
	scanf("%s",date);


	int night;
	printf("Please enter the nights you live\n");
	scanf("%d",&night);


	int number_1;
	printf("Please enter the number of the vistors number\n");
	scanf("%d",&number_1);


	strcpy(bookroom.arrival_data,date);
	bookroom.vistors=number_1;
	bookroom.nights=night;
	

	char s[2];
	printf("Whether you would take the breakfast (y/n) ? which would add $10 per day.\n");
	scanf("%s",s);


	if (s[0]=='y')
	{
		bookroom.breakfast=bookroom.vistors;
		bookroom.price+=10*number_1;
	}
	else
	{
		bookroom.breakfast=0;
	}

	alter_room(head,number,bookroom);

	p=searchNode(room,"vis",3);

	for (int i=1;i<=number_1;i++)
	{
		char name[20]="";
		char ID[11]="";
		printf("Please enter the name of the %d vistor's name\n", i);
		scanf("%s",name);
		printf("Please enter the ID of the %d vistors\n",i );
		scanf("%s",ID);
		vistor_t s={"",""};
		strcpy(s.name,name);
		strcpy(s.ID,ID);
		p=addvisitors(p,s,i);
	}

	printf("Successfully booked! Please confirm your information\n");
	printf("\n");
	p = room;
	PNode q = find_next(room);
	while (p!=q)
	{
		printf("%s\n",p->content);
		p=p->next;
	}
	printf("------------------------------------------------------\n");

	writefile(head);

	return ;


}
void check_out(PNode head)
{
	int room_num;
	printf("------------------------------------------------------\n");
	printf("Please enter the room number you want to check out\n");
	scanf("%d",&room_num);
	printf("------------------------------------------------------\n");
	PNode room=searchroom(head,room_num);
	PNode p;
	printf("Successfully check out!\n");
	printf("\n");
	printf("your reciept!\n\n");
	printf("You booked the %s\n",room->content);
	p=searchNode(room,"name",4);
	printf("vistors:\n");
	while (p->content[0]=='n' || p->content[0]=='i')
	{
		printf("%s\n",p->content);
		p=p->next;
	}
	printf("\n");
	
	p=searchNode(room,"breakfast",5);
	for (int i=0;i<3;i++)
	{
		
		printf("%s\n", p->content);
		p=p->next;
	}
	FILE *pfile=fopen("reciept.db","a");
	PNode q=find_next(room);
	p=room;
	while (p!=q)
	{
		fprintf(pfile, "%s\n",p->content );
		p=p->next;
	}
	room_t newroom={room_num,"dorm","01/01/1999",0,0,0,0,0};
	alter_room(head,room_num,newroom);
	writefile(head);

}

void money(PNode head)
{
	PNode p = head->next;
	int total=0;
	printf("------------------------------------------------------\n");
	while (p!=NULL)
	{
		int tot=0;
		int ind=0;
		if (p->content[0]=='p')
		{
			while (p->content[6+ind]<='9' && p->content[6+ind]>='0')
			{
				tot=tot*10+p->content[6+ind]-'0';
				ind+=1;
			}
		}
		total+=tot;
		p=p->next;
	}
	printf("In this day you can receive the money %d\n",total);
	printf("------------------------------------------------------\n");
}
void ava_room(PNode head)
{
	PNode p=head->next;
	printf("------------------------------------------------------\n");
	printf("Available room:---->\n");
	while (p!=NULL)
	{
		if (!whetherfull1(head,p))
		{
			PNode q=searchNode(p,"type",4);
			printf("%s ",p->content );
			printf("%s\t",q->content );
		}
		p=find_next(p);
	}
	printf("\n------------------------------------------------------\n");
}
PNode readreciept()
{
	
	FILE * pfile = fopen("reciept.db","r");
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
void guest(PNode head)
{
	PNode guest=createlist();
	PNode q=guest;
	PNode p=head->next;
	PNode m;
	while (p!=NULL)
	{

		if (whetherfull1(head,p))
		{
			int tot=0;
			int ind=0;
			m=searchNode(p,"vis",3);
			while (m->content[8+ind]<='9' && m->content[8+ind]>='0')
			{
				tot=tot*10+m->content[8+ind]-'0';
				ind+=1;
			}
			ind=0;
			while( ind <tot) 
			{
				
				m=searchNode(m,"name",4);
				char content[30];
				strcpy(content,m->content);
				content[5]=':';
				content[4]=':';
				addnode(q,content);
				q=q->next;
				m=m->next;
				strcpy(content,m->content);
				content[3]=':';
				content[2]=':';
				addnode(q,content);
				q=q->next;
				strcpy(content,"state: still in the hotel");
				addnode(q,content);
				q=q->next;
				ind+=1; 
				
			}

		}
		p=find_next(p);
	}

	PNode old_guest=readreciept();
	p=old_guest->next;
	while (p!=NULL)
	{
			int tot=0;
			int ind=0;
			m=searchNode(p,"vis",3);
			while (m->content[8+ind]<='9' && m->content[8+ind]>='0')
			{
				tot=tot*10+m->content[8+ind]-'0';
				ind+=1;
			}
			ind=0;
			while( ind <tot) 
			{
				
				m=searchNode(m,"name",4);
				char content[30];
				strcpy(content,m->content);
				content[5]=' ';
				content[4]=':';
				addnode(q,content);
				q=q->next;
				m=m->next;
				strcpy(content,m->content);
				content[3]=' ';
				content[2]=':';
				addnode(q,content);
				q=q->next;
				strcpy(content,"state: Arealdy leaved");
				addnode(q,content);
				q=q->next;
				ind+=1; 
			}

		p=find_next(p);
	}
	sort_byname(guest);
	q=guest;

	printf("------------------------------------------------------\n");
	printf("There are all the information of the guest!\n");
	q=q->next;
	while (q!=NULL)
	{
		for (int i=0;i<3;i++)
		{
			printf("%s\n",q->content );
			q=q->next;
		}
		printf("-------------------\n");

	}
	printf("------------------------------------------------------\n");

}



void sort_byname(PNode head)
{
	PNode p_0=head;
	PNode p=p_0->next;
	PNode q;
	PNode p_tail;
	PNode q_tail;
	PNode q_0;

	while ((p!=NULL) && (p->next->next->next!=NULL))
	{	

		p_tail=p->next->next;
		q_0=p_tail;
		q=q_0->next;

		while (q!=NULL)
		{
			

			p_tail=p->next->next;
			q_tail=q->next->next;
			int i=6;
			char name1[30]="";
			char name2[30]="";
			while (p->content[i]!='\0')
			{
				name1[i-6]=p->content[i];
				i+=1;
			}
			name1[i-6]='\0';
			i=6;
			while (q->content[i]!='\0')
			{
				name2[i-6]=q->content[i];
				i+=1;
			}
			name2[i-6]='\0';

			if (strcmp(name1,name2)>0)
			{
				
				if (p_tail==q_0)
				{
					p_tail->next=q_tail->next;
					q_tail->next=p;
					p_0->next=q;
					q_0=q_tail;
				}
				else
				{
					p_0->next=q;
					PNode nextp=p_tail->next;
					p_tail->next=q_tail->next;
					q_tail->next=nextp;
					q_0->next=p;
				}
			}
			q_0=q_0->next->next->next;
			q=q_0->next;
			p=p_0->next;
		}

		p_0=p_0->next->next->next;
		p=p_0->next;
	}
}
void alter_information(PNode head)
{
	int room_num;
	printf("Enter the room number\n");
	scanf("%d",&room_num);
	PNode room=searchroom(head,room_num);
	int sel;
	do{
	printf("Please select the information you want to alter!\n");
	printf("1 - breakfast \n");
	printf("2 - nights\n");
	printf("3 - quit\n");
	scanf("%d",&sel);
	PNode bf;
	char bf_str[4];
	char content[30];
	PNode night_p;
	switch (sel)
	{
		case 1:
			bf=searchNode(room,"breakfast",5);

			printf("At present  %s\n",bf->content );
			strcpy(bf_str,"");
			printf("Please enter how many breakfast you need?\n");
			scanf("%s",bf_str);
			
			strcpy(content,"breakfast=");
			strcat(content,bf_str);
			strcpy(bf->content,content);
			break;
		case 2:
			night_p=searchNode(room,"night",5);
			printf("At present you book %s\n",night_p->content );
			printf("You would like to add nights or decline nights\n");
			int num;
			printf("1 - add\n");
			printf("2 - decline\n");
			printf("3 - quit\n");
			scanf("%d",&num);
			switch (num)
			{
				case 1:
					addnight(night_p);
					break;
				case 2:
					minusnight(night_p);
					break;
				case 3:break;
			}
		case 3:break;
	}
}while (sel!=3);

}
