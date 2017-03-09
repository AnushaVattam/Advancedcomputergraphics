//VM POLYGONS ANUSHA_VATTAM_ASSIGNMENT1//
//Spring 2017 ACG //
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//<<<<<<<<<<<<<<<<<<<<<Constants >>>>>>>>>>>>>>>>>>
const int screenHeight = 480; // window height is 480
const int screenWidth = 640 ; //window width is 640
//<<<<<<<<<<<<<<<<<<<<< Prototypes >>>>>>>>>>>>>>>>>>
	void exit(int) ;
        void Triangle();
        void Rectangle();
        void Hexagon();
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
        glClearColor(1.0,1.0,1.0,0.0);       // set background color
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
        glOrtho(0.0,640.0,0.0,480.0,0,0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< Triangle>>>>>>>>>>>>>>>>>
void Triangle()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.5f,0.0f);
    glVertex2f(-0.9, -0.85);
    glVertex2f(0.9, -0.85);
    glVertex2f(0.00, 0.85);
    glEnd();
}
//<<<<<<<<<<<<<<<<<<<<<<<< Rectangle>>>>>>>>>>>>>>>>>
void Rectangle()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.5f);
    glVertex2f(-1.00, 1.00);
    glVertex2f(-1.00, -1.00);
    glVertex2f(1.00, -1.00);
    glVertex2f(1.00, 1.00);
    glEnd();
}
//<<<<<<<<<<<<<<<<<<<<<<<< Hexagon>>>>>>>>>>>>>>>>>
void Hexagon()
{
    glColor3f(1.50f, 0.50f, 0.50f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.5,-0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-1.0 ,0.00);
    glEnd();
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 

        glViewport(35, 50, 65, 80);
        Triangle();


       glViewport(90, 110, 125, 145);
        Rectangle();

        glViewport(190, 210, 230, 250);
        Hexagon();

	glFlush();          // send all output to display 
}
//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>
void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
    switch(theKey)
    {

    case 't':
    case 'T':
                glClear(GL_COLOR_BUFFER_BIT);
                Triangle();
                glFlush();
                break;
    case 'H':
    case 'h':
                glClear(GL_COLOR_BUFFER_BIT);
                Hexagon();
                glFlush();
                break;
   case 'r':
   case 'R':
                glClear(GL_COLOR_BUFFER_BIT);
                Rectangle();
                glFlush();
                break;
    case 'Q':
    case 'q':
                exit(-1); //terminate the program
    default:
                break; // do nothing

    }
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int	 main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640,480);     // set window size
        glutInitWindowPosition(150, 150); // set window position on screen
        glutCreateWindow("VM POLYGONS ANUSHA_VATTAM_Assign01 - "
                         "Type T or t for Triangle/ R or r for Rectangle/H or "
                         "h for Hexagon/Q or q to quit") ; // open the screen windo
        glutDisplayFunc(myDisplay);     // register redraw function
        glutKeyboardFunc(myKeyboard); // register the keyboard action function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
}


