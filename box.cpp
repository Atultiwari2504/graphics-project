//#include <graphics.h>
//#include <conio.h>    // for kbhit(), getch()
//#include <windows.h>  // for Sleep()
//
//int main() {
//    initwindow(1300, 700);
//    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
//    const int step = 10;
//
//    while (true) {
//        // 1) Check for keypress and adjust coords
//        if (kbhit()) {
//            int ch = getch();
//            // For arrow keys, getch() returns 0 or 0xE0, then another code:
//            if (ch == 0 || ch == 0xE0) {
//                ch = getch();
//                switch (ch) {
//                    case 72:  // Up arrow
//                        y1 -= step; y2 -= step; 
//                        break;
//                    case 80:  // Down arrow
//                        y1 += step; y2 += step;
//                        break;
//                    case 75:  // Left arrow
//                        x1 -= step; x2 -= step;
//                        break;
//                    case 77:  // Right arrow
//                        x1 += step; x2 += step;
//                        break;
//                }
//            }
//            else {
//                // Optional: handle WASD as well
//                switch (ch) {
//                    case 'w': y1 -= step; y2 -= step; break;
//                    case 's': y1 += step; y2 += step; break;
//                    case 'a': x1 -= step; x2 -= step; break;
//                    case 'd': x1 += step; x2 += step; break;
//                }
//            }
//        }
//
//        // 2) Draw
//        setbkcolor(WHITE);
//        cleardevice();
//        setcolor(BLACK);
//        rectangle(x1, y1, x2, y2);
//
//        // 3) Small delay
//        Sleep(10);
//    }
//
//    closegraph();
//    return 0;
//}

#include <graphics.h>
#include <windows.h>
#include <dos.h>
int main(){
	initwindow(1300,700);
	int x1=100,y1=100,x2=200,y2=200;
	while(1){
		if(kbhit()){
			int e=getch();
		    switch(e){
			    case 'w':
				    y1-=10;
				    y2-=10;
				    break;
			    case 'd':
				    x1+=10;
				    x2+=10;
				    break;
			    case 's':
				    (y1)+=10;
				    (y2)+=10;
				    break;
			    case 'a':
				    (x1)-=10;
				    (x2)-=10;
				    break;
		    }
	    }
    
		setbkcolor(BLACK);
		cleardevice();
		setcolor(YELLOW);
		rectangle(x1,y1,x2,y2);
		delay(2);
	
}
	getch();

	return 0;
}
