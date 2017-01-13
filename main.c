#include <stdio.h>
#include <stdlib.h>
//CONSTANTE taille carré
#define TAILLE 5
//Type pour le curseur se déplaçant dans le tableau
typedef struct Position{

    int x;
    int y;
}Position;
//Initialisation du tableau( remplir de 0) et positionne le curseur sur le nord du milieu
Position init(int tab[TAILLE][TAILLE],Position Pos);
//Fonction de remplissage du tableau
void remplissage(int tab[TAILLE][TAILLE], Position Pos);
//Fonction déplace Curseur dans la direction voulu
Position DeplacerCurseur(int tab[TAILLE][TAILLE],Position Pos);
//Fonction affiche le carre magique
void affichage(int tab[TAILLE][TAILLE]);

int main()
{
    int Carre_M[TAILLE][TAILLE];
    Position Pos;
    Pos=init(Carre_M, Pos);
    remplissage(Carre_M, Pos);
    affichage(Carre_M);
    return 0;
}
//But : Afficher le carré magique
//ENTREE : Carré remplie au préalable
//Sortie : Carré affiché à l'écran
void affichage(int tab[TAILLE][TAILLE]){
    int i,j;
    for (i=0;i<TAILLE;i++){
            printf("\n");
        for (j=0;j<TAILLE;j++)
        {
            if (tab[j][i]<10){
                printf(" %i  ", tab[j][i]);
            } else {
                printf(" %i ", tab[j][i]);
            }

        }
    }
}
//BUT : Deplacer le curseur sur la prochaine case vide
//ENTREE : tableau et curseur
//SORTIE : Curseur à la position suivante
Position DeplacerCurseur(int tab[TAILLE][TAILLE],Position Pos){
    //Déplacement nord-est de base si nord-est rempli aller-ouest
    //Mouvement nord-est
        if ((Pos.y==0)&&(Pos.x<TAILLE-1)&&(tab[Pos.x+1][TAILLE-1]==0)) //Trop haut
        {
            Pos.y=TAILLE-1;
            Pos.x=Pos.x+1;

        } else if ((Pos.x==TAILLE-1)&&(Pos.y>0)&&(tab[0][Pos.y-1]==0)) //Trop à droite
        {
            Pos.x=0;
            Pos.y=Pos.y-1;
        } else if ((Pos.x==TAILLE-1)&&(Pos.y==0)&&(tab[0][TAILLE-1]==0)) //En haut à droite
        {
            Pos.y=TAILLE-1;
            Pos.x=0;
        } else if (tab[Pos.x+1][Pos.y-1]==0) { //Si on ne se trouve pas sur les bords
            Pos.x=Pos.x+1;
            Pos.y=Pos.y-1;
            //Mouvement nord-ouest : la case nord-est est prise donc on va au nord-ouest
        } else if ((Pos.y==0)&&(tab[Pos.x][TAILLE-2]==0)) //Si on est sur la ligne du haut ( x=0)        {
            Pos.y=TAILLE-2;

        } else if ((Pos.y>1)&&(tab[Pos.x][Pos.y-2]==0)) //Si on est sur la deuxième ligne ( x=1)
        {
            Pos.y=Pos.y-2;
        } else if ((Pos.y==1)&&(tab[Pos.x][TAILLE-1]==0)) //Si on est sur les autres lignes
        {
            Pos.y=TAILLE-1;
        }
    return Pos;
}

//BUT : Remplir le carre magique
//ENTREE : Tableau et curseur
//SORTIE : Tableau rempli
void remplissage(int tab[TAILLE][TAILLE], Position Pos){
    int i;
    int Deplacement;
    for (i=1; i<(TAILLE*TAILLE)+1; i++)
    {
        tab[Pos.x][Pos.y]=i;
        Pos=DeplacerCurseur(tab,Pos);
    }
}

//BUT : Initialise tableau + position curseur
//ENTREE : Tableau et Curseur
//SORTIE : Tableau rempli de zero et curseur au nord du milieu
Position init(int tab[TAILLE][TAILLE],Position Pos){
    int i,j;
    //On initialise le tableau en le remplissant de 0
    for (i=0; i<TAILLE; i++)
    {
        for (j=0; j<TAILLE; j++)
        {
            tab[i][j]=0;
        }
    }
    //On place le curseur sur la position de départ
    Pos.x=TAILLE/2;
    Pos.y=TAILLE/2-1;
    return Pos;
}
