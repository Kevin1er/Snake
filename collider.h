#include "objet.h"

#define TYPE_SOL 0
#define TYPE_MUR 1
#define TYPE_SERPENT 2
#define TYPE_OBJET 3
#define TYPE_MORT 4


/**
*Structure qui gère un collider
**/
typedef struct collider collider;
struct collider
{
    cube volume;
    int type;
};

/**
*Structure qui gère un groupe de collider
**/
typedef struct colliderSysteme colliderSysteme;
struct colliderSysteme
{
    int taille;
    collider tabCollider[];
};

void colliderSystemeInit();
void colliderSystemeAdd(collider * _collider);
void colliderInit(colliderSysteme * _systeme, cube * _obj, int _type);
