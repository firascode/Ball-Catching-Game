
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define CIRCLE_RADIUS  0.15f
#define PI 3.14159265358979323846
int eggs_caught=0,missed_eggs=0,level_count=1,points=0;
GLfloat d1=0.0, d2=0.0, d3=0.0, d4=0.0,d5=0.0;

int egg_xc,egg_yc;
// for coordinates of egg
int basket_x,basket_y;
// for coordinates of basket
int a=600,b=650; // for default size of the screen
int s=0;
// for menu option
int dropped_eggs=0;
int speed_1=1,speed_2=1.1,speed_3=1.2,speed_4=1.3;
int w=48,h=48,t=10,e=9,g=12;
void myinit();
void start_screen(int,int);
void cloud1();
void egg();
void basket(int,int);
void dino(int,int);
void print_score();
void egg_start();
void color();
void score();
void display(void);
void basket_set(int,int);
void myReshape(int,int);
void keys(unsigned char,int,int);
void menu(int);

void myinit()
{
glViewport(0,0,a,b);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,(GLdouble)a,0,(GLdouble)b);
glMatrixMode(GL_MODELVIEW);
glutPostRedisplay();
}

void start_screen(int i,int j)
{
int k;
char cat[4]="EGG";
char orr[9]="Catching";
char hatch[5]="Game";
char start[20]="Press S for start";
glColor3f(0,1,0);
glRasterPos2i(150,320);
for(k=0;k<4;k++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,cat[k]);
glColor3f(1,1,1);
glRasterPos2i(200,320);
for(k=0;k<9;k++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,orr[k]);
glColor3f(1,0,0);
glRasterPos2i(300,320);
for(k=0;k<5;k++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,hatch[k]);
glColor3f(1,1,0);
glRasterPos2i(210,200);
for(k=0;k<20;k++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,start[k]);
glColor3f(1,.5,.5);

}

void sun()
{

 float theta;

GLfloat angle;
glLineWidth(1.5);
glBegin(GL_POLYGON);
for (int i = 0; i <360 ; i++)
{
theta  = i*PI*i/180;
glVertex2f(500+80*cos(theta)/2, 600+80*sin(theta)/2);
}

glEnd();
glFlush();
}
void cloud1()
{

 float theta;

GLfloat angle;
glLineWidth(1.5);
glColor3f(1,1,1);
glBegin(GL_POLYGON);
for (int i = 0; i <360 ; i++)
{
theta  = i*PI*i/180;
glVertex2f(100+50*cos(theta)/2, 590+50*sin(theta)/2);
}

glEnd();
//GLfloat angle;
glLineWidth(1.5);
glColor3f(1,1,1);
glBegin(GL_POLYGON);
for (int i = 0; i <360 ; i++)
{
theta  = i*PI*i/180;
glVertex2f(130+50*cos(theta)/2, 580+50*sin(theta)/2);
}
glEnd();

glLineWidth(1.5);
glColor3f(1,1,1);
glBegin(GL_POLYGON);
for (int i = 0; i <360 ; i++)
{
theta  = i*PI*i/180;
glVertex2f(140+50*cos(theta)/2, 600+50*sin(theta)/2);
}
glEnd();

glLineWidth(1.5);
glColor3f(1,1,1);
glBegin(GL_POLYGON);
for (int i = 0; i <360 ; i++)
{
theta  = i*PI*i/180;
glVertex2f(170+50*cos(theta)/2, 590+50*sin(theta)/2);
}

glEnd();
glFlush();
}

void cloud2()
{
    float theta;
    glLineWidth(1.5);
glColor3f(1,1,1);
glBegin(GL_POLYGON);
for (int i = 0; i <360 ; i++)
{
theta  = i*PI*i/180;
glVertex2f(420+45*cos(theta)/2, 540+45*sin(theta)/2);
}

glEnd();

   glLineWidth(1.5);
glColor3f(1,1,1);
glBegin(GL_POLYGON);
for (int i = 0; i <360 ; i++)
{
theta  = i*PI*i/180;
glVertex2f(455+45*cos(theta)/2, 550+45*sin(theta)/2);
}

glEnd();

   glLineWidth(1.5);
glColor3f(1,1,1);
glBegin(GL_POLYGON);
for (int i = 0; i <360 ; i++)
{
theta  = i*PI*i/180;
glVertex2f(455+45*cos(theta)/2, 530+45*sin(theta)/2);
}

glEnd();

   glLineWidth(1.5);
glColor3f(1,1,1);
glBegin(GL_POLYGON);
for (int i = 0; i <360 ; i++)
{
theta  = i*PI*i/180;
glVertex2f(490+45*cos(theta)/2, 540+45*sin(theta)/2);
}

glEnd();
glFlush();

}


void line(int i , int j)
{

glBegin(GL_QUADS);
 glColor3f(1.0,.5,0.5);
glVertex2f(0.0+i,10.0+j);
glVertex2f(0.0+i,15.0+j);
glVertex2f(600.0+i,15.0+j);
glVertex2f(600.0+i,10.0+j);
glEnd();
glFlush();
}


void backk(int i , int j)
{
glColor3f(0.3,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(0.0+i,0.0+j);
glVertex2f(600.0+i, 0.0+j);
glVertex2f(600.0+i,-500+j);
glVertex2f(0.0+i,-500+j);
glEnd();
glFlush();
}


void ground(int i , int j)
{

glBegin(GL_QUADS);
glColor3f(0,1.0,0);
glVertex2f(0.0+i,0.0+j);
glVertex2f(600.0+i, 0.0+j);
glVertex2f(600.0+i,-j);
glVertex2f(0.0+i,-j);
glEnd();
}





void egg()
{

float x,y,z;
int t;
 glColor3f(1.0,10,1.0);
glBegin(GL_POLYGON);
for(t=0;t<=360;t+=1)
{
x = egg_xc+12*(cos(t));
y = egg_yc+12*(sin(t));
z = 0;
glVertex3f(x,y,z);
}
glEnd();
}


void basket(int i,int j)
{
j=20;
if(i>=a-80)i=a-60;
glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);

glVertex2f(0.0+i,30.0+j);
glVertex2f(10.0+i,10.0+j);
glVertex2f(50.0+i,10.0+j);
glVertex2f(60.0+i,30.0+j);
//glVertex2f(20.0+i,30.0+j);
//glVertex2f(90.0+i,30.0+j);
//glVertex2f(90.0+i,15.0+j);
//glVertex2f(20.0+i,15.0+j);

glEnd();
}


void dino(int i,int j)
{


//glPushMatrix();
//	glTranslatef(800,800,0);
//	glScalef(0.8,0.8,1);

	glPushMatrix();
	glTranslatef(500, 300,0);
	glScalef(0.7, 0.7, 1);
	glTranslatef(-500, -250,0);
	glTranslatef(i,j,0);	
	//glColor3f(1.0,1.0,0.0);
glBegin(GL_QUADS);
 //1
	glVertex2i(525,290);	
	glVertex2i(530,290);	
	glVertex2i(530,255);
	 glVertex2i(525,255);	
	 
	 
	/////2 
	glVertex2i(520,280);		
	glVertex2i(525,280);	
	glVertex2i(525,255);
	glVertex2i(520,255);
	
	//3
	glVertex2i(515,270);		
	glVertex2i(520,270);	
	glVertex2i(520,250);
	
	glVertex2i(515,250);
	
	//4
	glVertex2i(510,270);		
	glVertex2i(515,270);	
	glVertex2i(515,245);
	glVertex2i(510,245);
	
	///5
	glVertex2i(440,265);		
	glVertex2i(510,265);	
	glVertex2i(510,240);
	glVertex2i(440,240);
	
	///6
	
	glVertex2i(445,240);		
	glVertex2i(500,240);	
	glVertex2i(500,235);
	glVertex2i(445,235);
	
	
	///7
	
	glVertex2i(450,235);		
	glVertex2i(475,235);	
	glVertex2i(475,230);
	glVertex2i(450,230);
	
	///8
	glVertex2i(480,235);		
	glVertex2i(500,235);	
	glVertex2i(500,230);
	glVertex2i(440,230);
	
	
	///9
	glVertex2i(455,230);		
	glVertex2i(465,230);	
	glVertex2i(465,205);
	glVertex2i(455,205);
	
	///10
	glVertex2i(490,230);		
	glVertex2i(500,230);	
	glVertex2i(500,205);
	glVertex2i(490,205);
	
	///11
	glVertex2i(445,215);		
	glVertex2i(455,215);	
	glVertex2i(455,205);
	glVertex2i(445,205);
	
	///12
	glVertex2i(480,215);		
	glVertex2i(490,215);	
	glVertex2i(490,205);
	glVertex2i(480,205);
	
	///13
	glVertex2i(465,230);		
	glVertex2i(470,230);	
	glVertex2i(470,225);
	glVertex2i(465,225);
	
	///14
	glVertex2i(485,230);		
	glVertex2i(490,230);	
	glVertex2i(490,225);
	glVertex2i(485,225);
	
	///15
	glVertex2i(415,260);		
	glVertex2i(440,260);	
	glVertex2i(440,255);
	glVertex2i(415,255);
	
	
	///16
	glVertex2i(410,260);		
	glVertex2i(415,260);	
	glVertex2i(415,250);
	glVertex2i(410,250);
	
	//17
	
	glVertex2i(440,315);		
	glVertex2i(465,315);	
	glVertex2i(465,265);
	glVertex2i(440,265);
	
	///18
	glVertex2i(405,315);		
	glVertex2i(440,315);	
	glVertex2i(440,295);
	glVertex2i(405,295);
	
	///19
	glVertex2i(410,320);		
	glVertex2i(460,320);	
	glVertex2i(460,315);
	glVertex2i(410,315);
	
	///20
	glVertex2i(430,295);		
	glVertex2i(440,295);	
	glVertex2i(440,280);
	glVertex2i(430,280);
	
	///21
	glVertex2i(415,285);		
	glVertex2i(430,285);	
	glVertex2i(430,280);
	glVertex2i(415,280);
	
	//22
	glVertex2i(475,285);		
	glVertex2i(480,285);	
	glVertex2i(480,265);
	glVertex2i(475,265);
	
	//23
	glVertex2i(480,290);		
	glVertex2i(485,290);	
	glVertex2i(485,280);
	glVertex2i(480,280);
	
	//24
	glVertex2i(485,295);		
	glVertex2i(490,295);	
	glVertex2i(490,285);
	glVertex2i(485,285);
	
	
	
		glEnd(); 
		glPopMatrix();
		
		
			glPushMatrix();
			glTranslatef(500, 300,0);
	glScalef(0.7, 0.7, 1);
	glTranslatef(-500, -250,0);
	glTranslatef(i,j,0);	
	//glColor3f(1.0,1.0,0.0);
glBegin(GL_TRIANGLES);
 //1
	glVertex2i(515,315);	
	glVertex2i(515,275);	
	glVertex2i(485,292);
		glEnd();
		glPopMatrix();
glFlush();
}
/*void dino_scale(void)
{
	glPushMatrix();
	duck(0,0);
	glPopMatrix();
}*/

void print_score()
 {
printf("\nLevel reached: %d\n\n",level_count);
printf("\nNo. of eggs dropped= %d \n",dropped_eggs);
printf("\nNo. of eggs caught = %d\n",eggs_caught);
printf("\nNo. of eggs missed = %d\n",missed_eggs);

getchar();
exit(0);
}
void egg_start()
{
egg_yc=450;
if(missed_eggs>=10)
{
printf("\n\n\t\t\t\tGAME OVER\n\n");
print_score();
}
dropped_eggs++;

switch(rand()%9)
{
case 0:egg_xc=115 ; break;
case 1:egg_xc=255; break;
case 2:egg_xc=390; break;
case 5:egg_xc=115; break;
case 3:egg_xc=255; break;
case 4:egg_xc=390; break;
case 7:egg_xc=115; break;
case 6:egg_xc=255; break;
case 8:egg_xc=390; break;
}
}




void score()
{
if(egg_yc<=50 && (egg_xc>=basket_x&&egg_xc<=basket_x+60))
{
printf("\a");
eggs_caught++;
egg_yc=-10;
}
missed_eggs=dropped_eggs-eggs_caught;
}






void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
d1=d1-1.0;
if(d1<-200)
{
	d1= 750;
}
d2=d2-1.0;
if(d2<-405)
{
	d2= 545;
}

d3=d3-1.0;
if(d3< -580)
{ 
	d3 = 370;
}


d4= d4 - 1.0;
if(d4 < -780)
{
	d4 = 170;
}


d5= d5 - 1.0;
if(d5 < -850)
{
	d5 = 100;
}

ground(0 , 650);
backk(0, 650);
cloud1();
cloud2();
glPushMatrix();
glColor3f(0.9,0.5,0.0);
dino(-530+d1,250);
glColor3f(0.9,0.3,0.2);
dino(-325+d2,250);
glColor3f(0.9,0.5,0.4);
dino(-150+d3,250);
glColor3f(1.0,0.5,0.4);
dino(50+d4,250);
glColor3f(1.0,0.6,0.3);
dino(250+d5,250);
glPopMatrix();
//dino_scale();

glPushMatrix();
glColor3f(1.0, 0.9, 0.0);
sun();
glPopMatrix();

line(0,375);

int i;
char z[15]="Group 2";
char level1[12]="LEVEL 1";
char level2[12]="LEVEL 2";
char level3[12]="LEVEL 3";
char level4[12]="LEVEL 4";

if(s>=0)
{
glColor3f(0,0,1);

glRasterPos2i(10,10);
for(i=0;i<12;i++)
glutBitmapCharacter(GLUT_BITMAP_8_BY_13,z[i]);

if(level_count==1)
{
glColor3f(1,1,1);
glRasterPos2i(500,300);
for(i=0;i<12;i++)
glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level1[i]);
}
else if(level_count==2)
{
glColor3f(1,0,0);
glRasterPos2i(500,300);
for(i=0;i<12;i++)
glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level2[i]);
}
else if(level_count==3)
{
glColor3f(0,1,1);
glRasterPos2i(500,300);
for(i=0;i<12;i++)
glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level3[i]);
}
if(level_count==4)
{
glColor3f(1,0,1);
glRasterPos2i(500,300);
for(i=0;i<12;i++)
glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level4[i]);
}

if(egg_yc<=10)
egg_start();

egg();
basket(basket_x,basket_y);
if(eggs_caught>=10)
{
egg_yc-=speed_2;
level_count=2;
}
if(eggs_caught>=20)
{
egg_yc-=speed_3;
level_count=3;
}
if(eggs_caught>=30)
{
egg_yc-=speed_4;
level_count=4;
}
else
egg_yc-=speed_1;
score();
}
else
start_screen(40,300);
glFlush();
glutSwapBuffers();
}





void basket_set(int a,int b)
{
basket_x=a;
basket_y=b;
glutPostRedisplay();
}



void myReshape(int w,int h)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,(GLdouble)w,0.0,(GLdouble)h);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glViewport(0,0,w,h);
a=w;
b=h;
}

void keys(unsigned char key,int x,int y)
{
if(key=='q'||key=='Q')
{
printf("\n\n\n\t\tQUIT BY PLAYER\n\n");
print_score();
}
if(key=='s'||key=='S') ;

if(key=='a'||key=='A')
{
egg_xc-=10;
if(egg_xc<=0) egg_xc=10;
}
if(key=='d'||key=='D')
{
egg_xc+=10;
if(egg_xc>=500) egg_xc=490;
}

}


void menu(int id)
{
switch(id)
{
case 1: s+=1;
break;
case 2:print_score();
break;
case 3: printf("\n\n\n\t\tQUIT BY PLAYER\n");
break;
default:exit(0);
}
glutPostRedisplay();
}


int main(int argc,char **argv)
{


glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(a,b);
glutCreateWindow("CATCH IT IF YOU CAN");
myinit();
glutInitWindowPosition (100, 100);
glutCreateMenu(menu);
glutAddMenuEntry("Start game",1);
glutAddMenuEntry("score",2);
glutAddMenuEntry("Quit",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutDisplayFunc(display);
glutKeyboardFunc(keys);
glutPassiveMotionFunc(basket_set);
glutIdleFunc(display);
glutReshapeFunc(myReshape);
glutMainLoop();
}
