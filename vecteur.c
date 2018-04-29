#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "vecteur.h"

/**
*Fonction d'initialisation d'un vecteur 4D avec des valeurs données.
**/
vector4D vector4dInit(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w)
{
    vector4D result;
    result.x = _x;
    result.y = _y;
    result.z = _z;
    result.w = _w;

    return result;
}

/**
*Fonction qui normalise un vecteur 4D donné.
**/
vector4D vector4dGetNormalise(vector4D _vector)
{
    vector4D result;
    result.x = _vector.x / (sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2)));
    result.y = _vector.y / (sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2)));
    result.z = _vector.z / (sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2)));
    result.w = 1.0;

    return result;
}

/**
*Fonction qui retourne la norme d'un vecteur 4d
**/
GLfloat vector4dGetNorme(vector4D _vector)
{
    return sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2));
}

/**
*Fonction qui retourne le produit vectoriel de deux vecteurs 4
**/
vector4D vector4dGetVectoriel(vector4D _vector, vector4D _vector2)
{
    vector4D result;
    result.x = (_vector.y * _vector2.z) - (_vector.z * _vector2.y);
    result.y = (_vector.z * _vector2.x) - (_vector.x * _vector2.z);
    result.z = (_vector.x * _vector2.y) - (_vector.y * _vector2.x);
    result.z = 1.0;

    return result;
}

/**
*Fonction qui retourne le produit scalaire de deux vecteurs 4
**/
GLfloat vector4dGetScalaire(vector4D _vector, vector4D _vector2)
{
    return (_vector.x * _vector2.x) + (_vector.y * _vector2.y) + (_vector.z * _vector2.z);
}

/**
*Fonction qui retourne l'opposé d'un vector
**/
vector4D vector4dGetOppose(vector4D _vecteur)
{
    return vector4dInit(-_vecteur.x,-_vecteur.y,-_vecteur.z,_vecteur.w);
}

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
vector3D vector3dGetNormalise(vector3D _vector)
{
    vector3D result;
    result.x  = _vector.x / (sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2)));
    result.y  = _vector.y / (sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2)));
    result.z  = _vector.z / (sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2)));

    return result;
}

/**
*Fonction qui retourne la norme d'un vecteur 3d
**/
GLfloat vector3dGetNorme(vector3D _vector)
{
    return sqrt(pow(_vector.x,2) + pow(_vector.y,2) + pow(_vector.z,2));
}

/**
*Fonction qui retourne le produit vectoriel de deux vecteurs
**/
vector3D vector3dGetVectoriel(vector3D _vector, vector3D _vector2)
{
    vector3D result;
    result.x = (_vector.y * _vector2.z) - (_vector.z * _vector2.y);
    result.y = (_vector.z * _vector2.x) - (_vector.x * _vector2.z);
    result.z = (_vector.x * _vector2.y) - (_vector.y * _vector2.x);

    return result;
}

/**
*Fonction qui retourne le produit scalaire de deux vecteurs
**/
GLfloat vector3dGetScalaire(vector3D _vector, vector3D _vector2)
{
    return (_vector.x * _vector2.x) + (_vector.y * _vector2.y) + (_vector.z * _vector2.z);
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
