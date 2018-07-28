#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

    double x1, x2, y1, y2, m, dx, dy;
    int i;
    double x[100], y[100];

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void DDA()
{
     glClear (GL_COLOR_BUFFER_BIT);

    dx = (x2-x1);
    dy = (y2-y1);
    m = dy/dx;

    x[0]=x1;
    y[0]=y1;

    if(m<=1)
    {
        for(i=0;;i++)
        {
            x[i+1] = x[i] + 1;
            y[i+1]= y[i] + m;

            if(x[i]==x2 && y[i]==y2)
            {
                break;
            }
        }
    }
    else
    {
        for(i=0;;i++)
        {
            x[i+1] = x[i] + (1/m);
            y[i+1]= y[i] + 1;

            if(x[i]==x2 && y[i]==y2)
            {
                break;
            }
        }
    }


    for(i=0;;i++)
    {
            glColor3f(1, 0, 0);
            glBegin(GL_POINTS);
            glVertex2d(x[i], y[i]);
            glEnd();
        if(x[i]==x2 && y[i]==y2)
        {
            break;
        }
    }

    glutSwapBuffers();

}

int main(int argc,char **argv){

    printf("Enter the value of x1: ");
    scanf("%lf", &x1);

    printf("Enter the value of y1: ");
    scanf("%lf", &y1);

    printf("Enter the value of x2: ");
    scanf("%lf", &x2);

    printf("Enter the value of y2: ");
    scanf("%lf", &y2);

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Circle Algorithm");
    init();
    glutDisplayFunc(DDA);
    glutMainLoop();
    return 0;
}


