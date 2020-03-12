#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
static int window;
static int menu_id,menu_id1,menu_id2;
static int value = 0;
static int rot = 0;
int jj=0;

void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }
  else if(num==4)
  {
      rot+=30;
      jj=1;
    }
    else if(num==5)
    {
        rot =0;
        value =0;
        jj=0;
    }
    else if(num==6)
    {
        rot = 0;
        value=2;
    }
    else if(num==7)
    {
        rot = 0;
        value=3;

    }
    else if(num==8)
    {
        rot = 0;
        value=8;
    }
    else if(num==9)
    {
        rot = 0;
        value=9;
    }
    else if(num==10)
    {
        rot = 0;
        value=10;
    }
    else if(num==11)
    {
        rot = 0;
        value=11;
    }
    else{
    value = num;
  }
  glutPostRedisplay();
  
} 

void createMenu(void){
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Solid", 2);
    glutAddMenuEntry("Wired", 3);

    menu_id1 = glutCreateMenu(menu);
    glutAddMenuEntry("red", 8);
    glutAddMenuEntry("green", 9);

    menu_id2 = glutCreateMenu(menu);
    glutAddMenuEntry("red", 10);
    glutAddMenuEntry("green", 11);

    glutCreateMenu(menu);
    glutAddSubMenu("Teapot type", menu_id);
    glutAddSubMenu("Solid",menu_id1);
    glutAddSubMenu("Wired",menu_id2);
    glutAddMenuEntry("Quit", 0);
    glutAddMenuEntry("Rotate", 4);
    glutAddMenuEntry("Reset", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 


void display () {

    /* clear window */ 
    glClear(GL_COLOR_BUFFER_BIT);
    if(jj)
    {glRotatef(rot,0,0,1.0);jj=0; rot=0;}
    /* draw scene */
    if(value==2)
    {
        glColor3f(0.0,0.0,1.0);
    glutSolidTeapot(.5);
    }
    else if(value==3)
    {
        glColor3f(0.5,0.5,0);
    glutWireTeapot(.5);
    }
    else if(value==8)
    {
        glColor3f(1,0,0);
        glutSolidTeapot(.5);
    }
    else if(value==9)
    {
        glColor3f(0,1,0);
        glutSolidTeapot(.5);
    }
    else if(value==10)
    {
        glColor3f(1,0,0);
        glutWireTeapot(.5);
    }
    else if(value==11)
    {
        glColor3f(0,1,0);
        glutWireTeapot(.5);
    }
    
    /* flush drawing routines to the window */
    glFlush();

}

int main ( int argc, char * argv[] ) {

    
    glutInit(&argc,argv);

   
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB);

    /* create and set up a window */
    window = glutCreateWindow("Menu");
    createMenu();
    glutDisplayFunc(display);

    /* tell GLUT to wait for events */
    glutMainLoop();
}