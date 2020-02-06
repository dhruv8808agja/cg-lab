#include <GL/glut.h>
#include <stdio.h>
 
int x, y, r,dist=0,inc=1,max=50;
float angle=0.0;
int r = 100;

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
           y = 500-y;
           draw_circle(x, y, r);
           draw_circle(x, y, r/2);
           draw_line(x,x,y+r,y+r/2);//line up
           draw_line(x+r/2.818,x+r/1.414,y+r/2.818,y+r/1.414);//line up right
           draw_line(x+r/2, x+r, y,y);//line right
           draw_line(x+r/2.818, x+r/1.414, y-r/2.818, y-r/1.414);//line right down
           draw_line(x,x, y-r, y-r/2);//line down
           draw_line(x-r/2.818, x-r/1.414, y-r/2.818, y-r/1.414);//line down left
           draw_line(x-r/2, x-r, y,y);//line left
           draw_line(x-r/2.818, x-r/1.414, y+r/2.818, y+r/1.414);//line left up
           glutIdleFunc(NULL);
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
	if(key=='x')
	{
		//setSpin(1.0,0.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='y')
	{
		//setSpin(0.0,1.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='z')
	{
		//setSpin(0.0,0.0,1.0);
		glutPostRedisplay();
	}
	else if(key=='a')
	{
		//setSpin(1.0,1.0,1.0);
		glutPostRedisplay();
	}
	//-------- spin --------
	//-------- zoom --------
	else if(key=='i')
	{
		r+=10;
		glutPostRedisplay();
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
	//-------- reset -------
}

void myInit() {
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glColor3f(0.0,1.0,0.0);
   gluOrtho2D(0, 500, 0, 500);
}
 

void myDisplay()
{
    
//    glPushMatrix();
//     //    glTranslatef(180+dist,190,0);
//     //    glRotatef(angle,0,0,1);
//     //    glTranslatef(-180,-190,0);
//            //wheel1
           
//    glPopMatrix();
    glFlush();
//    glPushMatrix();
//        glTranslatef(320+dist,190,0);
//        glRotatef(angle,0,0,1);
//        glTranslatef(-320,-190,0);
//            //wheel2
//            draw_circle(320, 190, 20);
//            draw_circle(320, 190, 5);
//            draw_line(320,320,195,210);//line up
//            draw_line(324,334,194,204);//line up right
//            draw_line(325,340,190,190);//line right
//            draw_line(324,334,186,176);//line right down
//            draw_line(320,320,185,170);//line down
//            draw_line(316,306,186,176);//line down left
//            draw_line(315,300,190,190);//line left
//            draw_line(316,306,194,204);//line left up
//    glPopMatrix();
//    glPushMatrix();
//        glTranslatef(dist,0,0);
//        draw_line(200,300,300,300);//top
//        draw_line(200,200,300,250);//left
//        draw_line(300,300,300,250);//right
//        draw_line(150,200,250,250);//base1
//        draw_line(300,350,250,250);//base1
//        draw_line(150,150,250,200);//leftbottom
//        draw_line(350,350,250,200);//right
//        draw_line(200,300,200,200);//bottom
//        draw_line(150,160,200,200);
//        draw_line(340,350,200,200);
//        draw_semi(180,200,20);
//        draw_semi(320,200,20);
//    glPopMatrix();
//    //base
//    draw_line(0,500,170,170);
   
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
