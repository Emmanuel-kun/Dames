/* Programme de  gestion d'un jeux de dames
 *
 * Authors :    Lucie Potiron
 *              Franck Guillaume
 *              Emmanuel Rochet
 *
 * */

/*
Damier 10x10.

Générer un affichage.
chaque tour on doit voir l'état du damier.
chaque déplacement affiche la source du pion et la destination

On doit afficher :
le nombre de pièces noires restantes.
le nombre de pieces blanches restantes.

Le jeu doit permettre la sauvegarde et le chargement de sauvegarde.
chaque deplacement d'une partie doit etre log dans un fichier.


Utiliser une liste chainee
malloc et free.

donner la possibilite de revenir sur un coup.
*/

#include <stdio.h>
#include "dames.h"

int main() {

    struct damier *jeu = malloc(sizeof(* jeu));
    jeu->nbre_noirs=20;
    jeu->nbre_blancs=20;

    struct histo *historique;

    return 0;
}
