#ifndef EARTH_H_INCLUDED
#define EARTH_H_INCLUDED
#include "mars.h"

const float DEG2RAD = 3.14159/180;
float c1xp=0.0,c1yp=0.0,c1zp=0.0;
float c2xp=0.0,c2yp=0.0,c2zp=0.0;
float x=1.0;
float rxp=0.0,ryp=0.0,rzp=0.0;
float r=0.0;

float roc=-940,rocx=0.0,rocd=0.0;
float cdxp1=0.0,cdxp2=0.0,cdxp3=0.0;
float width1=-940,width12=600,width13=2000;
float i,j,count=0,count1=0.0,count3=0,flag=0,flag1=0,t=0,f=0,flag3=0;

int p;
int dnr=103,dng=155,dnb=176;//day sky
int sdr=246,sdg=171,sdb=26;//sun color
int cdr=230,cdg=234,cdb=237;//cloud color
int gdr=0,gdg=180,gdb=0;//Grass color
//int m1r=103,m1g=155,m1b=176;
int m2r=103,m2g=155,m2b=176;
int m=0;

char NASA[] = "NASA";
char n[] = "M = Mars view";
char l[] = "L = Rocket Launch";
void myInit (void)
{
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(4.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}

void print( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0,0,0);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

void Sky()
{
        glPushMatrix();
        glColor3ub(dnr,dng,dnb);
        glBegin(GL_QUADS);
        glVertex2i(0,684);
        glVertex2i(902,684);
        glVertex2i(902,0);
        glVertex2i(0,0);
        glEnd();
        glPopMatrix();

        glutPostRedisplay();
}
//******Circle******
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle
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

//**********NASA part***********

void nasaWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}

void nasa()
{
    glPushMatrix();
    glColor3ub(255,0,5);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,351);
    glVertex2i(643,351);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,351);
    glVertex2i(887,351);
    glVertex2i(887,358);
    glVertex2i(640,358);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();
    glPopMatrix();



    int nasaStripe1=623;
    for(int i=2;i>=0;i--)
    {
        nasaStripe1+=25;
        nasaWindow1(nasaStripe1,328);
    }

     int nasaStripe2=623;
    for(int i=2;i>=0;i--)
    {
        nasaStripe2+=25;
        nasaWindow1(nasaStripe2,304);
    }

    int nasaStripe3=623;
    for(int i=2;i>=0;i--)
    {
        nasaStripe3+=25;
        nasaWindow1(nasaStripe3,281);
    }

    int nasaStripe4=783;
    for(int i=2;i>=0;i--)
    {
        nasaStripe4+=25;
        nasaWindow1(nasaStripe4,328);
    }

    int nasaStripe5=783;
    for(int i=2;i>=0;i--)
    {
        nasaStripe5+=25;
        nasaWindow1(nasaStripe5,304);
    }

    int nasaStripe6=783;
    for(int i=2;i>=0;i--)
    {
        nasaStripe6+=25;
        nasaWindow1(nasaStripe6,282);
    }

}
void nasaDoor()
{
    glPushMatrix();
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,257);
    glVertex2i(797,257);
    glVertex2i(797,321);
    glVertex2i(728,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(120,120,120);
    glBegin(GL_QUADS);
    glVertex2i(728,300);
    glVertex2i(797,300);
    glVertex2i(797,326);
    glVertex2i(728,326);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(743,257);
    glVertex2i(782,257);
    glVertex2i(782,295);
    glVertex2i(743,295);
    glEnd();
    glPopMatrix();
}

void static_rocket()
{
    glColor3f(0.0,0.0,0.0);//stand object
	glBegin(GL_POLYGON);
	glVertex2i(243.0,257.0);
    glVertex2i(284.0,257.0);
    glVertex2i(284.0,451.0);
    glVertex2i(243.0,451.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(284.0,300.0);
	glVertex2f(350.0,300.0);
	glVertex2f(284.0,400.0);// rocket line
	glVertex2f(350.0,400.0);
	glEnd();

    glPushMatrix();
    glTranslatef(0,rocx+rocd,0);
	glColor3f(0.8,0.498039 ,0.196078);
	glBegin(GL_POLYGON);           //core
    glVertex2f(360.0,430.0);
    glVertex2f(410.0,430.0);
    glVertex2f(410.0,280.0);
    glVertex2f(360.0,280.0);

	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);      //front
	glVertex2f(360.0,430.0);
	glVertex2f(410.0,430.0);
	glVertex2f(385.0,490.0);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);     //left_side_top
	glVertex2f(360.0,430.0);
	glVertex2f(330.0,390.0);
	glVertex2f(360.0,390.0);
	glEnd();

    glBegin(GL_POLYGON);      //left_side_bottom
	glVertex2f(360.0,330.0);
	glVertex2f(330.0,280.0);
	glVertex2f(360.0,280.0);
	glEnd();

    glBegin(GL_POLYGON);     //right_side_top
	glVertex2f(410.0,430.0);
	glVertex2f(440.0,390.0);
	glVertex2f(410.0,390.0);
	glEnd();

    glBegin(GL_POLYGON);    //right_side_button
	glVertex2f(410.0,330.0);
	glVertex2f(440.0,280.0);
	glVertex2f(410.0,280.0);
	glEnd();

	glColor3f(0.556863 ,0.137255  ,0.419608);
    glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(360.0,280.0);
	glVertex2f(366.0,260.0);
	glVertex2f(372.0,280.0);
	glEnd();

    glBegin(GL_POLYGON);   //bottom_2_exhaust
	glVertex2f(379.0,280.0);
	glVertex2f(385.0,260.0);
	glVertex2f(391.0,280.0);
	glEnd();

    glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(398.0,280.0);
	glVertex2f(404.0,260.0);
	glVertex2f(410.0,280.0);
	glEnd();
	glPopMatrix();
}
void Sun()
{
    glColor3ub(sdr,sdg,sdb);
    drawCircle(824.0f,615.0f,40.0f);
    glutPostRedisplay();
}
void Cloud()
{
    glPushMatrix();
    glTranslatef(c1xp+cdxp1,0,0);
    glColor3ub(cdr,cdg,cdb);
    drawCircle(594.0f,586.0f,20.0f);
    drawCircle(572.0f,595.0f,28.0f);
    drawCircle(539.0f,595.0f,35.0f);
    drawCircle(513.0f,575.0f,20.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(c1xp+cdxp3,0,0);
    drawCircle(193.0f,607.0f,20.0f);
    drawCircle(170.0f,615.0f,28.0f);
    drawCircle(139.0f,613.0f,35.0f);
    drawCircle(111.0f,595.0f,20.0f);
    glPopMatrix();

    glutPostRedisplay();
}
void Road()
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(0,148);
    glVertex2i(902,148);
    glVertex2i(902,47);
    glVertex2i(0,47);
    glEnd();
    glPopMatrix();

    for(int i=0;i<120*8;i+=120)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,95);
        glVertex2i(35+i,95);
        glVertex2i(35+i,100);
        glVertex2i(0+i,100);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner1()
{
    for(int i=0;i<16*60;i+=18)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner2()
{
    for(int i=0;i<16*60;i+=18)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148-100);
        glVertex2i(16+i,148-100);
        glVertex2i(16+i,157-100);
        glVertex2i(0+i,157-100);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148-100);
        glVertex2i(39+i,148-100);
        glVertex2i(39+i,157-100);
        glVertex2i(16+i,157-100);
        glEnd();
        glPopMatrix();
    }
}

void RoadGrash()
{
    glPushMatrix();
    glColor3ub(gdr,gdg,gdb);
    glBegin(GL_QUADS);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(902.0,0.0,0.0);
    glVertex3f(902.0,47.0,0.0);
    glVertex3f(0.0,47.0,0.0);
    glEnd();
    glPopMatrix();
}

void BetweenRoadAndBuldings()
{
    glPushMatrix();
    glColor3ub(gdr,gdg,gdb);
    glBegin(GL_QUADS);
    glVertex3f(0.0,157.0,0.0);
    glVertex3f(902.0,157.0,0.0);
    glVertex3f(902.0,258.0,0.0);
    glVertex3f(0.0,258.0,0.0);
    glEnd();
    glPopMatrix();
}
void Car1()
{
    glPushMatrix();
    glColor3ub(128,0,0);
    glTranslatef(c1xp,c1yp,c1zp);
    glBegin(GL_QUADS);
    glVertex2i(311-500,112);
    glVertex2i(414-500,112);
    glVertex2i(414-500,174);
    glVertex2i(311-500,174);
    glEnd();

    glColor3ub(162,42,42);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(414-500,162);
    glVertex2i(445-500,162);
    glVertex2i(473-500,134);
    glVertex2i(473-500,112);
    glVertex2i(414-500,112);
    glEnd();

    glColor3ub(75,89,89);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(417-500,158);
    glVertex2i(444-500,158);
    glVertex2i(463-500,139);
    glVertex2i(463-500,134);
    glVertex2i(417-500,134);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(464-500,128);
    glVertex2i(472-500,128);
    glVertex2i(472-500,113);
    glVertex2i(464-500,113);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(419-500,126);
    glVertex2i(431-500,126);
    glVertex2i(431-500,129);
    glVertex2i(419-500,129);
    glEnd();

    glColor3ub(48,48,46);
    drawCircle(342-500,116,15);
    glColor3ub(255,255,255);
    drawCircle(342-500,116,10);
    glColor3ub(0,0,0);
    drawCircle(342-500,116,8);

    glColor3ub(48,48,46);
    drawCircle(434-500,116,15);
    glColor3ub(255,255,255);
    drawCircle(434-500,116,10);
    glColor3ub(0,0,0);
    drawCircle(434-500,116,8);

    glPopMatrix();
}

void Car2()
{
    glPushMatrix();
    glTranslatef(c2xp,c2yp,c2zp);
    glColor3ub(153,50,204);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(459+500,154-70);
    glVertex2i(466+500,160-70);
    glVertex2i(491+500,160-70);
    glVertex2i(510+500,179-70);
    glVertex2i(568+500,179-70);
    glVertex2i(579+500,162-70);
    glVertex2i(579+500,141-70);
    glVertex2i(459+500,141-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(503+500,169-70);
    glVertex2i(512+500,177-70);
    glVertex2i(525+500,177-70);
    glVertex2i(521+500,163-70);
    glVertex2i(503+500,163-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(526+500,163-70);
    glVertex2i(530+500,177-70);
    glVertex2i(547+500,177-70);
    glVertex2i(547+500,163-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(552+500,163-70);
    glVertex2i(551+500,177-70);
    glVertex2i(561+500,177-70);
    glVertex2i(570+500,163-70);
    glEnd();

    glColor3ub(51,53,50);
    drawCircle(474+500,142-70,10);
    glColor3ub(255,0,0);
    drawCircle(474+500,142-70,8);
    glColor3ub(0,0,0);
    drawCircle(474+500,142-70,7);

    glColor3ub(51,53,50);
    drawCircle(551+500,142-70,10);
    glColor3ub(255,0,0);
    drawCircle(551+500,142-70,8);
    glColor3ub(0,0,0);
    drawCircle(551+500,142-70,7);

    glPopMatrix();
}
void rocket_translate(int value){
    roc+=1.0;
    if(roc<10000){

        rocd+=0.1;
        rocx+=0.1;
    }
    glutTimerFunc(0,rocket_translate,25);

}
void CarTranslate(int value)
{
    width1+=1.0;
    width12-=1.0;
    if(width1<10093)
    {
        cdxp1+=0.09;
        cdxp2+=0.1;
        cdxp3+=0.0001; //CloudsT variable
        c1xp+=0.1;
        if(width1>10091)
        {
            width1=-940;
            c1xp=0.0;
        }
    }
    if(width12>-1614)
    {
        c2xp-=0.5;
        if(width12==-1613)
        {
            width12=600;
            c2xp=0;
            x=1.0;
            glutPostRedisplay();
        }
    }

    glutTimerFunc(0,CarTranslate,25);
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='L' || key=='l'){
        rocket_translate(0);
        glutPostRedisplay();
    }
    if(key=='M' || key=='m'){
        glutCreateWindow ("Mars View");
        glutDisplayFunc(MyDisp);
        MyInitialization ();
        glutMainLoop();
        glutPostRedisplay();
    }
    }
void mouse(int button,int state,int x,int y)
{
    switch(button)
    {
    case GLUT_RIGHT_BUTTON:
        if(state==GLUT_DOWN)
         CarTranslate(0);
        break;
    default:
        break;
    }
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Sky();
    nasa();
    nasaDoor();
    static_rocket();
    Sun();
    Cloud();
    BetweenRoadAndBuldings();
    Road();
    RoadCorner1();
    RoadCorner2();
    RoadGrash();
    Car1();
    Car2();

    print(740,306,NASA);
    print(630,533,n);
    print(630,510,l);
    glFlush ();
    glutSwapBuffers();
}
#endif
