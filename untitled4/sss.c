//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//
//typedef struct Node
//{
//    /*密码，编号，指向下一结点的指针*/
//    int pwd;//value
//    int num;
//    struct Node *next;//指针域
//}Node,*LinkList;
//
////创建一个新的链表
//LinkList CreateList(int n,Node *L)
//{
//    LinkList p,s;
//    int i;
//    s=L;
//    //依次创造结点，并输入密码
//    for(i=1;i<=n;i++)
//    {
//        p=(Node*)malloc(sizeof(Node));  //申请块空间 node
//        p->num=i;   //node 可以用num找   int num[20]  num[1]
//        printf("输入第%d个人的密码:",i);
//        scanf("%d",&p->pwd);
//        s->next=p;
//        s=p;
//    }
//    L=L->next;
//
//    s->next=L;
//    //返回一个创建好了的单循环链表
//    return L;
//}
//
////输出信息 ，m是初始密码，n是总人数
//void PrintList(int m,int n,Node* L)
//{
//    LinkList p;
//    //x来保存新的密码
//    int x,i;
//    p=L;
//    printf("\n输出顺序（编号，密码）：");
//    //找到第一个要出局的人
//    for(i=1;i<m;i++)
//        p=p->next;
//
//    while(n)
//    {
//        x=p->next->pwd;//此时密码更新了
//        //输出编号和所持有的密码
//        printf("%d(%d)  ",p->next->num,x);
//        //出局
//        p->next=p->next->next;
//        for(i=1;i<x;i++)
//            p=p->next;
//        n--;
//    }
//}
//
//int main()
//{
//    Node L;
//    int m,n;
//    printf("输入总人数:");
//    scanf("%d",&n);
//    printf("输入起始密码:");
//    scanf("%d",&m);
//    //调用函数，进行输出
//    //把人围成圈 ，把密码分配给人
//    CreateList(n,&L);
//    //开始约瑟夫环游戏
//    PrintList(m,n,&L);
//}
