#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "identite.h"

#define MAXTAILLE 300

/** \brief
 *
 * \param FILE *pFile - pointeur de fichier
 * \param int nI - ID à incrémenté
 * \return file
 *
 */
void EcritureIdentite (FILE *pFile, int nI)
{
    tIdentite* pID=NULL;

    if((pID=malloc(sizeof(tIdentite)))==NULL)
    {
        perror("Erreur d'allocation dynamique");
        exit(0);
    }
    else
    {
        printf("Nom: \n");
        gets(pID->sNom);
        fflush(stdin);

        printf("Prenom: \n");
        gets(pID->sPrenom);
        fflush(stdin);

        printf("Adresse: \n");
        gets(pID->sAdresse);
        fflush(stdin);

        printf("Code postal: \n");
        gets(pID->sCP);
        fflush(stdin);

        printf("Ville: \n");
        gets(pID->sVille);
        fflush(stdin);
    }

     if ((pFile=fopen("identite.txt", "a"))==NULL)
      {
        perror("Erreur de creation de fichier\n");

      }
      else
      {
        fprintf(pFile,"\n Carte n° %d", nI);
        fputc('\n', pFile);
        fputs(pID->sNom, pFile);
        fputc('\n', pFile);
        fputs(pID->sPrenom, pFile);
        fputc('\n', pFile);
        fputs(pID->sAdresse, pFile);
        fputc('\n', pFile);
        fputs(pID->sCP, pFile);
        fputc('\n', pFile);
        fputs(pID->sVille, pFile);
        fputc('\n', pFile);
        fclose(pFile);
      }
    free(pID);
}

/** \brief lecture du fichier
 *
 * \param FILE *pfile - pointeur fichier
 * \return affichage à l'écran du contenue du fichier
 *
 */

void LectureIdentite(FILE *pFile)
{
    char sTemp[MAXTAILLE];
    char sTemp2[MAXTAILLE];

    if ((pFile = fopen("identite.txt","r"))== NULL)
    {
        perror("Erreur de creation de fichier\n");
    }
    else
    {
        while(fgets(sTemp,MAXTAILLE,pFile)!=NULL)
        {
            strcat(sTemp2,sTemp);
        }
    }

    fclose(pFile);

    printf("%s\n",sTemp2);

}

/** \brief verification dans le fichier du combre de carte déjà présent
 *
 * \param  File *pFile
 * \param  int nI
 * \return le nombre de carte contenue dans le fichier (nI)
 *
 */

void nbcarteexistant (FILE *pFile, int *nI)
{

    int nTemp=0;
    char cChara;

    if ((pFile=fopen("identite.txt", "r"))==NULL)
    {
        *nI=1;
    }
    else
    {
        rewind(pFile);
        while((cChara = fgetc(pFile)) !=  EOF)
        {
            if(cChara == '\n')
            {
                nTemp ++;
            }
        }
        fclose(pFile);
        *nI=nTemp/7;
    }

}
