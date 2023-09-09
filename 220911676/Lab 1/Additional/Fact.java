class Fact{

public static void main(String args[]){

int i,ck,fin=1;

ck=Integer.parseInt(args[0]);
for(i=1;i<ck+1;i++){
	fin=fin*i;}


System.out.println("The factorial of the given Number is "+fin);

}


}