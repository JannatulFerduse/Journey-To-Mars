#ifndef MARS_H_INCLUDED
#define MARS_H_INCLUDED

const float dtor = 3.14159/180;

void circleDraw(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50;
    GLfloat twicePi = 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
        glEnd();
}
void halfCircle(GLfloat x, GLfloat y, GLfloat radius)
{
int i;
    int triangleAmount = 50; //# of triangles used to draw circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  3.1416 / triangleAmount)),
            y + (radius * sin(i * 3.1416 / triangleAmount))
        );
    }
        glEnd();
}

void rover()
{


glColor3ub(188,44 ,110);
circleDraw(400.0f,250.0f,40.0f);
circleDraw(485.0f,250.0f,40.0f);
circleDraw(570.0f,250.0f,40.0f);

glColor3f(0,0,0.196078);
circleDraw(400.0f,250.0f,25.0f);
circleDraw(485.0f,250.0f,25.0f);
circleDraw(570.0f,250.0f,25.0f);

halfCircle(480.0f,360.0f,120.0f);

circleDraw(300.0f,515.0f,20.0f);
glColor3f(0.8,0.498039 ,0.196078);

	glBegin(GL_POLYGON);//core
    glVertex2f(340.0,360.0);
    glVertex2f(620.0,360.0);
    glVertex2f(620.0,280.0);
    glVertex2f(340.0,280.0);
    glEnd();

    glColor3ub(128,0 ,128);
    glBegin(GL_POLYGON);//core
    glVertex2f(340.0,350.0);
    glVertex2f(620.0,350.0);
    glVertex2f(620.0,290.0);
    glVertex2f(340.0,290.0);
    glEnd();

    glColor3ub(188,44 ,110);
    glBegin(GL_POLYGON);//1st window
    glVertex2f(400.0,420.0);
    glVertex2f(450.0,420.0);
    glVertex2f(450.0,370.0);
    glVertex2f(400.0,370.0);
    glEnd();

    glBegin(GL_POLYGON);//2nd window
    glVertex2f(500.0,420.0);
    glVertex2f(550.0,420.0);
    glVertex2f(550.0,370.0);
    glVertex2f(500.0,370.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(400.0,450.0);
    glVertex2f(400.0,520.0);
    glVertex2f(340.0,520.0);
    glVertex2f(340.0,510.0);
    glVertex2f(390.0,510.0);
    glVertex2f(390.0,440.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(340.0,540.0);
    glVertex2f(300.0,540.0);
    glVertex2f(300.0,490.0);
    glVertex2f(340.0,490.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(600.0,360.0);
    glVertex2f(620.0,420.0);
    glVertex2f(650.0,430.0);
    glEnd();
    circleDraw(650.0f,430.0f,10.0f);
    glColor3f(0.756,0.615,.4);
    circleDraw(660.0f,430.0f,10.0f);

	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();

}

void MyDisp(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    rover();
    glFlush ();
}
void MyInitialization (void)
{
        glClearColor(0.756,0.615,.4,0.0);
        glPointSize(4.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}
#endif
