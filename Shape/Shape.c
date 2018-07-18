
#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
glColor3f (255,69,0);
glBegin(GL_POLYGON);
glVertex3f (20, 20, 0.0);
glVertex3f (20, 30, 0.0);
glVertex3f (30, 20, 0.0);
glVertex3f (30, 30, 0.0);
glVertex3f (20, 30, 0.0);
glVertex3f (30, 30, 0.0);
glEnd();

glColor3f (0, 128, 0);
glBegin(GL_POLYGON);
glVertex3f (10, 25, 0.0);
glVertex3f (20, 30, 0.0);
glVertex3f (20, 20, 0.0);
glEnd();

glColor3f (0, 0, 255);
glBegin(GL_POLYGON);
glVertex3f (25, 40, 0.0);
glVertex3f (20, 30, 0.0);
glVertex3f (30, 30, 0.0);
glEnd();

glColor3f (128, 0, 128);
glBegin(GL_POLYGON);
glVertex3f (30, 20, 0.0);
glVertex3f (30, 30, 0.0);
glVertex3f (40, 25, 0.0);
glEnd();

glColor3f (0, 255, 255);
glBegin(GL_POLYGON);
glVertex3f (25, 10, 0.0);
glVertex3f (30, 20, 0.0);
glVertex3f (20, 20, 0.0);
glEnd();




glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 50.0, 0.0, 50.0, -1.0, 1.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer & RGBA). Open window with "hello"
* In its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Shape");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

