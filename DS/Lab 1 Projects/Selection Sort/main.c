#include<stdio.h>

void main() {

int i,j,len,low,temp,pos;
printf("Enter length of the Array ");
scanf("%d",&len);
printf("Enter element of the Array ");
for(i=0;i<len;i++) {
    scanf("%d",&arr[i]);}

for(i=0;i<len-1;i++)
    {
    low=arr[i];
    pos=i;
    for(j=i+1;j<len;j++)
        {
        if (low>arr[j]) {
            low=arr[j];
            pos=j;}
        }
arr[pos]=arr[i];
arr[i]=low;}

for(i=0;i<len;i++){
    printf("%d ",arr[i]);}
}
