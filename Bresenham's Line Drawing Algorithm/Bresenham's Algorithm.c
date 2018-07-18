#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

int dx, dy, pk, dx2, dy2, i, x1, x2, y1, y2;
int x[1000], y[1000];
int r, s;
float m;

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  gluOrtho2D(0.0,400.0,0.0,400.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void line()
{
    glClear (GL_COLOR_BUFFER_BIT);

    dx = (x2-x1);
    dy = (y2-y1);
    dx2 = 2*dx;
    dy2 = 2*dy;

    m = (float)dy / dx;

    x[0] = x1;
    y[0] = y1;

    printf("The value of m is %f\n", m);

    if(m<=1)
    {
        pk = dy2-dx;
        for(i=0;(y[i]<=y2 && x[i] <= x2);i++)
        {
            if(pk>=0)
            {
                x[i+1] = x[i] + 1;
                y[i+1] = y[i] + 1;
            }
            else
            {
                x[i+1] = x[i] + 1;
                y[i+1] = y[i];
            }
            pk = pk + dy2 - dx2 * (y[i+1] - y[i]);
        }
    }
    else
    {
        pk = dx2-dy;
        for(i=0;(y[i]<=y2 && x[i] <= x2);i++)
        {
            if(pk>=0)
            {
                x[i+1] = x[i] + 1;
                y[i+1] = y[i] + 1;
            }
            else
            {
                x[i+1] = x[i];
                y[i+1] = y[i]+1;
            }
            pk = pk + dx2 - dy2 * (x[i+1] - x[i]);
        }

    }


         for(i=0;(y[i]<=y2 && x[i] <= x2);i++)
         {
            r=x[i];
            s=y[i];
            glColor3f(1.0,1.0, 1.0);
            glBegin(GL_POINTS);
            glVertex2i(r, s);
            glEnd();
            printf("%d\t%d\n", r, s);
         }


    glutSwapBuffers();
}

int main(int argc,char **argv){

    printf("Enter the value of x1: ");
    scanf("%d", &x1);

    printf("Enter the value of y1: ");
    scanf("%d", &y1);

    printf("Enter the value of x2: ");
    scanf("%d", &x2);

    printf("Enter the value of y2: ");
    scanf("%d", &y2);

    glutInit(&argc,argv);

    //glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham's Line");
    init();
    glutDisplayFunc( line );
    glutMainLoop();
    return 0;
}
