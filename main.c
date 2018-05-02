#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "serpent.h"
#include "collider.h"

#define SIZE_CUBE 0.5
#define PI 3.14
#define TRUE 1
#define FALSE 0

GLfloat recul, angle;
vector4D camera;
vector4D rotCamera, oldRotCamera;

//cube teteSnake;
//cube* cubeTete = &teteSnake;

//cube corps;
//cube* corpsSnake = &corps;

serpent test;
serpent* serpentTest = &test;

faceQuad sol;

colliderSysteme colliderSystemeTest;

int bAvant, bGauche, bDroite, countTest;

/*
* Fonction d'initialisation du serpent.
*/
void initSnake()
{
	//teteSnake = initCube(vector4dInit(0.0,0.0,0.5,1.0), 0.5);
	//corps = initCube(vector4dInit(1.0,0.0,0.5,1.0), 0.5);

	test = serpentInit(vector4dInit(0.0,0.0,0.5,1.0), 0.5);
	serpentAddCorps(serpentTest,50,0.5);
}

void init()
{
	/*
	*Zone tests
	*/
		countTest = 0;

		colliderSystemeTest = colliderSystemeInit();
		collider colliderTest = colliderInit(&colliderSystemeTest, &serpentTest->tete, 2);

		//cube cubeTest =
		printf("TEST COLLIDER TYPE : %i\n", colliderSystemeTest.tabCollider[0]->type);
		printf("TEST COLLIDER VOLUME : %f\n", colliderSystemeTest.tabCollider[0]->volume->ptA.x);
	/*
	*Fin zone tests
	*/


	bAvant = bGauche = bDroite = FALSE;

	sol.ptA = vector4dInit(0.0,0.0,0.0,1.0);
	sol.ptB = vector4dInit(0.0,1000.0,0.0,1.0);
	sol.ptC = vector4dInit(1000.0,1000.0,0.0,1.0);
	sol.ptD = vector4dInit(1000.0,0.0,0.0,1.0);

	initSnake();


	recul = 15.0;
	rotCamera = vector4dInit(0.0,0.0,1.0,1.0);
	angle = 0.0;

	sol.couleur = vector3dInit(1.0,0.0,0.0);
}

void actionsClavier()
{
	if(bAvant == TRUE)
	{
		if(bGauche == TRUE)
		{
			angle += 10.0;
		}
		if(bDroite == TRUE)
		{
			angle -= 10.0;
		}
		/*vector2D vecCamera = vector2dInit((tete.x - camera.x), (tete.y - camera.y));
		vector2D vecCameraNorm = vector2dGetNorme(vecCamera);
		tete.x += .1 * vecCameraNorm.x;
		tete.y += .1 * vecCameraNorm.y;*/
		//vector4D vecTranslation = vector4dGetNormalise(vector4dInit(cubeTete->ptE.x-cubeTete->ptA.x, cubeTete->ptE.y-cubeTete->ptA.y, cubeTete->ptE.z-cubeTete->ptA.z, 1.0));

		vector4D vecTranslation = vector4dGetNormalise(vector4dInit(serpentTest->tete.ptE.x-serpentTest->tete.ptA.x, serpentTest->tete.ptE.y-serpentTest->tete.ptA.y, serpentTest->tete.ptE.z-serpentTest->tete.ptA.z, 1.0));

		//vecTranslation.x *= 0.05;
		//vecTranslation.y *= 0.05;
		//vecTranslation.z *= 0.05;
		//translationCube(cubeTete, vecTranslation);

		serpentDeplacement(serpentTest);
		translationCube(&serpentTest->tete, vecTranslation);
	}
}

void Animer()
{
	/*
	*Zone tests
	*/

	if(++countTest >= 10)
	{
		actionsClavier();
		countTest = 0;
	}
	/*
	*Fin zone tests
	*/

	//actionsClavier();
	//rotationCube(cubeTete, angle);
	rotationCube(&serpentTest->tete, angle);
	angle = 0.0;

	printf("TEST COLLIDER VOLUME : %f\n", colliderSystemeTest.tabCollider[0]->volume->ptA.x);

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
	//printf("CentreX : %f\nCentreY : %f\nCentreZ : %f\n", teteSnake.centre.x, teteSnake.centre.y, teteSnake.centre.z);

	//camera.x = teteSnake.centre.x + (recul * cos(rotCamera.x*(PI/180)) * cos(rotCamera.y*(PI/180)));
	//camera.y = teteSnake.centre.y + (recul * -(sin(rotCamera.x*(PI/180))) * cos(rotCamera.y*(PI/180)));
	//camera.z = teteSnake.centre.z + (recul * (sin(rotCamera.y*(PI/180))));

	camera.x = test.tete.centre.x + (recul * cos(rotCamera.x*(PI/180)) * cos(rotCamera.y*(PI/180)));
	camera.y = test.tete.centre.y + (recul * -(sin(rotCamera.x*(PI/180))) * cos(rotCamera.y*(PI/180)));
	camera.z = test.tete.centre.z + (recul * (sin(rotCamera.y*(PI/180))));

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-4.8,4.8,-2.7,2.7,2,500);
	//gluLookAt(camera.x, camera.y, camera.z, teteSnake.centre.x, teteSnake.centre.y, teteSnake.centre.z,0,0,1);

	gluLookAt(camera.x, camera.y, camera.z, test.tete.centre.x, test.tete.centre.y, test.tete.centre.z,0,0,1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	trace_map();
	//trace_cube();

	//afficherCube(*cubeTete);
	//afficherCube(*corpsSnake);
	serpentAfficher(test);
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
