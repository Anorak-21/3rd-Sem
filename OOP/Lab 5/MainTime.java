class Time{

int hr;
int min;
int sec;

Time(){
hr=0;
min=0;
sec=0;}

Time(int hr,int min,int sec){
this.hr=hr;
this.min=min;
this.sec=sec;}

public static Time add(Time t1,Time t2){
Time t3=new Time();
int total=t1.hr*3600+t2.hr*3600+t1.min*60+t2.min*60+t1.sec+t2.sec;
t3.hr=total/3600;
total%=3600;
t3.min=total/60;
total%=60;
t3.sec=total;
return t3;}

void display(){
System.out.println(hr+":"+min+":"+sec);}

}


class MainTime{
public static void main(String args[]){

Time t1=new Time(1,40,46);
Time t2=new Time(2,46,47);
t1.display();
t2.display();
Time t3=new Time();
t3=Time.add(t1,t2);
t3.display();

}}