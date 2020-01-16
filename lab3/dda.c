#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

float round(float x)
{
    return floor(x + 0.5);
}
int main()
{
        /* Initialise GLUT library */
    glutInit(&argc,argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    /* Create the window with title "DDA_Line" */
    glutCreateWindow("DDA_Line");
    glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(0 , 640 , 0 , 480);
    /* Call the displaying function */
    glutDisplayFunc(LineDDA);
    /* Keep displaying untill the program is closed */
    glutMainLoop();


    float x1,x2,y1,y2,x,y,dx,dy, step;
    int i;
    printf("Enter (x1 y1 x2 y2): \n");
    scanf("%f %f %f %f", x1,y1,x2,y2);

    dx = (float)abs(x2-x1);
    dy = (float)abs(y2-y1);

    if(dy >= dx)
    {
        step = (float)abs(dy);
    }
    else{
        step = (float)abs(dx);
    }

    x = x1;
    y = y1;

    dx = (float)(abs(dx)/step);
    dy = (float)(abs(dy)/step);

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);

    glVertex2d(x,y);

    for(i = 0; i<step; i++)
    {
        x += dx;
        y += dy;

        glVertex2d(round(x), round(y));
    }

    glEnd();

    glFlush();

    glClearColor(1.0,1.0,1.0,0);







}