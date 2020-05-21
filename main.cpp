//Simple Program:
#include<stdlib.h>
#include<GL/glut.h>
#include <math.h>

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
char buff[10];
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24
};
int cc=25,cb=65,s=0,speed=30,status=1;
float pointer=25;
typedef struct
{ GLfloat x,y;} Pt;
Pt  q1, q2,q3,q4;
GLfloat colors[][3] = {{0.5,0.5,0.5},{0.5,0.5,0.5},{0.8,0.8,0.8},{0.8,0.8,0.8},{0.8,0.8,0.8},{0.4,0.4,0.4}};
void init()
{
	glClearColor(0.0,0,0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
    glutPostRedisplay();
}

void DrawLine(Pt n1, Pt n2)
     {

        glBegin(GL_LINES);
 for (int i=0;i<3;i++){
       glVertex2f(n1.x+i, n1.y+i);
       glVertex2f(n2.x+i, n2.y+i);
 }
       glEnd();
  //     glFlush();

     }
void point (float x,float y){
   glPointSize(10.0f);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
glEnd();
//glFlush();

}
void rect(Pt n1, Pt n2,Pt n3, Pt n4){
    glBegin(GL_QUADS);        // Draw The Cube Using quads
//    glColor3f(0.0f,1.0f,0.0f);    // Color Blue
    glVertex2f(n1.x, n1.y);
    glVertex2f(n2.x, n2.y);
    glVertex2f(n3.x, n3.y);
    glVertex2f(n4.x, n4.y);
    glEnd();            // End Drawing The Cube
//glFlush();
}

void Circle(float cx, float cy, float r, int num_segments,int h) {
    //glColor3f(0.0,0.0,1.0);
    float xx,yy,n;
    if(h==1)
    glBegin(GL_LINE_LOOP);//  for not filled circle
    else
    glBegin(GL_TRIANGLE_FAN);

    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex

      }
    glEnd();

}
void quad(Pt n1, Pt n2,int i){
    glBegin(GL_QUADS);        // Draw The Cube Using quads
 //   glColor3f(0.0f,1.0f,0.0f);    // Color Blue
    glVertex2f(n1.x-i, n1.y);
    glVertex2f(n1.x+i, n1.y);
    glVertex2f(n2.x+i, n2.y);
    glVertex2f(n2.x-i, n2.y);
    glEnd();            // End Drawing The Cube
//glFlush();
}

void quadd(Pt n1, Pt n2){
    glBegin(GL_QUADS);        // Draw The Cube Using quads
    //glColor3f(0.0f,1.0f,0.0f);    // Color Blue
    glVertex2f(n1.x, n1.y-5);
    glVertex2f(n1.x, n1.y+5);
    glVertex2f(n2.x, n2.y+5);
    glVertex2f(n2.x, n2.y-5);
    glEnd();            // End Drawing The Cube
//glFlush();
}

void rectangle(Pt n1, Pt n2,int i){
	glBegin(GL_QUADS);        // Draw The Cube Using quads
    //glColor3f(0.0f,1.0f,0.0f);    // Color Blue
    glVertex2f(n1.x-i, n1.y);
    glVertex2f(n2.x+i, n1.y);
    glVertex2f(n2.x+i, n2.y);
    glVertex2f(n1.x-i, n2.y);
    glEnd();            // End Drawing The Cube
//glFlush();
}
void outlet(float x,float y){
    glColor3fv(colors[3]);
glBegin(GL_TRIANGLE_FAN);
if(s==1 )
{   if(cc>=75 && cc<100 || cc>=0 && cc<=25)
    glColor3f(0.9,0.96,0.96);

}
if(s==0){
   if(cc>25 && cc<=50){
        float r=(cc-25)*0.006;
        glColor3f(0.9-(r),0.95-(r),0.95-(r));
    }}

        float cx=x+50,cy=y+225,r=32;
    for (int ii = 0; ii < 100; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=25 && ii<=50)
        glVertex2f(x + cx, y + cy);//output vertex

      } r=10;
    for (int ii = 100; ii >=0; ii--)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=25 && ii<=50)
        glVertex2f(x + cx, y + cy);//output vertex

      }
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x+100, y+234);
        glVertex2f(x+100, y+256);
        glVertex2d(x+41, y+256);
        glVertex2f(x+41, y+234);
        glEnd();

}

void outletcover(float x,float y){
glColor3fv(colors[1]);
//glColor3f(0,0,0);
glBegin(GL_TRIANGLE_FAN);

        float cx=x+50,cy=y+225,r=34;
    for (int ii = 0; ii < 100; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=25 && ii<=50)
        glVertex2f(x + cx, y + cy);//output vertex

      } r=8;
    for (int ii = 100; ii >=0; ii--)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=25 && ii<=50)
        glVertex2f(x + cx, y + cy);//output vertex

      }
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x+100, y+232);
        glVertex2f(x+100, y+259);
        glVertex2d(x+42, y+259);
        glVertex2f(x+42, y+232);
        glEnd();

}
void Crank(float cx, float cy, float r, int num_segments) {
    glColor3f(0.0,0.0,1.0);
    float xx,yy,n;
    glBegin(GL_LINE_LOOP);//  for not filled circle
    //glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
      if(ii==cc){
       xx=x+ cx;
                yy=y+ cy;    }
      }
    glEnd();
    if(cc>=0 && cc<25)
    {n=cy+125+(cc*1.4);}
    else if(cc>=25 && cc<=75)
        {n=cy+160-((cc-25)*1.4);}
     else if(cc>75 && cc<100)
    {n=cy+90+((cc-75)*1.4);}


    glColor3f(0.0f,1.0f,0.0f);
    q1.x=xx;
    q1.y=yy;
                    /*glColor3f(0.0f,0.0f,1.0f);
                    q2.x=cx;
                    q2.y=cy;
                    quad(q1,q2,5);
                    q2.x=cx;
                    q2.y=cy;
                    quadd(q1,q2);*/
    glColor3f(0.4f,0.4f,0.4f);
    q2.x=cx;
    q2.y=n;
    quad(q1,q2,5);
    q1.x=cx;
    q1.y=n;
    q2.x=cx;
    q2.y=n+40;
    //glColor3f(0.0f,0.0f,1.0f);
    glColor3fv(colors[0]);
    quad(q1,q2,45);
    glColor3f(0.4f,0.4f,0.4f);


    glColor3f(0.4f,0.4f,0.4f);
    q1.x=cx;
    q1.y=n+18;
    q2.x=cx;
    q2.y=n+28;
    //quad(q1,q2,45);
    q1.x=cx;
    q1.y=n+30;
    q2.x=cx;
    q2.y=n+39;
    //quad(q1,q2,45);
    Circle(xx,yy,10,100,0);//crank connector
    Circle(cx,n+10,10,100,0);//piston connecting rod


}

void Crankrod(float cx, float cy, float r, int num_segments) {
    float xx,yy,n,xxx,yyy,flg=0;
    glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

      if(ii>=cb && ii<=(cb+20)){
                glVertex2f(x + cx, y + cy);//output vertex
                if(flg!=1)
                {xxx=x+cx;
                yyy=y+cy;}
    }
     if(cb>=80 && ii<=(20-(100-cb))){
                glVertex2f(x + cx, y + cy);//output vertex
                xxx=x+cx;
                yyy=y+cy;
                flg=1;
    }
    if(ii==cb){
                xx=x+ cx;
                yy=y+ cy;
    }
    }
    glEnd();

    q1.x=xx;
    q1.y=yy;
    q2.x=xxx;
    q2.y=yyy;
    q3.x=cx;
    q3.y=cy;
    q4.x=cx;
    q4.y=cy;

    rect(q1,q2,q3,q4);


    //glColor3f(0.0,0.0,0.0);

    //Circle(xx,yy,3,100,0);

}void valve(float x,float y){

   float p=0;
    if(s==0){
     if(cc>=25 && cc<=50)
        p=-(cc-25)*0.6;
     else if(cc>50 && cc<75)
        p=-15+(cc-50)*0.6;
    }
                    //glColor3f(1.0f,0.0f,0.0f);
                    glColor3fv(colors[5]);
                    q1.x=x-30;
                    q1.y=y+225+p;
                    q2.x=x-30;
                    q2.y=y+220+p;
                    quad(q1,q2,10);
                    q1.x=x-30;
                    q1.y=y+225+p;
                    q2.x=x-30;
                    q2.y=y+276+p;
                    quad(q1,q2,2);


     p=0;
     if(s==1){
  if(cc>=0 && cc<25)
        p=-15+(cc)*0.6;
    if(cc>=75 && cc<100)
    p=-(cc-75)*0.6;

    }               q1.x=x+30;
                    q1.y=y+225+p;
                    q2.x=x+30;
                    q2.y=y+220+p;
                    quad(q1,q2,10);
                    q1.x=x+30;
                    q1.y=y+225+p;
                    q2.x=x+30;
                    q2.y=y+276+p;
                    quad(q1,q2,2);


}
void cover(float x,float y){// x=900;y=500;
//glColor3f(1.0,1.0,0.0);
glBegin(GL_TRIANGLE_FAN);
glVertex2d(x-120,y+60);
glVertex2d(x-55,y+125);
glVertex2d(x+55,y+125);
glVertex2d(x+120,y+60);
glVertex2d(x+120,y-120);
glVertex2d(x-120,y-120);
glEnd();

glBegin(GL_TRIANGLE_FAN);
//glVertex2d(780,560);
glVertex2d(x-55,y+125);
glVertex2d(x-55,y+225);
glVertex2d(x-20,y+250);
glVertex2d(x+20,y+250);
glVertex2d(x+55,y+225);
glVertex2d(x+55,y+125);
glEnd();

}
void innlet(float x,float y){
    glColor3fv(colors[3]);

glBegin(GL_TRIANGLE_FAN);
if(s==0 )
{   if(cc>=27 && cc<75)
    glColor3f(0.0,0.5,1.0);
    if(cc>=75 && cc<100){
        float r=(cc-75)*0.032;
        glColor3f(0.0+r,0.5+(r/2.66),1.0-(r/4));
    }
}
        float cx=x-50,cy=y+225,r=32;
    for (int ii = 0; ii < 100; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=0 && ii<=25)
        glVertex2f(x + cx, y + cy);//output vertex

      }r=10;
    for (int ii = 100; ii >=0; ii--)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=0 && ii<=25)
        glVertex2f(x + cx, y + cy);//output vertex

      }
    glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x-100, y+256);
        glVertex2f(x-100, y+235);
        glVertex2d(x-49,y+235);
        glVertex2f(x-49, y+256);
        glEnd();

}
void innletcover(float x,float y){
    glColor3fv(colors[1]);

glBegin(GL_TRIANGLE_FAN);
        float cx=x-50,cy=y+225,r=34;
    for (int ii = 0; ii < 100; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=0 && ii<=25)
        glVertex2f(x + cx, y + cy);//output vertex

      }r=8;
    for (int ii = 100; ii >=0; ii--)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=0 && ii<=25)
        glVertex2f(x + cx, y + cy);//output vertex

      }
    glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x-100, y+259);
        glVertex2f(x-100, y+232);
        glVertex2d(x-47,y+232);
        glVertex2f(x-47, y+259);
        glEnd();

}
void spark(float x,float y){
glColor3f(1,1,0.1);
glBegin(GL_TRIANGLE_FAN);
//glBegin(GL_LINE_LOOP);
//glVertex2f(x-5,y+220);
glVertex2f(x+3,y+220);
glVertex2f(x+16,y+225);
glVertex2f(x+10,y+220);
glVertex2f(x+17,y+215);
glVertex2f(x-3,y+220);
glVertex2f(x-16,y+225);
glVertex2f(x-11,y+220);
glVertex2f(x-17,y+215);
glVertex2f(x+3,y+220);
glVertex2f(x+5,y+220);
glVertex2f(x,y+210);
glVertex2f(x-5,y+220);
glEnd();
}
void plug(float x,float y){ //float x=217,y=301;
   glColor3f(0.3,0.3,0.3);
 glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x-2, y+19);
        glVertex2f(x+3, y+19);
        glVertex2f(x+3, y+24);
        glVertex2f(x-2, y+24);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x-7, y+19);
        glVertex2f(x+8, y+19);
        glVertex2f(x+8, y+1);
        glVertex2f(x-7, y+1);
    glEnd();
glColor3f(0.0,0.0,0.0);

    glBegin(GL_QUADS);
        glVertex2f(x-17, y-1);
        glVertex2f(x+19, y-1);
        glVertex2f(x+19, y+1);
        glVertex2f(x-17, y+1);
    glEnd();
    glColor3f(1.8,1.8,1.0);
glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x-9, y-1);
        glVertex2f(x+10, y-1);
        glVertex2f(x+10, y-31);
        glVertex2f(x-9, y-31);
    glEnd();
     glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        for(int i=0;i<5;i++)
   {
            glVertex2f(x+10, (y-1)-(5*i));
            glVertex2f(x-9, (y-6)-(5*i));
   }
    glEnd();
     glColor3f(1.8,1.8,1.0);

    glPointSize(7.0f);
    glBegin(GL_POINTS);
    glVertex2d(x+1,y-31);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(x+6,y-32);
    glVertex2d(x+6,y-41);
    glEnd();
    glBegin(GL_LINES);

    glVertex2d(x-2,y-41);
    glVertex2d(x+6,y-41);

    glEnd();
 glColor3f(0.3,0.3,0.3);
  glBegin(GL_LINES);
        float cx=x+25,cy=y+24,r=25;
        for (int ii = 0; ii < 100; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=25 && ii<=50)
        glVertex2f(x + cx, y + cy);//output vertex

         }
    glEnd();
}


void fuel(float x,float y){
    float j,i=x,k=y+227,l,flag=0;
    if(s==0){k=y+224;
            if( cc>25 && cc<=75){
    l=y+170-((cc-25)*1.4);
    flag=1;

    glColor3f(0.0,0.5,1.0);//fuel color
            }
            if( cc>75 && cc<100){
    l=y+100+((cc-75)*1.4);
    flag=1;
    float rr=(cc-75)*0.02;
    glColor3f(rr,0.5-(rr/2),1-rr);//fuel color
            }
            if( cc>=0 && cc<25){
    l=y+135+(cc*1.4);
    flag=1;

    float rr=(cc)*0.02;

    glColor3f(rr+0.5,0.25-(rr/2),0.5-rr);//fuel color
            }
    }


     if(s==1){
            k=(y+225);
        if(cc>=25 && cc<=75){
    l=y+170-((cc-25)*1.4);
    flag=1;
    float rr=(cc-25)*0.02;
    if(rr>=0.95)
        rr=0.95;
    glColor3f(1-(rr*0.1),0+rr,0+rr);

        }
            if( cc>75 && cc<100){ l=y+100+((cc-75)*1.4);
            flag=1;
 glColor3f(0.9,0.95,0.95);

            }
            if( cc>=0 && cc<=25){ l=y+135+(cc*1.4);
            flag=1;

 glColor3f(0.9,0.95,0.95);//gas color
 }

    }

    if(flag==1){
    glBegin(GL_LINES);
    for(j=k;j>l;j--)
    {
        glVertex2f(i-43,j);
        glVertex2f(i+44,j);
    }
    glEnd();
    }

}

void board(float x,float y){
//glColor3f(0.0,1.0,1.0);
glColor3f(0.95,1,1);

glBegin(GL_QUADS);
glVertex2f(x-450,y-250);
glVertex2f(x+450,y-250);
glVertex2f(x+450,y+450);
glVertex2f(x-450,y+450);
glEnd();
//glColor3f(0.85,1,1);
glColor3f(0.2,.8,.5);

glBegin(GL_QUADS);
glVertex2f(x-400,y-200);
glVertex2f(x+400,y-200);
glVertex2f(x+400,y+400);
glVertex2f(x-400,y+400);
glEnd();

}

void smallboard(float x,float y){
//glColor3f(0.0,1.0,1.0);
glColor3f(0.95,1,1);

glBegin(GL_QUADS);
glVertex2f(x-200,y-200);
glVertex2f(x+200,y-200);
glVertex2f(x+200,y+200);
glVertex2f(x-200,y+200);
glEnd();
//glColor3f(0.85,1,1);
glColor3f(0.2,.8,.5);

glBegin(GL_QUADS);
glVertex2f(x-160,y-160);
glVertex2f(x+160,y-160);
glVertex2f(x+160,y+160);
glVertex2f(x-160,y+160);
glEnd();

}
/*void board(float x,float y){
glColor3f(0.3,0.3,0.3);
//glColor3f(0.95,1,1);

glBegin(GL_QUADS);
glVertex2f(x-550,y-250);
glVertex2f(x+550,y-250);
glVertex2f(x+550,y+450);
glVertex2f(x-550,y+450);
glEnd();
glColor3f(1.0,1.0,1.0);
//glColor3f(0.2,.8,.5);

glBegin(GL_QUADS);
glVertex2f(x-500,y-200);
glVertex2f(x+500,y-200);
glVertex2f(x+500,y+400);
glVertex2f(x-500,y+400);
glEnd();

}*/

void text(int x, int y, char *string,int j)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(fonts[j], string[i]);
  }
}
void indicator(float cx, float cy, float r, int num_segments,int h) {
    //glColor3f(0.0,0.0,1.0);
    float xx,yy,n;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);//output vertex

    for (int ii = 0; ii <= num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii>=h && ii<=(h+25))
        glVertex2f(x + cx, y + cy);//output vertex

      }
    glEnd();


}
void kk(float cx, float cy, float r, int num_segments){
    for (int ii = 0; ii <= num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        if(ii==pointer || ii==(pointer-0.5))
        glVertex2f(x + cx, y + cy);//output vertex

      }

}
void tip(float cx, float cy, float r, int num_segments){
    float xx,yy,n;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx-5, cy-5);//output vertex
        kk(cx,cy,r,num_segments);
      glVertex2f(cx+5, cy-5);//output vertex


    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx-5, cy-5);//output vertex
kk(cx,cy,r,num_segments);
      glVertex2f(cx-5, cy+5);//output vertex


    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx-5, cy+5);//output vertex
kk(cx,cy,r,num_segments);
      glVertex2f(cx+5, cy+5);//output vertex


    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx+5, cy-5);//output vertex
kk(cx,cy,r,num_segments);
      glVertex2f(cx+5, cy+5);//output vertex


    glEnd();




}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glClear(GL_COLOR_BUFFER_BIT);

int x=800,y=500;

    //Circle(x, y, 100, 100,0);
 glColor3f(0.0,1.0,1.0);
    board(x,y);
    glColor3fv(colors[1]);
    cover(x,y);
    glColor3f(0.8,0.8,0.8);
    innletcover(x,y);
    innlet(x,y);
    outletcover(x,y);
    outlet(x,y);
   // glColor3f(1.0,1.0,1.0);
    glColor3fv(colors[4]);
    Circle(x, y, 110, 100,0);


    q1.x=x-44;
    q1.y=y+100;
    q2.x=x-44;
    q2.y=y+225;
    q3.x=x+44;
    q3.y=y+225;
    q4.x=x+44;
    q4.y=y+100;

    rect(q1,q2,q3,q4); //inner cylinder
     fuel(x,y);
    glColor3f(0.0,0.0,1.0);

    //reectangle();
    //point(x,y+325);

 glColor3fv(colors[0]);
	//Crankrod(x, y, 65, 100);
    Circle(x, y, 50, 100,0);
  glColor3fv(colors[2]);
    Crank(x, y, 35, 100);
    glColor3f(0.0,0.0,1.0);
    valve(x,y);
    plug(x,y+253);
    if(s==0 && cc>=22 && cc<=25  )
        spark(x+1,y-2);
    if(s==1 && cc<=28 && cc>=25  )
        spark(x+1,y-2);
// title
    glColor3f(0.0,0.0,1.0);
    text(x-115,y+415,"IC Petrol Engine",2);
 y+=150;
    smallboard(x+700,y);
    glColor3f(0.3,0.3,0.3);
    Circle(x+700, y, 145, 100,0);
        glColor3f(0.9,0.95,0.95);
        indicator(x+700, y, 140, 100,0); //exhaust
    glColor3f(0.0,0.5,1.0);
     indicator(x+700, y, 140, 100,25); //suction
    glColor3f(0.8,0.5,0.5);
        indicator(x+700, y, 140, 100,50);//compression
    glColor3f(0.9,1.0,0.5);
        indicator(x+700, y, 140, 100,75);// working
    glColor3f(0.3,0.3,0.3);
    Circle(x+700, y, 15, 100,0);
    //glColor3f(0.0,0.0,0.0);

    tip(x+700, y, 100, 100);

    glColor3f(0.0,0.0,1.0);
    text(x+600,y+170,"Stroke Indicator",2);

    //lables
    glColor3f(0.0,0.5,1.0);
     point(x+520,y-240);

    glColor3f(0.5,0.9,1.0);
    text(x+540,y-245,"Suction Stroke",0);

    glColor3f(0.8,0.5,0.5);
     point(x+520,y-260);

    glColor3f(0.5,0.9,1.0);
    text(x+540,y-265,"Compression Stroke",0);

    glColor3f(0.9,1.0,0.5);
     point(x+520,y-280);

    glColor3f(0.5,0.9,1.0);
    text(x+540,y-285,"Working Stroke",0);

    glColor3f(0.9,0.95,0.95);
     point(x+520,y-300);

    glColor3f(0.5,0.9,1.0);
    text(x+540,y-305,"Exhaust Stroke",0);
    text(x-510,y-450,"Press 'space' to start/stop    Press '+' to speedup engine    Press '-' to slowdown engine",0);


    glFlush();

    //quad();



}
void start(){
    if(status==1)
{   cb++;
    cc++;
    pointer+=0.5;
    }
    if(cc==100)
    {
        cc=0;

    }
    if(pointer==100)
    {
        pointer=0;

    }
    if(cb==100) cb=0;
    display();

      //Game title

    if(cc==25){
        if(s==0)
            s=1;
        else
            s=0;
    }

    Sleep(speed);

}

void keypress(unsigned char key, int x,int y){
       if (key=='+') {speed--;
                                if(speed<=0) speed=0;}
       if (key=='-') {speed++;if(speed>=500) speed=500;}
       if(key==' ') {if(status==0) status=1; else status=0; }}
void myReshape(int w,int h)
{

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
    glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	glMatrixMode(GL_PROJECTION);
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutCreateWindow("Introduction to Open GL");
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(keypress);
	glutDisplayFunc(display);
	glutIdleFunc(start);
	init();
    glutMainLoop();
}
