//
// Created by asus on 2018/7/17.
//

#ifndef HOTEL_MAIN_C_HOTEL_DB_H
#define HOTEL_MAIN_C_HOTEL_DB_H
PNode readfile();
void writefile(PNode head);
PNode searchroom(PNode head,int room);
void addbreakfasts(PNode room_node);
void addnight(PNode room_node);
void minusnight(PNode room_node);
void adjustprice(PNode room_node, int price);
void setdate(PNode room_node,char *date);
bool whetherfull(PNode head,int room);
bool whetherfull1(PNode head,PNode room_1);
#endif //HOTEL_MAIN_C_HOTEL_DB_H
