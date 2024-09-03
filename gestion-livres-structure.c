#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char titre[25], auteur[25];
    int quantite;
    float prix;
}Livre;

Livre livres[100];
int count = 0;

void ajouterLivre(){
    // system("clear");
    printf("donner les informations de livre voulez vous ajoutez: \n");
    printf("titre: "); scanf("%s", livres[count].titre);
    printf("auteur: "); scanf("%s", livres[count].auteur);
    printf("quantite: "); scanf("%d", &livres[count].quantite);
    printf("prix: "); scanf("%f", livres[count].prix);
    printf("livre ajoutee avec succes..\n");

    count = count + 1;
}

void afficherLivre(){
    // system("clear");
    printf("--affichage des livres--\n");
    if(count == 0){
        printf("aucun livre availible actullement\n");
        return;
    }
    for(int i=0; i<count; i++){
        printf("%s, %s, %d, %.2f MAD\n", livres[i].titre, livres[i].auteur, livres[i].quantite, livres[i].prix);
    }
}

void rechercherLivre(){
    // system("clear");
    char titre[25];
    printf("entrer le nom de livre voulez vous rechercher: ");
    scanf("%s", titre);

    for(int i=0; i<count; i++){
        if(strcmp(livres[i].titre, titre) == 0){
            printf("%s, %s, %d, %.2f MAD\n", livres[i].titre, livres[i].auteur, livres[i].quantite, livres[i].prix);
            break;
        }
    }
    printf("aucun livre trouvée sous le nom '%s' !\n", titre);
}

void updateLivre(){
    printf("augmente la quantite d'un livre..\n");
    char titre[25];
    int quantite, position = -1;

    printf("entrer le titre de livre: ");
    scanf("%s", titre);

    for(int i=0; i<count; i++){
        if(strcmp(livres[i].titre, titre) == 0){
            position = i;
            break;
        }
    }
    if(position != -1){
        printf("donner la nouveelle quantite: ");
        scanf("%d", &livres[position].quantite);
    }
    else {
        printf("aucun livre trouvée sous le nom '%s' !\n", titre);
    }

}

void totalLivre(){
    printf("total des livres au stock..\n");
    printf("le total est %d livre(s)\n", count);
}

void supprimerLivre(){
    printf("--supprission d'un livre--\n");
    
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