/* Programme de  gestion d'un jeux de dames
 *
 * Authors :    Lucie Potiron
 *              Franck Guillaume
 *              Emmanuel Rochet
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include "dames.h"



void initJeu(struct damier * jeu, struct histo * historique)
{
    int cpt_b = 0, cpt_n = 0;

    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            if( (x+y)%2 == 1 && cpt_b <= jeu->nbre_blancs && (y < 4)){
                jeu->plateau[x][y] = 'b';
                cpt_b++;
            }
            else if ( (x+y)%2 == 1 && cpt_n <= jeu->nbre_noirs && (y >= 6) ){
                jeu->plateau[x][y] = 'n';
                cpt_n++;
            }
            else{
                jeu->plateau[x][y] = vide(x,y);
            }
        }
    }
}



void affichage(struct damier *jeu)
{
    for(int x = 0 ; x < 10 ; x++)
    {
        for(int y = 0 ; y < 10 ; y++)
        {
            if(jeu->plateau[x][y] == NULL)
            {
                printf("%hhu",vide(x,y));
            }
            else {
                printf("%hhu",jeu->plateau[x][y]);
            }
        }
        printf("\n");
    }
}

unsigned char vide(int x , int y)
{
    unsigned char ret;

    if((y+x)% 2 == 0)
    {
        ret = ' ' ;
    }
    else
    {
        ret = '#';
    }
    return ret;
}

void addHisto(int joueur,struct emplacement *depart,struct emplacement *arrivee, struct histo * dernierCoup,struct histo * nouveauCoup, struct pion * pionMange)
{
    //on empile notre coup
    nouveauCoup->precedent = dernierCoup;

    // on remplit notre historique
    nouveauCoup->depart = depart;
    nouveauCoup->arrivee = arrivee;
    nouveauCoup->pionMange = pionMange;
    nouveauCoup->joueur = joueur;
    nouveauCoup->coup = dernierCoup->coup + 1;

}

void afficherHisto(struct histo * h)
{
    if (h->suivant != NULL)
    {
        afficherHisto(h->suivant);
    }

    printf("le pion du joueur %d  a ete deplace de [%d,%d]en [%d,%d]",h->joueur,h->depart->x,h->depart->y,h->arrivee->x,h->arrivee->y);
}



void sauvegarde(struct histo * h, char* nomSauvegarde){

    printf("\nVeuillez entrer le nom de votre sauvegarde : ");
    scanf("%s",nomSauvegarde);

    FILE* f = fopen(nomSauvegarde,"w");

    while (h->coup != NULL){

    }


}