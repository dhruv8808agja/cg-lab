#include <GL/glut.h>
#include <stdio.h>
 
int x, y, r,dist=0,inc=1,max=50;
float angle=0.0;
int r = 30;
int initX = 250, initY=250;
int flag = 1;

void draw_pixel(int x, int y) {
   glBegin(GL_POINTS);
   glVertex2i(x, y);
   glEnd();
}
void mark_points(int x, int y, int p,int q)
{
   draw_pixel(x+p,y+q);
   draw_pixel(x+p,y-q);
   draw_pixel(x+q,y+p);
   draw_pixel(x+q,y-p);
   draw_pixel(x-p,y+q);
   draw_pixel(x-p,y-q);
   draw_pixel(x-q,y+p);
   draw_pixel(x-q,y-p);
}
void draw_circle(int x, int y, int r) {
   int d=3-2*r;
   int p=0;
   int q=r;
   draw_pixel(x+r,y);
   draw_pixel(x,y+r);
   draw_pixel(x-r,y);
   draw_pixel(x,y+r);
   while(p<q)
   {
       p++;
       if(d<=0)
           d=d+4*p+6;
       else
       {
           q--;
           d=d+4*(p-q)+10;
       }
       mark_points(x,y,p,q);
   }
}
void draw_semi(int x, int y, int r) {
   int d=3-2*r;
   int p=0;
   int q=r;
   draw_pixel(x+r,y);
   draw_pixel(x,y+r);
   draw_pixel(x-r,y);
   draw_pixel(x,y+r);
   while(p<q)
   {
       p++;
       if(d<=0)
           d=d+4*p+6;
       else
       {
           q--;
           d=d+4*(p-q)+10;
       }
       draw_pixel(x+p,y+q);
       draw_pixel(x+q,y+p);
       draw_pixel(x-p,y+q);
       draw_pixel(x-q,y+p);
   }
}
void draw_line(int x1, int x2, int y1, int y2) {
   int dx, dy, i, e;
   int incx, incy, inc1, inc2;
   int x,y;
 
   dx = x2-x1;
   dy = y2-y1;
 
   if (dx < 0) dx = -dx;
   if (dy < 0) dy = -dy;
   incx = 1;
   if (x2 < x1) incx = -1;
   incy = 1;
   if (y2 < y1) incy = -1;
   x = x1; y = y1;
   if (dx > dy) {
       draw_pixel(x, y);
       e = 2 * dy-dx;
       inc1 = 2*(dy-dx);
       inc2 = 2*dy;
       for (i=0; i<dx; i++) {
           if (e >= 0) {
               y += incy;
               e += inc1;
           }
           else
               e += inc2;
           x += incx;
           draw_pixel(x, y);
       }
 
   } else {
       draw_pixel(x, y);
       e = 2*dx-dy;
       inc1 = 2*(dx-dy);
       inc2 = 2*dx;
       for (i=0; i<dy; i++) {
           if (e >= 0) {
               x += incx;
               e += inc1;
           }
           else
               e += inc2;
           y += incy;
           draw_pixel(x, y);
       }
   }
}
void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
        {
        //    y = 500-y;
        //    draw_circle(x, y, r);
        //    draw_circle(x, y, r/2);
        //    draw_line(x,x,y+r,y+r/2);//line up
        //    draw_line(x+r/2.818,x+r/1.414,y+r/2.818,y+r/1.414);//line up right
        //    draw_line(x+r/2, x+r, y,y);//line right
        //    draw_line(x+r/2.818, x+r/1.414, y-r/2.818, y-r/1.414);//line right down
        //    draw_line(x,x, y-r, y-r/2);//line down
        //    draw_line(x-r/2.818, x-r/1.414, y-r/2.818, y-r/1.414);//line down left
        //    draw_line(x-r/2, x-r, y,y);//line left
        //    draw_line(x-r/2.818, x-r/1.414, y+r/2.818, y+r/1.414);//line left up
           glutPostRedisplay();

        }
			
		break;
	case GLUT_MIDDLE_BUTTON:
		if(state==GLUT_DOWN)
		{
			glutIdleFunc(NULL);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
        {
            exit(0);
        }
			//glutIdleFunc(spinDisplayReverse);
		break;
	default:
		break;
	}
}
void keyboard(unsigned char key, int x, int y)
{
	//-------- spin --------
	if(key=='i')
	{
		r+=10;
        flag = 1;
        glClear(GL_COLOR_BUFFER_BIT);
		glutPostRedisplay();
	}
	else if(key=='d')
	{
        
		r-=10;
        flag=1;
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
	}
	else if(key=='t')
	{
        
	    //glRotatef(angle, 0, 0, 1);
	    //glTranslatef(-320,-240,0);
		glClear(GL_COLOR_BUFFER_BIT);
        initX += 20;
		glutPostRedisplay();
	}
	else if(key=='h')
	{
        glClear(GL_COLOR_BUFFER_BIT);
        initX -= 20;
		//setSpin(1.0,1.0,1.0);
		glutPostRedisplay();
	}
	//-------- spin --------
	//-------- zoom --------
	else if(key=='c')
	{
		glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 1.0);
		//glutPostRedisplay();
	}
	else if(key=='o')
	{
        r-=10;
		//translate_z--;
		glutPostRedisplay();
	}
	//-------- zoom --------
	//-------- reset -------
	else if(key=='r')
	{
		//reset();
		glutPostRedisplay();
	}
    else if(key=='s')
    {

        glutPostRedisplay();
    }
	//-------- reset -------
}

void myInit() {
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glColor3f(0.0,1.0,0.0);
   glOrtho(0, 500, 0, 500, -100,100);
}
 

void myDisplay()
{  
    
        //head
    draw_semi(initX, initY+100, r);
    draw_circle(initX-r/2,initY+100+r/3,r/6);
    draw_circle(initX+r/2,initY+100+r/3,r/6);
    draw_line(initX-r,initX+r,initY+100, initY+100);
    
    //body
    draw_line(initX-r, initX+r, initY+90, initY+90);            //top line
    draw_line(initX-r, initX-r, initY+90, initY+90-2*r);           //left
    draw_line(initX+r, initX+r, initY+90, initY+90-2*r);            //right
    draw_line(initX-r, initX+r, initY+90-2*r, initY+90-2*r);        //bottom

    //hands
    //left hand
    draw_line(initX-r-20, initX-r-10, initY+90, initY+90);            //top line
    draw_line(initX-r-20, initX-r-20, initY+90, initY+90-2*r);           //left
    draw_line(initX-r-10, initX-r-10, initY+90, initY+90-2*r);            //right
    draw_line(initX-r-20, initX-r-10, initY+90-2*r, initY+90-2*r);        //bottom
    
    //right hand
    draw_line(initX+r+20, initX+r+10, initY+90, initY+90);            //top line
    draw_line(initX+r+20, initX+r+20, initY+90, initY+90-2*r);           //left
    draw_line(initX+r+10, initX+r+10, initY+90, initY+90-2*r);            //right
    draw_line(initX+r+20, initX+r+10, initY+90-2*r, initY+90-2*r);        //bottom
    
    //leg
    //left leg
    draw_line(initX-r/2-5,initX-r/2+5,initY+90-2*r,initY+90-2*r);
    draw_line(initX-r/2-5,initX-r/2-5,initY+90-2*r,initY+90-2*r-r/2);     //left
    draw_line(initX-r/2+5,initX-r/2+5,initY+90-2*r,initY+90-2*r-r/2);         //right
    draw_line(initX-r/2-5,initX-r/2+5,initY+90-2*r-r/2,initY+90-2*r-r/2);       //bottom
    
    //right leg
    draw_line(initX+r/2-5,initX-r/2+5,initY+90-2*r,initY+90-2*r);
    draw_line(initX+r/2-5,initX+r/2-5,initY+90-2*r,initY+90-2*r-r/2);     //left
    draw_line(initX+r/2+5,initX+r/2+5,initY+90-2*r,initY+90-2*r-r/2);         //right
    draw_line(initX+r/2-5,initX+r/2+5,initY+90-2*r-r/2,initY+90-2*r-r/2);       //bottom
    
    

    glFlush();
   
}
void StepRot(int n)
{
   angle-=inc;
   dist-=inc;
//    if(dist>=max)
//    {
//        inc=-1;
//        angle=0;
//    }
//    else if(dist<=-max)
//    {
//        inc=1;
//        angle=0;
//    }
   glClear(GL_COLOR_BUFFER_BIT);
   glutPostRedisplay();
   glutTimerFunc(50,StepRot,0);
}
void main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("MY Car");
   myInit();
   glutDisplayFunc(myDisplay);
//    glutTimerFunc(25,StepRot,0);
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
}
