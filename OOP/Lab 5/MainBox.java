class Box{

double w;
double h;
double d;

Box(double w,double h,double d){
this.w=w;
this.h=h;
this.d=d;}

double Volume(){
return w*h*d;}}

class MainBox{
public static void main(String args[]){

Box obj=new Box(1,2,3);
double vol=obj.Volume();

System.out.println(vol);








}

}