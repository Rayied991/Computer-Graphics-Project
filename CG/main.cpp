#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
#define PI     3.14159265358979323846
using namespace std;

bool night=false;
bool vrain=false;

char travel[] = "Welcome To Sajek";

float anglel_M = 0.0f;
float anglel_N = 0.0f;
GLfloat speed_M= 0.0f;
GLfloat speed_N = 0.0f;

GLfloat trainSpeed=0.02f;
GLfloat trainPos = 0.0f;

GLfloat rainSpeed=0.02f;
GLfloat rainPos = 0.0f;
GLfloat rainSpeedX=0.01f;
GLfloat rainPosX = 0.0f;


GLfloat positionOfCloud1 = 0.0f;
GLfloat speedOfCloud1 = 0.001f;
GLfloat positionOfCloud2 = 0.0f;
GLfloat speedOfCloud2 = 0.002f;

void line(double a1,double b1,double a2,double b2) // to draw line
{
    glBegin(GL_LINES);
    glVertex2f(a1,b1);
    glVertex2f(a2,b2);
    glEnd();

}
void triangle(double a1,double b1,double a2,double b2,double a3,double b3) // to draw triangle
{
    glBegin(GL_TRIANGLES);
    glVertex2f(a1,b1);
    glVertex2f(a2,b2);
    glVertex2f(a3,b3);
    glEnd();
}

void quad(double a1,double b1,double a2,double b2,double a3,double b3,double a4,double b4) // to draw quad
{
    glBegin(GL_QUADS);
    glVertex2f(a1,b1);
    glVertex2f(a2,b2);
    glVertex2f(a3,b3);
    glVertex2f(a4,b4);
    glEnd();
}


void printText( float x, float y, char *st) // to print string
{
    int l,i;
    l=strlen( st );
    glColor3ub(230,196,38);
    glRasterPos2f( x, y);
    for( i=0; i < l; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

void circle(GLfloat x, GLfloat y, GLfloat radius) // to draw circle
{
    int i;
    float angle;
    glBegin(GL_POLYGON);
    for(i=0; i<100; i++)
    {
        angle = i*2*(M_PI/100);
        glVertex2f(x+(sin(angle)*radius),y+(cos(angle)*radius));
    }
    glEnd();
}




void update(int value)
{

    if(trainPos<-2)
    {
        trainPos=1.8;
    }
    else if(trainPos>1.8)
    {
        trainPos=-1.8;
    }
    if(rainPos<-.001)
    {
        rainPos=.5;
    }
    if(rainPosX<-0.1)
    {
        rainPosX=.05;
    }
    if(vrain)
    {
        rainPos-=rainSpeed;
        rainPosX-=rainSpeedX;
    }

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}
void cloudAnimation1(int value)
{

    if(positionOfCloud1<-1.7f)
        positionOfCloud1=0.6f;

    positionOfCloud1-=speedOfCloud1;
    glutPostRedisplay();
    glutTimerFunc(40,cloudAnimation1,0);



}
void cloudAnimation2(int value)
{

    if(positionOfCloud2<-0.6f)
        positionOfCloud2=1.6f;

    positionOfCloud2-=speedOfCloud2;
    glutPostRedisplay();
    glutTimerFunc(40,cloudAnimation2,0);
}
void cloud1()
{

    glPushMatrix();
    glTranslatef(positionOfCloud1,0.05f,0.0f);
    int i;

    GLfloat x=.5f;
    GLfloat y=0.90f;
    GLfloat radius=0.05f;
    int triangleAmount=20;
    GLfloat twicePi=2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,240,255);
    glVertex2f(x,y);
    for(i=0; i<=triangleAmount; i++)
    {
        glVertex2f(
            x+(radius*cos(i*twicePi/triangleAmount)),
            y+(radius*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();

    GLfloat a=.55f;
    GLfloat b=.87f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    GLfloat c=.45f;
    GLfloat d=.87f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=.52f;
    GLfloat f=.84f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=.6f;
    GLfloat h=.86f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();






}

void cloud2()
{

    glPushMatrix();
    glTranslatef(positionOfCloud2,-0.02f,0.0f);
    int i;

    GLfloat x=-.5f;
    GLfloat y=0.84f;
    GLfloat radius=0.05f;
    int triangleAmount=20;
    GLfloat twicePi=2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,240,255);
    glVertex2f(x,y);
    for(i=0; i<=triangleAmount; i++)
    {
        glVertex2f(
            x+(radius*cos(i*twicePi/triangleAmount)),
            y+(radius*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();

    GLfloat a=-.55f;
    GLfloat b=.81f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a + (radius * cos(i *  twicePi / triangleAmount)),
            b + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    GLfloat c=-.45f;
    GLfloat d=.81f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            c + (radius * cos(i *  twicePi / triangleAmount)),
            d + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat e=-.52f;
    GLfloat f=.78f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat g=-.6f;
    GLfloat h=.80f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius * cos(i *  twicePi / triangleAmount)),
            f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();


}


void daysky()
{
    glColor3ub(100, 160, 210);
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0,0);
    glVertex2f(1.0,0);
    glColor4f(0.6f, 0.8f, 1.0f, 1.0f);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glEnd();

}

void nightsky()
{
    glColor3ub(13, 42, 67);
    glBegin(GL_QUADS);

    glVertex2f(-1.0,0);
    glVertex2f(1.0,0);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glEnd();

}


void myDisplay1(void)
{

    glClearColor(0.53f,0.81f,0.92f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    daysky();


    cloud1();
    cloud2();



    glFlush();

}

void myDisplay2(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    nightsky();
    glFlush();


}
void backGround()
{


    glColor3ub(4,88,50);
    triangle( .2,-.1,1,-.1,.6,.35 );


    glColor3ub(83, 112, 46);
    glBegin(GL_POLYGON);
    glVertex2f(-.8,0);
    glVertex2f(-1,0);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,0);
    glVertex2f(.4,0);
    glVertex2f(-.3,.35);
    glEnd();

}


void keyboardHandle(unsigned char key, int x, int y)
{

    switch (key)
    {




    case 'n':
        night=true;
        break;
    case 'N':
        night=false;
        break;

    case 'r':
        vrain=true;
        break;

    case 'R':
        vrain = false;
        break;

    case 'e':
        exit(0);
        break;
    }
}





void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    if(night)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        nightsky();


    }
    else
    {
        glClearColor(0.53f,0.81f,0.92f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        daysky();


        cloud1();
        cloud2();




    }
    backGround();
    glPushMatrix();
    glTranslated(-.1,0,0);


    if(!night && !vrain)
    {


        glPopMatrix();
        glPopMatrix();
    }


    glPushMatrix();
    glScaled(1.3,1.7,1);
    glTranslated(.2,0,0);

    glPopMatrix();




    glPushMatrix();
    glPopMatrix();
    glPushMatrix();
    if(vrain)
    {

    }
    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);


    cout<<"\n Press 'n' for Night mood.\n";
    cout<<"\n Press 'Shift n' for Day mood.\n";
    cout<<"\n Press 'r' for start the rain.\n";
    cout<<"\n Press 'Shift r' for stop the rain.\n";

    cout<<"\n Press 'e' for exit.\n";

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1920, 900);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Train");
    glutDisplayFunc(display);
    glutTimerFunc(40,cloudAnimation1,0);
    glutTimerFunc(40,cloudAnimation2,0);

    glutKeyboardFunc(keyboardHandle);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}
