//
// Created by 26247 on 12/20/2022.
//
#include <stdio.h>
#include <string.h>
typedef struct{
    char name[20];
}Name;
int BinarySearch1(Name arr[],int low,int high,char target[20]){
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
                if(strcmp(target,arr[mid].name)>0) {
                    return BinarySearch1(arr, mid + 1, high, target);
                }else {
                    return mid;
                }
            }

        }
    }
}
void test(){
    char name[20]="c";
    char name1[20]="b";
    printf("%d",strcmp(name,name1));
}
int main(){
    Name arr[10];
    scanf("%s",arr[0].name);
    Name name;
    scanf("%s",name.name);
    int result= BinarySearch1(arr,0,1,name.name);

    printf("%d\n",result);

    test();
}