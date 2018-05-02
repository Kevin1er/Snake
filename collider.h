#ifndef COLLIDER_H
#define COLLIDER_H

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
    cube * volume;
    int type;
};

/**
*Structure qui gère un groupe de collider
**/
typedef struct colliderSysteme colliderSysteme;
struct colliderSysteme
{
    int taille;
    int nbCollider;
    collider ** tabCollider;
};

colliderSysteme colliderSystemeInit();
void colliderSystemeAdd(colliderSysteme * _systeme, collider * _collider);
collider colliderInit(colliderSysteme * _systeme, cube * _obj, int _type);

#endif
