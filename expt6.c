#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

GLfloat T=0;
void MyInit()
{
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1,1,-1,1,2,10);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}
  void Spin()
 {
   T=T+1;
   if(T>360)
    T=0;
   glutPostRedisplay();
 }

   void Draw()
{
  GLfloat pos[]={0,1,0,1};
  GLfloat col[]={0,0,1,1};
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glLightfv(GL_LIGHT0,GL_POSITION,pos);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,col);

 gluLookAt(0,1,3,0,0,0,0,1,0);
   glRotatef(T,0,1,0);
 glPushMatrix();
   glScalef(1,0.05,1);
  glutSolidCube(1);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-0.5,-0.5,-0.5);
  glScalef(0.05,1,0.05);
  glutSolidCube(1);
  glPopMatrix();
  glPushMatrix();
 glTranslatef(-0.5,-0.5,0.5);
 glScalef(0.05,1,0.05);
 glutSolidCube(1);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(0.5,-0.5,-0.5);
 glScalef(0.05,1,0.05);
 glutSolidCube(1);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(0.5,-0.5,0.5);
 glScalef(0.05,1,0.05);
 glutSolidCube(1);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(0,0.25,0);
 glutSolidTeapot(0.3);
 glPopMatrix();
 glutSwapBuffers();
}
 int main(int argc,char*argv[])
{
  glutInit(&argc,argv);
  glutInitWindowSize(600,600);
  glutInitWindowPosition(100,100);
  glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
  glutCreateWindow("GLUT Sgapes");
  MyInit();
    glutDisplayFunc(Draw);
   glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}
