/* License           : Open Source
 * But               : Logiciel qui resout differents problemes de Physique_Chimie
 * Langage principal : C++
 * Bibliothéques     : Qt-> Interfaces graphiques
 *                     SFML-> *Futur* moteur de Simulations_Chimiques
 * Statut du projet  : En cours de developpement
 */

///Veuillez ne pas retirer les informations ci_dessus.
///Veuillez demander l'avis prealable de l'auteur pour toute modification du code source.

#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fenetre vitre;//On initialise la fenetre principale et on l'affiche
    vitre.show();
    return a.exec();
}
