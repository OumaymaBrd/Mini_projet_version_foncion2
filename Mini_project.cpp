#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("\033[1;31m\n\n\t\tMini-Projet : Systeme de Gestion de Stock dans une Librairie\n");

    // D�claration
    char titre[100][100];
    char auteur[100][100];
    float prix[100];
    int quantite[100];
    int choix, nmb = 0;
    int valide;

    // Affichage des livres au d�but
    printf("\n\n\t\033[1;34mNoter Bien!!!!!! Aucun livre n'a ete ajoute au stock au debut.\n\n");

    // R�p�ter jusqu'�
    do {
        printf("\n\t\t\033[0mLe programme offre les fonctionnalites suivantes :\n\n");
        printf("\t\033[1;32m1: Ajouter un livre au stock.\n");
        printf("\t\033[1;32m2: Afficher tous les livres disponibles\n");
        printf("\t3: Rechercher un livre par son titre\n");
        printf("\t4: Mettre a jour la quantite d'un livre\n");
        printf("\t5: Supprimer un livre du stock\n");
        printf("\t6: Afficher le nombre total de livres en stock\n");
        printf("\t0: Quitter le programme\n\n");

        // Traitement du choix
        // do {
        //     printf("-->\t\033[0mChoisir un nombre entre 0 et 6 : ");
        //     valide = scanf("%d", &choix);

        //     if (valide != 1 || choix < 0 || choix > 6) {
        //         printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer un nombre valide entre 0 et 6.\033[0m\n\n");
        //         while (getchar() != '\n');  // Vide  en cas d'entr�e incorrecte
        //     }
        // } while (valide != 1 || choix < 0 || choix > 6);

       do {
        char input[100];
        printf("-->\t\033[0mChoisir un nombre entre 0 et 6 : ");
        //scanf("%s", input); // Lire l'entrée comme chaîne de caractères
        fgets(input,sizeof(input),stdin);
        //input[strcspn(input, "\n")] = '\0';
        getchar();
        valide = 1; // Supposons que l'entrée est valide

        // Vérifier que chaque caractère de la chaîne est un chiffre et qu'il n'y a pas d'espace
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] == ' ') {
                printf("\033[1;31m\n\n\t\tErreur : Les espaces sont interdits. Veuillez ressaisir un nombre.\033[0m\n\n");
                valide = 0; // Invalide car il y a un espace
                break; // Sortir de la boucle for
            }
            if (!isdigit(input[i])) {
                printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer uniquement des chiffres.\033[0m\n\n");
                valide = 0; // Invalide car il y a un caractère non numérique
                break; // Sortir de la boucle for
            }
        }

        // Si l'entrée est valide, convertir en entier
        if (valide) {
            choix = atoi(input); // Convertir la chaîne en entier
        }

        // Vérifier si l'entrée est un nombre valide entre 0 et 6
        if (valide && (choix < 0 || choix > 6)) {
            printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer un nombre valide entre 0 et 6.\033[0m\n\n");
            valide = 0; // Refaire la boucle si l'entrée est invalide
        }

    } while (!valide);
    //
        // switch pour le traitement des cas
        switch (choix) {
            case 1: {
                if (nmb >= 100) {
                    printf("!!!!Erreur : La capacite maximale de livres est atteinte.\n");
                    break;
                }

                printf("\033[1;36m\n\t\tBienvenue sur la phase d'ajout d'un livre au stock\033[0m\n\n");
                int nb_saisir;
                printf("\tEst-ce que vous voulez ajouter un livre ou plusieurs livres?\n");
                g:
                printf("\t\t0: Ajouter un livre\n");
                printf("\t\t1: Ajouter plusieurs livres\n\n");

                // 1 ou n livre entrer
                while (1) {
                    printf("\tDonnez moi un numero de votre choix (0 || 1) : ");
                    if (scanf("%d", &nb_saisir) != 1 || (nb_saisir != 0 && nb_saisir != 1)) {
                        printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer 0 ou 1.\033[0m\n\n");
                        while (getchar() != '\n'); // Vider
                    } else {
                        break;
                    }
                }

                if (nb_saisir == 0) {
                    nb_saisir = 1;
                } else if (nb_saisir == 1) {
                    do {
                        printf("\tCombien de livres voulez-vous ajouter ? ");
                        valide = scanf("%d", &nb_saisir);

                        if (valide != 1 || nb_saisir < 2) {
                            printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer un nombre entier valide superieur ou �gal � 2.\033[0m\n\n");
                            while (getchar() != '\n');
                        }
                    } while (valide != 1 || nb_saisir < 2);
                }

                //  ajouter les livres
                for (int i = 0; i < nb_saisir; i++) {
                    int existe = 0;
                    printf("\tSaisir les informations du livre %d :\n\n", nmb + 1);

                    // Saisie et validation du titre
                    e:
                    printf("\t\tTitre : ");
                    scanf(" %[^\n]", titre[nmb]); //condition sur l'espace

                    for (int j = 0; titre[nmb][j] != '\0'; j++) {
                        if (!isalpha(titre[nmb][j]) && titre[nmb][j] != ' ') {
                            printf("\n\t\033[1;31m!!!!! Erreur : Le titre contient des caracteres non alphabetiques.\033[0m\n");
                            printf("\n\n\033[1;35m\t\tResaisir le titre!!!!\033[0m\n");
                            goto e;
                        }
                    }

                    // Traitement de  l'auteur
                    a:
                    printf("\t\tAuteur : ");
                    scanf(" %[^\n]", auteur[nmb]); // Accepte les espaces dans le nom de l'auteur
                    for (int j = 0; auteur[nmb][j] != '\0'; j++) {
                        if (!isalpha(auteur[nmb][j]) && auteur[nmb][j] != ' ') {
                            printf("\n\t\033[1;31m!!!!! Erreur : L'auteur contient des caracteres non alphabetiques.\033[0m\n");
                            printf("\n\n\n\t\t\033[1;35mResaisir le nom de l'auteur!!!!\033[0m \n");
                            goto a;
                        }
                    }

                    // Saisie du prix
                    do {
                        printf("\t\tPrix : ");
                        valide = scanf("%f", &prix[nmb]);
                        if (valide != 1) {
                            printf("\033[1;31m\n\t\t!!! Erreur : Vous devez entrer un nombre valide pour le prix.\033[0m\n\n");
                            while (getchar() != '\n');
                        }
                    } while (valide != 1);

                    // Saisie de la quantit�
                    do {
                        printf("\t\tQuantite : ");
                        valide = scanf("%d", &quantite[nmb]);
                        if (valide != 1) {
                            printf("\033[1;31m\n\t\t!!!! Erreur : Vous devez entrer un nombre valide pour la quantite.\033[0m\n\n");
                            while (getchar() != '\n');
                        }
                    } while (valide != 1);

                    nmb++;
                    printf("\t\t\033[1;33mLivre ajoute avec succes !\033[0m\n");
                }
                break;
            }

            case 2: {
                if (nmb == 0) {
                    printf("\n\t\t\033[1;31m Ooops!!!!! Aucun livre n'a ete ajoute au stock.\n\n");
                } else {
                    printf("\n\n\t***** Affichage de Tous les Livres Disponibles *****\n\n");
                    printf("\t%-15s %-15s %-10s %-10s\n", "Titre", "Auteur", "Prix", "Quantite");
                    printf("\t-----------------------------------------------------\n");
                    for (int i = 0; i < nmb; i++) {
                        printf("\t%-15s %-15s %-10.2f %-10d\n", titre[i], auteur[i], prix[i], quantite[i]);
                    }
                    printf("\n\t***********************************************\n\n");
                }
                break;
            }

            // Recherche par titre
            case 3: {
                char recherche[100];
                printf("Saisir le titre du livre a rechercher : ");
                scanf(" %[^\n]", recherche);
                int found = 0;

                for (int i = 0; i < nmb; i++) {
                    if (strcmp(titre[i], recherche) == 0) {
                        printf("Livre trouve :\n");
                        printf("\tTitre : %s\n", titre[i]);
                        printf("\tAuteur : %s\n", auteur[i]);
                        printf("\tPrix : %.2f\n", prix[i]);
                        printf("\tQuantite : %d\n", quantite[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\t\033[1;31m !!! Aucun Livre trouve par ce titre \n");
                }
                break;
            }

            //  Mettre � jour la Qt
            case 4: {
                char recherche[100];
                printf("\t\033[0mSaisir le titre du livre a mettre a jour : ");
                scanf(" %[^\n]", recherche);
                int found = 0;

                for (int i = 0; i < nmb; i++) {
                    if (strcmp(titre[i], recherche) == 0) {
                        printf("\tLivre trouve :\n");
                        printf("\tTitre : %s\n", titre[i]);
                        printf("\tAuteur : %s\n", auteur[i]);
                        printf("\tPrix : %.2f\n", prix[i]);
                        printf("\tQuantite actuelle : %d\n", quantite[i]);

                        printf("\n\tNouvelle quantite : ");
                        int nouvelleQuantite;
                        valide = scanf("%d", &nouvelleQuantite);
                        if (valide == 1 && nouvelleQuantite >= 0) {
                            quantite[i] = nouvelleQuantite;
                            printf("\n\t\t\033[1;32mQuantite mise a jour avec succes !\n");
                        } else {
                            printf("\033[1;31m\n\t\t!!! Erreur : Vous devez entrer un nombre valide pour la quantite.\033[0m\n\n");
                        }
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\t\033[1;31m !!! Aucun Livre trouve par ce titre \n");
                }
                break;
            }

            //  Supprimer
            case 5: {
                char recherche[100];
                printf("Saisir le titre du livre a supprimer : ");
                scanf(" %[^\n]", recherche);
                int found = 0;

                for (int i = 0; i < nmb; i++) {
                    if (strcmp(titre[i], recherche) == 0) {
                        printf("\tLivre trouve et supprime : %s\n", titre[i]);
                        for (int j = i; j < nmb - 1; j++) {
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantite[j] = quantite[j + 1];
                        }
                        nmb--;
                        found = 1;
                        printf("\n\t\033[1;32mLivre supprime avec succes !\033[0m\n");
                        break;
                    }
                }

                if (!found) {
                    printf("\033[1;31m !!! Aucun Livre trouve par ce titre \n");
                }
                break;
            }

            // Afficher le nombre total
            case 6: {
                printf("\033[1;36m\n\n\t\tLe nombre total de livres en stock est de : %d\033[0m\n\n", nmb);
                break;
            }

            //  Quitter
            case 0: {
                printf("\033[1;36m\n\n\t\tMerci d'avoir utilise notre application. A bientot!\033[0m\n");
                break;
            }

            default: {
                printf("\n\t\t\033[1;31mOption non valide !\033[0m\n");
                break;
            }
        }

    } while (choix != 0);

    return 0;
}
