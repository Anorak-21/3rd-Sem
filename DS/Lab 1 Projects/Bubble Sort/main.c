#include<stdio.h>

void main() {

int i,j,len,arr[100],temp;
printf("Enter length of the Array ");
scanf("%d",&len);
printf("Enter element of the Array ");
for(i=0;i<len;i++) {
    scanf("%d",&arr[i]);}

for(i=0;i<len-1;i++){
    for(j=0;j<len-1-i;j++) {
        if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;}}}

for(i=0;i<len;i++){
    printf("%d ",arr[i]);
}
}
