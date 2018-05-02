#ifndef SERPENT_H
#define SERPENT_H

#include "objet.h"

#define TAILLE_MAX 50
#define TAILLE_MIN 5

typedef struct serpent serpent;
struct serpent
{
    cube tete;
    cube corps[TAILLE_MAX];
    int taille;
};

serpent serpentInit(vector4D _position, GLfloat _taille);
void serpentAddCorps(serpent * _serpent, int _nombre, GLfloat _taille);
void serpentRemoveCorps(serpent * _serpent, int _nombre);
void serpentAfficher(serpent _serpent);
void serpentDeplacement(serpent * _serpent);

#endif
