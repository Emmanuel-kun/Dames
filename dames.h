/* Programme de  gestion d'un jeux de dames
 *
 * Authors :    Lucie Potiron
 *              Franck Guillaume
 *              Emmanuel Rochet
 *
 *
 */


struct emplacement
{
    int x;
    int y;
};


struct pion{
    char couleur;
    struct emplacement * c
};

/*
 * Structure de notre pile d'historique
 * Le début pointe sur le haut de la pile, on a pas besoin de dépiler d'un coup
 * */
struct histo{
    struct emplacement * depart;
    struct emplacement * arrivee;
    struct pion * pionMange;
    int joueur;
    int coup;

    struct histo * precedent;
};


//structure utilisée
struct damier{
    unsigned char plateau[10][10];
    int nbre_noirs;
    int nbre_blancs;
};

int menu();

void initJeu(struct damier * jeu, struct histo * historique);

void jouer();

void affichage(struct damier *jeu);

unsigned char vide(int x , int y);

void addHisto(int joueur,struct emplacement *depart,struct emplacement *arrivee, struct histo * dernierCoup,struct histo * nouveauCoup, struct pion * pionMange);

struct histo rollback(struct histo dernierCoup, struct damier jeu);

void afficherHisto(struct histo * h);

void sauvegarde(struct histo * h, char* nomSauvegarde);

struct histo * charger(char * nomFichier, struct damier * jeu);

