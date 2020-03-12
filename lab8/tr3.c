#include <GL/glut.h>
#include<stdio.h>
int n;
float ax=-400,ay=-400,bx=400,by=-400,cx=400,cy=400,dx=-400,dy=400;
void displayCB(void)		/* function called whenever redisplay needed */
{
  glClear(GL_COLOR_BUFFER_BIT);		/* clear the display */
  glColor3f(1, 0.0, 0.0);		/* set current color to white */
  glBegin(GL_POLYGON);			/* draw filled triangle */
  glVertex2f(-400,-400);			/* specify each vertex of triangle */
  glVertex2f(400,-400);
  glVertex2f(400,400);
  glVertex2f(-400,400);
  glEnd();				/* OpenGL draws the filled triangle */
  glFlush();				/* Complete any pending operations */
}

// void keyCB(unsigned char key, int x, int y)	 called on key press 
// {
//   if( key == 'q' ) exit(0);
// }
void gasket(float ax,float ay,float bx,float by,float cx,float cy,float dx,float dy,float n){
  printf("hello1\n");
  if(n==0){
    return;
  }
  else{
    float midax,miday,midbx,midby,midcx,midcy,middx,middy;
    printf("hello2\n");
    midax=(bx+2*ax)/3;
    midbx=(2*bx+ax)/3;
    miday=(2*ay+dy)/3;
    midby=(2*by+cy)/3;
    midcx=(2*cx+dx)/3;
    midcy=(2*cy+by)/3;
    middx=(2*dx+cx)/3;
    middy=(2*dy+ay)/3;
    //printf("%f %f",midax,miday);
      /* set current color to white */
    glBegin(GL_POLYGON); 
    glColor3f(0.0, 0.0, 0.0);      /* draw filled triangle */
    glVertex2f(midax,miday);      /* specify each vertex of triangle */
    glVertex2f(midbx,midby);
    glVertex2f(midcx,midcy);
    glVertex2f(middx,middy);
    glEnd();  
    gasket(ax,ay,midax,ay,midax,miday,ax,miday,n-1);
    gasket(midbx,by,bx,by,bx,midby,midbx,midby,n-1);
    gasket(midcx,midcy,cx,midcy,cx,cy,midcx,cy,n-1);
    gasket(dx,middy,middx,middy,middx,dy,dx,dy,n-1);
    glFlush();
  }
}
void mydisplay(){
  displayCB();
  gasket(ax,ay,bx,by,cx,cy,dx,dy,n);
}

int main(int argc, char *argv[])
{
  int win;
  printf("enter the value of n\n");
  scanf("%d",&n);

  glutInit(&argc, argv);		/* initialize GLUT system */

  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(500,500);		/* width=400pixels height=500pixels */
  win = glutCreateWindow("Square");	/* create window */

  /* from this point on the current window is win */

  glClearColor(0.0,0.0,0.0,0.0);	/* set background to black */
  gluOrtho2D(-500,500,-500,500);		/* how object is mapped to window */
  glutDisplayFunc(mydisplay);		/* set window's display callback */
  //glutKeyboardFunc(keyCB);		/* set window's key callback */

  glutMainLoop();			/* start processing events... */

  /* execution never reaches this point */

  return 0;
}