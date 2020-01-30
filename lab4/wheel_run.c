#include <stdio.h>
#include <math.h>
#include<GL/glut.h>

// Center = (320,240)
int xc = 320, yc = 240;
int delay = 300,angle;

void Timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(40, Timer, 0);
}

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

//line

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int y1, int x2, int y2) {
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
	glFlush();
}

void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
	glTranslatef(320,240,0);
	glRotatef(angle, 0, 0, 1);
	glTranslatef(-320,-240,0);
	bresenham_circle(200);
	bresenham_circle(40);
	
	//spokes
	draw_line(320,40,320,200);
	draw_line(120,240,280,240);
	draw_line(320,440,320,280);
	draw_line(360,240,520,240);
	
	angle += 1.0f;
	glPopMatrix();
	draw_line(40,40,600,40);	//ground
	
	//draw_line(206.8,130,206.8,190);

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
	glutCreateWindow("wheel_run");
	Init();

	
	glutDisplayFunc(mydisplay);
	glutTimerFunc(1,Timer,0);
	glutMainLoop();	
}