#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>


int pk, i, r, cx, cy;
int x[1000], y[1000];

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  gluOrtho2D(0.0,40.0,0.0,40.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
    glClear (GL_COLOR_BUFFER_BIT);

     pk = 1-r;
    x[0] = 0;
    y[0] = r;

    for(i=0;;i++)
    {
        if(pk >= 0)
        {
            x[i+1] = x[i] + 1;
            y[i+1] = y[i] - 1;
        }
        else
        {
            x[i+1] = x[i] + 1;
            y[i+1] = y[i];
        }
        pk = pk + 1 + ((2) * (x[i]+1)) + ((y[i+1] * y[i+1])-(y[i] * y[i])) - (y[i+1] - y[i]);
        if((x[i] >= y[i]))
        {
            break;
        }

    }

    for(i=0;;i++)
    {
        glColor3f(1, 0, 0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2i(x[i]+cx, y[i]+cy);
        glVertex2i(y[i]+cy, x[i]+cx);
        glVertex2i(-x[i]+cx, y[i]+cy);
        glVertex2i(y[i]+cy, -x[i]+cx);
        glVertex2i(-x[i]+cx, -y[i]+cy);
        glVertex2i(-y[i]+cy, -x[i]+cx);
        glVertex2i(x[i]+cx, -y[i]+cy);
        glVertex2i(-y[i]+cy, x[i]+cx);

        glEnd();
        if((x[i] >= y[i]))
        {
            break;
        }
    }

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (16, 12, 0.0);
    glVertex3f (16, 35, 0.0);
    glVertex3f (17, 12, 0.0);
    glVertex3f (17, 35, 0.0);
    glVertex3f (16, 35, 0.0);
    glEnd();

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (19, 12, 0.0);
    glVertex3f (19, 35, 0.0);
    glVertex3f (21, 12, 0.0);
    glVertex3f (21, 35, 0.0);
    glVertex3f (19, 35, 0.0);
    glEnd();

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (23, 12, 0.0);
    glVertex3f (23, 35, 0.0);
    glVertex3f (24, 12, 0.0);
    glVertex3f (24, 35, 0.0);
    glVertex3f (23, 35, 0.0);
    glEnd();

    glColor3f (139,0,0);
    glBegin(GL_POLYGON);
    glVertex3f (10, 12, 0.0);
    glVertex3f (10, 13, 0.0);
    glVertex3f (30, 12, 0.0);
    glVertex3f (30, 13, 0.0);
    glVertex3f (10, 13, 0.0);
    glEnd();

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (16, 34, 0.0);
    glVertex3f (16, 35, 0.0);
    glVertex3f (23, 34, 0.0);
    glVertex3f (23, 35, 0.0);
    glVertex3f (16, 35, 0.0);
    glEnd();

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (12, 13, 0.0);
    glVertex3f (12, 23, 0.0);
    glVertex3f (13, 13, 0.0);
    glVertex3f (13, 23, 0.0);
    glVertex3f (12, 23, 0.0);
    glEnd();

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (10, 13, 0.0);
    glVertex3f (10, 23, 0.0);
    glVertex3f (11, 13, 0.0);
    glVertex3f (11, 23, 0.0);
    glVertex3f (10, 23, 0.0);
    glEnd();

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (10, 23, 0.0);
    glVertex3f (10, 24, 0.0);
    glVertex3f (13, 23, 0.0);
    glVertex3f (13, 24, 0.0);
    glVertex3f (10, 24, 0.0);
    glEnd();

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (26, 13, 0.0);
    glVertex3f (26, 23, 0.0);
    glVertex3f (27, 13, 0.0);
    glVertex3f (27, 23, 0.0);
    glVertex3f (26, 23, 0.0);
    glEnd();

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (29, 13, 0.0);
    glVertex3f (29, 23, 0.0);
    glVertex3f (30, 13, 0.0);
    glVertex3f (30, 23, 0.0);
    glVertex3f (29, 23, 0.0);
    glEnd();

    glColor3f (1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (26, 23, 0.0);
    glVertex3f (26, 24, 0.0);
    glVertex3f (30, 23, 0.0);
    glVertex3f (30, 24, 0.0);
    glVertex3f (26, 24, 0.0);
    glEnd();

    glutSwapBuffers();
}

int main(int argc,char **argv){

    r=5;
    cx = 20;
    cy = 20;

    glutInit(&argc,argv);

    //glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Shahid Minar");
    init();
    glutDisplayFunc( Draw );
    glutMainLoop();
    return 0;
}
