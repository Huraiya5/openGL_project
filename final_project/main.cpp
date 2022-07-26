#include<windows.h>
#include<GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#include <iostream>
#define PI 3.1416
#include <MMSystem.h>
using namespace std;


float rain_position2=0.0f;
float rain_speed2=-0.02f;
float basketX=0;
float basketY=-0.8;
int rand(),r;
float angle=90;

void egg()
{
     float x=0.04f,y=0.06f;
	 float angle;
	//glMatrixMode(GL_MODELVIEW);
	glBegin(GL_POLYGON);

		for(int i = 0; i <=100; i++)
		{
			angle = 2 * PI * i /100;
			glVertex2f (cos(angle)*x , sin(angle)*y+0.3);
		}
    glEnd();

}
void busket()
{

    glColor3ub(0,245,0);
    glutWireCone(0.1,0.2,20,20);
}

void display() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


   glPushMatrix();
   glTranslatef(basketX,basketY, 0.0f);
   glRotated(angle,1,0,1);
    busket();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(rain_position2,0, 0.0f);


    egg();


    glPopMatrix();
    glFlush();
glutSwapBuffers();
angle+=0.6;

    }
  void rain_update2(int value) {

    if(rain_position2 <-1.5f)

       rain_position2= 1.0f;


        rain_position2 +=rain_speed2;


	glutPostRedisplay();

	glutTimerFunc(100, rain_update2, 0);
}

 void skeys(int key,int x, int y)
    {
        if(key==GLUT_KEY_LEFT)

           basketX-=0.02f;
            if(key==GLUT_KEY_RIGHT)
           basketX+=0.02f;
    }



  int main(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(1000, 800);
        glutCreateWindow("AIUB");
        glutDisplayFunc(display);

        glutTimerFunc(100,rain_update2,0);

         glutSpecialFunc(skeys);
         sndPlaySound("f.wav",SND_ASYNC);
        glutMainLoop();
        return 0;
        }
