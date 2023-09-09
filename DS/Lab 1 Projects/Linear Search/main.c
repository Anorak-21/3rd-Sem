#include<stdio.h>

void main() {

int i,len,arr[100],pos,temp,exists=0;
printf("Enter length of the Array ");
scanf("%d",&len);
printf("Enter element of the Array ");
for(i=0;i<len;i++) {
    scanf("%d",&arr[i]);}

printf("Enter element to check ");
scanf("%d",&temp);
for (i=0;i<len;i++) {
    if (temp==arr[i]) {
        pos=i;
        exists=1;}}

if (exists==1) {
    printf("Element exists at position: %d ", pos+1);}
else
    printf("Element does not exist");
}
