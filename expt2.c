#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
GLfloat triangle[3][9]={{100.0,500.0,300.0},{100.0,100.0,500.0},{1.0,1.0,1.0}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][9]={{0},{0},{0}};
GLfloat h,k,theta,theta1;
void multiply()
{
int i,j,l;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
result[i][j]=0;
for(l=0;l<3;l++)
result[i][j]+=rot_mat[i][l]*triangle[l][j];
}
}
}
void rotate()
{
GLfloat m,n;
theta = theta1 * 3.142 /180;
m=-h*(cos(theta)-1)+k*(sin(theta));
n=-k*(cos(theta)-1)-h*(sin(theta));
rot_mat[0][0]=cos(theta);
rot_mat[0][1]=-sin(theta);
rot_mat[0][2]=m;
rot_mat[1][0]=sin(theta);
rot_mat[1][1]=cos(theta);
rot_mat[1][2]=n;
rot_mat[2][0]=0;
rot_mat[2][2]=0;
rot_mat[2][2]=1;
multiply();
}
void drawtriangle()
{
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(triangle[0][0],triangle[1][0]);
glVertex2f(triangle[0][1],triangle[1][1]);
glVertex2f(triangle[0][2],triangle[1][2]);
glEnd();
}
void drawrotatedtriangle()
{
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(result[0][0],result[1][0]);
glVertex2f(result[0][1],result[1][1]);
glVertex2f(result[0][2],result[1][2]);
glEnd();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
drawtriangle();
rotate();
drawrotatedtriangle();
glFlush();
}
void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,999.0,0.0,999.0);
}
void main(int argc,char** argv)
{
printf("Enter the rotation angle:");
scanf("%f",&theta1);
printf("Enter the fixed point of rotation:");
scanf("%f%f",&h,&k);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Triangle Rotation");
glutDisplayFunc(display);
myinit();
glutMainLoop();
}
