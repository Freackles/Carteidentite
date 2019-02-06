#include <stdio.h>
#include <stdlib.h>
#include "identite.h"


int main()
{
    printf("Programme Carte d'identit�\n");

    int nI=1;
    FILE *pFile;
    int nTemp=0;

    //Test du nombre de carte d�j� pr�sent dans le fichier
    nbcarteexistant(pFile, &nI);

    do
    {
        printf("1: Saisir de carte d'itentit�\n");
        printf("2: Lecture des donn�es saisi\n");
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
