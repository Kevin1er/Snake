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
    vector4D centre;
    vector4D ptA, ptB, ptC, ptD, ptE, ptF, ptG, ptH;
};

cube initCube(vector4D _centre, GLfloat _demiLongueur);
void afficherFaceQuad(faceQuad _face);
void afficherCube(cube _cube);
void rotationCube(cube* _cube, GLfloat _angle);
void translationCube(cube* _cube, vector4D _vector);
