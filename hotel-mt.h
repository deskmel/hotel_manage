
#ifndef HOTEL_MAIN_C_HOTEL_MT_H
#define HOTEL_MAIN_C_HOTEL_MT_H


typedef struct room
{
    int room_index;
    char room_type[10];
    char arrival_data[11];
    int keys;
    int vistors;
    int nights;
    int breakfast;
    int price;
}room_t;
typedef struct visitor
{
    char name[11];
    char ID[11];
}vistor_t;//
PNode addvisitors(PNode p,struct visitor s,int i);
PNode find_next(PNode room);
void alter_room(PNode head,int room_index,struct room s);
PNode initia_room(PNode head,int room_index,const char *type);
PNode initialize(int floor,int num);/////////是否直接加数值
void ava_room(PNode head);
void check_in(PNode head);
void check_out(PNode head);
void money(PNode head);
void sort_byname(PNode head);
PNode readreciept();
void guest(PNode head);
void sort_byname(PNode head);
void alter_information(PNode head);
// Created by asus on 2018/7/17.
//

#endif //HOTEL_MAIN_C_HOTEL_MT_H
