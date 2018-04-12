#include <GL/gl.h>
#include <GL/glut.h>
#include "objet.h"

/*
* Fonction qui affiche une face.
*/
void afficherFaceQuad(faceQuad _face)
{
    glBegin(GL_QUADS);

	//Couleur
	glColor3f(_face.couleur.x,_face.couleur.y,_face.couleur.z);

    //Points
	glVertex3f(_face.ptA.x,_face.ptA.y,_face.ptA.z);
	glVertex3f(_face.ptB.x,_face.ptB.y,_face.ptB.z);
	glVertex3f(_face.ptC.x,_face.ptC.y,_face.ptC.z);
	glVertex3f(_face.ptD.x,_face.ptD.y,_face.ptD.z);

	glEnd();
}

/*
* Fonction qui affiche un cube.
*/
void afficherCube(cube _cube)
{
    afficherFaceQuad(_cube.fHaut);
    afficherFaceQuad(_cube.fBas);
    afficherFaceQuad(_cube.fAvant);
    afficherFaceQuad(_cube.fArriere);
    afficherFaceQuad(_cube.fGauche);
    afficherFaceQuad(_cube.fDroite);
}

/*
* Fonction qui effectue une rotation sur un cube (autour de lui-même).
*/
void rotationCube(cube* _cube, GLfloat _angle)
{
    vector4D axe = vector4dInit(_cube->fBas.ptA.x - _cube->fBas.ptC.x,_cube->fBas.ptA.y - _cube->fBas.ptC.y,1.0,1.0);

    _cube->fHaut.ptA = rotation(_cube->fHaut.ptA, _angle, axe);
    _cube->fHaut.ptB = rotation(_cube->fHaut.ptB, _angle, axe);
    _cube->fHaut.ptC = rotation(_cube->fHaut.ptC, _angle, axe);
    _cube->fHaut.ptD = rotation(_cube->fHaut.ptD, _angle, axe);
    _cube->fBas.ptA = rotation(_cube->fBas.ptA, _angle, axe);
    _cube->fBas.ptB = rotation(_cube->fBas.ptB, _angle, axe);
    _cube->fBas.ptC = rotation(_cube->fBas.ptC, _angle, axe);
    _cube->fBas.ptD = rotation(_cube->fBas.ptD, _angle, axe);
}

/*
* Fonction qui effectue une translation sur un cube.
*/
void translationCube(cube* _cube, vector4D _vector)
{
    _cube->fHaut.ptA = translation(_cube->fHaut.ptA, _vector);
    _cube->fHaut.ptB = translation(_cube->fHaut.ptB, _vector);
    _cube->fHaut.ptC = translation(_cube->fHaut.ptC, _vector);
    _cube->fHaut.ptD = translation(_cube->fHaut.ptD, _vector);
    _cube->fBas.ptA = translation(_cube->fBas.ptA, _vector);
    _cube->fBas.ptB = translation(_cube->fBas.ptB, _vector);
    _cube->fBas.ptC = translation(_cube->fBas.ptC, _vector);
    _cube->fBas.ptD = translation(_cube->fBas.ptD, _vector);
}
