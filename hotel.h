

/*
type:
	0 room_index
	1 room_type
	2 arrival_time
	3 visitors
	4 visitor_name
	5 visitor_id
	6 keys
	7 breakfast
	8 nights
	9 price
*/
PNode createlist();
void addnode(PNode n,char content[30]);
void deleteNode(PNode n);
PNode searchNode(PNode head,const char *value,int len);