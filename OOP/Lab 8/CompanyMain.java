import java.util.Scanner;

interface Sales
{
    int compute();
    int date3();	

}

class Hardware implements Sales
{
    Scanner in=new Scanner(System.in);
    static int count=0;
    int Date;
    String category;
    String manufacturer;
    Hardware()
    {
        System.out.println("Hardware category: ");
        category=in.nextLine();
        System.out.println("Manufacturer: ");
        manufacturer=in.nextLine();    
	System.out.println("Date: ");
        Date=in.nextInt();    
        count++;
    } 
    public int compute(){
        return count;
    }
    public int date3(){
	
	if(Date<20230707)return 0;
	return 1;}

}

class Software implements Sales{
    Scanner in=new Scanner(System.in);
    static int count=0;
    int Date;
    String type;
    String OS;
    Software()
    {
        System.out.println("Software type: ");
        type=in.nextLine();
        System.out.println("Operating System: ");
        OS=in.nextLine(); 
	System.out.println("Date: ");
        Date=in.nextInt();        
	count++;
    } 
    public int compute(){
	return count;}
    public int date3(){
	
	if(Date<20230707)return 0;
	return 1;}
}

class CompanyMain
{
    public static void main(String args[])
    {
        int i=0,j=0,ch,countsoft=0,counthard=0;
	Scanner in =new Scanner(System.in);
        Hardware h[]=new Hardware[50];
        Software s[]=new Software[50];
        do{
            System.out.println("1.Hardware\n2.Software\n3.Hardware_sales\n4.Software_sales\n5.Exit");
            ch=in.nextInt();
            switch(ch){
                case 1:
                    h[i++]=new Hardware();
                    break;
                case 2:
                    s[j++]=new Software();
                    break;
                case 3:
                    for(int l=0;l<h.length;l++) {countsoft=countsoft+h[l].date3();}
		    System.out.println("Total hardware sales: "+countsoft);
                    break;
                case 4:
                    for(int k=0;k<h.length;k++) {counthard=counthard+h[k].date3();}
		    System.out.println("Total software sales: "+counthard);
                    break;
                case 5:
                    System.out.println("Exiting program");
                    break;
                default: System.out.println("Invalid input");
            }
        }while(ch!=5);
        in.close();
    }
}
