#include<windows.h>
#include <GL/glut.h>
#include <math.h>
//#include<stdio.h>




float red=0.97,green=0.32,blue=0.27;
float red1=0.21,green1=0.4,blue1=1.0;
float xx=0;
float yy=0;
float mrx=0;
float mry=0;

void keyPressed (unsigned char key, int x, int y) {
    if (key == 'f'){glutFullScreen();}
    if (key == 'q'){exit(0);}
    if (key == 'c'){
        red=0.97;
        green=0.32;
        blue=0.27;
        red1=0.21;
        green1=1.0;
        blue1=1.0;
    }
    if (key == 'r'){
        red=0.97;
        green=0.32;
        blue=0.27;
        red1=0.21;
        green1=0.4;
        blue1=1.0;
    }
    glutPostRedisplay();
}





void init2D(float r, float g, float b)
{
    glClearColor(r,g,b,0.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}

void step(float x,float y,float r,float g,float b){
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2d(x,-y);
    glVertex2d(x,-y-1);
    glVertex2d(-x,-y-1);
    glVertex2d(-x,-y);
    glEnd();
    glFlush();
}




void Flower(float cx, float cy, float r, int num_segments)
{
    float theta = 2 * 3.1415926 / num_segments * 1.0;
    float c = cosf(theta+10);
    float s = sinf(theta+10);
    float t;

    float x = r;
    float y = 0;

    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        glVertex2d(x + cx, y + cy);

        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }
    glEnd();
glFlush();
}


void myMouseFunc(int button, int state, int x, int y)
{
        red=0.97;
        green=0.40;
        blue=0.20;
        red1=0.30;
        green1=0.50;
        blue1=0.60;
}





void DrawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 2 * 3.1415926 / num_segments * 1.0;
    float c = cosf(theta);
    float s = sinf(theta);
    float t;

    float x = r;
    float y = 0;

    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        glVertex2d(x + cx, y + cy);

        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }
    glEnd();
glFlush();
}

void man_in_run(){
    if(mry >= 35){
        mry = 0;
    }

    glPushMatrix();

    glTranslatef(mry,mry,mry);

    glColor3f(1.0,0.0,0.0);
    Flower(-34.0,-40.0,3.0,60);

//nick
 glColor3f(1.0,0.74,0.19);
 glBegin(GL_QUADS);
    glVertex2d(-32.75,-35.0);
    glVertex2d(-33.15,-35.0);
    glVertex2d(-33.15,-37.0);
    glVertex2d(-32.75,-37.0);
    glEnd();
    glFlush();
//head
 glColor3f(1.0,0.74,0.19);
 DrawCircle(-33.15,-35.0,1.3,50);
 glColor3f(0.0,0.0,0.0);
 DrawCircle(-33.0,-35.0,1.3,300);
//body
 glColor3f(0.0,0.0,0.1);
 glBegin(GL_QUADS);
    glVertex2d(-31.75,-37.0);
    glVertex2d(-34.15,-37.0);
    glVertex2d(-34.15,-44.0);
    glVertex2d(-31.75,-44.0);
    glEnd();
    glFlush();
//leg
 glColor3f(0.1,0.0,0.1);
 glBegin(GL_QUADS);
    glVertex2d(-31.75,-44.0);
    glVertex2d(-32.75,-44.0);
    glVertex2d(-32.75,-50.0);
    glVertex2d(-31.75,-50.0);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(-33.15,-44.0);
    glVertex2d(-34.15,-44.0);
    glVertex2d(-34.15,-50.0);
    glVertex2d(-33.15,-50.0);
    glEnd();
    glFlush();
//hand
 glColor3f(0.0,0.0,0.1);
 glBegin(GL_QUADS);
    glVertex2d(-31.75,-37.0);
    glVertex2d(-30.25,-42.0);
    glVertex2d(-30.75,-42.0);
    glVertex2d(-31.75,-38.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(-34.15,-37.0);
    glVertex2d(-35.65,-42.0);
    glVertex2d(-36.15,-42.0);
    glVertex2d(-33.75,-38.5);
    glEnd();
    glFlush();


//footer
 glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(-32.0,-50.0);
    glVertex2d(-32.6,-50.0);
    glVertex2d(-32.6,-50.5);
    glVertex2d(-32.0,-50.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(-33.4,-50.0);
    glVertex2d(-34.0,-50.0);
    glVertex2d(-34.0,-50.5);
    glVertex2d(-33.4,-50.5);
    glEnd();
    glFlush();


    mrx+=.09;
    mry+=.04;


 glPopMatrix();

//bird1
glColor3f(0.0,0.0,0.1);
 glBegin(GL_QUADS);
    glVertex2d(23.0,44.0);
    glVertex2d(20.0,46.0);
    glVertex2d(20.0,46.0);
    glVertex2d(23.0,44.5);
    glEnd();
    glFlush();

 glBegin(GL_QUADS);
    glVertex2d(23.0,44.0);
    glVertex2d(26.0,46.0);
    glVertex2d(26.0,46.0);
    glVertex2d(23.0,44.5);
    glEnd();
    glFlush();
//bird2
 glBegin(GL_QUADS);
    glVertex2d(16.0,44.0);
    glVertex2d(13.0,46.0);
    glVertex2d(13.0,46.0);
    glVertex2d(16.0,44.5);
    glEnd();
    glFlush();

 glBegin(GL_QUADS);
    glVertex2d(16.0,44.0);
    glVertex2d(19.0,46.0);
    glVertex2d(19.0,46.0);
    glVertex2d(16.0,44.5);
    glEnd();
    glFlush();
//bird3
glBegin(GL_QUADS);
    glVertex2d(19.5,41.0);
    glVertex2d(16.5,43.0);
    glVertex2d(16.5,43.0);
    glVertex2d(19.5,41.5);
    glEnd();
    glFlush();

 glBegin(GL_QUADS);
    glVertex2d(19.5,41.0);
    glVertex2d(22.5,43.0);
    glVertex2d(22.5,43.0);
    glVertex2d(19.5,41.5);
    glEnd();
    glFlush();


}

void cloud2(){
    if(yy >= 20){
        yy = -90;
    }
    glPushMatrix();
    glTranslatef(yy,0,0);
     glColor3f(1.0,1.0,1.0);
    DrawCircle(40.5,45.0,2.0,300);
    DrawCircle(38.5,45.0,3.0,300);
    DrawCircle(35.5,45.0,4.0,300);
    DrawCircle(32.5,45.0,3.0,300);
    DrawCircle(30.0,45.0,2.0,300);



    yy+=.03;


 glPopMatrix();


}


void cloud(){
    if(xx >= 95){
        xx = -20;
    }
    glPushMatrix();
    glTranslatef(xx,0,0);
    glColor3f(1.0,1.0,1.0);
    DrawCircle(-40.5,45.0,2.0,300);
    DrawCircle(-38.5,45.0,3.0,300);
    DrawCircle(-35.5,45.0,4.0,300);
    DrawCircle(-32.5,45.0,3.0,300);
    DrawCircle(-30.0,45.0,2.0,300);



    xx+=.04;


 glPopMatrix();
    cloud2();
    man_in_run();
    glutSwapBuffers();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // FOR X,Y CORDINET
    glColor3f(0.0, 0.0, 0.0);

    //background color
    glBegin(GL_QUADS);
    glColor3f(red,green, blue);
    glVertex2d(50.0,0.0);
    glColor3f(red1,green1, blue1);
    glVertex2d(50.0,50.0);
    glVertex2d(-50.0,50.0);
    glVertex2d(-50.0,0.0);
    glEnd();
    glFlush();




    //background color floor
    glBegin(GL_QUADS);
    glColor3f(0.53, 0.44, 0.44);
    glVertex2d(50.0,0.0);
    glColor3f(1.0, 0.68, 0.71);
    glVertex2d(50.0,-50.0);
    glVertex2d(-50.0,-50.0);
    glColor3f(0.53, 0.44, 0.44);
    glVertex2d(-50.0,0.0);
    glEnd();
    glFlush();


    //carpet
    glBegin(GL_QUADS);
    glColor3f(0.63, 0.0, 0.0);
    glVertex2d(-7.0,0.0);
    glVertex2d(-2.0,-50.0);
    glVertex2d(15.0,-50.0);
    glVertex2d(7.0,0.0);
    glEnd();
    glFlush();


    // shohid minal cycle
    glColor3f(1.0,0.0,0.0);
    DrawCircle(0.0,16.0,8.0,300);

    // step background color
    glColor3f(0.65,0.64,0.64);
    glBegin(GL_QUADS);
    glVertex2d(50.0,0.0);
    glVertex2d(50.0,-9.0);
    glVertex2d(-50.0,-9.0);
    glVertex2d(-50.0,0.0);
    glEnd();
    glFlush();

    step(50.0,0.0,0.65,0.04,0.04);
    step(50.0,3.0,0.65,0.04,0.04);
    step(50.0,6.0,0.65,0.04,0.04);

    //Flowers
    glColor3f(1.0,0.0,0.0);
    Flower(-8.0,-3.0,3.0,50);
    glColor3f(0.95,0.27,0.0);
    Flower(0.0,-3.0,3.0,50);

    glColor3f(0.95,0.95,0.01);
    Flower(-4.0,-3.0,3.0,60);
   glColor3f(0.95,0.95,0.01);
    Flower(3.0,-2.0,3.0,50);


 glColor3f(1.0,0.0,0.0);
    Flower(6.0,-3.0,3.0,60);


    // LEFT MID MINAR

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2d(-14.0,0.0);
    glVertex2d(-14.0,22.0);
    glVertex2d(-15.0,22.0);
    glVertex2d(-15.0,0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(-20.0,0.0);
    glVertex2d(-20.0,22.0);
    glVertex2d(-21.0,22.0);
    glVertex2d(-21.0,0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(-21.0,22.0);
    glVertex2d(-21.0,20.0);
    glVertex2d(-14.0,20.0);
    glVertex2d(-14.0,22.0);
    glEnd();
    glFlush();

    glBegin(GL_LINE_LOOP);
    glVertex2d(-16.5,0.0);
    glVertex2d(-16.5,22.0);
    glEnd();
    glFlush();
    glBegin(GL_LINE_LOOP);
    glVertex2d(-18.5,22.0);
    glVertex2d(-18.5,0.0);
    glEnd();
    glFlush();


    // LEFT MINI MINAR

    glBegin(GL_QUADS);
    glVertex2d(-24.0,0.0);
    glVertex2d(-24.0,18.0);
    glVertex2d(-25.0,18.0);
    glVertex2d(-25.0,0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(-30.0,0.0);
    glVertex2d(-30.0,18.0);
    glVertex2d(-31.0,18.0);
    glVertex2d(-31.0,0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(-31.0,18.0);
    glVertex2d(-31.0,16.0);
    glVertex2d(-24.0,16.0);
    glVertex2d(-24.0,18.0);
    glEnd();
    glFlush();




    glBegin(GL_LINE_LOOP);
    glVertex2d(-26.5,0.0);
    glVertex2d(-26.5,17.5);
    glEnd();
    glFlush();
    glBegin(GL_LINE_LOOP);
    glVertex2d(-28.5,17.5);
    glVertex2d(-28.5,0.0);
    glEnd();
    glFlush();



    // MIDE BIG MINAL

    glBegin(GL_QUADS);

    glVertex2d(-7.0,0.0);
    glVertex2d(-7.0,26.0);
    glVertex2d(-6.0,26.0);
    glVertex2d(-6.0,0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(-0.5,0.0);
    glVertex2d(-0.5,26.0);
    glVertex2d(1.0,26.0);
    glVertex2d(1.0,0.0);
    glEnd();
    glFlush();


    glBegin(GL_QUADS);
    glVertex2d(7.0,0.0);
    glVertex2d(7.0,26.0);
    glVertex2d(6.0,26.0);
    glVertex2d(6.0,0.0);
    glEnd();
    glFlush();

   glBegin(GL_LINE_LOOP);
    glVertex2d(-2.5,0.0);
    glVertex2d(-2.5,26.0);
    glEnd();
    glFlush();

   glBegin(GL_LINE_LOOP);
    glVertex2d(3.0,26.0);
    glVertex2d(3.0,0.0);
    glEnd();
    glFlush();

   glBegin(GL_LINE_LOOP);
    glVertex2d(-4.5,0.0);
    glVertex2d(-4.5,26.0);
    glEnd();
    glFlush();

   glBegin(GL_LINE_LOOP);
    glVertex2d(4.5,26.0);
    glVertex2d(4.5,0.0);
    glEnd();
    glFlush();


    // MID MINAR TOP

    glBegin(GL_QUADS);
    glVertex2d(0.0,40.0);
    glVertex2d(0.0,38.0);
    glVertex2d(14.0,38.0);
    glVertex2d(14.0,40.0);
    glEnd();
    glFlush();


    glBegin(GL_QUADS);
    glVertex2d(-7.0,26.0);
    glVertex2d(0.0,40.0);
    glVertex2d(0.0,38.0);
    glVertex2d(-6.0,26.0);
    glEnd();
    glFlush();



    glBegin(GL_QUADS);
    glVertex2d(-0.5,26.0);
    glVertex2d(7.0,40.0);
    glVertex2d(8.0,38.0);
    glVertex2d(1.0,26.0);
    glEnd();
    glFlush();




    glBegin(GL_QUADS);
    glVertex2d(7.0,26.0);
    glVertex2d(14.0,38.0);
    glVertex2d(14.0,40.0);
    glVertex2d(6.0,26.0);
    glEnd();
    glFlush();





   glBegin(GL_LINE_LOOP);
    glVertex2d(-2.5,26.0);
    glVertex2d(5.5,40.0);
    glEnd();
    glFlush();

  glBegin(GL_LINE_LOOP);
    glVertex2d(3.0,26.0);
    glVertex2d(11.0,40.0);
    glEnd();
    glFlush();


   glBegin(GL_LINE_LOOP);
    glVertex2d(-4.5,26.0);
    glVertex2d(3.0,40.0);
    glEnd();
    glFlush();

  glBegin(GL_LINE_LOOP);
    glVertex2d(4.5,26.0);
    glVertex2d(13.0,40.0);
    glEnd();
    glFlush();


    // RIGRHT MID MINAR


    glBegin(GL_QUADS);
    glVertex2d(14.0,0.0);
    glVertex2d(14.0,22.0);
    glVertex2d(15.0,22.0);
    glVertex2d(15.0,0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(20.0,0.0);
    glVertex2d(20.0,22.0);
    glVertex2d(21.0,22.0);
    glVertex2d(21.0,0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(21.0,22.0);
    glVertex2d(21.0,20.0);
    glVertex2d(14.0,20.0);
    glVertex2d(14.0,22.0);
    glEnd();
    glFlush();



    glBegin(GL_LINE_LOOP);
    glVertex2d(16.5,0.0);
    glVertex2d(16.5,22.0);
    glEnd();
    glFlush();
    glBegin(GL_LINE_LOOP);
    glVertex2d(18.5,22.0);
    glVertex2d(18.5,0.0);
    glEnd();
    glFlush();



    // RIGRHT MINI MINAR

    glBegin(GL_QUADS);
    glVertex2d(24.0,0.0);
    glVertex2d(24.0,18.0);
    glVertex2d(25.0,18.0);
    glVertex2d(25.0,0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(30.0,0.0);
    glVertex2d(30.0,18.0);
    glVertex2d(31.0,18.0);
    glVertex2d(31.0,0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex2d(31.0,18.0);
    glVertex2d(31.0,16.0);
    glVertex2d(24.0,16.0);
    glVertex2d(24.0,18.0);
    glEnd();
    glFlush();


    glBegin(GL_LINE_LOOP);
    glVertex2d(26.5,0.0);
    glVertex2d(26.5,17.5);
    glEnd();
    glFlush();
    glBegin(GL_LINE_LOOP);
    glVertex2d(28.5,17.5);
    glVertex2d(28.5,0.0);
    glEnd();
    glFlush();



///left



//left_people2

//nick
glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(-27.5,-15.0);
    glVertex2d(-27.90,-15.0);
    glVertex2d(-27.90,-16.0);
    glVertex2d(-27.5,-16.0);
    glEnd();
    glFlush();
//head
 glColor3f(0.0, 0.0, 0.0);
 DrawCircle(-27.75,-13.5,1.5,300);
//body
glColor3f(1.0, 0.31, 0.04);
 glBegin(GL_QUADS);
    glVertex2d(-26.5,-16.0);
    glVertex2d(-28.90,-16.0);
    glVertex2d(-28.90,-23.0);
    glVertex2d(-26.5,-23.0);
    glEnd();
    glFlush();
//leg
glColor3f(0.0, 0.1, 0.4);
 glBegin(GL_QUADS);
    glVertex2d(-26.5,-23.0);
    glVertex2d(-27.5,-23.0);
    glVertex2d(-27.5,-28.0);
    glVertex2d(-26.5,-28.0);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(-27.90,-23.0);
    glVertex2d(-28.90,-23.0);
    glVertex2d(-28.90,-28.0);
    glVertex2d(-27.90,-28.0);
    glEnd();
    glFlush();
//hand
glColor3f(1.0, 0.31, 0.04);
 glBegin(GL_QUADS);
    glVertex2d(-26.5,-16.0);
    glVertex2d(-25.0,-21.0);
    glVertex2d(-25.5,-21.0);
    glVertex2d(-26.5,-17.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(-28.90,-16.0);
    glVertex2d(-30.4,-21.0);
    glVertex2d(-30.90,-21.0);
    glVertex2d(-28.5,-17.5);
    glEnd();
    glFlush();
// footer
glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(-26.7,-28.0);
    glVertex2d(-27.3,-28.0);
    glVertex2d(-27.3,-28.5);
    glVertex2d(-26.7,-28.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(-28.10,-28.0);
    glVertex2d(-28.70,-28.0);
    glVertex2d(-28.70,-28.5);
    glVertex2d(-28.10,-28.5);
    glEnd();
    glFlush();


//left_people1
//head
glColor3f(0.0, 0.0, 0.0);
 DrawCircle(-30.75,-16.0,1.6,300);
 glColor3f(1.0, 0.74, 0.19);
 DrawCircle(-30.75,-16.0,1.3,300);

 glColor3f(0.0, 0.0, 0.0);
 DrawCircle(-31.4,-16.0,0.2,300);
 DrawCircle(-30.4,-16.0,0.2,300);
 DrawCircle(-30.95,-16.5,0.2,300);

 glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(-30.5,-17.0);
    glVertex2d(-30.90,-17.0);
    glVertex2d(-30.90,-18.0);
    glVertex2d(-30.5,-18.0);
    glEnd();
    glFlush();
//body
glColor3f(0.0, 0.0, 1.0);
 glBegin(GL_QUADS);
    glVertex2d(-29.5,-18.0);
    glVertex2d(-31.90,-18.0);
    glVertex2d(-31.90,-25.0);
    glVertex2d(-29.5,-25.0);
    glEnd();
    glFlush();
//leg
glColor3f(1.0, 1.0, 1.0);
 glBegin(GL_QUADS);
    glVertex2d(-29.5,-25.0);
    glVertex2d(-30.5,-25.0);
    glVertex2d(-30.5,-30.0);
    glVertex2d(-29.5,-30.0);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(-30.90,-25.0);
    glVertex2d(-31.90,-25.0);
    glVertex2d(-31.90,-30.0);
    glVertex2d(-30.90,-30.0);
    glEnd();
    glFlush();
//hand
glColor3f(0.0, 0.0, 1.0);
 glBegin(GL_QUADS);
    glVertex2d(-29.5,-18.0);
    glVertex2d(-28.0,-23.0);
    glVertex2d(-28.5,-23.0);
    glVertex2d(-29.5,-19.5);
    glEnd();
    glFlush();

 glBegin(GL_QUADS);
    glVertex2d(-31.90,-18.0);
    glVertex2d(-33.4,-23.0);
    glVertex2d(-33.90,-23.0);
    glVertex2d(-31.5,-19.5);
    glEnd();
    glFlush();
// footer
glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(-29.70,-30.0);
    glVertex2d(-30.30,-30.0);
    glVertex2d(-30.30,-30.5);
    glVertex2d(-29.70,-30.5);
    glEnd();
    glFlush();

//left_people3

//nick
glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(7.5,-11.5);
    glVertex2d(7.90,-11.5);
    glVertex2d(7.90,-13.0);
    glVertex2d(7.75,-13.0);
    glEnd();
    glFlush();

//head
glColor3f(0.0, 0.0, 0.0);
 DrawCircle(7.75,-10.5,1.5,300);

//body
glColor3f(0.45, 0.06, 0.43);
 glBegin(GL_QUADS);
    glVertex2d(9.0,-13.0);
    glVertex2d(6.5,-13.0);
    glVertex2d(6.5,-20.0);
    glVertex2d(9.0,-20.0);
    glEnd();
    glFlush();
//leg
glColor3f(0.45, 0.37, 0.44);
 glBegin(GL_QUADS);
    glVertex2d(6.5,-20.0);
    glVertex2d(7.5,-20.0);
    glVertex2d(7.5,-25.0);
    glVertex2d(6.5,-25.0);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(7.90,-20.0);
    glVertex2d(8.90,-20.0);
    glVertex2d(8.90,-25.0);
    glVertex2d(7.90,-25.0);
    glEnd();
    glFlush();

//footer
glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(6.70,-25.0);
    glVertex2d(7.30,-25.0);
    glVertex2d(7.30,-25.5);
    glVertex2d(6.70,-25.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(8.10,-25.0);
    glVertex2d(8.70,-25.0);
    glVertex2d(8.70,-25.5);
    glVertex2d(8.10,-25.5);
    glEnd();
    glFlush();





//hand
glColor3f(0.45, 0.06, 0.43);
 glBegin(GL_QUADS);
    glVertex2d(6.5,-13.0);
    glVertex2d(5.0,-18.0);
    glVertex2d(5.5,-18.0);
    glVertex2d(6.5,-14.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(8.90,-13.0);
    glVertex2d(10.4,-18.0);
    glVertex2d(10.90,-18.0);
    glVertex2d(8.5,-14.5);
    glEnd();
    glFlush();



    //shopbackground
    glColor3f(0.7,0.97,0.7);
    glBegin(GL_QUADS);
    glVertex2d(-50.0,-28.0);
    glVertex2d(-33.0,-28.0);
    glVertex2d(-33.0,-50.0);
    glVertex2d(-50.0,-50.0);
    glEnd();
    glFlush();

    //shoproof
    glColor3f(0.26,0.09,0.0);
    glBegin(GL_QUADS);
    glVertex2d(-50.0,-20.0);
    glVertex2d(-35.0,-20.0);
    glVertex2d(-31.0,-30.0);
    glVertex2d(-50.0,-30.0);
    glEnd();
    glFlush();

    //shopbody

    glBegin(GL_LINE_LOOP);
    glVertex2d(-33.0,-28.0);
    glVertex2d(-33.0,-49.0);
    glEnd();
    glFlush();





//shopkeeper
//head
 glColor3f(0.0,0.0,0.0);
 DrawCircle(-43.0,-35.0,1.8,50);


 glColor3f(1.0,0.74,0.19);
 DrawCircle(-43.0,-35.0,1.3,300);

 glColor3f(0.0,0.0,0.0);
DrawCircle(-42.5,-34.5,0.2,50);
DrawCircle(-43.5,-34.5,0.2,50);
DrawCircle(-43.0,-35.5,0.2,50);



 glColor3f(1.0,0.74,0.19);
 glBegin(GL_QUADS);
    glVertex2d(-42.75,-36.0);
    glVertex2d(-43.15,-36.0);
    glVertex2d(-43.15,-37.0);
    glVertex2d(-42.75,-37.0);
    glEnd();
    glFlush();


//body
 glColor3f(0.8,0.04,0.75);
 glBegin(GL_QUADS);
    glVertex2d(-41.75,-37.0);
    glVertex2d(-44.15,-37.0);
    glVertex2d(-44.15,-44.0);
    glVertex2d(-41.75,-44.0);
    glEnd();
    glFlush();
//leg
 glBegin(GL_QUADS);
    glVertex2d(-41.75,-44.0);
    glVertex2d(-42.75,-44.0);
    glVertex2d(-42.75,-49.0);
    glVertex2d(-41.75,-49.0);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(-43.15,-44.0);
    glVertex2d(-44.15,-44.0);
    glVertex2d(-44.15,-49.0);
    glVertex2d(-43.15,-49.0);
    glEnd();
    glFlush();
//hand
 glBegin(GL_QUADS);
    glVertex2d(-41.75,-37.0);
    glVertex2d(-40.25,-42.0);
    glVertex2d(-40.75,-42.0);
    glVertex2d(-41.75,-38.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(-44.15,-37.0);
    glVertex2d(-45.65,-42.0);
    glVertex2d(-46.15,-42.0);
    glVertex2d(-43.75,-38.5);
    glEnd();
    glFlush();


    //table
    glColor3f(0.4,0.0,0.0);
 glBegin(GL_QUADS);
    glVertex2d(-33.0,-39.0);
    glVertex2d(-44.0,-42.0);
    glVertex2d(-44.0,-50.0);
    glVertex2d(-33.0,-50.0);
    glEnd();
    glFlush();

    glColor3f(0.78,0.35,0.3);
    glBegin(GL_QUADS);
    glVertex2d(-33.0,-39.0);
    glVertex2d(-44.0,-42.0);
    glVertex2d(-44.0,-45.0);
    glVertex2d(-33.0,-42.0);
    glEnd();
    glFlush();

    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2d(-44.0,-42.0);
    glVertex2d(-50.0,-39.0);
    glVertex2d(-50.0,-50.0);
    glVertex2d(-44.0,-50.0);
    glEnd();
    glFlush();

    glColor3f(0.78,0.35,0.3);
    glBegin(GL_QUADS);
    glVertex2d(-44.0,-42.0);
    glVertex2d(-50.0,-39.0);
    glVertex2d(-50.0,-42.0);
    glVertex2d(-44.0,-45.0);
    glEnd();
    glFlush();

//shopflowers
    glColor3f(1.0,0.0,0.0);
    Flower(-36.0,-40.0,2.5,50);
    glColor3f(0.95,0.95,0.01);
    Flower(-40.0,-41.0,2.5,50);
    glColor3f(0.95,0.27,0.0);
    Flower(-44.0,-43.0,2.5,60);
    glColor3f(1.0,0.0,0.0);
    Flower(-47.0,-41.0,2.5,50);

   //flag


    glColor3f(0.4,0.0,0.0);


    glBegin(GL_QUADS);
    glVertex2d(-37.0,0.0);
    glVertex2d(-43.0,0.0);
    glVertex2d(-43.0,2.0);
    glVertex2d(-37.0,2.0);
    glEnd();
    glFlush();

    //flag leg
    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2d(-39.5,0.0);
    glVertex2d(-40.5,0.0);
    glVertex2d(-40.5,30.0);
    glVertex2d(-39.5,30.0);
    glEnd();
    glFlush();

    //flag head
    glColor3f(0.0,0.5,0.0);
    glBegin(GL_QUADS);
    glVertex2d(-39.5,30.0);
    glVertex2d(-28.5,30.0);
    glVertex2d(-28.5,20.0);
    glVertex2d(-39.5,20.0);
    glEnd();
    glFlush();

    //flag cycle

    glColor3f(1.0,0.0,0.0);
    DrawCircle(-34.5,25.0,2.0,300);


    //tree1

    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2d(35.5,0.0);
    glVertex2d(37.5,0.0);
    glVertex2d(36.5,15.0);
    glVertex2d(36.0,15.0);
    glEnd();
    glFlush();

    //tree1 head
    glColor3f(0.0,0.5,0.0);
    DrawCircle(35.5,15.0,4.0,300);
    DrawCircle(35.5,18.0,4.0,300);
    DrawCircle(36.5,20.0,3.0,300);
    DrawCircle(36.5,22.0,3.0,300);
    DrawCircle(37.5,18.0,4.0,300);
    DrawCircle(37.0,15.0,4.0,300);
    DrawCircle(36.5,12.0,2.0,300);


    //tree2

    glColor3f(0.4,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2d(44.5,0.0);
    glVertex2d(46.5,0.0);
    glVertex2d(45.5,17.0);
    glVertex2d(45.0,17.0);
    glEnd();
    glFlush();

    //tree2head

    glColor3f(0.0,0.5,0.0);
    DrawCircle(44.5,17.0,4.0,300);
    DrawCircle(44.5,21.0,5.0,300);
    DrawCircle(45.5,22.0,4.0,300);
    DrawCircle(45.5,25.0,4.0,300);
    DrawCircle(46.5,20.0,4.0,300);
    DrawCircle(46.0,17.0,4.0,300);
    DrawCircle(45.5,14.5,2.0,300);

    //cloud


    glColor3f(1.0,1.0,1.0);
    DrawCircle(-20.5,30.0,1.8,300);
    DrawCircle(-18.5,30.0,2.5,300);
    DrawCircle(-15.5,30.0,3.5,300);
    DrawCircle(-12.5,30.0,2.5,300);
    DrawCircle(-10.0,30.0,1.8,300);





//right_people2
//head
glColor3f(0.0, 0.0, 0.0);
DrawCircle(38.75,-14.0,1.5,300);

glColor3f(1.0, 0.74, 0.19);
 DrawCircle(38.75,-14.0,1.3,300);

 glColor3f(0.0, 0.0, 0.0);

DrawCircle(38.3,-13.5,0.2,300);
DrawCircle(39.1,-13.5,0.2,300);
DrawCircle(38.7,-14.5,0.2,300);

glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(38.5,-15.0);
    glVertex2d(38.90,-15.0);
    glVertex2d(38.90,-16.0);
    glVertex2d(38.5,-16.0);
    glEnd();
    glFlush();
//body
glColor3f(1.0, 0.04, 0.89);
 glBegin(GL_QUADS);
    glVertex2d(37.5,-16.0);
    glVertex2d(39.90,-16.0);
    glVertex2d(39.90,-23.0);
    glVertex2d(37.5,-23.0);
    glEnd();
    glFlush();
//leg
glColor3f(0.27, 0.25, 0.27);
 glBegin(GL_QUADS);
    glVertex2d(37.5,-23.0);
    glVertex2d(38.5,-23.0);
    glVertex2d(38.5,-28.0);
    glVertex2d(37.5,-28.0);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(38.90,-23.0);
    glVertex2d(39.90,-23.0);
    glVertex2d(39.90,-28.0);
    glVertex2d(38.90,-28.0);
    glEnd();
    glFlush();
//hand
glColor3f(1.0, 0.04, 0.89);
 glBegin(GL_QUADS);
    glVertex2d(37.5,-16.0);
    glVertex2d(36.0,-21.0);
    glVertex2d(36.5,-21.0);
    glVertex2d(37.5,-17.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(39.90,-16.0);
    glVertex2d(41.4,-21.0);
    glVertex2d(41.90,-21.0);
    glVertex2d(39.5,-17.5);
    glEnd();
    glFlush();

//footer

glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(37.70,-28.0);
    glVertex2d(38.30,-28.0);
    glVertex2d(38.30,-28.5);
    glVertex2d(37.70,-28.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(39.10,-28.0);
    glVertex2d(39.70,-28.0);
    glVertex2d(39.70,-28.5);
    glVertex2d(39.10,-28.5);
    glEnd();
    glFlush();

//right_people1
//head
//nick
glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(35.5,-16.0);
    glVertex2d(35.90,-16.0);
    glVertex2d(35.90,-18.0);
    glVertex2d(35.5,-18.0);
    glEnd();
    glFlush();

glColor3f(0.0, 0.0, 0.0);
 DrawCircle(35.75,-16.0,1.5,300);
//body
glColor3f(0.15, 0.29, 0.18);
 glBegin(GL_QUADS);
    glVertex2d(34.5,-18.0);
    glVertex2d(36.90,-18.0);
    glVertex2d(36.90,-25.0);
    glVertex2d(34.5,-25.0);
    glEnd();
    glFlush();
//leg
glColor3f(1.0, 1.0, 1.0);
 glBegin(GL_QUADS);
    glVertex2d(34.5,-25.0);
    glVertex2d(35.5,-25.0);
    glVertex2d(35.5,-30.0);
    glVertex2d(34.5,-30.0);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(35.90,-25.0);
    glVertex2d(36.90,-25.0);
    glVertex2d(36.90,-30.0);
    glVertex2d(35.90,-30.0);
    glEnd();
    glFlush();
//hand
glColor3f(0.15, 0.29, 0.18);
 glBegin(GL_QUADS);
    glVertex2d(34.5,-18.0);
    glVertex2d(33.0,-23.0);
    glVertex2d(33.5,-23.0);
    glVertex2d(34.5,-19.5);
    glEnd();
    glFlush();

 glBegin(GL_QUADS);
    glVertex2d(36.90,-18.0);
    glVertex2d(38.4,-23.0);
    glVertex2d(38.90,-23.0);
    glVertex2d(36.5,-19.5);
    glEnd();
    glFlush();


//footer

glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(34.7,-30.0);
    glVertex2d(35.3,-30.0);
    glVertex2d(35.3,-30.5);
    glVertex2d(34.7,-30.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(36.10,-30.0);
    glVertex2d(36.70,-30.0);
    glVertex2d(36.70,-30.5);
    glVertex2d(35.10,-30.5);
    glEnd();
    glFlush();

//right_people3

//nick
glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(42.5,-17.0);
    glVertex2d(42.90,-17.0);
    glVertex2d(42.90,-19.0);
    glVertex2d(42.5,-19.0);
    glEnd();
    glFlush();
//head
 glColor3f(0.0, 0.0, 0.0);
 DrawCircle(42.75,-17.0,1.5,300);

//body
glColor3f(0.94, 0.03, 0.03);
 glBegin(GL_QUADS);
    glVertex2d(41.5,-19.0);
    glVertex2d(43.90,-19.0);
    glVertex2d(43.90,-26.0);
    glVertex2d(41.5,-26.0);
    glEnd();
    glFlush();
//leg
 glColor3f(0.5, 0.5, 0.5);
 glBegin(GL_QUADS);
    glVertex2d(41.5,-26.0);
    glVertex2d(42.5,-26.0);
    glVertex2d(42.5,-31.0);
    glVertex2d(41.5,-31.0);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(42.90,-26.0);
    glVertex2d(43.90,-26.0);
    glVertex2d(43.90,-31.0);
    glVertex2d(42.90,-31.0);
    glEnd();
    glFlush();
//hand
glColor3f(0.94, 0.03, 0.03);
 glBegin(GL_QUADS);
    glVertex2d(41.5,-19.0);
    glVertex2d(40.0,-24.0);
    glVertex2d(40.5,-24.0);
    glVertex2d(41.5,-20.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(43.90,-19.0);
    glVertex2d(45.4,-24.0);
    glVertex2d(45.90,-24.0);
    glVertex2d(43.5,-20.5);
    glEnd();
    glFlush();

//footer

 glColor3f(1.0, 0.74, 0.19);
 glBegin(GL_QUADS);
    glVertex2d(41.7,-31.0);
    glVertex2d(42.3,-31.0);
    glVertex2d(42.3,-31.5);
    glVertex2d(41.7,-31.5);
    glEnd();
    glFlush();
 glBegin(GL_QUADS);
    glVertex2d(43.10,-31.0);
    glVertex2d(43.70,-31.0);
    glVertex2d(43.70,-31.5);
    glVertex2d(43.10,-31.5);
    glEnd();
    glFlush();



    cloud();



}



int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1200, 680);
    glutInitWindowPosition (90, 20);
    glutCreateWindow ("Morning Scenery of 21 February");
    init2D(1,1,1);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keyPressed);
    glutMouseFunc(myMouseFunc);
    glutMainLoop();
    return 0;
}


