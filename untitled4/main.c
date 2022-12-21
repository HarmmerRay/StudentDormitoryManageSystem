#include <stdio.h>
#include <mqoai.h>

typedef struct{
    int number;
    char name[20];
    _Bool gender;
    int building;
    int room;
}Student;
typedef struct {
    Student s[20];
    int length;
}Sqlist;

int RoomStuNum(Sqlist l,int building,int room){
    int i=1;
    l.length=0;
    FILE *fp1;
    fp1= fopen("data.txt","r+");
    while(!feof(fp1)){
        fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
        l.length++;
        i++;
    }
    fclose(fp1);
    int num=0;
    for (i = 1; i <=l.length; ++i) {
        if( l.s[i].building==building && l.s[i].room==room){
            num++;
        }
    }
    return num;
}
void createStudent(Sqlist l,int n){
    l.length=0;
    for(int i=1;i<=n;i++){
        printf("�����%d��ѧ����Ϣ\n",i);
        printf("ѧ�ţ�");
        scanf("%d",&l.s[i].number);
        getchar();
        printf("������");
        scanf("%s",&l.s[i].name);
        getchar();
        printf("�Ա�");
        scanf("%d",&l.s[i].gender);
        getchar();
        printf("¥�ţ�");
        scanf("%d",&l.s[i].building);
        getchar();
        //���� 1,2,3����¥  Ů��4��5��6����¥

        printf("����ţ�");
        scanf("%d",&l.s[i].room);
        getchar();
        //�жϴ˷�����м����� <6�˲��ܷ���

        if(l.s[i].gender==0) {
            if (l.s[i].building == 4 || l.s[i].building == 5 || l.s[i].building == 6) {
            } else {
                printf("Ů����������4,5,6������¥!������Ϊ���������¥����������¥�ţ�");
                scanf("%d", &l.s[i].building);
                getchar();
            }
        }else{
            if(l.s[i].building==1 ||l.s[i].building==2 ||l.s[i].building==3){
            }else{
                printf("������������1,2,3������¥!������Ϊ���������¥����������¥�ţ�");
                scanf("%d",&l.s[i].building);
                getchar();
            }
        }
        if(RoomStuNum(l,l.s[i].building,l.s[i].room)>=6){
            printf("������������Ѿ����ˣ�������Ϊ���������,��������ţ�");
            scanf("%d",&l.s[i].room);

        }
        l.length++;
    }
    FILE *fp;
    fp= fopen("data.txt","a");
    for(int i=1;i<=l.length;i++){
        fprintf(fp,"%d %s %d %d %d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
    }
    printf("��ӳɹ�!\n");
    fclose(fp);
}

void NameSort(Sqlist l){//����������
    int i=1,j;
    l.length=0;
    FILE *fp1;
    fp1=fopen("data.txt","r+");
    while(!feof(fp1)){
        fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
        l.length++;
        i++;
    }
    l.length--;
    fclose(fp1);
    for(i=1;i<l.length;i++)
    {
        for(j=1;j<=l.length-i;j++)
        {
            if(strcmp(l.s[j].name,l.s[j+1].name)>=0){//ѡ������
                l.s[0]=l.s[j];
                l.s[j]=l.s[j+1];
                l.s[j+1]=l.s[0];
            }
        }
    }
    printf("����������Ϊ��\n");
    for(int i=1;i<=l.length;i++)
    {
        printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
    }
    printf("����ɹ�!\n");
}

void numberSort(Sqlist l){  //��ѧ������
    int i=1;
    l.length=0;
    FILE *fp1;
    fp1= fopen("data.txt","r+");
    while (!feof(fp1)){
        fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
        l.length++;
        i++;
    }
    l.length--;
    fclose(fp1);
    for(i=2;i<=l.length;i++)
    {
        if(l.s[i].number<l.s[i-1].number)
        {
            l.s[0]=l.s[i];
            l.s[i]=l.s[i-1];
            int j;
            for(j=i-2;l.s[0].number<l.s[j].number;j--)
            {
                l.s[j+1]=l.s[j];
            }
            l.s[j+1]=l.s[0];
        }
    }
    printf("��ѧ������Ϊ��\n");
    for(int i=1;i<=l.length;i++)
    {
        printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
    }
    printf("����ɹ�!\n");
}


void BuildingSort(Sqlist l)//��¥�Ž�������
{
    int i=1;
    l.length=0;
    FILE *fp1;
    fp1=fopen("data.txt","r+");
        while(!feof(fp1))
        {
            fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
            l.length++;
            i++;
        }
        l.length--;
        fclose(fp1);
        for(i=2;i<=l.length;i++)
        {
            if(l.s[i].building<l.s[i-1].building)
            {
                l.s[0]=l.s[i];
                l.s[i]=l.s[i-1];
                int j;
                for(j=i-2;l.s[0].building<l.s[j].building;j--)
                {
                    l.s[j+1]=l.s[j];
                }
                l.s[j+1]=l.s[0];
            }
        }
        printf("��¥������Ϊ��\n");
        for(int i=1;i<=l.length;i++)
        {
            printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
        }
        printf("����ɹ�!\n");
}
void NumberSearch(Sqlist l){ //��ѧ�Ų�ѯ
        int i=1,k,flag=0;
        int num;
        l.length=0;
        FILE *fp1;
        fp1=fopen("data.txt","r+");
            while(!feof(fp1)){
                fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
                l.length++;
                i++;
            }
            l.length--;
            fclose(fp1);
            printf("����Ҫ��ѯѧ����ѧ�ţ�\n");
            scanf("%d",&num);
            for(i=1;i<=l.length;i++){
                if(l.s[i].number==num){
                    k=i;
                    flag=1;
                }
            }
            if(flag==0) printf("û���ҵ���ѧ������ѯʧ�ܣ�\n");
            else
            printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[k].number,l.s[k].name,l.s[k].gender,l.s[k].building,l.s[k].room);
}
void NameSearch(Sqlist l){//��������ѯ
        int i=1,k,flag=0;
        char na[20];
        l.length=0;
        FILE *fp1;
        fp1=fopen("data.txt","r+");
            while(!feof(fp1)){
                fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
                l.length++;
                i++;
            }
            l.length--;
            fclose(fp1);
            printf("����Ҫ��ѯѧ����������\n");
            scanf("%s",na);
            for(i=1;i<=l.length;i++){
                if(strcmp(l.s[i].name,na)==0){
                    k=i;
                    flag=1;
                }
            }
            if(flag==0) printf("û���ҵ���ѧ������ѯʧ�ܣ�\n");
            else
            printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[k].number,l.s[k].name,l.s[k].gender,l.s[k].building,l.s[k].room);
}
void RoomSearch(Sqlist l){
        int i=1,flag=0;
        int room;
        l.length=0;
        FILE *fp1;
        fp1=fopen("data.txt","r+");
            while(!feof(fp1)){
                fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
                l.length++;
                i++;
            }
            l.length--;
            fclose(fp1);
            printf("����Ҫ��ѯѧ���ķ���ţ�\n");
            scanf("%d",&room);
            for(i=1;i<=l.length;i++){
                if(l.s[i].room==room){
                    printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
                    flag=1;
                }
            }
            if(flag==0)
            printf("û���ҵ��÷���ţ���ѯʧ�ܣ�\n");
}
void ShowRoom(Sqlist l){
        int i=1;
        l.length=0;
        FILE *fp1;
        fp1=fopen("data.txt","r+");
            while(!feof(fp1)){
                fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
                l.length++;
                i++;
            }
            fclose(fp1);
            for(i=1;i<=l.length;i++){
                printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
            }
}
void Sort_select(int array[10]){
    int begin=array[0];
    for (int j = 0; j < 10-1; ++j) {
        for (int i = j+1; i < 10; ++i) {
            if(begin>array[i]){
                int tmp=begin;
                begin=array[i];
                array[i]=tmp;
            }
        }
        array[j]=begin;
    }
}
void Sort_insert(int array[10],int n){
    int i, j, temp;
    for(i = 1; i < n; i++){ //��ԭ����ĵڶ���Ԫ�ؽ��бȽϣ�Ĭ�ϵ�һ��Ԫ���Ѿ����ź���ģ�
        if(array[i] < array[i-1]){  //��ǰ���Ѿ��ź����Ԫ�رȵ�ǰԪ�ش�ʱ����temp��ʱ�����洢
            temp = array[i];
            for (j = i-1;j >= 0 && array[j] > temp; j--) {    //���ǰ�������Ѿ��źõ�Ԫ��
                array[j+1] = array[j];//����Ԫ������Ų��һλ
            }
            array[j+1] = temp;//��temp���ֵ���Ƶ�����λ��
        }
    }
}
void Sort_bubble(int array[10],int length){
    for (int i = 0; i < length; ++i) {  //ð������ һ��ѭ��Ƕ��
        for (int j = i; j <length; ++j) {// һ��һ������ȣ���ǰ����ں����򽻻�
            if(array[j]>array[j+1]){
                int tmp=array[j+1];
                array[j+1]=array[j];
                array[j]=array[j+1];
            }
        }
    }
}
int main(){
    Sqlist l;
    int n,option;
    printf("********��ӭ������������ѯϵͳ**************\n");
    ShowRoom(l);
    while(1)
    {
        printf("****************************************");
        printf("\n1.����\t2.��ѧ������\n");
        printf("\n3.����������\t4.��¥������\n");
        printf("\n5.��ѧ�Ų�ѯ\t6.��������ѯ\n");
        printf("\n7.��¥�Ų�ѯ\t8.�˳�\n");
        printf("****************************************");
        printf("\n��ѡ����Ҫ�ķ���:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("������ѧ������:");
                scanf("%d",&n);
                createStudent(l,n);
                break;
            case 2:
                numberSort(l);
                break;
            case 3:
                NameSort(l);
                break;
            case 4:
                BuildingSort(l);
                break;
            case 5:
                NumberSearch(l);
                break;
            case 6:
                NameSearch(l);
                break;
            case 7:
                RoomSearch(l);
                break;
            case 8:
                exit(0);
                break;
        }
    }
    return 0;
}
