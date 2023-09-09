#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int len,i,j,option,pos,flag=1,len_case4,len_case5,n;
    char mainstr[100],substr[100],resultstr[200]="Hi";
    printf("Enter:\n1 for length of the string\n2 for string concatenation\n3 for string comparison\n4 for inserting a sub string\n5 to delete a sub string\n");
    scanf("%d",&option);
switch(option)  {

    case 1:
        printf("Enter the string whose length you want to find ");
        scanf("%s",mainstr);
        for(len=0;mainstr[len]!='\0';len++);
        printf("The length of the string is %d",len);
        break;

    case 2:
        printf("Enter the string 1 ");
        scanf("%s",mainstr);
        printf("Enter the string 2 ");
        scanf("%s",substr);
        for(i=0;i<strlen(mainstr);i++){
            resultstr[i]=mainstr[i];}
        for(i=0;i<strlen(substr)+strlen(mainstr);i++){
            resultstr[i+strlen(mainstr)]=substr[i];}
        printf("The resultant String is %s",resultstr);
        break;

    case 3:
        printf("Enter the string 1 ");
        scanf("%s",mainstr);
        printf("Enter the string 2 ");
        scanf("%s",substr);
        if(strlen(mainstr)!=strlen(substr)) {flag=0; }
        for(i=0;i<strlen(mainstr);i++){
            if (mainstr[i]!=substr[i]) flag=0;
            }
        if(flag==1)printf("The Strings are same");
        else printf("The Strings are not same");
        break;

    case 4:
        printf("Enter the string 1 ");
        getchar();
        gets(mainstr);
        printf("Enter the string 2 ");
        scanf("%s",substr);
        printf("Enter the position you want to insert ");
        scanf("%d",&pos);
        for(i=0;i<pos;i++){
            resultstr[i]=mainstr[i];}
        len_case4=strlen(resultstr);
        for(i=0;i<strlen(substr);i++){
            resultstr[len_case4+i]=substr[i];}
        len_case4=strlen(resultstr);
        len_case5=strlen(mainstr);
        for(i=0;i<strlen(mainstr)-pos;i++){
            resultstr[len_case4+i]=mainstr[pos+i];}
        printf("The resultant String is %s",resultstr);
        break;

    case 5:
        printf("Enter the string 1 ");
        getchar();
        gets(mainstr);
        printf("Enter the string you want to delete ");
        scanf("%s",substr);
        for(i=0;i<strlen(mainstr);i++) {
            if(mainstr[i]==substr[0]) {
                for(j=0;j<strlen(substr)+1;j++){
                    if(substr[j]!=mainstr[i+j]){
                            break;}
                    if(j+1==strlen(substr))
                    pos=i;
                }}}
        for(i=pos;i<strlen(mainstr)-strlen(substr);i++){
            mainstr[i]=mainstr[i+strlen(substr)];}
        mainstr[strlen(mainstr)-strlen(substr)]='\0';
        printf("The resultant String is %s",mainstr);
        break;

}
}
