//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//
//typedef struct Node
//{
//    /*���룬��ţ�ָ����һ����ָ��*/
//    int pwd;//value
//    int num;
//    struct Node *next;//ָ����
//}Node,*LinkList;
//
////����һ���µ�����
//LinkList CreateList(int n,Node *L)
//{
//    LinkList p,s;
//    int i;
//    s=L;
//    //���δ����㣬����������
//    for(i=1;i<=n;i++)
//    {
//        p=(Node*)malloc(sizeof(Node));  //�����ռ� node
//        p->num=i;   //node ������num��   int num[20]  num[1]
//        printf("�����%d���˵�����:",i);
//        scanf("%d",&p->pwd);
//        s->next=p;
//        s=p;
//    }
//    L=L->next;
//
//    s->next=L;
//    //����һ���������˵ĵ�ѭ������
//    return L;
//}
//
////�����Ϣ ��m�ǳ�ʼ���룬n��������
//void PrintList(int m,int n,Node* L)
//{
//    LinkList p;
//    //x�������µ�����
//    int x,i;
//    p=L;
//    printf("\n���˳�򣨱�ţ����룩��");
//    //�ҵ���һ��Ҫ���ֵ���
//    for(i=1;i<m;i++)
//        p=p->next;
//
//    while(n)
//    {
//        x=p->next->pwd;//��ʱ���������
//        //�����ź������е�����
//        printf("%d(%d)  ",p->next->num,x);
//        //����
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
//    printf("����������:");
//    scanf("%d",&n);
//    printf("������ʼ����:");
//    scanf("%d",&m);
//    //���ú������������
//    //����Χ��Ȧ ��������������
//    CreateList(n,&L);
//    //��ʼԼɪ����Ϸ
//    PrintList(m,n,&L);
//}
