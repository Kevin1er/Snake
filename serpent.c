#include <stdio.h>
#include "serpent.h"


/**
*Fonction d'initialisation d'un serpent
**/
serpent serpentInit(vector4D _position, GLfloat _taille)
{
    int itFor;
    GLfloat distance = 2*_taille;
    serpent result;
    result.taille = 0;

    result.tete = initCube(_position, _taille);

    for(itFor = 0; itFor < TAILLE_MIN; itFor++)
    {
        result.corps[itFor] = initCube(vector4dInit(_position.x + (distance), _position.y, _position.z, _position.w), _taille);
        result.taille++;
        distance += 2*_taille;
    }

    return result;
}

/**
*Fonction d'ajout' d'éléments au coprs d'un serpent
**/
void serpentAddCorps(serpent * _serpent, int _nombre, GLfloat _taille)
{
    int itFor;
    GLfloat distance = 2*_taille;

    if(_serpent->taille + _nombre > TAILLE_MAX)
    {
        for(itFor = _serpent->taille; itFor < TAILLE_MAX; itFor++)
        {
            _serpent->corps[itFor] = initCube(vector4dInit(_serpent->corps[itFor-1].centre.x + (distance), _serpent->corps[itFor-1].centre.y, _serpent->corps[itFor-1].centre.z, _serpent->corps[itFor-1].centre.w), _taille);
            _serpent->taille++;
            distance += 2*_taille;
        }
    }
    else
    {
        for(itFor = 0; itFor < _nombre; itFor++)
        {
            _serpent->corps[_serpent->taille] = initCube(vector4dInit(
                _serpent->corps[_serpent->taille-1].centre.x + (distance),
                _serpent->corps[_serpent->taille-1].centre.y,
                _serpent->corps[_serpent->taille-1].centre.z,
                _serpent->corps[_serpent->taille-1].centre.w), _taille);
            _serpent->taille++;
            distance += 2*_taille;
        }
        //printf("Total : %i\n", _serpent->taille);
    }
}

/**
*Fonction de supression d'éléments du coprs d'un serpent
**/
void serpentRemoveCorps(serpent * _serpent, int _nombre)
{
    if(_serpent->taille - _nombre < TAILLE_MIN) _serpent->taille = TAILLE_MIN;
    else _serpent->taille -= _nombre;
}

/**
*Fonction d'affichage d'un serpent
**/
void serpentAfficher(serpent _serpent)
{
    int itFor;

    afficherCube(_serpent.tete);

    for(itFor = 0; itFor < _serpent.taille; itFor++)
    {
        afficherCube(_serpent.corps[itFor]);
    }
}

/**
*Fonction de déplacement d'un serpent
**/
void serpentDeplacement(serpent * _serpent)
{
    int itFor;

    for(itFor = _serpent->taille-1; itFor > 0; itFor--)
    {
        _serpent->corps[itFor] = _serpent->corps[itFor-1];
    }

    _serpent->corps[0] = _serpent->tete;
}
