#include <graphics.h>
#include <math.h>
void polar_offset(double x1, double y1,
                  double d, double theta_deg,
                  double *x2_out, double *y2_out)
{
    /* Convert degrees to radians */
    double theta = theta_deg * M_PI / 180.0;

    /* Compute new coordinates */
    *x2_out = x1 + d * cos(theta);
    *y2_out = y1 + d * sin(theta);
}

int main(){
	initwindow(1200, 6000);
	int i,j=270,k=0,n=15;
	for(;1;k++){
		for(i=0;i<=1500;i+=n,j+=3+n){
		setbkcolor(BLUE);
		cleardevice();
		setcolor(WHITE);
	    double cx1=i-400,cy1=200,cx2=300+cx1,cy2=cy1,r=50,ang=0+i,x,y,a,b,r1=17,c,d;
	    circle(cx1,cy1,r);
	    circle(cx1,cy1,10);
	    circle(cx1,cy1,r+10);
	    arc(cx1, cy1, 10, 170, r+20);
	    circle(cx2,cy2,r);
	    circle(cx2,cy2,10);
	    circle(cx2,cy2,r+10);
	    arc(cx2, cy2, 50, 190, r+20);
	    for(;ang<360+i;ang+=30){
		    polar_offset(cx1,cy1,10,ang,&a,&b);
		    polar_offset(cx1,cy1,r,ang,&x,&y);
		    line(a,b,x,y);
		    polar_offset(cx2,cy2,10,ang,&a,&b);
		    polar_offset(cx2,cy2,r,ang,&x,&y);
		    line(a,b,x,y);
	    }
	    line(cx1+10,cy1,(cx2+cx1)/2-r1,(cy2+cy1)/2);
	    polar_offset((cx2+cx1)/2,(cy2+cy1)/2,r1,j,&a,&b);
	    polar_offset(a,b,17,j,&x,&y);
	    line(a,b,x,y);
	    polar_offset(x,y,17,j-90,&a,&b);
        line(x,y,a,b);	
        polar_offset(x,y,17,j+90,&a,&b); 
        line(a,b,x,y);
        polar_offset((cx2+cx1)/2,(cy2+cy1)/2,34,j+180,&a,&b);
        line((cx2+cx1)/2,(cy2+cy1)/2,a,b);
        polar_offset(a,b,17,j-90,&x,&y);
        line(a,b,x,y);
        polar_offset(a,b,17,j+90,&x,&y);
        line(a,b,x,y);
	    circle((cx2+cx1)/2,(cy2+cy1)/2,r1);
	    polar_offset(cx1,cy1,r,300,&a,&b);
	    polar_offset(a,b,90,300,&x,&y);
	    line(a,b,x,y);
	    polar_offset((cx2+cx1)/2,(cy2+cy1)/2,r1,237,&a,&b);
	    line(a,b,x,y);
	    c=x,d=y;
	    polar_offset(cx2,cy2,r,240,&a,&b);
	    polar_offset(a,b,90,240,&x,&y);
	    line(a,b,x,y);
	    line(c,d,x,y);
	    polar_offset(x,y,20,240,&a,&b);
	    line(x,y,a,b);
	    line(a-10,b,a+30,b);
	    arc(a+30,b+10,270,90,10);
	    polar_offset(c,d,20,237,&a,&b);
	    line(c,d,a,b);
	    line(a-10,b,a+30,b);
	    polar_offset(cx2,cy2,r+20,240,&a,&b);
	    polar_offset(a,b,35,240,&x,&y);
	    polar_offset((cx2+cx1)/2,(cy2+cy1)/2,r1,300,&a,&b);
	    line(a,b,x,y);
	    delay(20);
	    if(kbhit()){
		    break;
	    }
	}
	}
	getch();
	return 0;
}
