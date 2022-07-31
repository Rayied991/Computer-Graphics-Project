//new branch created"Angela"
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
//bool vrain=false;
//char carnival[]="TRAIN STATION";

//float anglel_M = 0.0f;
//float anglel_N = 0.0f;
//GLfloat speed_M= 0.0f;
//GLfloat speed_N = 0.0f;

//GLfloat trainSpeed=0.02f;
//GLfloat trainPos = 0.0f;
/*
GLfloat rainSpeed=0.08f;
GLfloat rainPos = 0.1f;
GLfloat rainSpeedX=0.00f;
GLfloat rainPosX = 0.0f;
*/
/*
GLfloat positionOfCloud1 = 0.0f;
GLfloat speedOfCloud1 = 0.001f;
GLfloat positionOfCloud2 = 0.0f;
GLfloat speedOfCloud2 = 0.002f;
*/
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
/*
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
*/
/*
void cloudAnimation1(int value)
{
    if(positionOfCloud1 < -1.7f)
        positionOfCloud1 = 0.6f;

    positionOfCloud1 -= speedOfCloud1;
    glutPostRedisplay();
    glutTimerFunc(40, cloudAnimation1, 0);
}
void cloudAnimation2(int value)
{
    if(positionOfCloud2 < -0.6f)
        positionOfCloud2 = 1.6f;

    positionOfCloud2 -= speedOfCloud2;
    glutPostRedisplay();
    glutTimerFunc(40, cloudAnimation2, 0);

}
*/
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
    glColor3f(0.0f, 0.0f, 0.0f);
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
       //sun();
	  //cloud1();
   //cloud2();
  // bird();
   glFlush();
}
void myDisplay2(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   nightsky();
    //stars();
   //moon();
   glFlush();
}
void backGround()
{
    //---------------------------------------------SKY
   /* if(!  night){glColor3ub(100, 160, 210);}
    else{ glColor3ub(13, 42, 67);}*/
    //quad( -1,-1,1,-1 ,1,1 ,-1,1 );

    //----------------------------------green ->back
    glColor3ub(4,88,50);
    triangle( .2,-.1,1,-.1 ,.6,.35 );

    //----------------------------------green ->front
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


void trainLine()
{
    glPushMatrix();
    glTranslated(0,-.455,0);
        glPushMatrix();
            glScaled(1,10,1);
            glTranslated(0,.448,0);
            glColor3ub(128,116,120);
            quad( -1,-.5,-1,-.488,1,-.488,1,-.5);
        glPopMatrix();
    glColor3ub(82,55,48);
    quad( -1,-.5,-1,-.488,1,-.488,1,-.5);
        glPushMatrix();
            glTranslated(0,.06,0);
            quad( -1,-.488,-1,-.5,1,-.5,1,-.488);
        glPopMatrix();

        //quad(-.99,-.48,-.99,);

    glPopMatrix();

}
void keyboardHandle(unsigned char key, int x, int y)
{

   switch (key) {
     /* case 'm':
        anglel_M += speed_M;
        speed_M+=0.75;
        //update(0);
        break;
      case 'M':
        speed_M=0.0;
        break;
      case 'b':
        speed_N+=0.4;
        update(0);
        break;
      case 'B':
          speed_N = 0.0;
          break;
          //Train Start
        case 'w':
          trainPos-=trainSpeed;
          update(0);
          break;
        case 's':
          trainPos+=trainSpeed;
          update(0);
          break;
*/

        case 'n':
            night=true;
            break;
        case 'N':
            night=false;
            break;
            /*
        case 'r':
            vrain=true;

            break;
        case 'R':
            vrain=false;
            break;
*/

        case 'e':
         exit(0);
         break;
   }
}
void bogy()
{

    glPushMatrix();

    //body=====================
    glBegin(GL_POLYGON);
    glColor3ub(128,15,46);
    glVertex2f(.0f,.1f);
    glVertex2f(.02f,.12f);
    glVertex2f(.02f,.32f);
    glVertex2f(-.38f,.32f);
    glVertex2f(-.4f,.3f);
    glVertex2f(0.0f,0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153,170,177);
    glVertex2f(-.4f,.3f);
    glVertex2f(-.4f,.1f);
    glVertex2f(.0f,.1f);
    glVertex2f(.0f,.3f);
    glEnd();

    //window==================
    glBegin(GL_QUADS);
    if(night)
    {
       glColor3ub(247, 240, 188);
    }
    else
    {
        glColor3ub(37,47,53);
    }
    glVertex2f(-.35f,.23f);
    glVertex2f(-.35f,.18f);
    glVertex2f(-.3f,.18f);
    glVertex2f(-0.3f,.23f);
    glEnd();

    //
    glPushMatrix();
        glTranslated(.07,0,0);
        glBegin(GL_QUADS);
        //glColor3ub(200,255,255);
        glVertex2f(-.35f,.23f);
        glVertex2f(-.35f,.18f);
        glVertex2f(-.3f,.18f);
        glVertex2f(-0.3f,.23f);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(.14,0,0);
        glBegin(GL_QUADS);
        //glColor3ub(200,255,255);
        glVertex2f(-.35f,.23f);
        glVertex2f(-.35f,.18f);
        glVertex2f(-.3f,.18f);
        glVertex2f(-0.3f,.23f);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(.21,0,0);
        glBegin(GL_QUADS);
        //glColor3ub(200,255,255);
        glVertex2f(-.35f,.23f);
        glVertex2f(-.35f,.18f);
        glVertex2f(-.3f,.18f);
        glVertex2f(-0.3f,.23f);
        glEnd();
    glPopMatrix();

        glPushMatrix();
        glColor3ub(128,15,46);
            glTranslated(0,-.1,0);
            glScalef(.4f,.4f,0.0f);
            circle(-.7,.5,.1);
            glTranslated(0.4f,0.0f,0.0f);
            circle(-.7,.5,.1);
        glPopMatrix();
    glPopMatrix();

}
/*
void item()
{
glPushMatrix();
//BOAT
glTranslatef(-0.4363f,0.0185f, 0.0f);
glRotatef(anglel_N, 1.0, 0.0, 1.0);
//Main Boat
glColor3ub(255, 87, 34);
triangle(-0.0816,0.0214,-0.1293,0.034,-0.0816,-0.0123);
quad(-0.0816,0.0086,-0.0816,-0.0123,0.0772,-0.0123,0.0772,0.0086);
triangle(0.0772,-0.0123,0.1255,0.034,0.0772,0.0233);
quad(0.053,0.0248,0.0271,0.0248,0.0271,0.0086,0.053,0.0086);
quad(-0.0255,0.0248,-0.0508,0.0248,-0.0508,0.0086,-0.0255,0.0086);
triangle(0,0.043,-0.0093,0.0086,0.009,0.0086);
//BARS
glColor3ub(62, 39, 35);
triangle(0,0.1919,-0.0402,0.0248,-0.0304,0.0248);
triangle(0,0.1919,0.0351,0.0248,0.0447,0.0248);
glPopMatrix();

glColor3ub(121, 125, 127);
triangle(-0.4348,0.2,-0.5555,-0.018,-0.54,-0.018);
triangle(-0.4348,0.2,-0.3278,-0.018,-0.3123,-0.018);

glPushMatrix();
glColor3ub(216, 67, 21);
glTranslatef(-0.4348f,0.18, 0.0f);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
    float pi=3.1416;
    float A=(i*2*pi)/50 ;
    float r=0.03;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x,y );
}
glEnd();
glPopMatrix();

*/
/*
void completeTrain()
{
    glPushMatrix();

      glTranslated(trainPos,-1,0);
        bogy();

      glPushMatrix();
        glTranslated(.45,0,0);
        bogy();
      glPopMatrix();

      glPushMatrix();
        glTranslated(.9,0,0);
        bogy();
      glPopMatrix();

            glTranslated(0,.14,0);
            glBegin(GL_QUADS);
            glColor3ub(37,47,53);
            glVertex2f(-.35f,.25f);
            glVertex2f(-.35f,.18f);
            glVertex2f(-.3f,.18f);
            glVertex2f(-0.3f,.25f);
            glEnd();
        glPopMatrix();

        /*
        glPushMatrix();
            glTranslated(.35,-.05,0);
            glBegin(GL_QUADS);
            glColor3ub(0,0,0);
            glVertex2f(-.35f,.23f);
            glVertex2f(-.35f,.18f);
            glVertex2f(-.3f,.18f);
            glVertex2f(-0.3f,.23f);
            glEnd();
        glPopMatrix();
        */
/*
        glPushMatrix();
            glTranslated(.8,-.05,0);
            glBegin(GL_QUADS);
            glColor3ub(0,0,0);
            glVertex2f(-.35f,.23f);
            glVertex2f(-.35f,.18f);
            glVertex2f(-.3f,.18f);
            glVertex2f(-0.3f,.23f);
            glEnd();
        glPopMatrix();


      glPopMatrix();




    glPopMatrix();

}
*/
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
    if(night)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        nightsky();
        //stars();
        //moon();
    }
    else
    {
        glClearColor(0.53f,0.81f,0.92f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        daysky();
        //sun();
       // cloud1();
        //bird();
       // cloud2();

    }
    backGround();
    glPushMatrix();
        glTranslated(-.1,0,0);
        //tent();



/*
    if(!night && !vrain)
    {


        glPopMatrix();
    glPopMatrix();
    }
*/

    //-------------------------------------------LABU
    glPushMatrix();
        glScaled(1.3,1.7,1);
        glTranslated(.2,0,0);
        //item();

    glPopMatrix();

    //-------------------------------Train
   // trainLine();
    glPushMatrix();
//        completeTrain();
    glPopMatrix();
    glPushMatrix();
    /*
        if(vrain)
        {
            rain();
        }
    glPopMatrix();
    */

   glutSwapBuffers();
   glFlush();
}

int main(int argc, char** argv) {

	cout<<"\n Press 'n' for Night mood.\n";
	cout<<"\n Press 'Shift n' for Day mood.\n";
	cout<<"\n Press 'e' for exit.\n";
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1800, 900);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Sajek");
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboardHandle);

    glutMainLoop();
   return 0;
}
