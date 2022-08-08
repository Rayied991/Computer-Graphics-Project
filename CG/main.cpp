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
    for(i=0;i<100;i++)
	{
        angle = i*2*(M_PI/100);
        glVertex2f(x+(sin(angle)*radius),y+(cos(angle)*radius));
    }
    glEnd();
  }
////sun


//sun movement


void sun()
{
    int i;

    GLfloat x= 0.23f; GLfloat y=0.23f; GLfloat radius =0.4f;
    int triangleAmount = 55;
   glColor3ub(243, 249, 57);
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

}

void moon()
{
    int i;
    GLfloat x= 0.3f;
    GLfloat y= 0.5f;
    GLfloat radius= 0.17f;
    int triangleAmount = 55;
   glColor3ub(243, 241, 230 );
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

}

void stars()
{

    glPointSize(3.7);
    glBegin(GL_POINTS);
    glVertex2f(.45f,.3f);
    glVertex2f(.66f,.9f);
    glVertex2f(.79f,.8f);
    glVertex2f(.45f,.7f);
    glVertex2f(.77f,.6f);
    glVertex2f(.67f,.8f);
    glVertex2f(.56f,.9f);
    glVertex2f(.7f,.6f);

    glVertex2f(-.4f,.8f);
    glVertex2f(-.5f,.6f);
    glVertex2f(-.3f,.5f);
    glVertex2f(-.2f,.8f);
    glVertex2f(-.4f,.8f);
    glVertex2f(-.7f,.5f);
    glVertex2f(-.6f,.7f);
    glVertex2f(-.2f,.8f);

    glVertex2f(-.1f,.9f);
    glVertex2f(-.3f,.85f);
    glVertex2f(-.72f,.92f);
    glVertex2f(-.8f,.84f);

    glVertex2f(-.9f,.84f);
    glVertex2f(-.6f,.94f);
    glVertex2f(-.9f,.2f);

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

sun();

   glFlush();
}
void myDisplay2(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   nightsky();
   moon();
stars();
   glFlush();
}
void backGround()
{


    glColor3ub(4,88,50);
    triangle( .2,-.1,1,-.1 ,.6,.35 );


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

//TrainLine

void trainLine()
{
    glPushMatrix();
    glTranslated(0,0.455, 0);
    glPushMatrix();
    glScaled(1,10,1);
    glTranslated(0, 0.448, 0);
    glColor3ub(128, 116, 120);
    quad( -1,-.5,-1,-.488,1,-.488,1,-.5);
    glPopMatrix();
    glColor3ub(82, 55, 48);
    quad( -1, -0.5, -1, 0.488, 1, -0.488, 1, -0.5);
    glPushMatrix();
    glTranslated(0, .06, 0);
    quad( -1,-.488,-1,-.5,1,-.5,1,-.488);
    glPopMatrix();

    glPopMatrix();
}

void keyboardHandle(unsigned char key, int x, int y)
{

   switch (key) {



        case 'n':
            night=true;
            break;
        case 'N':
            night=false;
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
        moon();
        stars();

    }
    else
    {
        glClearColor(0.53f,0.81f,0.92f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        daysky();
sun();


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

int main(int argc, char** argv) {
//   glutInit(&argc, argv);


	cout<<"\n Press 'n' for Night mood.\n";
	cout<<"\n Press 'Shift n' for Day mood.\n";

	cout<<"\n Press 'e' for exit.\n";
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1800, 900);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Carnival");
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboardHandle);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
   return 0;
}
