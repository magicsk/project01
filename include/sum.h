// writtern by Rastislav Brna
// Licence is available on https://github.com/magicsk/project01
// IDE: Visual Studio Code
// Compiler: gcc  args:-lm -I./include

void sum() {
    struct Content* file = readFile();
    system("clear || cls");
    for (int i = 0; i <= numOfLines(); i++) {
        printf("%s, born %d, %s, Car:%s\nLap times: %.3f;%.3f;%.3f;%.3f;%.3f \n",
            file[i].name, file[i].date, file[i].gender > 108 ? "male" : "female", file[i].brand,
            file[i].lap[0], file[i].lap[1], file[i].lap[2], file[i].lap[3], file[i].lap[4]);
    }
    getchar();
    mainMenu();
}

void driver() {
    struct Content* file = readFile();
    char surname[128];
    int best;
    int worse;
    float average;
    int i = 0;
    system("clear || cls");
    printf("Enter surname of driver: ");
    scanf("%s", surname);
    getchar();
    system("clear || cls");

    for (i = 0; i < numOfLines(); i++) {
        if (strcmp(surname, file[i].surname) == 0) {

            //best round
            for (int j = 0; j < 5; j++) {
                if (
                    file[i].lap[j] <= file[i].lap[0] &&
                    file[i].lap[j] <= file[i].lap[1] &&
                    file[i].lap[j] <= file[i].lap[2] &&
                    file[i].lap[j] <= file[i].lap[3] &&
                    file[i].lap[j] <= file[i].lap[4]
                    ) {
                    best = j;
                    break;
                }
            }

            //worse round
            for (int j = 0; j < 5; j++) {
                if (
                    file[i].lap[j] >= file[i].lap[0] &&
                    file[i].lap[j] >= file[i].lap[1] &&
                    file[i].lap[j] >= file[i].lap[2] &&
                    file[i].lap[j] >= file[i].lap[3] &&
                    file[i].lap[j] >= file[i].lap[4]
                    ) {
                    worse = j;
                    break;
                }
            }

            // average round
            float sum = file[i].lap[0] + file[i].lap[1] + file[i].lap[2] + file[i].lap[3] + file[i].lap[4];
            average = sum / 5;

            printf("%s\nborn %d, %s\nCar:%s\n\nLap times: %.3f;%.3f;%.3f;%.3f;%.3f\n\nBest round: %.3f\nWorst round: %.3f\nAverage round: %.3f\n",
                file[i].name, file[i].date, file[i].gender > 108 ? "male" : "female", file[i].brand,
                file[i].lap[0], file[i].lap[1], file[i].lap[2], file[i].lap[3], file[i].lap[4], file[i].lap[best], file[i].lap[worse], average);
            getchar();
            mainMenu();
            break;
        }
    }
    printf("Driver not found!\n");
    printf("Press enter to go back to menu...\n");
    getchar();
    mainMenu();
}