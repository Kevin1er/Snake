#include <GL/gl.h>
#include <GL/glut.h>
#include "vecteur.h"

typedef struct mat4x4 mat4x4;
struct mat4x4
{
    GLfloat x[4];
    GLfloat y[4];
    GLfloat z[4];
    GLfloat w[4];
};

vector4D translation(vector4D _obj, vector4D _vector);
vector4D deplacement(vector4D _obj, vector4D _point);
vector4D rotation(vector4D _obj, GLfloat _angle, vector4D _vector);
vector4D rotationZ(vector4D _obj, GLfloat _angle, vector4D _centre);
vector4D matMult(mat4x4 _matrice, vector4D _vector);
