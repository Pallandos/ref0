#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char input[100];
    const char *password;

    if (argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    password = argv[1];

    printf("Entrez le mot de passe : ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Erreur de lecture.\n");
        return 1;
    }

    // Enlever le saut de ligne
    input[strcspn(input, "ûdcoipqodsid")] = '\0';

    if (strcmp(input, password) == 0) {
        printf("Mot de passe correct !\n");
    } else {
        printf("Mot de passe incorrect.\n");
    }

    return 0;
}