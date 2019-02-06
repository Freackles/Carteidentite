#include <stdio.h>
#include <stdlib.h>
#include "identite.h"


int main()
{
    printf("Programme Carte d'identité\n");

    int nI=1;
    FILE *pFile;
    int nTemp=0;

    //Test du nombre de carte déjà présent dans le fichier
    nbcarteexistant(pFile, &nI);

    do
    {
        printf("1: Saisir de carte d'itentité\n");
        printf("2: Lecture des données saisi\n");
        printf("3: Quitter\n");
        scanf("%d",&nTemp);
        fflush(stdin);

        switch(nTemp)
        {
            case 1:
                EcritureIdentite(pFile, nI);
                nI++;
            break;

            case 2:
                system("cls");
                LectureIdentite(pFile);
                getchar();
            break;
        }
        system("cls");
    }while(nTemp!=3);

    return 0;
}
