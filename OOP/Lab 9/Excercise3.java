/*  Write a menu driven program to do the following:-
    a. To check whether a string is palindrome or not
    b. Write the string in an alphabetical order
    c. Reverse the string
    d. Concatenate the original string and the reversed string */

import java.util.Scanner;
class Excercise3
{
    public static void main(String args[])
    {
        String str,sortstr,revstr;
        int i,j,n,option,flag=0;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter string:");
        str = in.nextLine();
        char temp,s[] = str.toCharArray(),x[]=s;
        n = str.length();
        while(true)
        {
            System.out.println("\n1. To check whether a string is palindrome or not");
            System.out.println("2. Write the string in an alphabetical order");
            System.out.println("3. Reverse the string");
            System.out.println("4. Concatenate the original string and the reversed string");
            System.out.println("5. Exit the program");
            System.out.print("Enter option: ");
            option = in.nextInt();
            switch(option)
            {
                case 1:
                    //To check whether string is palindrome or not
                    for(i=0;i<n/2;i++)
                    {
                        if(s[i]!=s[n-i-1])
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag!=1)
                        System.out.println("String is a palindrome.");
                    else
                        System.out.println("String is not a palindrome.");   
                    break;

                case 2:
                    //Write the string in an alphabetical order
                    for(i=0;i<n-1;i++)
                    {
                        for(j=i+1;j<n;j++)
                        {
                            if(x[i]>x[j])
                            {
                                temp=x[i];
                                x[i]=x[j];
                                x[j]=temp;
                            }
                        }
                    }
                    sortstr = new String(x);
                    System.out.println("Sorted string: "+sortstr);
                    break;

                case 3:
                    //Reverse the string
                    break;
                case 4:
                    //Concatenate the original string and the reversed string
                    break;
                case 5:
                    System.out.println("Exiting the program.");
                    System.exit(0);
                default:
                    System.out.println("Invalid Option.");
            }
        }
    }
}