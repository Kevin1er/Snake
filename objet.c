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
* Fonction qui initialise un cube.
*/
cube initCube(vector4D _centre, GLfloat _demiLongueur)
{
    cube result;

    result.centre = _centre;

    result.ptA = vector4dInit((_centre.x - _demiLongueur), (_centre.y + _demiLongueur), (_centre.z - _demiLongueur), 1.0);
    result.ptB = vector4dInit((_centre.x - _demiLongueur), (_centre.y + _demiLongueur), (_centre.z + _demiLongueur), 1.0);
    result.ptC = vector4dInit((_centre.x + _demiLongueur), (_centre.y + _demiLongueur), (_centre.z + _demiLongueur), 1.0);
    result.ptD = vector4dInit((_centre.x + _demiLongueur), (_centre.y + _demiLongueur), (_centre.z - _demiLongueur), 1.0);
    result.ptE = vector4dInit((_centre.x - _demiLongueur), (_centre.y - _demiLongueur), (_centre.z - _demiLongueur), 1.0);
    result.ptF = vector4dInit((_centre.x - _demiLongueur), (_centre.y - _demiLongueur), (_centre.z + _demiLongueur), 1.0);
    result.ptG = vector4dInit((_centre.x + _demiLongueur), (_centre.y - _demiLongueur), (_centre.z + _demiLongueur), 1.0);
    result.ptH = vector4dInit((_centre.x + _demiLongueur), (_centre.y - _demiLongueur), (_centre.z - _demiLongueur), 1.0);

    return result;
}


/*
* Fonction qui affiche un cube.
*/
void afficherCube(cube _cube)
{
    faceQuad fHaut,fBas,fAvant,fArriere,fGauche,fDroite;

    fHaut.couleur = vector3dInit(1.0,0.0,1.0);
    fHaut.ptA = _cube.ptB;
    fHaut.ptB = _cube.ptF;
    fHaut.ptC = _cube.ptG;
    fHaut.ptD = _cube.ptC;

    fBas.couleur = vector3dInit(1.0,0.0,1.0);
    fBas.ptA = _cube.ptA;
    fBas.ptB = _cube.ptE;
    fBas.ptC = _cube.ptH;
    fBas.ptD = _cube.ptD;

    fAvant.couleur = vector3dInit(0.0,1.0,0.0);
    fAvant.ptA = _cube.ptA;
    fAvant.ptB = _cube.ptB;
    fAvant.ptC = _cube.ptC;
    fAvant.ptD = _cube.ptD;

    fArriere.couleur = vector3dInit(0.0,1.0,0.0);
    fArriere.ptA = _cube.ptE;
    fArriere.ptB = _cube.ptF;
    fArriere.ptC = _cube.ptG;
    fArriere.ptD = _cube.ptH;

    fGauche.couleur = vector3dInit(0.0,0.0,1.0);
    fGauche.ptA = _cube.ptA;
    fGauche.ptB = _cube.ptB;
    fGauche.ptC = _cube.ptF;
    fGauche.ptD = _cube.ptE;

    fDroite.couleur = vector3dInit(0.0,0.0,1.0);
    fDroite.ptA = _cube.ptD;
    fDroite.ptB = _cube.ptC;
    fDroite.ptC = _cube.ptG;
    fDroite.ptD = _cube.ptH;

    afficherFaceQuad(fHaut);
    afficherFaceQuad(fBas);
    afficherFaceQuad(fAvant);
    afficherFaceQuad(fArriere);
    afficherFaceQuad(fGauche);
    afficherFaceQuad(fDroite);
}

/*
* Fonction qui effectue une rotation sur un cube (autour de lui-même).
*/
void rotationCube(cube* _cube, GLfloat _angle)
{
    //vector4D ptBas = vector4dInit((_cube->ptH.x - _cube->ptA.x)/2,(_cube->ptH.y - _cube->ptA.y)/2,(_cube->ptH.z - _cube->ptA.z)/2,1.0);
    //vector4D ptHaut = vector4dInit((_cube->ptG.x - _cube->ptB.x)/2,(_cube->ptG.y - _cube->ptB.y)/2,(_cube->ptG.z - _cube->ptB.z)/2,1.0);

    //vector4D axe = vector4dInit(ptBas.x - ptHaut.x, ptBas.y - ptHaut.y, ptBas.z - ptHaut.z,1.0);

    _cube->ptA = rotationZ(_cube->ptA, _angle/*, axe*/);
    _cube->ptB = rotationZ(_cube->ptB, _angle/*, axe*/);
    _cube->ptC = rotationZ(_cube->ptC, _angle/*, axe*/);
    _cube->ptD = rotationZ(_cube->ptD, _angle/*, axe*/);
    _cube->ptE = rotationZ(_cube->ptE, _angle/*, axe*/);
    _cube->ptF = rotationZ(_cube->ptF, _angle/*, axe*/);
    _cube->ptG = rotationZ(_cube->ptG, _angle/*, axe*/);
    _cube->ptH = rotationZ(_cube->ptH, _angle/*, axe*/);
}

/*
* Fonction qui effectue une translation sur un cube.
*/
void translationCube(cube* _cube, vector4D _vector)
{
    _cube->centre = translation(_cube->centre, _vector);

    _cube->ptA = translation(_cube->ptA, _vector);
    _cube->ptB = translation(_cube->ptB, _vector);
    _cube->ptC = translation(_cube->ptC, _vector);
    _cube->ptD = translation(_cube->ptD, _vector);
    _cube->ptE = translation(_cube->ptE, _vector);
    _cube->ptF = translation(_cube->ptF, _vector);
    _cube->ptG = translation(_cube->ptG, _vector);
    _cube->ptH = translation(_cube->ptH, _vector);
}
