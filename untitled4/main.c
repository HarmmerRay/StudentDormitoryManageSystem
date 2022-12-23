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

int RoomStuNum(Sqlist l,int building,int room){  //�����Ǹ��������ڵ�ѧ������
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
        for (int i = j+1; i < length; ++i) {//�ҳ���j���� ��С������
            if(begin>array[i]){
                begin=array[i];
                location=i;
            }
        }
        int tmp=array[j];  //������С������ �ڱ�����ֵ
        array[j]=begin;
        array[location]=tmp;
    }
}

int* Sort_insert(int array[10],int length){
    int i, j, temp;
    for(i = 1; i < length; i++){ //��ԭ����ĵڶ���Ԫ�ؽ��бȽϣ�Ĭ�ϵ�һ��Ԫ���Ѿ����ź���ģ�
        if(array[i] < array[i-1]){  //��ǰ���Ѿ��ź����Ԫ�رȵ�ǰԪ�ش�ʱ����temp��ʱ�����洢
            temp = array[i];
            for (j = i-1;j >= 0 && array[j] > temp; j--) {    //���ǰ�������Ѿ��źõ�Ԫ��
                array[j+1] = array[j];//��Ԫ�ص��������Ԫ��֮�� ����Ԫ������Ų��һλ
            }
            array[j+1] = temp;//��temp���ֵ���Ƶ�����λ��
        }
    }
    return array;

}

void Sort_bubble(int array[10],int length){
    for (int i = 0; i < length; ++i) {  //ð������ һ��ѭ��Ƕ��
        for (int j = 0; j <length-i; ++j) {// һ��һ������ȣ���ǰ����ں����򽻻�
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
        printf("����ţ�");
        scanf("%d",&l.s[i].room);
        getchar();
        //�жϴ˷�����м����� <6�˲��ܷ���

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
Sqlist NameSort1(Sqlist l){
    Student begin;
    int location;
    for (int j = 0; j < l.length-1; ++j) {   //ѡ������
        begin=l.s[j];
        location=j;
        for (int i = j+1; i < l.length; ++i) {//�ҳ���j���� ��С������
            if(strcmp(begin.name,l.s[i].name)>=0){
                begin=l.s[i];
                location=i;
            }
        }
        Student tmp=l.s[j];  //������С������ �ڱ�����ֵ
        l.s[j]=begin;
        l.s[location]=tmp;
    }
    return l;
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
    fclose(fp1);
    for(i=1;i<l.length;i++)
    {
        for(j=1;j<l.length-i;j++)
        {
            if(strcmp(l.s[j].name,l.s[j+1].name)>=0){//ѡ������
                l.s[0]=l.s[j];   //��l.s[o]�����ڱ�
                l.s[j]=l.s[j+1];
                l.s[j+1]=l.s[0];
            }
        }
    }
    printf("����������Ϊ��\n");
    for(int i=1;i<l.length;i++)
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
    for(i=2;i<=l.length;i++)//��������
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

    for (int i = 1; i <= l.length; ++i) {  //ð������
        for (int j = 1; j <=l.length-i; ++j) {
            if(l.s[j].building>l.s[j+1].building){
                int tmp=l.s[j+1].building;
                l.s[j+1].building=l.s[j].building;
                l.s[j].building=tmp;
            }
        }
    }

    printf("��¥������Ϊ��\n");
    for(int i=1;i<=l.length;i++)
    {
        printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[i].number,l.s[i].name,l.s[i].gender,l.s[i].building,l.s[i].room);
    }
    printf("����ɹ�!\n");
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

void NumberSearch(Sqlist l){ //��ѧ�Ų�ѯ
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
        printf("����Ҫ��ѯѧ����ѧ�ţ�\n");
        scanf("%d",&num);
        //���ֲ���  �������ٲ���
        for (int i = 0; i < l.length; ++i) {  //ð������ һ��ѭ��Ƕ��
            for (int j = 0; j <l.length-i; ++j) {// һ��һ������ȣ���ǰ����ں����򽻻�
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
        if(k==-1) printf("û���ҵ���ѧ������ѯʧ�ܣ�\n");
        else
        printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[k].number,l.s[k].name,l.s[k].gender,l.s[k].building,l.s[k].room);
}

void NameSearch(Sqlist l){//��������ѯ
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
    printf("����Ҫ��ѯѧ����������\n");
    scanf("%s",name.name);
    getchar();
    //���ֲ���
    // ������
    l=NameSort1(l);

        Name arr[20];
        for (int j = 0; j < 20; ++j) {
            for (int m = 0; m < 20; ++m) {
                arr[j].name[m] = l.s[j].name[m];
            }
        }
    //�ٲ���
    k=BinarySearch1(arr,0,l.length,name.name);

    if(k==-1) printf("û���ҵ���ѧ������ѯʧ�ܣ�\n");
    else
        printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[k].number,l.s[k].name,l.s[k].gender,l.s[k].building,l.s[k].room);
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
    printf("����Ҫ��ѯѧ����¥�źͷ���ţ�\n");
    scanf("%d%d",&building,&room);
        //����¥�Ƚ��� ��˳����ҾͿ��� ������űȽ϶� �ö��ֲ������Ч��
    Sqlist l1;
    l1.length=0;
    int m=0;   // 7E-330-name
    for (int j = 0; j < l.length; ++j) {
        if(l.s[j].building==building){
            l1.s[m]=l.s[j];
            ++m;
            l1.length++;
        }
    }     //�õ�ĳ��¥��ѧ������Ϣ

    Student temp;//�����Һ�����һ��¥sqlist����
    int j;
    for(i = 1; i < l1.length; i++){ //��ԭ����ĵڶ���Ԫ�ؽ��бȽϣ�Ĭ�ϵ�һ��Ԫ���Ѿ����ź���ģ�
        if(l1.s[i].room<l1.s[i-1].room){  //��ǰ���Ѿ��ź����Ԫ�رȵ�ǰԪ�ش�ʱ����temp��ʱ�����洢
            temp = l1.s[i];
            for (j = i-1;j >= 0 && l1.s[j].room > temp.room; j--) {    //���ǰ�������Ѿ��źõ�Ԫ��
                l1.s[j+1] = l1.s[j];//����Ԫ������Ų��һλ
            }
            l1.s[j+1] = temp;//��temp���ֵ���Ƶ�����λ��
        }
    }//�õ�ĳ��¥���ݷ�����������ѧ������Ϣ

    Sqlist l2;
    int n=0;
    int tmp=BinarySearch2(l1,0,l1.length,room);
    //��һ�ζ��ֲ��ҵ���һ������ �����������е�λ��,���еڶ��ζ��ֲ��ҵ�ǰ�����������򣬵������������������������±����Ӧ��sqlist�±겻�ٶ�Ӧ,�����޷��������
    //repair:���ֲ���sqllist ��l.s[i].room�޸�ֵ��Ȼ��������������һ��
    while (tmp!=-1){
        l2.s[n]=l1.s[tmp];
        l1.s[tmp].room=-520;
        for (int i = 0; i < l1.length; ++i) {  //ð������ һ��ѭ��Ƕ��
            for (int j = 0; j <l1.length-i; ++j) {// һ��һ������ȣ���ǰ����ں����򽻻�
                if(l1.s[j].room>l1.s[j+1].room){
                    Student tmp=l1.s[j+1];
                    l1.s[j+1]=l1.s[j];
                    l1.s[j]=tmp;
                }
            }
        }
        n++;
        tmp=BinarySearch2(l1,0,l1.length,room);
    }       //�õ�ĳ��¥ĳ�������ѧ������Ϣ
    for (int j = 0; j < n; ++j) {
        printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l2.s[j].number,l2.s[j].name,l2.s[j].gender,l2.s[j].building,l2.s[j].room);
        flag=1;
    }
    if(flag==0)
    printf("û���ҵ��÷���ţ���ѯʧ�ܣ�\n");
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
            printf("ѧ��:%d  ����:%s  �Ա�:%d  ¥��:%d  �����:%d\n",l.s[j].number,l.s[j].name,l.s[j].gender,l.s[j].building,l.s[j].room);
        }
}

int main(){
    Sqlist l;
    int n,option;

    printf("********��ӭ������������ѯϵͳ**************\n");
    ShowRoom(l);
    while(1)
    {
        fflush(stdin);
        printf("****************************************");
        printf("\n1.����\t2.��ѧ������\n");
        printf("\n3.����������\t4.��¥������\n");
        printf("\n5.��ѧ�Ų�ѯ\t6.��������ѯ\n");
        printf("\n7.�����Ų�ѯ\t8.�˳�\n");
        printf("****************************************");
        printf("\n��ѡ����Ҫ�ķ���:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("������ѧ������:");
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
                printf("����������Χ������ѡ����Ҫ�Ĺ��� 1~8");
                break;
        }
    }
    return 0;
}
