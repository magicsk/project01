// writtern by Rastislav Brna
// Licence is available on https://github.com/magicsk/project01
// IDE: Visual Studio Code
// Compiler: gcc  args:-lm -I./include

void under() {
    struct Content* file = readFile();
    system("clear || cls");

    float lapTime = 0;
    while (lapTime < 1 || lapTime > 64000){
        printf("Enter a lap time: ");
        scanf("%f", &lapTime);
        getchar();
    }

    system("clear || cls");

    int laps[128];
    for (int i = 0; i < 128; i++) {
        laps[i] = 0;
    }


    for (int i = 0; i <= numOfLines(); i++) {
        for (int j = 0; j < 5; j++) {
            if (file[i].lap[j] <= lapTime) {
                laps[i]++;
            }
        }
    }

    for (int i = 0; i <= numOfLines(); i++) {
        if (laps[i] > 0) {
            printf("%s - %d laps", file[i].name, laps[i]);
            for (int j = 0; j < 5; j++) {
                if (file[i].lap[j] <= lapTime) {
                    printf(", %d (%.3f)", j + 1, file[i].lap[j]);
                }
            }
            printf("\n");
        }
    }

    int none = 0;
    for (int i = 0; i < 128; i++) {
        if (laps[i] == 0) {
            none++;
        }
    }
    if (none > 127) {
        printf("No lap time faster then %.3f was found!\n", lapTime);
        getchar();
        mainMenu();
    } else {
        getchar();
        mainMenu();
    }
}