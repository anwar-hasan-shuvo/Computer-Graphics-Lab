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
        glBegin(GL_POLYGON);
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



    //1st
    glColor3f(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3f(20, 30, 0);
    glVertex3f(18, 25, 0);
    glVertex3f(22, 25, 0);
    glEnd();

    //2nd
    glColor3f(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3f(18, 15, 0);
    glVertex3f(20, 10, 0);
    glVertex3f(22, 15, 0);
    glEnd();

    //3rd
    glColor3f(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3f(22, 25, 0);
    glVertex3f(27, 29, 0);
    glVertex3f(25, 22, 0);
    glEnd();

     //3rd
    glColor3f(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3f(25, 22, 0);
    glVertex3f(30, 20, 0);
    glVertex3f(25, 18, 0);
    glEnd();

    //4th
    glColor3f(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3f(25, 22, 0);
    glVertex3f(30, 20, 0);
    glVertex3f(25, 18, 0);
    glEnd();


    //5th
    glColor3f(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3f(18, 25, 0);
    glVertex3f(13, 29, 0);
    glVertex3f(15, 22, 0);
    glEnd();

    //6th
    glColor3f(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3f(15, 22, 0);
    glVertex3f(10, 20, 0);
    glVertex3f(15, 18, 0);
    glEnd();

    //7th
    glColor3f(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3f(15, 18, 0);
    glVertex3f(12, 13, 0);
    glVertex3f(18, 15, 0);
    glEnd();

     //8th
    glColor3f(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex3f(25, 18, 0);
    glVertex3f(28, 13, 0);
    glVertex3f(22, 15, 0);
    glEnd();

    //Dandy
    glColor3f(0.0, 1.0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(22, 14, 0);
    glVertex3f(24, 14, 0);
    glVertex3f(26, 6, 0);
    glVertex3f(28, 7, 0);
    glVertex3f(28, 7, 0);
    glVertex3f(24, 14, 0);
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
    glutCreateWindow("Sun Flower");
    init();
    glutDisplayFunc( Draw );
    glutMainLoop();
    return 0;
}
