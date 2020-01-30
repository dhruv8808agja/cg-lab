#include <stdio.h>
#include <math.h>
#include<GL/glut.h>

// Center = (320,240)
int xc = 320, yc = 240;

void plot_point (int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xc+x, yc+y);
	glVertex2i(xc-x, yc+y);
	glVertex2i(xc-x, yc-y);
	glVertex2i(xc+x, yc-y);
	glVertex2i(xc+y, yc+x);
	glVertex2i(xc+y, yc-x);
	glVertex2i(xc-y, yc+x);
	glVertex2i(xc-y, yc-x);
	glEnd();
}

void bresenham_circle(int r)
{
	int x = 0, y = r;
	float pk = (5.0/4.0) - r;

	plot_point(x,y);
	int k;

	while(x < y)
	{
		x++;
		if(pk<0)
		{
			pk+=2*x+1;
		}
		else
		{
			y--;
			pk += 2*(x-y) + 1;	
		}
		plot_point(x,y);
	}
	glFlush();
}

void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	bresenham_circle(100);
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0,640,0,480);
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("bresenham_circle");
	Init();

	
	glutDisplayFunc(mydisplay);
	glutMainLoop();	
}










