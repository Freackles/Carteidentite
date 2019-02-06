#ifndef IDENTITE_H_INCLUDED
#define IDENTITE_H_INCLUDED
#pragma once

#define TAILLE 100

typedef struct tIdentite {
    int nID;
    char sNom[TAILLE];
    char sPrenom[TAILLE];
    char sAdresse[TAILLE];
    char sCP[TAILLE];
    char sVille[TAILLE];
}tIdentite;

//Prototype
extern void EcritureIdentite(FILE *pFile, int nI);
extern void LectureIdentite(FILE *pFile);
extern void nbcarteexistant (FILE *pFile, int *nI);


#endif // IDENTITE_H_INCLUDED
