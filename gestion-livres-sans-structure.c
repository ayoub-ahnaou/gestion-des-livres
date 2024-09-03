#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LIVRES 100

char titres[MAX_LIVRES][35];
char auteurs[MAX_LIVRES][35];
int quantite[MAX_LIVRES];
float prix[MAX_LIVRES];
int counter = 0;

void ajouterLivre(){
    printf("--ajout d'un livre--");
    printf("donner le titre de livre: "); scanf(" %[^\n]s", titres[counter]);
    printf("donner l'autheur de livre: "); scanf(" %[^\n]s", auteurs[counter]);
    printf("donner la quantite de livre: "); scanf("%d", &quantite[counter]);
    printf("donner le prix de livre: "); scanf("%f", &prix[counter]);

    printf("un livre a ete ajoute avec succes.. sous les infos (%s, %s, %d, %.2f)\n", titres[counter], auteurs[counter], quantite[counter], prix[counter]);

    counter = counter + 1;
}

void afficherLivre(){
    printf("--affichage des livres--\n");
    if(counter == 0){
        printf("aucun livre availible actullement\n");
        return;
    }
    for(int i=0; i<counter; i++){
        printf("titre: '%s',autheur: '%s',quantite: %d, prix: %.2f MAD\n", titres[i], auteurs[i], quantite[i], prix[i]);
    }
}

void rechercherLivre(){
    printf("--recherche d'un livre--");
    char titre[25];
    printf("entrer le nom de livre voulez vous rechercher: ");
    scanf(" %[^\n]s", titre);

    for(int i=0; i<counter; i++){
        if(strcmp(titres[i], titre) == 0){
            printf("%s, %s, %d, %.2f MAD\n", titres[i], auteurs[i], quantite[i], prix[i]);
            return ;
        }
    }
    printf("aucun livre trouvée sous le nom '%s' !\n", titre);
}

void updateLivre(){
    printf("--augmente la quantite d'un livre--\n");
    char titre[25];
    int qty, position = -1;

    printf("entrer le titre de livre: ");
    scanf(" %[^\n]s", titre);

    for(int i=0; i<counter; i++){
        if(strcmp(titres[i], titre) == 0){
            position = i;
            break;
        }
    }
    if(position != -1){
        printf("donner la nouveelle quantite: ");
        scanf("%d", &qty);
        quantite[position] = qty;
    }
    else {
        printf("aucun livre trouvée sous le nom '%s' !\n", titre);
    }
}

void supprimerLivre(){
    printf("--supprission d'un livre--\n");
    char titre[25];
    int position = -1;

    printf("entrer le titre de livre: ");
    scanf(" %[^\n]s", titre);

    for(int i=0; i<counter; i++){
        if(strcmp(titres[i], titre) == 0){
            position = i;
            break;
        }
    }
    if(position != -1){
        for(int i=position; i<counter; i++){
            titres[i][35] = titres[i + 1];
            auteurs[i][35] = auteurs[i + 1];
            quantite[i] = quantite[i + 1];
            prix[i] = prix[i + 1];
            printf("livre a ete supprime..\n");

            counter = counter - 1;
        }
    }
    else {
        printf("aucun livre trouvée sous le nom '%s' !\n", titre);
    }
}

void totalLivre(){
    printf("--informations sur le stock--\n");
    printf("le total est %d livre(s)\n", counter);
    int total = 0;
    for(int i=0; i<counter; i++){
        total = total + quantite[i];
    }
    printf("le total des quantites de livre %d \n", total);
}

int main(){
    int choice;
    do{
        printf("-----------------------------------------------------\n");
        printf("                   gestion des livres                \n");
        printf("-----------------------------------------------------\n");
        printf("1- ajouter un livre au stock\n");
        printf("2- afficher tous les livres du stock\n");
        printf("3- rechercher un livre par titre\n");
        printf("4- mettre a jour la quantite d'un livre\n");
        printf("5- supprimer un livre du stock\n");
        printf("6- afficher le nombre total de livres\n");
        printf("0- quitter\n");
        printf("-----------------------------------------------------\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: ajouterLivre(); break;
            case 2: afficherLivre(); break;
            case 3: rechercherLivre(); break;
            case 4: updateLivre(); break;
            case 5: supprimerLivre(); break;
            case 6: totalLivre(); break;
            case 0: printf("au revoir...\n"); break;
            default: 
                printf("-----------------------------------------------------\n");
                printf("selectionner un choix valid...\n");
                printf("-----------------------------------------------------\n");
                break;
        }
    }
    while(choice != 0);


    printf("\n");
    return 0;
}