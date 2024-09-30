#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void fonction_affichage() {
    printf("\n\t\t\033[0mLe programme offre les fonctionnalites suivantes :\n\n");
    printf("\t\033[1;32m1: Ajouter un livre au stock.\n");
    printf("\t\033[1;32m2: Afficher tous les livres disponibles\n");
    printf("\t3: Mettre a jour la quantite d'un livre\n");
   // printf("\t3: Rechercher un livre par son titre\n");
    printf("\t4: Supprimer un livre du stock\n");
    printf("\t5: Afficher le nombre total de livres en stock\n");
    printf("\t0: Quitter le programme\n\n\033[0m");
}

int nb_livre() {
    int nb;
    char buffer[100];

    while (1) {
        
         printf("\tChoisissez le nombre de livres que vous souhaitez ajouter : ");
        fgets(buffer, sizeof(buffer), stdin);

        // Verifie si tous les caracteres sont numeiques
        int valid = 1;
        for (int j = 0; buffer[j] != '\0'; j++) {
            if (!isdigit(buffer[j]) && buffer[j] != '\n') {
                valid = 0; // Si un caractere n'est pas un chiffre, on marque comme invalide
                break;
            }
        }

        // Si valide, convertir en entier
        if (valid && sscanf(buffer, "%d", &nb) == 1 && nb > 0) {
            return nb; // Retourne le nombre si valide
        } else {
            printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer un nombre >=1.\033[0m\n\n");

        }
    }
}

int verifier_alphabets(char str[500]) {
    for (int j = 0; str[j] != '\0'; j++) {
        if (!isalpha(str[j]) && str[j] != ' ') {
            return 0;
        }
    }
    return 1;
}

int verifier_nombre(char str[100]) {
    for (int j = 0; str[j] != '\0'; j++) {
        if (!isdigit(str[j]) && str[j] != '\n') {
            return 0; 
        }
    }
    return 1; // 
}

void ajouter(int i, char titre[][500], char auteur[][500], float prix[], int quantite[]) {
    char buffer[100];

    
    while (1) {
        printf("\n\tEntrer Les donner de %d Livres: \n\n",i+1);
        printf("\t\tTitre : ");
        fgets(titre[i], sizeof(titre[i]), stdin);
        titre[i][strcspn(titre[i], "\n")] = '\0'; 

        if (strlen(titre[i]) == 0 || verifier_alphabets(titre[i]) == 0) {
          printf("\n\t\033[1;31m!!!!! Erreur : Le titre contient des caracteres non alphabetiques.\033[0m\n");
           printf("\n\n\033[1;35m\t\tResaisir le Titre!!!!\033[0m\n");
        } else {
            break;
        }
    }

    // Ajouter l'auteur
    while (1) {
        printf("\t\tAuteur : ");
        fgets(auteur[i], sizeof(auteur[i]), stdin);
        auteur[i][strcspn(auteur[i], "\n")] = '\0'; // Enlever le saut de ligne

        if (strlen(auteur[i]) == 0 || verifier_alphabets(auteur[i]) == 0) {
        printf("\n\t\033[1;31m!!!!! Erreur : l'auteur contient des caracteres non alphabetiques.\033[0m\n");
            printf("\n\n\033[1;35m\t\tResaisir l'auteur!!!!\033[0m\n\n");
        } else {
            break;
        }
    }

    // Ajouter le prix
    while (1) {
        printf("\t\tPrix: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (verifier_nombre(buffer) && sscanf(buffer, "%f", &prix[i]) == 1 && prix[i] >= 0) {
            break;
        } else {
            printf("\n\t\033[1;31m!!!!! Erreur : le Prix contient des caracteres non Numeriques.\033[0m\n");
            printf("\n\n\n\t\t\033[1;35mResaisir le Prix!!!!\033[0m \n\n");

        }
    }

    // Ajouter la quantit
    while (1) {
        printf("\t\tQuantite: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (verifier_nombre(buffer) && sscanf(buffer, "%d", &quantite[i]) == 1 && quantite[i] >= 0) {
            break;
        } else {
            printf("\n\t\033[1;31m!!!!! Erreur : la Quantite contient des caracteres non Numeriques.\033[0m\n");
            printf("\n\n\n\t\t\033[1;35mResaisir la Quantite!!!!\033[0m \n\n");
        }
    }
}

void affichage_tableau(int nb, char titre[][500], char auteur[][500], float prix[], int quantite[]) {
  if (nb == 0) {
    printf("\n\t\t\033[1;31m Ooops!!!!! Aucun livre n'a ?t? ajout? au stock.\n\n");
} else {
    
    printf("\n\n\t***** Affichage de Tous les Livres Disponibles *****\n\n");
    printf("\t%-15s %-15s %-10s %-10s\n", "Titre", "Auteur", "Prix", "Quantit?");
    printf("\t-----------------------------------------------------\n");

    for (int i = 0; i < nb; i++) {
        if (titre[i][0] != '\0') { 
            printf("\t%-15s %-15s %-10.2f %-10d\n", titre[i], auteur[i], prix[i], quantite[i]);
        }
    }

    printf("\n\t***********************************************\n\n");
}

    
}

int verifier_saisir_nombre() {
    char buffer[100];
    int valid;

    while (1) {
         printf("-->\n\n\t\033[0mChoisir un nombre entre 0 et 6 : ");
        fgets(buffer, sizeof(buffer), stdin);
        
        // Enleve le saut de ligne
        buffer[strcspn(buffer, "\n")] = 0;

        // Veifie si la chaine represente un nombre
        valid = 1; // Supposer que c'est valide
        for (int j = 0; buffer[j] != '\0'; j++) {
            if (!isdigit(buffer[j])) {
                valid = 0; 
                break;
            }
        }

        if (valid) {
            int n = atoi(buffer);
            if (n >= 0 && n<=5) {
                return n; // Retourne le nombre si valide
            } else {
            printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer un nombre valide entre 0 et 6.\033[0m\n\n");

            }
        } else {
            printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer un nombre valide entre 0 et 6.\033[0m\n\n");

        }
    }
}

void mettre_a_jour_quantite(int nb, char titre[][500], int quantite[]) {
    char livre[500];
    int nv;

    printf("\n\n\t\tSaisir le titre du livre ? rechercher : ");
    fgets(livre, sizeof(livre), stdin);
    livre[strcspn(livre, "\n")] = 0; // Supprime le saut de ligne

    for (int i = 0; i < nb; i++) {
        if (strcmp(titre[i], livre) == 0) {
            printf("\t\tLivre trouv? :\n\n");
            printf("\tTitre : %s\n", titre[i]);
            printf("\tQuantite: %d\n", quantite[i]);
            printf("\n\n\t\tSaisir la nouvelle quantite: ");

            char buffer[100];
            while (1) {
                fgets(buffer, sizeof(buffer), stdin);
                if (verifier_nombre(buffer) && sscanf(buffer, "%d", &nv) == 1 && nv >= 0) {
                    quantite[i] = nv; // Met a jour 
                    printf("\n\n\t\t ** \033[1;33mQuantit? mise ? jour avec succ?s ! \033[1;0m**\n\n");
                    return;
                } else {
                    printf("\n\n\t\033[1,31mErreur : Veuillez entrer une quantit? valide (nombre entier positif).\033[1;0m\n");
                    printf("\t\033[1;35mReSaisir la nouvelle quantite : \033[1;0m");
                }
            }
        }
    }

    printf("\t\033[1;31m !!! Aucun livre trouve avec ce titre.\n");
}
void supprimer_livre(int nb, char titre[][500], char auteur[][500], float prix[], int quantite[]) {
    char livre[500];
    printf("\n\t\tEntrez le titre du livre supprimer : ");
    fgets(livre, sizeof(livre), stdin);
    livre[strcspn(livre, "\n")] = 0; // Supprime le saut de ligne

    int found = 0; // Pour veifier si le livre 

    for (int i = 0; i < nb; i++) {
        if (strcmp(titre[i], livre) == 0 && titre[i][0] != '\0') { 
            titre[i][0] = '\0'; 
            auteur[i][0] = '\0'; 
            prix[i] = 0; 
            quantite[i] = 0; 
            found = 1; 
            printf("Livre '%s' supprime avec succes.\n", livre);
            break; 
        }
    }

    if (!found) {
        printf("\n\n\t\033[1;31mLivre non trouve\033[0m\n"); // Affiche une erreur si le livre n'est pas trouv?
    }
}

void afficher_nombre_total(int nb, int quantite[]) {
    int total = 0;
    for (int i = 0; i < nb; i++) {
        total += quantite[i]; // Additionne toutes les quantit?s
    }
    printf("\n\t\tTotal de livres en stock : %d\n\n", total);
}




int main() {
    
    
    printf("\033[1;31m\n\n\t\tMini-Projet : Syst?me de Gestion de Stock dans une Librairie\n\033[0m");
    fonction_affichage();
    printf("\n\n\t\033[1;34mNoter Bien!!!!!! Aucun livre n'a ete ajoute au stock au debut.\n\n\033[0m");

   
    //declaration des variable 
    int nb=0;
    char titre[nb][500], auteur[nb][500];
    float prix[100];
    int quantite[100],choix;
    //traiter les cas 
    
    do{
         choix=verifier_saisir_nombre();
        switch(choix){
        case 1:{
            printf("\033[1;36m\n\t\tBienvenue sur la phase d'ajout d'un ou plusieurs livres au stock\033[0m\n\n");
              nb = nb_livre();
             for (int i = 0; i < nb; i++){
                 ajouter(i, titre, auteur, prix, quantite);
             }
            break;
        }//fin de case 1
         
        case 2:{
            affichage_tableau(nb, titre, auteur, prix, quantite);
            break;
        }//fin de case 2
        
        case 3:{
            supprimer_livre(nb, titre, auteur, prix, quantite);
            break;
        } //fin case 3 
        
        case 4:{
           mettre_a_jour_quantite(nb,titre,quantite);
            break;
        } //fin case 4
        
        case 5:{
           printf("\033[1;36m\n\t\tBienvenue sur la phase d'ajout d'un ou plusieurs livres au stock\033[0m\n\n");
           nb = nb_livre();
           for (int i = 0; i < nb; i++) {
                ajouter(i, titre, auteur, prix, quantite);
            }
            afficher_nombre_total(nb, quantite); // Affiche le total apr?s ajout
    break;

        }
        default:{
            printf("Rien fiat!!!"); 
            break;
        }
    
    } //fin switch
    }while(choix!=0);
    

    return 0;
}

