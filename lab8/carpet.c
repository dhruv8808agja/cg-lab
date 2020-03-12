#include <GL/glut.h>
#include <stdio.h>
 
int n;
float x1=-100.0f,x2=100.0f,x3=100.0f,x4=-100.0f,yc1=0,y2=0,y3=200.0f,y4=200.0f;
void myInit()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glColor3f(0.0,1.0,1.0);
   gluOrtho2D(-250, 250, -250, 250);
}
void divide(int x1,int yc1,int x2,int y2,int x3,int y3,int x4,int y4,int n)
{
   if(n>0)
   {
       glColor3f(0.0,0.0,0.0);
       glBegin(GL_POLYGON);
           glVertex2f((2*x1+x3)/3,(2*yc1+y3)/3);
           glVertex2f((2*x2+x4)/3,(2*y2+y4)/3);
           glVertex2f((2*x3+x1)/3,(2*y3+yc1)/3);
           glVertex2f((2*x4+x2)/3,(2*y4+y2)/3);
       glEnd();
       divide(x1,yc1,(2*x1+x2)/3,y2,(2*x1+x3)/3,(2*yc1+y3)/3,x1,(2*yc1+y4)/3,n-1);
       //leftbottom
 
       divide((x1+2*x2)/3,yc1,x2,y2,x2,(2*y2+y3)/3,(2*x2+x4)/3,(2*y2+y4)/3,n-1);
       //rightbottom
 
       divide((2*x3+x1)/3,(2*y3+yc1)/3,x2,(y2+2*y3)/3,x3,y3,(2*x3+x4)/3,y3,n-1);
       //righttop
 
       divide(x4,(yc1+2*y4)/3,(2*x4+x2)/3,(2*y4+y2)/3,(x3+2*x4)/3,y3,x4,y4,n-1);
       //lefttop
 
       divide((2*x1+x2)/3,y2,(x1+2*x2)/3,yc1,(2*x2+x4)/3,(2*y2+y4)/3,(2*x1+x3)/3,(2*yc1+y3)/3,n-1);
       //bottommiddle
      
       divide((2*x2+x4)/3,(2*y2+y4)/3,x2,(2*y2+y3)/3,x2,(y2+2*y3)/3,(2*x3+x1)/3,(2*y3+yc1)/3,n-1);
       //middleright
 
       divide((2*x4+x2)/3,(2*y4+y2)/3,(2*x3+x1)/3,(2*y3+yc1)/3,(2*x3+x4)/3,y3,(x3+2*x4)/3,y3,n-1);
       //topmiddle
 
       divide(x1,(2*yc1+y4)/3,(2*x1+x3)/3,(2*yc1+y3)/3,(2*x4+x2)/3,(2*y4+y2)/3,x4,(yc1+2*y4)/3,n-1);
       //middleleft
   }
}
void myDisplay()
{
   glBegin(GL_POLYGON);
       glVertex2f(x1,yc1);
       glVertex2f(x2,y2);
       glVertex2f(x3,y3);
       glVertex2f(x4,y4);
   glEnd();
   divide(x1,yc1,x2,y2,x3,y3,x4,y4,n);
   glFlush();
}
int main(int argc, char **argv)
{
   printf("Enter value for n\n");
   scanf("%d",&n);
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(1000, 1000);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("2d gasket");
   myInit();
   glutDisplayFunc(myDisplay);
   glutMainLoop();
}
