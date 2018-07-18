#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
glColor3f (0,128,0);
glBegin(GL_POLYGON);
glVertex3f (19, 19, 0.0);
glVertex3f (19, 21, 0.0);
glVertex3f (21, 19, 0.0);
glVertex3f (21, 21, 0.0);
glVertex3f (19, 21, 0.0);
glEnd();

glColor3f (0,128,0);
glBegin(GL_POLYGON);
glVertex3f (19, 19, 0.0);
glVertex3f (17, 20, 0.0);
glVertex3f (19, 21, 0.0);
glEnd();

glColor3f (0,128,0);
glBegin(GL_POLYGON);
glVertex3f (19, 19, 0.0);
glVertex3f (20, 17, 0.0);
glVertex3f (21, 19, 0.0);
glEnd();

glColor3f (0,128,0);
glBegin(GL_POLYGON);
glVertex3f (21, 19, 0.0);
glVertex3f (21, 21, 0.0);
glVertex3f (23, 20, 0.0);
glEnd();

glColor3f (0,128,0);
glBegin(GL_POLYGON);
glVertex3f (19, 21, 0.0);
glVertex3f (21, 21, 0.0);
glVertex3f (20, 23, 0.0);
glEnd();

glColor3f (255,0,0);
glBegin(GL_POLYGON);
glVertex3f (16, 16, 0.0);
glVertex3f (16, 18, 0.0);
glVertex3f (18, 16, 0.0);
glVertex3f (18, 18, 0.0);
glVertex3f (16, 18, 0.0);
glVertex3f (18, 18, 0.0);
glEnd();

glColor3f (255,0,0);
glBegin(GL_POLYGON);
glVertex3f (18, 16, 0.0);
glVertex3f (18, 18, 0.0);
glVertex3f (20, 17, 0.0);
glEnd();

glColor3f (255,0,0);
glBegin(GL_POLYGON);
glVertex3f (18, 18, 0.0);
glVertex3f (17, 20, 0.0);
glVertex3f (16, 18, 0.0);
glEnd();

glColor3f (255,0,0);
glBegin(GL_POLYGON);
glVertex3f (16, 16, 0.0);
glVertex3f (16, 18, 0.0);
glVertex3f (14, 17, 0.0);
glEnd();

glColor3f (255,0,0);
glBegin(GL_POLYGON);
glVertex3f (16, 16, 0.0);
glVertex3f (18, 16, 0.0);
glVertex3f (17, 14, 0.0);
glEnd();

glColor3f (255, 255, 1.0);
glBegin(GL_POLYGON);
glVertex3f (22, 16, 0.0);
glVertex3f (22, 18, 0.0);
glVertex3f (24, 16, 0.0);
glVertex3f (24, 18, 0.0);
glVertex3f (22, 18, 0.0);
glVertex3f (24, 18, 0.0);
glEnd();

glBegin(GL_POLYGON);
glVertex3f (22, 18, 0.0);
glVertex3f (22, 16, 0.0);
glVertex3f (20, 17, 0.0);
glEnd();

glBegin(GL_POLYGON);
glVertex3f (22, 16, 0.0);
glVertex3f (24, 16, 0.0);
glVertex3f (23, 14, 0.0);
glEnd();

glBegin(GL_POLYGON);
glVertex3f (24, 16, 0.0);
glVertex3f (24, 18, 0.0);
glVertex3f (26, 17, 0.0);
glEnd();

glBegin(GL_POLYGON);
glVertex3f (22, 18, 0.0);
glVertex3f (24, 18, 0.0);
glVertex3f (23, 20, 0.0);
glEnd();

glColor3f (0, 0, 255);
glBegin(GL_POLYGON);
glVertex3f (19, 13, 0.0);
glVertex3f (19, 15, 0.0);
glVertex3f (21, 13, 0.0);
glVertex3f (21, 15, 0.0);
glVertex3f (19, 15, 0.0);
glEnd();

glColor3f (0, 0, 255);
glBegin(GL_POLYGON);
glVertex3f (19, 15, 0.0);
glVertex3f (19, 13, 0.0);
glVertex3f (17, 14, 0.0);
glEnd();

glColor3f (0, 0, 255);
glBegin(GL_POLYGON);
glVertex3f (19, 13, 0.0);
glVertex3f (21, 13, 0.0);
glVertex3f (20, 11, 0.0);
glEnd();

glColor3f (0, 0, 255);
glBegin(GL_POLYGON);
glVertex3f (21, 13, 0.0);
glVertex3f (21, 15, 0.0);
glVertex3f (23, 14, 0.0);
glEnd();

glColor3f (0, 0, 255);
glBegin(GL_POLYGON);
glVertex3f (19, 15, 0.0);
glVertex3f (21, 15, 0.0);
glVertex3f (20, 17, 0.0);
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
glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);
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
glutCreateWindow ("Flower");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
