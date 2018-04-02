#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "vecteur.h"

#define SIZE_CUBE 0.5
#define PI 3.14

GLfloat recul;
vector3D tete, camera;
vector2D rotCamera, oldRotCamera;

void init()
{
	tete = vector3dInit(0.5,0.5,0.5);
	recul = 10.0;
	rotCamera = vector2dInit(0.0,0.0);
}

void Animer()
{
	glutPostRedisplay();
}

void GererClavier(unsigned char _touche, int _x, int _y)
{
	if(_touche == 'z')
	{
		vector2D vecCamera = vector2dInit((tete.x - camera.x), (tete.y - camera.y));
		vector2D vecCameraNorm = vector2dGetNorme(vecCamera);
		tete.x += .1 * vecCameraNorm.x;
		tete.y += .1 * vecCameraNorm.y;

		printf("X : %f\nY: %f\n\n", tete.x, tete.y);
	}
	if(_touche == 'q')
	{
		tete.x -= .1;
	}
	if(_touche == 'd')
	{
		tete.x += .1;
	}
}

void processMousePassiveMotion(int _x, int _y)
{
	rotCamera.x += (_x-oldRotCamera.x)*0.04;
	rotCamera.y += (_y-oldRotCamera.y)*0.04;

	if(rotCamera.y > 3*270) rotCamera.y = 3*270;
	if(rotCamera.y < 270) rotCamera.y = 270;

	if(rotCamera.x > 3*480) rotCamera.x = 3*480;
	if(rotCamera.x < 480) rotCamera.x = 480;

	oldRotCamera.x = rotCamera.x;
	oldRotCamera.y = rotCamera.y;

	glutPostRedisplay();
}

void trace_cube()
{
	glBegin(GL_QUADS);

	//Sol
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0,0,0);
	glVertex3f(0,10,0);
	glVertex3f(10,10,0);
	glVertex3f(10,0,0);

	//Cube Face_avant
	glColor3f(0.0,1.0,0.0);
	glVertex3f(tete.x-SIZE_CUBE, tete.y-SIZE_CUBE, tete.z-SIZE_CUBE);		//A
	glVertex3f(tete.x-SIZE_CUBE, tete.y-SIZE_CUBE, tete.z+SIZE_CUBE);		//B
	glVertex3f(tete.x+SIZE_CUBE, tete.y-SIZE_CUBE, tete.z+SIZE_CUBE);		//C
	glVertex3f(tete.x+SIZE_CUBE, tete.y-SIZE_CUBE, tete.z-SIZE_CUBE);		//D

	//Cube Face_arriere
	glColor3f(0.0,1.0,0.0);
	glVertex3f(tete.x-SIZE_CUBE, tete.y+SIZE_CUBE, tete.z-SIZE_CUBE);		//E
	glVertex3f(tete.x-SIZE_CUBE, tete.y+SIZE_CUBE, tete.z+SIZE_CUBE);		//F
	glVertex3f(tete.x+SIZE_CUBE, tete.y+SIZE_CUBE, tete.z+SIZE_CUBE);		//G
	glVertex3f(tete.x+SIZE_CUBE, tete.y+SIZE_CUBE, tete.z-SIZE_CUBE);		//H

	//Cube Face_gauche
	glColor3f(0.0,0.0,1.0);
	glVertex3f(tete.x-SIZE_CUBE, tete.y+SIZE_CUBE, tete.z-SIZE_CUBE);		//E
	glVertex3f(tete.x-SIZE_CUBE, tete.y+SIZE_CUBE, tete.z+SIZE_CUBE);		//F
	glVertex3f(tete.x-SIZE_CUBE, tete.y-SIZE_CUBE, tete.z+SIZE_CUBE);		//B
	glVertex3f(tete.x-SIZE_CUBE, tete.y-SIZE_CUBE, tete.z-SIZE_CUBE);		//A

	//Cube Face_droite
	glColor3f(0.0,0.0,1.0);
	glVertex3f(tete.x+SIZE_CUBE, tete.y-SIZE_CUBE, tete.z-SIZE_CUBE);		//D
	glVertex3f(tete.x+SIZE_CUBE, tete.y-SIZE_CUBE, tete.z+SIZE_CUBE);		//C
	glVertex3f(tete.x+SIZE_CUBE, tete.y+SIZE_CUBE, tete.z+SIZE_CUBE);		//G
	glVertex3f(tete.x+SIZE_CUBE, tete.y+SIZE_CUBE, tete.z-SIZE_CUBE);		//H

	//Cube Face_haut
	glColor3f(1.0,0.0,1.0);
	glVertex3f(tete.x-SIZE_CUBE, tete.y-SIZE_CUBE, tete.z+SIZE_CUBE);		//B
	glVertex3f(tete.x-SIZE_CUBE, tete.y+SIZE_CUBE, tete.z+SIZE_CUBE);		//F
	glVertex3f(tete.x+SIZE_CUBE, tete.y+SIZE_CUBE, tete.z+SIZE_CUBE);		//G
	glVertex3f(tete.x+SIZE_CUBE, tete.y-SIZE_CUBE, tete.z+SIZE_CUBE);		//C

	//Cube Face_bas
	glColor3f(1.0,0.0,1.0);
	glVertex3f(tete.x-SIZE_CUBE, tete.y-SIZE_CUBE, tete.z-SIZE_CUBE);		//A
	glVertex3f(tete.x-SIZE_CUBE, tete.y+SIZE_CUBE, tete.z-SIZE_CUBE);		//E
	glVertex3f(tete.x+SIZE_CUBE, tete.y+SIZE_CUBE, tete.z-SIZE_CUBE);		//H
	glVertex3f(tete.x+SIZE_CUBE, tete.y-SIZE_CUBE, tete.z-SIZE_CUBE);		//D


	glEnd();
	glutSwapBuffers();
}

void affichage()
{
	camera.x = tete.x + (recul * cos(rotCamera.x*(PI/180)) * cos(rotCamera.y*(PI/180)));
	camera.y = tete.y + (recul * -(sin(rotCamera.x*(PI/180))) * cos(rotCamera.y*(PI/180)));
	camera.z = tete.z + (recul * (sin(rotCamera.y*(PI/180))));

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-4.8,4.8,-2.7,2.7,2,500);
	gluLookAt(camera.x, camera.y, camera.z, tete.x, tete.y, tete.z,0,0,1);

	trace_cube();

	glFlush();
}

int main(int argc, char *argv[])
{
	init();
  	glutInit(&argc, argv);
  	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH),glutGet(GLUT_SCREEN_HEIGHT));
  	glutInitWindowPosition(0,0);
  	glutCreateWindow("Fenetre");
  	glEnable(GL_DEPTH_TEST);
	//glutSetCursor(GLUT_CURSOR_NONE);
  	glutDisplayFunc(affichage);
	glutIdleFunc(Animer);
	glutKeyboardFunc(GererClavier);
	glutPassiveMotionFunc(processMousePassiveMotion);

  	glutMainLoop();
  	return 0;
}
