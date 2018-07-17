//
// Created by asus on 2018/7/17.
//

#ifndef HOTEL_MAIN_C_HOTEL_LL_H
#define HOTEL_MAIN_C_HOTEL_LL_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
typedef struct Node{ char content[30]; struct Node *next;} node_t,*PNode;
void itoa_1 (int n,char s[],int k);
PNode createlist();
void addnode(PNode n,char content[30]);
void deleteNode(PNode n);
PNode searchNode(PNode head,const char *value,int len);
#endif //HOTEL_MAIN_C_HOTEL_LL_H
