#include "stdafx.h"
#include <windows.h>
#include "glut.h"
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

int w, h;
const int font = (int)GLUT_BITMAP_HELVETICA_18;
char s[30];
double t;

static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	w = width;
	h = height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);     glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void setOrthographicProjection() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glScalef(1, -1, 1);
	glTranslatef(0, -h, 0);
	glMatrixMode(GL_MODELVIEW);
}
void resetPerspectiveProjection() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void renderLineData(){	
	glColor3f(1.0, 1.0, 1.0);  /*For line color*/
	glBegin(GL_LINE_STRIP);
	for (unsigned int i(0); i < 500; ++i)
		glVertex2f(i-200, i-200);
	glEnd();
}
void renderBitmapString(float x, float y, void *font, const char *string){
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
static void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	setOrthographicProjection();
	renderBitmapString(200, 200, (void *)font, "Text Drawing Utility");
	renderBitmapString(300, 220, (void*)font, s);
	renderLineData();
	resetPerspectiveProjection();
	glutSwapBuffers();
}
void update(int value){
	t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	int time = (int)t;
	sprintf_s(s, "TIME : %2d Sec", time);
	glutTimerFunc(1000, update, 0);
	glutPostRedisplay();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);     glutCreateWindow("Font Rendering Using Bitmap Font - Programming Techniques0");     glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutTimerFunc(25, update, 0);     glutMainLoop();
	return EXIT_SUCCESS;
}