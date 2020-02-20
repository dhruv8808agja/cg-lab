// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 


// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	// making picture color green (in RGB mode), as middle argument is 1.0 
	glColor3f(0.0, 1.0, 0.0); 
	
	// breadth of picture boundary is 1 pixel 
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction 
	gluOrtho2D(-780, 780, -420, 420); 
}

void polygon(int* x,int* y,int n)
{
	int i;
	glColor3f(0.3, 0.0, 0.1);
	glBegin(GL_POLYGON);
	for(i=0;i<n;i++)
	{
		glVertex2i(x[i],y[i]);
	}
	glEnd();
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_POLYGON);
	for(i=0;i<n;i++)
	{
		glVertex2i(-x[i],y[i]);
	}
	glEnd();
	glColor3f(0.3, 0.0, 0.7);
	glBegin(GL_POLYGON);
	for(i=0;i<n;i++)
	{
		glVertex2i(x[i],-y[i]);
	}
	glEnd();
}



int n;

int A[100];
int B[100];

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT);

		polygon(A,B,n);

	glEnd();
	
	 /*
 	circle(50,50,100,-100,100);
 	int A[4]={0,100,100,0};
 	int B[4]={0,0,100,100};
 	polygon(A,B,4,300,0);
 	line(0,0,300,300,350,-350);*/
	glFlush(); 
} 

int main (int argc, char** argv) 
{
	printf("LIMIT for x-axis : [-780,780]\n");
	printf("LIMIT for y-axis : [-420,420]\n");

		int i;
		printf("Enter number of points : ");
		scanf("%d",&n);
		printf("Enter %d points\n",n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&A[i],&B[i]);
		}


	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 
	
	// Giving name to window 
	glutCreateWindow("Circle Drawing"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

