#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct{
    char name[20];
}Name;

int RoomStuNum(Sqlist l,int building,int room){  //返回那个房间现在的学生人数
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

void Sort_select(int array[10],int length){
    int begin,location;
    for (int j = 0; j < length-1; ++j) {
        begin=array[j];
        location=j;
        for (int i = j+1; i < length; ++i) {//找出除j往后 最小的数，
            if(begin>array[i]){
                begin=array[i];
                location=i;
            }
        }
        int tmp=array[j];  //交换最小的数和 哨兵数的值
        array[j]=begin;
        array[location]=tmp;
    }
}

int* Sort_insert(int array[10],int length){
    int i, j, temp;
    for(i = 1; i < length; i++){ //从原数组的第二个元素进行比较，默认第一个元素已经是排好序的，
        if(array[i] < array[i-1]){  //当前方已经排好序的元素比当前元素大时，用temp临时变量存储
            temp = array[i];
            for (j = i-1;j >= 0 && array[j] > temp; j--) {    //检查前面所有已经排好的元素
                array[j+1] = array[j];//此元素到比它大的元素之间 所有元素往后挪动一位
            }
            array[j+1] = temp;//将temp里的值复制到插入位置
        }
    }
    return array;

}

void Sort_bubble(int array[10],int length){
    for (int i = 0; i < length; ++i) {  //冒泡排序 一个循环嵌套
        for (int j = 0; j <length-i; ++j) {// 一下一下往后比，若前面大于后面则交换
            if(array[j]>array[j+1]){
                int tmp=array[j+1];
                array[j+1]=array[j];
                array[j]=tmp;
            }
        }
    }
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
        printf("房间号：");
        scanf("%d",&l.s[i].room);
        getchar();
        //判断此房间号有几个人 <6人才能分配

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
Sqlist NameSort1(Sqlist l){
    Student begin;
    int location;
    for (int j = 0; j < l.length-1; ++j) {   //选择排序
        begin=l.s[j];
        location=j;
        for (int i = j+1; i < l.length; ++i) {//找出除j往后 最小的数，
            if(strcmp(begin.name,l.s[i].name)>=0){
                begin=l.s[i];
                location=i;
            }
        }
        Student tmp=l.s[j];  //交换最小的数和 哨兵数的值
        l.s[j]=begin;
        l.s[location]=tmp;
    }
    return l;
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
    fclose(fp1);
    for(i=1;i<l.length;i++)
    {
        for(j=1;j<l.length-i;j++)
        {
            if(strcmp(l.s[j].name,l.s[j+1].name)>=0){//选择排序
                l.s[0]=l.s[j];   //拿l.s[o]当作哨兵
                l.s[j]=l.s[j+1];
                l.s[j+1]=l.s[0];
            }
        }
    }
    printf("按姓名排序为：\n");
    for(int i=1;i<l.length;i++)
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
    for(i=2;i<=l.length;i++)//插入排序
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

Sqlist BuildingSort1(Sqlist l){
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
//        l.length--;
    fclose(fp1);
    int arr[l.length];
    for (int j = 0; j < l.length; ++j) {
        arr[j]=l.s[i].building;
    }
    return l;
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

    for (int i = 1; i <= l.length; ++i) {  //冒泡排序
        for (int j = 1; j <=l.length-i; ++j) {
            if(l.s[j].building>l.s[j+1].building){
                int tmp=l.s[j+1].building;
                l.s[j+1].building=l.s[j].building;
                l.s[j].building=tmp;
            }
        }
    }

    printf("按楼号排序为：\n");
    for(int i=1;i<=l.length;i++)
    {
        printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
    }
    printf("排序成功!\n");
}
int BinarySearch(int arr[], int low, int high, int target) {
    if (low > high)return -1;
    else {
        int mid = (low + high) / 2;
        if (target < arr[mid]) return BinarySearch(arr, low, mid - 1, target);
        else if (target > arr[mid]) return BinarySearch(arr, mid + 1, high, target);
        else return mid;
    }
}

int BinarySearch1(Name arr[],int low,int high,char *target){

    if(low>high) return -1;
    else{
        int mid=(low+high)/2;
        if(strcmp(arr[mid].name,target)==0) {
            return mid;
        }
        else{
            if (strcmp(arr[mid].name,target)>0) {
                return BinarySearch1(arr, low, mid - 1, target);
            }
            else {
                return BinarySearch1(arr, mid + 1, high, target);
            }
        }
    }
}

void NumberSearch(Sqlist l){ //按学号查询
    int i=0,k;
    int num;
    l.length=0;
    FILE *fp1;
    fp1=fopen("data.txt","r+");
        while(!feof(fp1)){
            fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
            l.length++;
            i++;
        }
        fclose(fp1);
        printf("输入要查询学生的学号：\n");
        scanf("%d",&num);
        //二分查找  先排序再查找
        for (int i = 0; i < l.length; ++i) {  //冒泡排序 一个循环嵌套
            for (int j = 0; j <l.length-i; ++j) {// 一下一下往后比，若前面大于后面则交换
                if(l.s[j].number>l.s[j+1].number){
                    Student tmp=l.s[j+1];
                    l.s[j+1]=l.s[j];
                    l.s[j]=tmp;
                }
            }
        }
        int arr[l.length];
        for (int j = 0; j < l.length; ++j) {
            arr[j]=l.s[j].number;
        }
        k=BinarySearch(arr,0,l.length,num);
        if(k==-1) printf("没有找到该学生，查询失败！\n");
        else
        printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[k].number,l.s[k].name,l.s[k].gender,l.s[k].building,l.s[k].room);
}

void NameSearch(Sqlist l){//按姓名查询
    Name name;
    int i=0,k;
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
    scanf("%s",name.name);
    getchar();
    //二分查找
    // 先排序
    l=NameSort1(l);

        Name arr[20];
        for (int j = 0; j < 20; ++j) {
            for (int m = 0; m < 20; ++m) {
                arr[j].name[m] = l.s[j].name[m];
            }
        }
    //再查找
    k=BinarySearch1(arr,0,l.length,name.name);

    if(k==-1) printf("没有找到该学生，查询失败！\n");
    else
        printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[k].number,l.s[k].name,l.s[k].gender,l.s[k].building,l.s[k].room);
}
int BinarySearch2(Sqlist l, int low, int high, int target) {
    if (low > high)return -1;
    else {
        int mid = (low + high) / 2;
        if (target < l.s[mid].room) return BinarySearch2(l, low, mid - 1, target);
        else if (target > l.s[mid].room) return BinarySearch2(l, mid + 1, high, target);
        else return mid;
    }
}
void RoomSearch(Sqlist l){
    int i=1,flag=0;
    int building,room;
    l.length=0;
    FILE *fp1;
    fp1=fopen("data.txt","r+");
    while(!feof(fp1)){
        fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
        l.length++;
        i++;
    }

    fclose(fp1);
    printf("输入要查询学生的楼号和房间号：\n");
    scanf("%d%d",&building,&room);
        //宿舍楼比较少 用顺序查找就可以 ，房间号比较多 用二分查找提高效率
    Sqlist l1;
    l1.length=0;
    int m=0;   // 7E-330-name
    for (int j = 0; j < l.length; ++j) {
        if(l.s[j].building==building){
            l1.s[m]=l.s[j];
            ++m;
            l1.length++;
        }
    }     //得到某个楼的学生的信息

    Student temp;//按寝室号来对一栋楼sqlist排序
    int j;
    for(i = 1; i < l1.length; i++){ //从原数组的第二个元素进行比较，默认第一个元素已经是排好序的，
        if(l1.s[i].room<l1.s[i-1].room){  //当前方已经排好序的元素比当前元素大时，用temp临时变量存储
            temp = l1.s[i];
            for (j = i-1;j >= 0 && l1.s[j].room > temp.room; j--) {    //检查前面所有已经排好的元素
                l1.s[j+1] = l1.s[j];//所有元素往后挪动一位
            }
            l1.s[j+1] = temp;//将temp里的值复制到插入位置
        }
    }//得到某个楼根据房间号排完序的学生的信息

    Sqlist l2;
    int n=0;
    int tmp=BinarySearch2(l1,0,l1.length,room);
    //第一次二分查找到第一个室友 返回其数组中的位置,进行第二次二分查找的前提是数组有序，但是如果给数组排完序，数组的下标与对应的sqlist下标不再对应,导致无法正常输出
    //repair:二分查找sqllist 给l.s[i].room修改值，然后排序序，再找下一个
    while (tmp!=-1){
        l2.s[n]=l1.s[tmp];
        l1.s[tmp].room=-520;
        for (int i = 0; i < l1.length; ++i) {  //冒泡排序 一个循环嵌套
            for (int j = 0; j <l1.length-i; ++j) {// 一下一下往后比，若前面大于后面则交换
                if(l1.s[j].room>l1.s[j+1].room){
                    Student tmp=l1.s[j+1];
                    l1.s[j+1]=l1.s[j];
                    l1.s[j]=tmp;
                }
            }
        }
        n++;
        tmp=BinarySearch2(l1,0,l1.length,room);
    }       //得到某个楼某个房间的学生的信息
    for (int j = 0; j < n; ++j) {
        printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l2.s[j].number,l2.s[j].name,l2.s[j].gender,l2.s[j].building,l2.s[j].room);
        flag=1;
    }
    if(flag==0)
    printf("没有找到该房间号，查询失败！\n");
}
void ShowRoom(Sqlist l){
    int i=0;
    l.length=0;
    FILE *fp1;
    fp1=fopen("data.txt","r+");
        while(!feof(fp1)){
            fscanf(fp1,"%d %s %d %d %d",&l.s[i].number,&l.s[i].name,&l.s[i].gender,&l.s[i].building,&l.s[i].room);
            l.length++;
            i++;
        }
        fclose(fp1);
        for(int j=0;j<l.length-1;j++){
            printf("学号:%d  姓名:%s  性别:%d  楼号:%d  房间号:%d\n",l.s[j].number,l.s[j].name,l.s[j].gender,l.s[j].building,l.s[j].room);
        }
}

int main(){
    Sqlist l;
    int n,option;

    printf("********欢迎进入宿舍管理查询系统**************\n");
    ShowRoom(l);
    while(1)
    {
        fflush(stdin);
        printf("****************************************");
        printf("\n1.创建\t2.按学号排序\n");
        printf("\n3.按姓名排序\t4.按楼号排序\n");
        printf("\n5.按学号查询\t6.按姓名查询\n");
        printf("\n7.按房号查询\t8.退出\n");
        printf("****************************************");
        printf("\n请选择需要的服务:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("请输入学生个数:");
                scanf("%d",&n);
                createStudent(l,n);
                ShowRoom(l);
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
            default:
                printf("输入正常范围的数字选择您要的功能 1~8");
                break;
        }
    }
    return 0;
}
