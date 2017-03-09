#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>


// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Cube Function>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.//

void CubeFunc();
void ngon(int);

void exit(int);

void myInit(void)
{
    glMatrixMode(GL_PROJECTION);
    glClearColor(0.0,0.0,0.0,0.0);
    glLoadIdentity();
    gluPerspective(0.0,1.05,0.0,0.0);
    gluLookAt(0,0,-1,0,0,-5,0,2,0);
    glViewport(0,500, 0, 500 ); // set viewport of 500X500
}


// Display function to call the respectoive functions and to display the diagram
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the screen
    glLoadIdentity();

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Point >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
    glPointSize(5.0);
    glPushMatrix();
    glTranslatef(0.125, 0.125, 0);
    glScalef(2, 2, 0);
    glBegin(GL_POINTS);
    glColor3f(1.5f, 0.5f,1.5f);
    glVertex3f(0.0f,0.0f,0.0f);
    glEnd();
    glPopMatrix();

// <<<<<<<<<<<<<<<<<<<<Triangle>>>>>>>>>>>>>>>>>>>>>>>>>>>//
    glColor3f(0.3f, 1.5f, 1.0f);
    glTranslatef(-0.5, 0.0, 0.0);
    glScalef(0.3, 0.3, 0.3);
    glRotatef(-55, 0, 0, 1);
    ngon(3);
    glPopMatrix();
    glPushMatrix();
 // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Line>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
    glTranslatef(0, 0.5, 0.0);
     glScalef(0.5, 0.5, 0.5);
     glRotatef(35, 0, 0, 1);
     glLineWidth(3.5f);
     glColor3f(1.0f,0.5f,0.0f);
     glBegin(GL_LINES);
     glVertex3f(0.0, 2.5, 0.0);
     glVertex3f(3.0, 2.5, 0.0);
     glEnd();
     glPopMatrix();
     glPushMatrix();
// <<<<<<<<<<<<<<<<<Square>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
     glColor3f(0.0f, 0.5f, 1.0f);
     glTranslatef(0, 0.75, 0);
     glScalef(0.5, 0.5, 0.5);
     glRotatef(80, 1, 0, 1);
     ngon(4);
     glPopMatrix();
     glPushMatrix();
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Cube>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
     // Initital Cube
     glTranslatef(-0.6, 0.7, 0.0);
     glScalef(0.25, 0.25, 0.25);
     CubeFunc();
     glPopMatrix();
     glPushMatrix();

     // Cube
     glTranslatef(0.7, -0.7, 0.0);
     glScalef(0.25, 0.25, 0.25);
     glRotatef(45.0, 1.0, 1.0, 1.0);
     CubeFunc();
     glPopMatrix();
     glPushMatrix();
//<<<<<<<<<<<<<<<<<<<<<<<<<<Hexagon>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
     // Hexagon
     glColor3f(0.70f, 0.10f, 0.30f);
     glTranslatef(-0.1, -0.8, 0.33);
     glScalef(0.53, 0.85, 0.68);
     glRotatef(-55, 0, 0, 1);
     ngon(6);
     glPopMatrix();
     glPushMatrix();
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Circle>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
     glColor3f(0.55f,0.20f,0.15f);
     glTranslatef(-0.60,-0.60,0.0); // translating to (-0.6,-0.6,0.0)
     glScalef(0.4,0.3,0.2); // scaleing by factor 0.4,0.3,0.2 along x,y,z respectively
     glRotatef(30,0,0,1); // rotating by 30deg around z axis
     ngon(30);
     glPopMatrix();
     glPushMatrix();
//<<<<<<<<<to display >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//

     glFlush();
}

//<<<<<<<<<<< Function that accepts the value entered by the user on the keyboard>>>>>//
void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
    switch(theKey)
    {
        // It comes to this case when the user wants to exit from the window screen
        case 'Q':
        case 'q':
                exit(-1); // Program terminates by closing the window when the user enters Q or q on the keyboard
                break;

        default:
                break;
    }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Main Function>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
    glutInitWindowSize(800,600);     // set window size
    glutInitWindowPosition(100,150); // set window position on screen
    glutCreateWindow("Scene-S2 - Type Q or q to quit") ; // open the screen window
    glutDisplayFunc(myDisplay);     // register redraw function
    glutKeyboardFunc(myKeyboard); // register the keyboard action function
    myInit();
    glutMainLoop(); 		    // go into a perpetual loop
}

//<<<<<<<<<<<<<< Function to set values for a cube>>>>>>>>>>>>>>>>>>>>>>>>>//
void CubeFunc()
{

    // back side
    glColor3f(0.3f,0.2f,1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.4, -0.5, -0.4);
    glVertex3f(0.4, 0.5, -0.4);
    glVertex3f(-0.4, 0.5, -0.4);
    glVertex3f(-0.4, -0.5, -0.4);
    glEnd();

    // front side
    glColor3f(1.0f, 2.0f, 0.5f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.5, -0.6, 0.4);
    glVertex3f(0.5, 0.4, 0.4);
    glVertex3f(-0.3, 0.4, 0.4);
    glVertex3f(-0.3, -0.6, 0.4);
    glEnd();


    // top side
    glColor3f(0.5f,0.0f,0.15f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.5, 0.4, -0.4);
    glVertex3f(0.4, 0.5, 0.4);
    glVertex3f(-0.4, 0.5, 0.4);
    glVertex3f(-0.3, 0.4, -0.4);
    glEnd();
   // right side
    glColor3f(1.0f, 0.52f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.5, -0.6, 0.4);
    glVertex3f(0.5, 0.4, -0.4);
    glVertex3f(0.4, 0.5, -0.4);
    glVertex3f(0.4, -0.5, 0.4);
    glEnd();

    // bottom side
    glColor3f(0.0f, 0.2f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.5, -0.6, -0.4);
    glVertex3f(0.4, -0.5, 0.4);
    glVertex3f(-0.4, -0.5, 0.4);
    glVertex3f(-0.3, -0.6, -0.4);
    glEnd();

   // left side
    glColor3f(0.3f, 0.5f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.4, -0.5, -0.4);
    glVertex3f(-0.3, -0.6, 0.4);
    glVertex3f(-0.3, 0.4, 0.4);
    glVertex3f(-0.4, 0.5, -0.4);
    glEnd();



}


//Function to draw a N-sided object that is upright (defined to have the bottom edge horizontal) at the center of the current model identity, with diameter = 1
void ngon(int n)
{
    float degree, vertx, verty, rotate, degToRad;
    rotate = 360.0/n;       //Vertex rotation increment
    degree = rotate/2 + 180;//Current degree of vertex (starts rotated to make object upright)
    degToRad = 180/3.14159; //Conversion factor from degrees to radians
    glBegin(GL_POLYGON);

    for(int i = 0; i < n; i++, degree += rotate)
    {
        vertx = 0.5 * sin(degree/degToRad);        //next vertex's x coordinate
        verty = 0.5 * sin((90 - degree)/degToRad); //next vertex's y coordinate
        glVertex3f(vertx, verty, 0);
    }

    glEnd();

}
