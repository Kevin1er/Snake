#include <GL/gl.h>
#include <GL/glut.h>

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

vector3D vector3dInit(GLfloat _x, GLfloat _y, GLfloat _z);
vector3D vector3dGetNorme(vector3D _vector);
vector2D vector2dInit(GLfloat _x, GLfloat _y);
vector2D vector2dGetNorme(vector2D _vector);
