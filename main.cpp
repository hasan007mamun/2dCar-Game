#include<windows.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include<math.h>
#define pi (2*acos(0.0))
//font declaring
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_8_BY_13;

//for game speed
int fps = 50;

//Score board variables
int start=0;
int gv=0;

//Track Score
int score = 0;

//Form move track
int roadTopMost = 0;
int roadTop = 0;
int roadMdl = 0;
int roadBtm = 0;

//variables for all the cars
int lrIndex = 0 ;
int car1 = 0;
int lrIndex1=0;
int car2 = +35;
int lrIndex2=0;
int car3 = +70;
int lrIndex3=0;

void string_printing(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void drawCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }
	glEnd();
}
void cloud()
{

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
       glPushMatrix();
       glTranslatef(-10,0,0);
       drawCircle(10,10);
       glPopMatrix();

       glPushMatrix();
       drawCircle(10,10);
       glPopMatrix();

       glPushMatrix();
       glTranslatef(10,0,0);
       drawCircle(10,10);
       glPopMatrix();
    glPopMatrix();
}
void game_S(){
    //Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();

    //Road Left Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(23,100);
    glVertex2f(23,0);
    glEnd();

    //Road Right Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(77,0);
    glVertex2f(77,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();

    //Road Middle Border
    //TOP
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48,roadTop+80);
    glVertex2f(48,roadTop+100);
    glVertex2f(52,roadTop+100);
    glVertex2f(52,roadTop+80);
    glEnd();
    roadTop--;
    if(roadTop<-100){
        roadTop =20;
        score++;
    }

    //Middle
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48,roadMdl+40);
    glVertex2f(48,roadMdl+60);
    glVertex2f(52,roadMdl+60);
    glVertex2f(52,roadMdl+40);
    glEnd();



    roadMdl--;
    if(roadMdl<-60){
        roadMdl =60;
        score++;
    }

    //Bottom
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48,roadBtm+0);
    glVertex2f(48,roadBtm+20);
    glVertex2f(52,roadBtm+20);
    glVertex2f(52,roadBtm+0);
    glEnd();
    roadBtm--;
    if(roadBtm<-20){
        roadBtm=100;
        score++;
    }

    //Score Card
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(80,97);
    glVertex2f(90,97);
    glVertex2f(90,94);
    glVertex2f(80,94);
    glEnd();

    //Print Score
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3f(0.000, 1.000, 0.000);
    string_printing(80.5,95,(void *)font3,buffer);

    //My car
    //Front wheel
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+26-2,5);
    glVertex2f(lrIndex+26-2,7);
    glVertex2f(lrIndex+30+2,7);
    glVertex2f(lrIndex+30+2,5);
    glEnd();

    //Back wheel
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+26-2,1);
    glVertex2f(lrIndex+26-2,3);
    glVertex2f(lrIndex+30+2,3);
    glVertex2f(lrIndex+30+2,1);
    glEnd();

    //my Car Body
    glColor3f(0.498, 0.0,1);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+26,1);
    glVertex2f(lrIndex+26,8);
    glColor3f(0.555, 0.545, 0.545);
    glVertex2f(lrIndex+28,10);
    glVertex2f(lrIndex+30,8);
    glVertex2f(lrIndex+30,1);
    glEnd();

    //Opposite end car 1
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+26-2,car1+100-4);
    glVertex2f(lrIndex1+26-2,car1+100-6);
    glVertex2f(lrIndex1+30+2,car1+100-6);
    glVertex2f(lrIndex1+30+2,car1+100-4);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+26-2,car1+100);
    glVertex2f(lrIndex1+26-2,car1+100-2);
    glVertex2f(lrIndex1+30+2,car1+100-2);
    glVertex2f(lrIndex1+30+2,car1+100);
    glEnd();
    glColor3f(1.000, 0.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+26,car1+100);
    glVertex2f(lrIndex1+26,car1+100-7);
    glVertex2f(lrIndex1+28,car1+100-9);
    glVertex2f(lrIndex1+30,car1+100-7);
    glVertex2f(lrIndex1+30,car1+100);
    glEnd();
    car1--;
    if(car1<-100){
        car1=0;
        lrIndex1=lrIndex;
    }
   //game over
    if((abs(lrIndex-lrIndex1)<8) && (car1+100<10)){
            start = 0;
            gv=1;

    }
    //Opposite end car 2
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+26-2,car2+100-4);
    glVertex2f(lrIndex2+26-2,car2+100-6);
    glVertex2f(lrIndex2+30+2,car2+100-6);
    glVertex2f(lrIndex2+30+2,car2+100-4);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+26-2,car2+100);
    glVertex2f(lrIndex2+26-2,car2+100-2);
    glVertex2f(lrIndex2+30+2,car2+100-2);
    glVertex2f(lrIndex2+30+2,car2+100);
    glEnd();
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+26,car2+100);
    glVertex2f(lrIndex2+26,car2+100-7);
    glVertex2f(lrIndex2+28,car2+100-9);
    glVertex2f(lrIndex2+30,car2+100-7);
    glVertex2f(lrIndex2+30,car2+100);
    glEnd();
    car2--;
    if(car2<-100){
        car2=0;
        lrIndex2=lrIndex;
    }

    if((abs(lrIndex-lrIndex2)<8) && (car2+100<10)){
            start = 0;
            gv=1;
    }

    //Opposite end car 3
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+26-2,car3+100-4);
    glVertex2f(lrIndex3+26-2,car3+100-6);
    glVertex2f(lrIndex3+30+2,car3+100-6);
    glVertex2f(lrIndex3+30+2,car3+100-4);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+26-2,car3+100);
    glVertex2f(lrIndex3+26-2,car3+100-2);
    glVertex2f(lrIndex3+30+2,car3+100-2);
    glVertex2f(lrIndex3+30+2,car3+100);
    glEnd();
    glColor3f(0.23,0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+26,car3+100);
    glVertex2f(lrIndex3+26,car3+100-7);
    glVertex2f(lrIndex3+28,car3+100-9);
    glVertex2f(lrIndex3+30,car3+100-7);
    glVertex2f(lrIndex3+30,car3+100);
    glEnd();
    car3--;
    if(car3<-100){
        car3=0;
        lrIndex3=lrIndex;
    }
    //game over
    if((abs(lrIndex-lrIndex3)<8) && (car3+100<10)){
            start = 0;
            gv=1;
    }

}

void home_p()
{
    //field
    glColor3f(0.5, 0.9, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0,55);
    glVertex2f(100,55);
    glColor3f(0, 0.3, 0);
    glVertex2f(100,50-50);
    glVertex2f(0,50-50);
    glEnd();

    //Sky
    glColor3f(0.000, 0.989, 0.888);
    glBegin(GL_POLYGON);
    glVertex2f(100,100);
    glVertex2f(0,100);
    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(0,55);
    glVertex2f(100,55);
    glEnd();

    //cloud
    glPushMatrix();
       glPushMatrix();
        glTranslatef(-5,90,0);
        cloud();
       glPopMatrix();
       glPushMatrix();
        glTranslatef(-10,80,0);
        cloud();
       glPopMatrix();
       glPushMatrix();
        glTranslatef(50,90,0);
        cloud();
       glPopMatrix();
    glPopMatrix();

   // sun
      glPushMatrix();
       glColor3f(1.0f, 1.0f, 0.0f);
       glTranslatef(80,100,0);
       drawCircle(10,10);
      glPopMatrix();

    //Hill 1
    glColor3f(0.000, 0.6, 0.000);
    glBegin(GL_TRIANGLES);
    glVertex2f(15,70);
    glVertex2f(27,55);
    glVertex2f(0,55);
    glEnd();

    //Hill 2
    glColor3f(0.2, 0.7, 0.4);

    glBegin(GL_TRIANGLES);
    glVertex2f(30,80);
    glVertex2f(50,55);
    glVertex2f(10,55);
    glEnd();

    //Hill 4
    glColor3f(0.2, 0.7, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2f(87,75);
    glVertex2f(100,55);
    glVertex2f(60,55);
    glEnd();

    //Hill 3
    glColor3f(0, 0.6, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(70,80);
    glVertex2f(90,55);
    glVertex2f(50,55);
    glEnd();

    if(gv==1){
            glColor3f(0,0,0);
            string_printing(43,28,(void *)font1,"GAME OVER");
            glColor3f(0,0,0);
            char buffer2 [50];
            sprintf (buffer2, "Your Score : %d", score);
            string_printing(43,24,(void *)font1,buffer2);
        }

    glColor3f(1.0f, 0.0f, 0.89f);
    string_printing(43,59,(void *)font1,"2D Car Game");

    glColor3f(0.12,0.0,0.87);
    string_printing(38,49,(void *)font2,"Press SPACE - START RACE");
    string_printing(38,46,(void *)font2,"Press ESC      - QUIT GAME");

    glColor3f(0.453, 0,0.561);
    string_printing(38,43,(void *)font2,"Press RIGHT  - Move Right");
    string_printing(38,40,(void *)font2,"Press LEFT     - Move Left");
    string_printing(38,37,(void *)font2,"Press UP         - Speed UP");
    string_printing(38,34,(void *)font2,"Press DOWN  - Speed Down");

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(start==1)
    {
      glClearColor(0, 0.3, 0,3);
        game_S();
    }

    else
    {
        home_p();

    }

    glFlush();
    glutSwapBuffers();
}


//this is for speeding up and movement .
void specialkeys(int key, int x, int y){
        switch (key) {
        case GLUT_KEY_LEFT:
            if(lrIndex>=0){
                lrIndex = lrIndex - (fps/10);
                if(lrIndex<0){
                    lrIndex=-1;
                }
            }
            break;

        case GLUT_KEY_RIGHT:
            if(lrIndex<=40){
                lrIndex = lrIndex + (fps/10);
                if(lrIndex>40){
                    lrIndex = 45;
                }
            }
            break;

        case GLUT_KEY_DOWN:
            fps-=2;
            break;
        case GLUT_KEY_UP:
            fps+=2;
            break;

        default:
                break;
        }

}

//for refreshing the game window after one game
void keylistener(unsigned char key, int x, int y) {

      switch (key)
            {
                case ' ':
            if(start==0){
                start = 1;
                gv = 0;
                fps = 50;
                roadTopMost = 0;
                roadTop = 0;
                roadMdl = 0;
                roadBtm = 0;
                lrIndex = 0 ;
                car1 = 0;
                lrIndex1=0;
                car2 = +35;
                lrIndex2=0;
                car3 = +70;
                lrIndex3=0;
                score=0;

            }
             break;

             case 27:
                 exit(0);
             break;
             default:
                break;
        }
}

//this timer is set for counting the score
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/fps,timer,0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Car-Game");

    glutDisplayFunc(display);
    glutSpecialFunc(specialkeys);
    glutKeyboardFunc(keylistener);

    glOrtho(0,100,0,100,-1,1);
    glClearColor(0.1, 0.3, 0.3,1);

    glutTimerFunc(1000,timer,0);
    glutMainLoop();

    return 0;
}
