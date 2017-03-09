//VM Scene Production ANUSHA_VATTAM_ASSIGNMENT_S1//
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define PI (4.0*atan(1.0))

using namespace std;
const int screenHeight = 480;
const int screenWidth = 640;

void exit(int) ;
void drawSquare();
void drawTriangle();
void drawHexagon();
void drawCircle();
void drawCube();
void drawLine();
void drawPoint();

//--------------- INIT Function ---------------
void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0, 0.0, 0.5);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-0.5, 1.5, -0.5, 1.5, -1.5, 0.5); //Length of the edge is 2
}

//---------------- Declaration of Functions -----------------

//----------------Point Function-------------------
void drawPoint()
{
glPointSize(5.0f); //increases point size to make it visible
glBegin(GL_POINTS);
glColor3f(0.1f,0.2f,1.0f);
glVertex3f(0.50,1.0,0.0);
glEnd();
}
//---------------Line Function---------------------
void drawLine()
{
glLineWidth(7.0f);//increases line size to make it visible
glBegin(GL_LINES);
glColor3f(0.5f,0.f,0.2f);
glVertex3f(0.0,0.95,0.0);
glVertex3f(0.95 ,0.95,0);
glEnd();
}
//---------------- Triangle Function ----------------
void drawTriangle()
{
glBegin(GL_TRIANGLES);
glColor3f(0.0, 0.5, 0.5);
glVertex3f(0,0, 0);
glVertex3f(1.50, 0, 0);
glVertex3f(1,1.50, 0);
glEnd();
}
//--------------- Square Function ------------------
void drawSquare()
{
//edge 1, it becomes square
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);
glVertex3f(0.5,0.5,0.0);
glVertex3f(1.5,0.5, 0.0);
glVertex3f(1.5,1.5, 0.0);
glVertex3f(0.5, 1.5, 0.0);
glEnd();
}

//---------------- Hexagon Function -----------------
void drawHexagon()
{
glBegin(GL_POLYGON);
glColor3f(0.0, 0.2, 0.5);
glVertex3f(-0.25, 0.25,0);
glVertex3f(0.25, 0.25,0);
glVertex3f(0.50, 0.0,0);
glVertex3f(0.25,-0.25,0);
glVertex3f(-0.25, -0.25,0);
glVertex3f(-0.50 ,0.00,0);
glEnd();
}
//---------------- Circle Function -------------------
void drawCircle()
{
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.0f,0.5f,0.0f);
for (float i = 0; i < 2*PI; i+=0.01)
{
float x = sin(i)*0.5 + 0.5;
float y = cos(i)*0.5+ 0.5;
glVertex3f(x, y, 0);
}
glEnd();
}
//----------------- Cube Function --------------------
void drawCube()
{
 // Front face of cube
glBegin(GL_POLYGON);
glColor3f(0.5f,0.0f,0.5f);
glVertex3f(0,0,0);
glVertex3f(0.75f,-0.25f,0.25f);
glVertex3f(0.75f,0.75f,0.25f);
glVertex3f(0,1,0);
glEnd();



// Right side face of cube
glBegin(GL_POLYGON);
glColor3f(0.25f,0.0f,0.25f);
glVertex3f(0.75,-0.25,0.25);
glVertex3f(1.25f,0,0.75);
glVertex3f(1.25f,1,0.75f);
glVertex3f(0.75f,0.75,0.25f);
glEnd();


// Top face of cube
glBegin(GL_POLYGON);
glColor3f(0.5, 0.5, 0.2);
glVertex3f(0, 1, 0);
glVertex3f(0.75, 0.75, 0.25);
glVertex3f(1.25,1,0.75);
glVertex3f(0.5,1.25,1.25);
glEnd();
// Left face of cube
glBegin(GL_POLYGON);
glColor3f(1.5, 0.5, 0.0);
glVertex3f(0, 0, 0);
glVertex3f(0.5, 0.25, 1.25);
glVertex3f(0.5,1.25,1.25);
glVertex3f(0,1,0);
glEnd();

// Bottom face of cube
glBegin(GL_POLYGON);
glColor3f(0.0, 0.5, 0.6);
glVertex3f(0, 0, 0);
glVertex3f(0.75, -0.25, 0.25);
glVertex3f(1.25,0,0.75);
glVertex3f(0.5,0.25,1.25);
glEnd();

// Back face of cube
glBegin(GL_POLYGON); //
glColor3f(1.0, 0.6, 0.5);
glVertex3f(1.25, 0, 0.75);
glVertex3f(1.25,1,0.75);
glVertex3f(0.5,1.25,1.25);
glVertex3f(0.5,0.25,1.25);
glEnd();


}
//--------------- MyDisplay Function -------------------
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT); // clear the screen
glViewport(20, 20, 50, 50);
drawPoint();
glViewport(80, 80, 90, 90);
drawLine();
glViewport(280, 100, 240, 180);
drawTriangle();
glViewport(60, 60, 50, 50);
drawSquare();
glViewport(150, 150, 150, 150);
drawCircle();
glViewport(480, 350, 370, 490);
drawHexagon();
glViewport(250, 250, 250, 250);
drawCube();
glFlush();
}
//---------------- Keyboard Events ------------------
void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
switch(theKey)
{
case 'P':
case 'p':
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(250, 250, 250, 250);
        drawPoint();
        glFlush();
       break;
case 's':
case 'S':
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(250, 250, 250, 250);
        drawSquare();
        glFlush();
        break;
case 't':
case 'T':
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(250, 250, 250, 250);
        drawTriangle();
        glFlush();
        break;
case 'h':
case 'H':
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(250, 250, 250, 250);
        drawHexagon();
        glFlush();
        break;
case 'c':
case 'C':
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(250, 250, 250, 250);
        drawCircle();
        glFlush();
        break;
case 'u':
case 'U':
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(250, 250, 250, 250);
        drawCube();
        glFlush();
        break;
case 'l':
case 'L':
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(250, 250, 250, 250);
        drawLine();
        glFlush();
        break;
case 'Q':
case 'q':
        exit(-1); //terminate the program
default:
        break; //  to break the program by no action
}
}
//----------------- Main Function -------------------
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(screenWidth,screenHeight);
glutInitWindowPosition(100, 100);
glutCreateWindow("VM Scene Production ANUSHA_VATTAM_AssignS1 - "
                 "Type P,L,T,S,C,U "
                 "or q to quit");
glViewport(0,250, 650,650);
glutDisplayFunc(myDisplay);
glutKeyboardFunc(myKeyboard);
myInit();
glutMainLoop();
}
