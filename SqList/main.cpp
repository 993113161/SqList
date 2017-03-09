//
//  main.cpp
//  SqList
//
//  Created by Imac on 17/2/11.
//  Copyright © 2017年 Imac. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

const int maxSize = 100;

typedef struct SLNode
{
    int data[maxSize];
    int length;
} Sqlist;

//找到元素在顺序表中的位置
int LocateElem(Sqlist L,int e)
{
    int i;    //元素下标
    for(i=0; i<L.length; i++)
    {
        if(e==L.data[i])
        {
            return i;
        }
    }
    return i;
}

//在顺序表中插入一个元素
int insert(Sqlist &L, int p, int e)
{
    int i;
    if( p<1 || p>L.length+1 || L.length>=maxSize-1 )
    {
        return 0; //插入失败返回0
    }
    for(i=L.length-1; i>=p-1; i++)
    {
        L.data[i+1]=L.data[i];
    }
    L.data[p]=e;
    L.length++;
    return 1; //插入成功返回1
}

void visit(Sqlist L)
{
    int i;
    for(i=0; i<=L.length; i++)
    {
        printf("第%d个元素是： %d\n",i+1,L.data[i]);
    }
}

int main(int argc, const char * argv[])
{
    Sqlist *L;
    L=(Sqlist *)malloc(sizeof(Sqlist));
    for(int i=0; i<5; i++)
    {
        insert(*L, i, i+1);
    }
    visit(*L);
    return 0;
}

