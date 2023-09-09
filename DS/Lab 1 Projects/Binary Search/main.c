#include<stdio.h>

void main() {

int i,len,arr[100],pos,ck,exists=0,low=0,mid;
printf("Enter length of the Array ");
scanf("%d",&len);
printf("Enter element of the Array ");
for(i=0;i<len;i++) {
    scanf("%d",&arr[i]);}

printf("Enter element to check ");
scanf("%d",&ck);

int high=len;
i=0;

while(i<=high){
    mid=(high+low)/2;
    if (arr[mid]==ck) {
        pos=mid;
        exists=1;
        break;}
    else if (arr[mid]>ck) {
        high=mid;}
    else if (arr[mid]<ck) {
        low=mid;}
    i++;}

if (exists==1) {
    printf("Element exists at position: %d ", pos+1);}
else
    printf("Element does not exist");
    }
