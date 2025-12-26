#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *input;
    
    if (argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    input = argv[1];
    const char *password = "ovdoijvov";

    if (strcmp(input, password) == 0) {
        printf("Mot de passe correct !\n");
    } else {
        printf("Mot de passe incorrect.\n");
    }

    return 0;
}