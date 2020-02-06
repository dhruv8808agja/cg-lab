#include <stdio.h>
#include <GL/glut.h>


static GLfloat spin = 0.0;
static GLfloat spin_speed = 1.0;
float spin_x = 0;
float spin_y = 0;
float spin_z = 1;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = 0.0;

int xc = 320, yc = 240;

//------- custom functions starts -------
void setSpin(float x, float y, float z)
{
	spin_x = x;
	spin_y = y;
	spin_z = z;
}
void reset()
{
	spin_x = 0;
	spin_y = 0;
	spin_z = 1;
	translate_x = 0.0;
	translate_y = 0.0;
	translate_z = 0.0;
}
//------- custom functions ends -------
void reshape(int w,int h)
{
	glViewport(0,0, (GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void spinDisplay(void)
{
	spin=spin+spin_speed;
	if(spin>360.0)
	{
		spin=spin-360.0;
	}
	glutPostRedisplay();
}
void spinDisplayReverse(void)
{
	spin=spin-spin_speed;
	if(spin<360.0)
	{
		spin=spin+360.0;
	}
	glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_MIDDLE_BUTTON:
		if(state==GLUT_DOWN)
		{
			glutIdleFunc(NULL);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(spinDisplayReverse);
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
		setSpin(1.0,0.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='y')
	{
		setSpin(0.0,1.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='z')
	{
		setSpin(0.0,0.0,1.0);
		glutPostRedisplay();
	}
	else if(key=='a')
	{
		setSpin(1.0,1.0,1.0);
		glutPostRedisplay();
	}
	//-------- spin --------
	//-------- zoom --------
	else if(key=='i')
	{
		translate_z++;
		glutPostRedisplay();
	}
	else if(key=='o')
	{
		translate_z--;
		glutPostRedisplay();
	}
	//-------- zoom --------
	//-------- reset -------
	else if(key=='r')
	{
		reset();
		glutPostRedisplay();
	}
	//-------- reset -------
}

// assuming work-window width=50unit, height=25unit;
void init()
{
	glClearColor(0,0,0,0);
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    gluOrtho2D(0,1024,0,728);
}


// void drawFan()
// {
// 	glTranslatef(translate_x, translate_y, translate_z);
	
// 	glRotatef(spin,spin_x,spin_y,spin_z);

// 	glBegin(GL_TRIANGLES);
// 	glColor3f(1.0, 0.0, 0.0);
// 	glVertex2i(0, 0);
// 	glVertex2i(-2, 5);
// 	glVertex2i(2, 5);
// 	glEnd();

// 	glBegin(GL_TRIANGLES);
// 	glColor3f(1.0, 0.0, 0.0);
// 	glVertex2i(0, 0);
// 	glVertex2i(5, 2);
// 	glVertex2i(5, -2);
// 	glEnd();

// 	glBegin(GL_TRIANGLES);
// 	glColor3f(1.0, 0.0, 0.0);
// 	glVertex2i(0, 0);
// 	glVertex2i(-2, -5);
// 	glVertex2i(2, -5);
// 	glEnd();

// 	glBegin(GL_TRIANGLES);
// 	glColor3f(1.0, 0.0, 0.0);
// 	glVertex2i(0, 0);
// 	glVertex2i(-5, 2);
// 	glVertex2i(-5, -2);
// 	glEnd();
// }

// void drawFanStand()
// {
// 	//glTranslatef(translate_x, translate_y, translate_z);
// 	glBegin(GL_POLYGON);
// 	glColor3f(0.0, 1.0, 0.0);
// 	glVertex2i(-1, 0);
// 	glVertex2i(1, 0);
// 	glVertex2i(1, -10);
// 	glVertex2i(-1, -10);
// 	glVertex2i(-1, 0);
// 	glEnd();
// }
//basics
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
//basics end

void drawWheel()
{
    glTranslatef(translate_x, translate_y, translate_z);
	glRotatef(spin,spin_x,spin_y,spin_z);
	//glTranslatef(-320,-240,0);
    //
    glTranslatef(320,240,0);
	glRotatef(spin, 0, 0, 1);
	glTranslatef(-320,-240,0);
    //
	bresenham_circle(200);
	bresenham_circle(40);
	
	//spokes
	draw_line(320,40,320,200);
	draw_line(120,240,280,240);
	draw_line(320,440,320,280);
	draw_line(360,240,520,240);
	
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	//******************************************//
	//------- custom code starts -------

	// drawFan();
	// drawFanStand();

    drawWheel();


	//------- custom code ends -------
	//******************************************//
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard and Mouse Interaction");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
    return 0;
}