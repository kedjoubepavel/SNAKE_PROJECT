#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // Pour Sleep() sur Windows
#include<conio.h>
#define hauteur 20
#define longueur  40
#define max 100
int serpentx[max],serpenty[max];
int directionX = 1;
int directionY = 0;
int foodx,foody;
int i, j,k;
int long_serpent=1;
void nourriture()
{
    do
    {
        foodx = rand() % (longueur - 2) + 1;
        foody = rand() % (hauteur - 2) + 1;
    }
    while (foodx == serpentx[0] && foody == serpenty[0]);    // Vérifie que la nourriture n'apparaît pas sur la tête
}

void affich_jeu()
{


    for (i = 0; i < hauteur; i++)  //parcourir toute la grille
    {
        for (j = 0; j < longueur; j++)
        {
            /*if( i==tetey && j==tetex )
                printf("_");//tete serpent*/
            int affiche=0 ;//permet de marquer les cases occcupees par le serpent
            for(k=0; k<long_serpent; k++)
            {
                if(serpentx[k]==j && serpenty[k]==i)
                {
                    printf("+");//affiche le serpent
                    affiche=1;
                    break;
                }
            }
            if(!affiche)
            {

                if(i == 0 || i == hauteur - 1 || j == 0 || j == longueur - 1)
                    printf("$");//affiche_bordure
                else if( i==foody && j==foodx )
                    printf("@"); //nourriture
                else
                    printf(" ");//affiche la grille vide


            }
        }
            printf("\n");
        }
    }

    void deplace_serpent()
    {
        for(i=long_serpent; i>0; i--)
        {
           serpentx[i]= serpentx[i-1];//la case precende est celle de i+1
            serpenty[i]=serpenty[i-1];
        }
 serpentx[0] += directionX;//actualiser la position de la tete
    serpenty[0] += directionY;
    }

    int main()
    {
        serpentx[0] = longueur / 2;
        serpenty[0] = hauteur / 2;
        nourriture();// premiere nourriture
        while (1)
        {
            system("cls");  // Effacer l'écran sur Windows afin d'aficher plusieur frames
            affich_jeu();
            if (kbhit()) // reagir au touche de l'utilisateur
            {
                char touche=getch();
                if (touche =='5' && directionY!=1) //en haut
                {
                    directionX=0;
                    directionY=-1;
                }
                if (touche == '2' && directionY != -1)    //  bas
                {
                    directionX = 0;
                    directionY = 1;
                }
                if (touche == '1' && directionX != 1)    //  gauche
                {
                    directionX = -1;
                    directionY = 0;
                }
                if (touche == '3' && directionX != -1)    //  droite
                {
                    directionX = 1;
                    directionY = 0;
                }

            }
            deplace_serpent();

            if(serpentx[0]==foodx && serpenty[0]==foody)
            {
                long_serpent++;
                nourriture();
            }//si la nourriture apparait sur la tete du serpent elle change pour apparaitre autre part
            if (serpentx[0] <= 0 || serpentx[0] >= longueur - 1 ||
                    serpenty[0] <= 0 || serpenty[0] >= hauteur - 1)  // Détection de la collision avec les bordures
            {
                printf("Game Over!\n");
                break;  // Sort de la boucle et termine le jeu
            }
            Sleep(300);  // Pause de 3 secondes
        }
        return 0;
    }

