// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "glut.h"
//#include <stdlib.h>
//#include <vector>
//#include <math.h>
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//struct stPoint2D
//{
//	float X;
//	float Y;
//	stPoint2D()
//	{
//		X = Y = 0.0f;
//	}
//};
//
//std::vector<stPoint2D> vPlotData;
//
//
//void displayData()
//{
//	glPushMatrix(); /* GL_MODELVIEW is default */
//
//	glScalef(0.1 , 0.1 , 1.0);
//	glTranslatef(0.0, 0.0, 0.0);
//	glColor3f(1.0, 1.0, 1.0);  /*For line color*/
//
//	glBegin(GL_LINE_STRIP);
//	//for (unsigned int i(0); i < vPlotData.size();++i)
//		//glVertex2f(vPlotData.at(i).X, vPlotData.at(i).Y);
//	string csDraw = "Hi there !!!";
//	char cs[] = { "Hello" };
//	glRasterPos3f(2.0f,2.0f,0.0f);
//	glColor3f(1.0, 1.0, 1.0);
//	unsigned long font = (unsigned long)GLUT_BITMAP_HELVETICA_18;
//	for (int i(0); i < 5;++i)
//		::glutBitmapCharacter((void *)font, cs[i]);
//
//	glEnd();
//
//	glPopMatrix();
//};
///* Redrawing func */
//void redraw(void)
//{
//	glClearColor(0, 0, 0, 0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	displayData();
//
//	glutSwapBuffers();
//};
//
///* Idle proc. Redisplays, if called. */
//void idle(void)
//{
//	glutPostRedisplay();
//};
//
///* Key press processing */
//void key(unsigned char c, int x, int y)
//{
//	if (c == 27) exit(0);
//};
//
///* Window reashape */
//void reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0, 1, 0, 1, -1, 1);
//	glMatrixMode(GL_MODELVIEW);
//};
//
///* Main function */
//int main11(int argc, char **argv)
//{
//	if (argc == 1)
//	{
//		printf("<filename> Argument missing input file name\n");
//		return 0;
//	}
//	/* File Reading */
//	FILE *fpinput = nullptr;
//	fopen_s(&fpinput, argv[1], "r");
//	if (fpinput != nullptr)
//	{
//		stPoint2D pt_read;
//		do{
//			fscanf_s(fpinput, "%f %f", &pt_read.X, &pt_read.Y);
//			vPlotData.emplace_back(pt_read);
//		} while (!feof(fpinput));
//		fclose(fpinput);
//	}
//
//	/* Init OpenGL */
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//	glutCreateWindow("Graph");
//
//	/* Register GLUT callbacks. */
//	glutDisplayFunc(redraw);
//	glutKeyboardFunc(key);
//	glutReshapeFunc(reshape);
//	glutIdleFunc(idle);
//
//	/* Init the GL state */
//	glLineWidth(2.0);
//
//	/* Main loop */
//	glutMainLoop();
//	return 0;
//}
