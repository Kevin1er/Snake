#include "collider.h"

#define ALLOC_MIN 10

/**
*Fonction d'initialisation d'un système de collider
**/
colliderSysteme colliderSystemeInit()
{
    colliderSysteme result;

    result.tabCollider = malloc(sizeof(collider) * ALLOC_MIN);
    result.taille = ALLOC_MIN;
    result.nbCollider = 0;

    return result;
}

/**
*Fonction d'ajout d'un collider à un ensemble de collider
**/
void colliderSystemeAdd(colliderSysteme * _systeme, collider * _collider)
{
    if(_systeme->nbCollider >= _systeme->taille)
    {
        _systeme->tabCollider = malloc(sizeof(collider) * ALLOC_MIN);
        _systeme->taille += ALLOC_MIN;
    }
    _systeme->tabCollider[_systeme->nbCollider] = _collider;
    _systeme->nbCollider++;
}

/**
*Fonction d'initialisation d'un collider;
**/
collider colliderInit(colliderSysteme * _systeme, cube * _obj, int _type)
{
    collider result;

    result.volume = _obj;
    result.type = _type;
    colliderSystemeAdd(_systeme, &result);

    return result;
}
