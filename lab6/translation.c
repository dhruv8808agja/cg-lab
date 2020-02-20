// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
#define S_CIRCLE 0
#define S_POLYGON 1
#define S_LINE 2


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
	gluOrtho2D(-683, 683, -384, 384); 
}

void circle(int cx,int cy,int r,int tx,int ty)
{
	glBegin(GL_POINTS); 
	float x, y, i;
	for ( i = 0; i < (2 * pi); i += 0.001) 
	{  
		x = cx+r * cos(i); 
		y = cy+r * sin(i);	
		glVertex2i(x+tx, y+ty); 
	} 
	glEnd();
}

void polygon(int* x,int* y,int n,int tx,int ty)
{
	glBegin(GL_POLYGON);
	int i;
	for(i=0;i<n;i++)
	{
		glVertex2i(x[i]+tx,y[i]+ty);
	}
	glEnd();
}

void line(int x1,int py1,int x2,int y2,int tx,int ty)
{
	glBegin(GL_LINES);
	glVertex2i(x1+tx,py1+ty);
	glVertex2i(x2+tx,y2+ty);
	glEnd();
}

int shape,cx,cy,r,tx,ty,n,x1,x2,py1,y2;
int A[100];
int B[100];

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	if(shape==S_CIRCLE)
	{
		glColor3f(0.3, 0.0, 0.1);
		circle(cx,cy,r,0,0);
		glColor3f(0.0, 1.0, 0.0);
		circle(cx,cy,r,tx,ty);
	}else if(shape==S_POLYGON)
	{
		glColor3f(0.3, 0.0, 0.1);
		polygon(A,B,n,0,0);
		glColor3f(0.0, 1.0, 0.0);
		polygon(A,B,n,tx,ty);
	}else if(shape==S_LINE)
	{
		glColor3f(0.3, 0.0, 0.1);
		line(x1,py1,x2,y2,0,0);
		glColor3f(0.0, 1.0, 0.0);
		line(x1,py1,x2,y2,tx,ty);
	}
	
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
	printf("Choose Shape... {0: Circle, 1: Polygon, 2: Line}\n");
	scanf("%d",&shape);
	//-683, 683, -384, 384
	printf("LIMIT for x-axis : [-780,780]\n");
	printf("LIMIT for y-axis : [-420,420]\n");
	if(shape==S_CIRCLE)
	{
		printf("Enter coordinates of Circle cx,cy : ");
		scanf("%d %d",&cx,&cy);
		printf("Enter radius : ");
		scanf("%d",&r);
		printf("Enter translation factors tx,ty : ");
		scanf("%d %d",&tx,&ty);
	}else if(shape==S_POLYGON)
	{
		int i;
		printf("Enter number of points : ");
		scanf("%d",&n);
		printf("Enter %d points\n",n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&A[i],&B[i]);
		}
		printf("Enter translation factors tx,ty : ");
		scanf("%d %d",&tx,&ty);
	}else if(shape==S_LINE)
	{
		printf("Enter coordinate of POINT-1 : ");
		scanf("%d %d",&x1,&py1);
		printf("Enter coordinate of POINT-2 : ");
		scanf("%d %d",&x2,&y2);
		printf("Enter translation factors tx,ty : ");
		scanf("%d %d",&tx,&ty);
	}else{
		printf("INVALID INPUT!!!\n");
		return 0;
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

