#include <graphics.h>
#include <math.h>
int main(){
	initwindow(1300,700);
	double h=500,g=-9.8,v,u,d=0,a,k,s;
	while(1){
		d+=5;
		while(a<=590){
		setbkcolor(BLACK);
		cleardevice();
		a=590-h;
		line(0,600,1300,600);
		circle(400,a,10);
		v+=g*0.02;
		h+=v*0.02;
		if(!(a>=590)){
			k=v;
			s=a;
		}
		delay(1);
	}
	u=k;
	while(k<=u/2-d){
		setbkcolor(BLACK);
		cleardevice();
		line(0,600,1300,600);
		circle(400,s,10);
		k+=-g*0.02;
		s+=v*0.02;
		delay(1);
	}
	a=s;
	v=0;
	h=590-a;
	}
	getch();
}
