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
        printf("输入第%d个学生信息\n",i);
        printf("学号：");
        scanf("%d",&l.s[i].number);
        getchar();
        printf("姓名：");
        scanf("%s",&l.s[i].name);
        getchar();
        printf("性别：");
        scanf("%d",&l.s[i].gender);
        getchar();
        printf("楼号：");
        scanf("%d",&l.s[i].building);
        getchar();
        //男生 1,2,3宿舍楼  女生4，5，6宿舍楼

        printf("房间号：");
        scanf("%d",&l.s[i].room);
        getchar();
        //判断此房间号有几个人 <6人才能分配

        if(l.s[i].gender==0) {
            if (l.s[i].building == 4 || l.s[i].building == 5 || l.s[i].building == 6) {
            } else {
                printf("女生的宿舍是4,5,6号宿舍楼!请重新为其分配宿舍楼，输入宿舍楼号：");
                scanf("%d", &l.s[i].building);
                getchar();
            }
        }else{
            if(l.s[i].building==1 ||l.s[i].building==2 ||l.s[i].building==3){
            }else{
                printf("男生的宿舍是1,2,3号宿舍楼!请重新为其分配宿舍楼，输入宿舍楼号：");
                scanf("%d",&l.s[i].building);
                getchar();
            }
        }
        if(RoomStuNum(l,l.s[i].building,l.s[i].room)>=6){
            printf("该宿舍的人数已经满了！请重新为其分配宿舍,输入宿舍号：");
            scanf("%d",&l.s[i].room);

        }
        l.length++;
    }
    FILE *fp;
    fp= fopen("data.txt","a");
    for(int i=1;i<=l.length;i++){
        fprintf(fp,"%d %s %d %d %d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
    }
    printf("添加成功!\n");
    fclose(fp);
}

void NameSort(Sqlist l){//按姓名排序
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
            if(strcmp(l.s[j].name,l.s[j+1].name)>=0){//选择排序
                l.s[0]=l.s[j];
                l.s[j]=l.s[j+1];
                l.s[j+1]=l.s[0];
            }
        }
    }
    printf("按姓名排序为：\n");
    for(int i=1;i<=l.length;i++)
    {
        printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
    }
    printf("排序成功!\n");
}

void numberSort(Sqlist l){  //按学号排序
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
    printf("按学号排序为：\n");
    for(int i=1;i<=l.length;i++)
    {
        printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
    }
    printf("排序成功!\n");
}


void BuildingSort(Sqlist l)//按楼号进行排序
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
        printf("按楼号排序为：\n");
        for(int i=1;i<=l.length;i++)
        {
            printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
        }
        printf("排序成功!\n");
}
void NumberSearch(Sqlist l){ //按学号查询
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
            printf("输入要查询学生的学号：\n");
            scanf("%d",&num);
            for(i=1;i<=l.length;i++){
                if(l.s[i].number==num){
                    k=i;
                    flag=1;
                }
            }
            if(flag==0) printf("没有找到该学生，查询失败！\n");
            else
            printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[k].number,l.s[k].name,l.s[k].gender,l.s[k].building,l.s[k].room);
}
void NameSearch(Sqlist l){//按姓名查询
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
            printf("输入要查询学生的姓名：\n");
            scanf("%s",na);
            for(i=1;i<=l.length;i++){
                if(strcmp(l.s[i].name,na)==0){
                    k=i;
                    flag=1;
                }
            }
            if(flag==0) printf("没有找到该学生，查询失败！\n");
            else
            printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[k].number,l.s[k].name,l.s[k].gender,l.s[k].building,l.s[k].room);
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
            printf("输入要查询学生的房间号：\n");
            scanf("%d",&room);
            for(i=1;i<=l.length;i++){
                if(l.s[i].room==room){
                    printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
                    flag=1;
                }
            }
            if(flag==0)
            printf("没有找到该房间号，查询失败！\n");
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
                printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
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
    for(i = 1; i < n; i++){ //从原数组的第二个元素进行比较，默认第一个元素已经是排好序的，
        if(array[i] < array[i-1]){  //当前方已经排好序的元素比当前元素大时，用temp临时变量存储
            temp = array[i];
            for (j = i-1;j >= 0 && array[j] > temp; j--) {    //检查前面所有已经排好的元素
                array[j+1] = array[j];//所有元素往后挪动一位
            }
            array[j+1] = temp;//将temp里的值复制到插入位置
        }
    }
}
void Sort_bubble(int array[10],int length){
    for (int i = 0; i < length; ++i) {  //冒泡排序 一个循环嵌套
        for (int j = i; j <length; ++j) {// 一下一下往后比，若前面大于后面则交换
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
    printf("********欢迎进入宿舍管理查询系统**************\n");
    ShowRoom(l);
    while(1)
    {
        printf("****************************************");
        printf("\n1.创建\t2.按学号排序\n");
        printf("\n3.按姓名排序\t4.按楼号排序\n");
        printf("\n5.按学号查询\t6.按姓名查询\n");
        printf("\n7.按楼号查询\t8.退出\n");
        printf("****************************************");
        printf("\n请选择需要的服务:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("请输入学生个数:");
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
