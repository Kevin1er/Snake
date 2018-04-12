#include "transform.h"

typedef struct faceQuad faceQuad;
struct faceQuad
{
    vector4D ptA, ptB, ptC, ptD;
    vector3D couleur;
};

typedef struct cube cube;
struct cube
{
    faceQuad fHaut, fBas, fAvant, fArriere, fGauche, fDroite;
};

void afficherFaceQuad(faceQuad _face);
void afficherCube(cube _cube);
void rotationCube(cube* _cube, GLfloat _angle);
void translationCube(cube* _cube, vector4D _vector);
