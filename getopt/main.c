#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, const char *argv[])
{
    char c;
    int verbose_level = 0; /* Par défaut, programme silencieux. */
    char *filename = NULL;
    FILE *output = stdout; /* Par défaut, on écrit sur la console. */

    while ( (c = getopt(argc, argv, "hf:vV:")) != -1 ) {
        switch ( c ) {
            case 'v':
                /* Chaque fois que l'option -v est utilisée,
                 * on augmente le degré de verbosité. */
                verbose_level++;
                break;

            case 'V':
                /* Ici, on convertit la valeur de optarg
                 * en entier. Il conviendrait de gérer les
                 * cas où la conversion est impossible (si
                 * l'utilisateur a fait n'importe quoi...). */
                verbose_level = atoi(optarg);
                break;

            case 'h':
                /* On affiche l'aide et on termine. */
                fprintf(stderr, "Usage: monprog [options] FICHIER[...]\n"
                                "Options:\n"
                                "  -v         Augmente la verbosité.\n"
                                "  -V n       Définit le niveau de verbosité à n.\n"
                                "  -h         Affiche ce message d'aide.\n"
                                "  -f FICHIER Écrit dans FICHIER plutôt que sur la sortie standard.\n"
                       );
                return 0;

            case 'f':
                /* On stocke le pointeur vers l'argument
                 * (car sa valeur pourrait être écrasée
                 * au prochain tour de boucle). */
                filename = optarg;
                break;

            case '?':
                /* getopt renvoie (par défaut) '?' en cas
                 * d'erreur, si une option non acceptée
                 * est utilisée ou si une option attendant
                 * un argument n'est pas suivi de son argument. */
                fprintf(stderr, "Ligne de commande incorrecte.\n");
                return 1;
        }
    }

    /* Fin du traitement des options. */

    if ( filename != NULL ) {
        /* Si l'option -f a été utilisé, on écrit dans
         * le fichier spécifié. */
        output = fopen(filename, "w");
    }

    /* Maintenant, on récupère les autres arguments (ceux qui ne sont pas
     * des options).
     * À la fin du traitement des options, la variable optind (déclarée dans
     * getopt.h) contient l'index du premier élément du tableau argv qui ne
     * soit pas une option. */
    while ( optind < argc ) {

         /* Bien sûr, dans un programme réel, le "traitement" ne se ferait
          * probablement pas ici, dans la fonction main. On se contenterait
          * plutôt d'appeler la (les) fonction(s) chargée(s) de ce traitement. */

         fprintf(output, "Traitement du fichier %s\n", argv[optind]);

         if ( verbose_level >= 1 ) {
              fprintf(output, "  Ici, je donne un peu de détails sur ce fichier.\n");
         }

         if ( verbose_level >= 5 ) {
              fprintf(output, "  Là, je donne encore plus de détails sur ce fichier.\n");
         }

         optind++;
    }

    /* Traitement terminé, on ferme output et on termine. */
    fclose(output);

    return 0;
}