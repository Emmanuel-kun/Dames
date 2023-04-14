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


void initJeu(struct damier * jeu)
{
    int cpt_b = 0, cpt_n = 0;

    for(int x = 0; x < 10; x++)
    {
        for(int y = 1; y < 10; y++)
        {
            if( (x+y)%2 == 1 && cpt_b <= jeu->nb_blancs && (x < 4)){
                jeu->plateau[x][y] = 'b';
                cpt_b++;
            }
            else if ( (x+y)%2 == 1 && cpt_n <= jeu->nb_noirs && (x >= 6) ){
                jeu->plateau[x][y] = 'n';
                cpt_n++;
            }
            else{
                jeu->plateau[x][y] = vide(x,y);
            }
        }
    }
}

//AFFICHAGE
void affichage(struct damier *jeu)
{
    int x = 0;
    int y = 0;
    unsigned char val[21][21];

    for(x = 0 ; x < 21 ; x++)
    {
        for(y = 0 ; y < 21 ; y++) {
            if ((x == 0 && y == 0) || x == 0 && y == 20 || x == 20 && y == 20 || x ==20  && y == 0){
                val[x][y] = 'o';
                printf(" %c ", val[x][y]);
            }
            /*else if (x == 0 && y>0 && y<20)
                {
                    val[x][y]='-';
                    printf(" %c ",val[x][y]);
                }
            else if (y == 0 && x> 0 && x< 20)
            {
                    val[x][y]='|';
                    printf(" %c ",val[x][y]);
            }
            else if (y == 20  && x > 0 && x <20 )
            {
                    val[x][y]='|';
                    printf(" %c ",val[x][y]);
            }
            else if (x == 20 && y>0 && y<20)
            {
                    val[x][y]='-';
                    printf(" %c ",val[x][y]);
            }*/
            else if (x%2 == 0)
            {
                val[x][y]='-';
                printf(" %c ",val[x][y]);
            }
            else if(y%2 == 0){
                val[x][y]='|';
                printf(" %c ",val[x][y]);
            }

            /*else if(jeu->plateau[x][y] != 'b' && jeu->plateau[x][y] != 'n' && jeu->plateau[x][y] != '-' && jeu->plateau[x][y] != '|'){
                printf(" %c ",vide(x,y));
            }*/
            else {
                for(int i = 0;i<10;i++)
                printf(" %c ",jeu->plateau[x][y]);
            }
        }
        printf("\n");
    }
}

unsigned char vide(int x , int y)
{
    unsigned char ret;

    if((x+y)% 2 == 0)
    {
        ret = ' ';
    }
    else
    {
        ret = '#';
    }
    return ret;
}



//JEU
int tour_joueur(int tour, struct personne joueur){

    if (tour%2==1){
        joueur.joueur_actuel = 1;
    }
    else {
        joueur.joueur_actuel = 2;
    }

    return joueur.joueur_actuel;
}

int adversaire(int tour, struct personne joueur){

    if (tour%2==1){
        joueur.adversaire = 2;
    }
    else {
        joueur.adversaire = 1;
    }

    return joueur.adversaire;
}

void deplacer_pion(int numero_joueur, struct damier *jeu){

    int x, y, a, b;
    printf("Joueur %d, veuillez entrer les coordonnees du pion que vous voulez bouger sous la forme 'x y' : ",numero_joueur);
    scanf("%d %d",&x,&y);

    struct pion *jeton;
    jeton->c->x = x;
    jeton->c->y = y;

    printf("Joueur %d, veuillez entrer les coordonnees de la case ou vous voulez deplacer le pion sous la forme 'x y' : ",numero_joueur);
    scanf("%d %d",&a,&b);

    jeu->plateau[x][y] = effacer_pion(x,y,jeu);
    jeu->plateau[a][b] = 

}

int effacer_pion(int x, int y, struct damier *jeu){

    if((x+y)% 2 == 0)
    {
        jeu->plateau[x][y] = ' ';
    }
    else
    {
        jeu->plateau[x][y] = '#';
    }

    return jeu->plateau[x][y];
}

void jouer(){

    int tour = 1;
    struct personne J;
    struct damier *jeu;
    J.joueur_actuel = tour_joueur(tour, J);
    J.adversaire = adversaire(tour, J);

    if (J.joueur_actuel == 1) {
        printf("Au tour du Joueur 1.");
    }
    else{
        printf("Au tour du Joueur 2.");
    }

    //deplacer_pion(J.joueur_actuel,jeu);

}


//HISTORIQUE / SAUVEGARDE
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
    if (h->precedent != NULL)
    {
        afficherHisto(h->precedent);
    }
    printf("Coup n° %d : \n", &h->coup);
    printf("Le pion du joueur %d  a ete deplace de [%d,%d]en [%d,%d]",&h->joueur,&h->depart->x,&h->depart->y,&h->arrivee->x,&h->arrivee->y);
    printf("-----------------------------------------------------------");
}

void sauvegarde(struct histo * h, char* nomSauvegarde){

    printf("\nVeuillez entrer le nom de votre sauvegarde : ");
    scanf("%s",nomSauvegarde);
    struct histo *courant = h;
    FILE* f = fopen(nomSauvegarde,"w");

    while (courant->precedent != NULL){

        fputs((char*) &courant->coup,f);
        fputs(" ", f);
        fputs((char*) &courant->joueur,f);
        fputs(" ", f);
        fputs((char*) &courant->depart->x,f);
        fputs(" ", f);
        fputs((char*) &courant->depart->y,f);
        fputs(" ", f);
        fputs((char*) &courant->arrivee->x,f);
        fputs(" ", f);
        fputs((char*) &courant->arrivee->y,f);
        fputs(" ", f);

        if(courant->pionMange != NULL)
        {
            fputs((char*) &courant->pionMange->couleur,f);
            fputs(" ", f);
            fputs((char*) &courant->pionMange->c->x,f);
            fputs(" ", f);
            fputs((char*) &courant->pionMange->c->y,f);
            fputs(" ", f);
        }

        fputs("\n",f);
    }
}