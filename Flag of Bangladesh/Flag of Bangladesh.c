
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>


int pk, i, r, cx, cy;
int x[1000], y[1000];

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void line()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(70 , 70);
    glVertex2i(70, 170);
    glVertex2i(170, 170);
    glVertex2i(170, 70);
    glEnd();

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
        glColor3f(1.0,0.0, 0.0);
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

    glutSwapBuffers();
}

int main(int argc,char **argv){

    r=20;
    cx=120, cy=120;

    glutInit(&argc,argv);

    //glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Flag of Bangladesh");
    init();
    glutDisplayFunc( line );
    glutMainLoop();
    return 0;
}
