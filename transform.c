#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include "transform.h"

#define PI 3.14

/*
*   Fonction qui réalise une translation.
*/
vector4D translation(vector4D _obj, vector4D _vector)
{
    vector4D result;
    result.x = _obj.x + _vector.x;
    result.y = _obj.y + _vector.y;
    result.z = _obj.z + _vector.z;
    result.w = 1.0;

    return result;
}

/*
*   Fonction qui translate un objet vers un point
*/
vector4D deplacement(vector4D _obj, vector4D _point)
{
    vector4D vector = vector4dInit(_point.x-_obj.x, _point.y-_obj.y, _point.z-_obj.z,1.0);

    return translation(_obj, vector);
}

/*
*   Fonction qui réalise une rotation.
*/
vector4D rotation(vector4D _obj, GLfloat _angle, vector4D _vector)
{
    mat4x4 matRotation;
    matRotation.x[0] = _vector.x * _vector.x * (1 - cos(_angle*PI/180)) + cos(_angle*PI/180);
    matRotation.x[1] = _vector.y * _vector.x * (1 - cos(_angle*PI/180)) - _vector.z * sin(_angle*PI/180);
    matRotation.x[2] = _vector.x * _vector.z * (1 - cos(_angle*PI/180)) + _vector.y * sin(_angle*PI/180);
    matRotation.x[3] = 0.0;

    matRotation.y[0] = _vector.y * _vector.x * (1 - cos(_angle*PI/180)) + _vector.z * sin(_angle*PI/180);
    matRotation.y[1] = _vector.y * _vector.y * (1 - cos(_angle*PI/180)) + cos(_angle*PI/180);
    matRotation.y[2] = _vector.y * _vector.z * (1 - cos(_angle*PI/180)) - _vector.x * sin(_angle*PI/180);
    matRotation.y[3] = 0.0;

    matRotation.z[0] = _vector.x * _vector.z * (1 - cos(_angle*PI/180)) - _vector.y * sin(_angle*PI/180);
    matRotation.z[1] = _vector.y * _vector.z * (1 - cos(_angle*PI/180)) + _vector.x * sin(_angle*PI/180);
    matRotation.z[2] = _vector.z * _vector.z * (1 - cos(_angle*PI/180)) + cos(_angle*PI/180);
    matRotation.z[3] = 0.0;

    matRotation.w[0] = 0.0;
    matRotation.w[1] = 0.0;
    matRotation.w[2] = 0.0;
    matRotation.w[3] = 1.0;

    printf("Angle : %f\n", sin(_angle*PI/180));

    return matMult(matRotation, _obj);
}

/*
* Fonction de rotation d'un point autour de l'axe Z
*/
vector4D rotationZ(vector4D _obj, GLfloat _angle, vector4D _centre)
{
    mat4x4 matRotation;
    vector4D result, vecTranslation;

    vecTranslation = translation(_obj, vector4dInit(0.0-_centre.x, 0.0-_centre.y, 0.0-_centre.z, 1.0));

    matRotation.x[0] = cos(_angle*PI/180);
    matRotation.x[1] = - sin(_angle*PI/180);
    matRotation.x[2] = 0.0;
    matRotation.x[3] = 0.0;

    matRotation.y[0] = sin(_angle*PI/180);
    matRotation.y[1] = cos(_angle*PI/180);
    matRotation.y[2] = 0.0;
    matRotation.y[3] = 0.0;

    matRotation.z[0] = 0.0;
    matRotation.z[1] = 0.0;
    matRotation.z[2] = 1.0;
    matRotation.z[3] = 0.0;

    matRotation.w[0] = 0.0;
    matRotation.w[1] = 0.0;
    matRotation.w[2] = 0.0;
    matRotation.w[3] = 1.0;

    result = matMult(matRotation, vecTranslation);

    //printf("Angle : %f\n", sin(_angle*PI/180));

    return translation(result, _centre);
}

/*
*   Fonction qui multiplie une matrice 4x4 avec un vector 4.
*/
vector4D matMult(mat4x4 _matrice, vector4D _vector)
{
    vector4D result;
    result.x = (_matrice.x[0] * _vector.x) + (_matrice.x[1] * _vector.y) + (_matrice.x[2] * _vector.z) + (_matrice.x[3] * _vector.w);
    result.y = (_matrice.y[0] * _vector.x) + (_matrice.y[1] * _vector.y) + (_matrice.y[2] * _vector.z) + (_matrice.y[3] * _vector.w);
    result.z = (_matrice.z[0] * _vector.x) + (_matrice.z[1] * _vector.y) + (_matrice.z[2] * _vector.z) + (_matrice.z[3] * _vector.w);
    result.w = (_matrice.w[0] * _vector.x) + (_matrice.w[1] * _vector.y) + (_matrice.w[2] * _vector.z) + (_matrice.w[3] * _vector.w);

    return result;
}
