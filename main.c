#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "objet.h"

#define SIZE_CUBE 0.5
#define PI 3.14
#define TRUE 1
#define FALSE 0

GLfloat recul, angle;
vector4D tete, camera;
vector4D rotCamera, oldRotCamera;

cube teteSnake;
cube* cubeTete = &teteSnake;

faceQuad sol;

int bAvant, bGauche, bDroite;

/*
* Fonction d'initialisation du serpent.
*/
void initSnake()
{
	teteSnake = initCube(tete, 0.5);
}

void init()
{
	bAvant = bGauche = bDroite = FALSE;

	sol.ptA = vector4dInit(0.0,0.0,0.0,1.0);
	sol.ptB = vector4dInit(0.0,1000.0,0.0,1.0);
	sol.ptC = vector4dInit(1000.0,1000.0,0.0,1.0);
	sol.ptD = vector4dInit(1000.0,0.0,0.0,1.0);

	printf("aaa\n");
	initSnake();
	printf("bbb\n");


	recul = 10.0;
	rotCamera = vector4dInit(0.0,0.0,1.0,1.0);
	angle = 0.0;

	sol.couleur = vector3dInit(1.0,0.0,0.0);
}

void actionsClavier()
{
	if(bAvant == TRUE)
	{
		/*vector2D vecCamera = vector2dInit((tete.x - camera.x), (tete.y - camera.y));
		vector2D vecCameraNorm = vector2dGetNorme(vecCamera);
		tete.x += .1 * vecCameraNorm.x;
		tete.y += .1 * vecCameraNorm.y;*/
		vector4D vecTranslation = vector4dGetNormalise(vector4dInit(cubeTete->ptE.x-cubeTete->ptA.x, cubeTete->ptE.y-cubeTete->ptA.y, cubeTete->ptE.z-cubeTete->ptA.z, 1.0));
		translationCube(cubeTete, vecTranslation);
	}
	if(bGauche == TRUE)
	{
		angle += 1.0;
	}
	if(bDroite == TRUE)
	{
		angle -= 1.0;
	}
}

void Animer()
{
	actionsClavier();
	rotationCube(cubeTete, angle);
	angle = 0.0;

	glutPostRedisplay();
}

/**
*Fonction qui gère l'appuie sur une touche
**/
void GererClavier(unsigned char _touche, int _x, int _y)
{
	if(_touche == 'z'){ bAvant = TRUE; }
	if(_touche == 'q'){ bGauche = TRUE; }
	if(_touche == 'd'){ bDroite = TRUE; }
}

/**
*Fonction qui gère le relachement d'une touche
**/
void GererClavierUp(unsigned char _touche, int _x, int _y)
{
	if(_touche == 'z'){ bAvant = FALSE; }
	if(_touche == 'q'){ bGauche = FALSE; }
	if(_touche == 'd'){ bDroite = FALSE; }
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

void trace_map()
{
	afficherFaceQuad(sol);
}

void affichage()
{
	printf("CentreX : %f\nCentreY : %f\nCentreZ : %f\n", teteSnake.centre.x, teteSnake.centre.y, teteSnake.centre.z);

	camera.x = teteSnake.centre.x + (recul * cos(rotCamera.x*(PI/180)) * cos(rotCamera.y*(PI/180)));
	camera.y = teteSnake.centre.y + (recul * -(sin(rotCamera.x*(PI/180))) * cos(rotCamera.y*(PI/180)));
	camera.z = teteSnake.centre.z + (recul * (sin(rotCamera.y*(PI/180))));

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-4.8,4.8,-2.7,2.7,2,500);
	gluLookAt(camera.x, camera.y, camera.z, teteSnake.centre.x, teteSnake.centre.y, teteSnake.centre.z,0,0,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	trace_map();
	//trace_cube();

	afficherCube(*cubeTete);
	glutSwapBuffers();

	glFlush();
}

int main(int argc, char *argv[])
{
	init();
	printf("finInit\n");
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
	glutKeyboardUpFunc(GererClavierUp);
	glutPassiveMotionFunc(processMousePassiveMotion);

  	glutMainLoop();
  	return 0;
}
