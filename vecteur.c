#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "vecteur.h"

/**
*Fonction d'initialisation d'un vecteur 3D avec des valeurs données.
**/
vector3D vector3dInit(GLfloat _x, GLfloat _y, GLfloat _z)
{
    vector3D result;
    result.x = _x;
    result.y = _y;
    result.z = _z;

    return result;
}

/**
*Fonction qui normalise un vecteur 3D donné.
**/
vector3D vector3dGetNorme(vector3D _vector)
{
    vector3D result;
    result.x  = _vector.x / (sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2)));
    result.y  = _vector.y / (sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2)));
    result.z  = _vector.z / (sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2)));

    return result;
}

/**
*Fonction d'initialisation d'un vecteur 2D avec des valeurs données.
**/
vector2D vector2dInit(GLfloat _x, GLfloat _y)
{
    vector2D result;
    result.x = _x;
    result.y = _y;

    return result;
}

/**
*Fonction qui normalise un vecteur 2D donné.
**/
vector2D vector2dGetNorme(vector2D _vector)
{
    vector2D result;
    result.x  = _vector.x / (sqrt(pow(_vector.x,2) + pow(_vector.y,2)));
    result.y  = _vector.y / (sqrt(pow(_vector.x,2) + pow(_vector.y,2)));

    return result;
}
