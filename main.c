#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "objet.h"

#define SIZE_CUBE 0.5
#define PI 3.14

GLfloat recul, angle;
vector4D tete, camera;
vector4D rotCamera, oldRotCamera;

cube teteSnake;
cube* cubeTete = &teteSnake;

faceQuad sol;

/*
* Fonction d'initialisation du serpent.
*/
void initSnake()
{
	/*
	vector4D ptA, ptB, ptC, ptD, ptE,ptF,ptG, ptH;

	faceQuad fHaut, fBas, fAvant, fArriere, fGauche, fDroite;

	ptA = vector4dInit(0.0,0.0,0.0,1.0);
	ptB = vector4dInit(0.0,0.0,1.0,1.0);
	ptC = vector4dInit(1.0,0.0,1.0,1.0);
	ptD = vector4dInit(1.0,0.0,0.0,1.0);
	ptE = vector4dInit(0.0,1.0,0.0,1.0);
	ptF = vector4dInit(0.0,1.0,1.0,1.0);
	ptG = vector4dInit(1.0,1.0,1.0,1.0);
	ptH = vector4dInit(1.0,1.0,0.0,1.0);


	fHaut.couleur = vector3dInit(1.0,0.0,1.0);
	fHaut.ptA = ptB;
	fHaut.ptB = ptF;
	fHaut.ptC = ptG;
	fHaut.ptD = ptC;

	fBas.couleur = vector3dInit(1.0,0.0,1.0);
	fBas.ptA = ptA;
	fBas.ptB = ptE;
	fBas.ptC = ptH;
	fBas.ptD = ptD;

	fAvant.couleur = vector3dInit(0.0,1.0,0.0);
	fAvant.ptA = ptA;
	fAvant.ptB = ptB;
	fAvant.ptC = ptC;
	fAvant.ptD = ptD;

	fArriere.couleur = vector3dInit(0.0,1.0,0.0);
	fArriere.ptA = ptE;
	fArriere.ptB = ptF;
	fArriere.ptC = ptG;
	fArriere.ptD = ptH;

	fGauche.couleur = vector3dInit(0.0,0.0,1.0);
	fGauche.ptA = ptE;
	fGauche.ptB = ptF;
	fGauche.ptC = ptB;
	fGauche.ptD = ptA;

	fDroite.couleur = vector3dInit(0.0,0.0,1.0);
	fDroite.ptA = ptD;
	fDroite.ptB = ptC;
	fDroite.ptC = ptG;
	fDroite.ptD = ptH;

	printf("vvv\n");

	cubeTete->fHaut = fHaut;
	cubeTete->fBas = fBas;
	cubeTete->fAvant = fAvant;
	cubeTete->fArriere = fArriere;
	cubeTete->fGauche = fGauche;
	cubeTete->fDroite = fDroite;
	*/

	teteSnake = initCube(tete, 0.5);

}

void init()
{
	sol.ptA = vector4dInit(0.0,0.0,0.0,1.0);
	sol.ptB = vector4dInit(0.0,10.0,0.0,1.0);
	sol.ptC = vector4dInit(10.0,10.0,0.0,1.0);
	sol.ptD = vector4dInit(10.0,0.0,0.0,1.0);

	printf("aaa\n");
	initSnake();
	printf("bbb\n");

	tete = vector4dInit(0.5,0.5,0.5,1.0);
	recul = 10.0;
	rotCamera = vector4dInit(0.0,0.0,1.0,1.0);
	angle = 0.0;

	sol.couleur = vector3dInit(1.0,0.0,0.0);
}

void Animer()
{
	rotationCube(cubeTete, angle);

	glutPostRedisplay();
}

void GererClavier(unsigned char _touche, int _x, int _y)
{
	if(_touche == 'z')
	{
		/*vector2D vecCamera = vector2dInit((tete.x - camera.x), (tete.y - camera.y));
		vector2D vecCameraNorm = vector2dGetNorme(vecCamera);
		tete.x += .1 * vecCameraNorm.x;
		tete.y += .1 * vecCameraNorm.y;*/
		translationCube(cubeTete, vector4dInit(1.0,0.0,0.0,1.0));
	}
	if(_touche == 'q')
	{
		angle -= 1.0;
		//printf("X : %f\nY: %f\nZ: %f\n\n", sol.ptB.x, sol.ptB.y, sol.ptB.z);
	}
	if(_touche == 'd')
	{
		angle += 1.0;
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

void trace_map()
{
	afficherFaceQuad(sol);
}

void trace_cube()
{
	//glPushMatrix();
	//glTranslatef(tete.x,tete.y,tete.z);
	//glRotatef(angle, 0,0,1);
	//glTranslatef(-tete.x,-tete.y,-tete.z);

	glBegin(GL_QUADS);

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

	//glPopMatrix();
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
	glutPassiveMotionFunc(processMousePassiveMotion);

  	glutMainLoop();
  	return 0;
}
