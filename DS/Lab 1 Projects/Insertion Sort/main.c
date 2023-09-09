#include<stdio.h>

void main() {

int i,j,len,key,arr[100];
printf("Enter length of the Array ");
scanf("%d",&len);
printf("Enter element of the Array ");
for(i=0;i<len;i++) {
    scanf("%d",&arr[i]);}

for(i=1;i<len;i++) {
    key=arr[i];
    j=i-1;

    while(j>=0&&key<=arr[j]){
        arr[j+1]=arr[j];
        j--;}
    arr[j+1]=key;}

for(i=0;i<len;i++){
    printf("%d ",arr[i]);}

}
