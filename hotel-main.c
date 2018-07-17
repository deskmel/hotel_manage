#include "hotel-ll.h"
#include "hotel-db.h"
#include "hotel-mt.h"

int main(int argc, char const *argv[])
{
	int sele;
	int floor;
	int room_1;
	PNode head=readfile();


	do{
	printf("----------------------------------------------------\n");
	printf("welcome to the hotel manage system\n");
	printf("1 - initial the hotel\n");
	printf("2 - check in\n");
	printf("3 - check out\n");
	printf("4 - calculate the money\n");
	printf("5 - check the guest info\n");
	printf("6 - alter the information\n");
	printf("7 - quit\n");
	printf("----------------------------------------------------\n");
	scanf("%d",&sele);
	switch(sele)
	{
		case 1:
		printf("How many floor? How many room each floor?\n");
		scanf("%d",&floor);
		scanf("%d",&room_1);

		head=initialize(floor,room_1); //stuct
		printf("success to generate %d floor %d rooms ' hotel\n",floor,room_1);
		break;
		case 2:
		check_in(head);
		break;
		case 3:
		check_out(head);
		break;
		case 4:
		money(head);
		break;
		case 5:
		guest(head);
		break;
		case 6:
		alter_information(head);
		break;
		default:
		break;
	}
    }
    while (sele!=7);
	return 0;
}
