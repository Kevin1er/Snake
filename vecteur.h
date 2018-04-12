#include <GL/gl.h>
#include <GL/glut.h>

typedef struct vector4D vector4D;
struct vector4D
{
    GLfloat x, y, z, w;
};

typedef struct vector3D vector3D;
struct vector3D
{
    GLfloat x, y, z;
};

typedef struct vector2D vector2D;
struct vector2D
{
    GLfloat x, y;
};

vector4D vector4dInit(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w);
vector4D vector4dGetNormalise(vector4D _vector);
GLfloat vector4dGetNorme(vector4D _vector);
vector4D vector4dGetVectoriel(vector4D _vector, vector4D _vector2);
GLfloat vector4dGetScalaire(vector4D _vector, vector4D _vector2);

vector3D vector3dInit(GLfloat _x, GLfloat _y, GLfloat _z);
vector3D vector3dGetNormalise(vector3D _vector);
GLfloat vector3dGetNorme(vector3D _vector);
vector3D vector3dGetVectoriel(vector3D _vector, vector3D _vector2);
GLfloat vector3dGetScalaire(vector3D _vector, vector3D _vector2);

vector2D vector2dInit(GLfloat _x, GLfloat _y);
vector2D vector2dGetNorme(vector2D _vector);
