// writtern by Rastislav Brna
// Licence is available on https://github.com/magicsk/project01
// IDE: Visual Studio Code
// Compiler: gcc  args:-lm -I./include

void lap() {
    struct Content* file = readFile();
    system("clear || cls");
    int bestOfDriver[numOfLines() + 1];
    int bestDriver;
    int best = 0;
    for (int i = 0; i <= numOfLines(); i++) {
        bestDriver = 0;
        for (int j = 1; j < 5; j++) {
            if (file[i].lap[j] < file[i].lap[bestDriver]) {
                bestDriver = j;
            }
        }
        bestOfDriver[i] = bestDriver;
        if (file[i].lap[bestOfDriver[i]] < file[best].lap[bestOfDriver[best]]) {
            best = i;
        }
    }
    int bestLapNo = bestOfDriver[best];
    printf(
        "Best lap : %.3f\nDriver : %s\nLap number : %d\n",
        file[best].lap[bestLapNo], file[best].name, bestLapNo + 1);
    getchar();
    mainMenu();

}

void gender() {
    struct Content* file = readFile();
    system("clear || cls");
    printf("Select a gender:\n[m]Male\n[f]Female\n");

    char gender = getchar();
    getchar();

    system("clear || cls");
    if (gender == 'm' || gender == 'f') {
        int bestOfDriver[numOfLines() + 1];
        int bestDriver;
        int best = 0;
        for (int i = 0; i <= numOfLines(); i++) {
            if (gender == file[i].gender) {
                best = i;
                break;
            }
        }
        for (int i = 0; i <= numOfLines(); i++) {
            if (gender == file[i].gender) {
                bestDriver = 0;
                for (int j = 1; j < 5; j++) {
                    if (file[i].lap[j] < file[i].lap[bestDriver]) {
                        bestDriver = j;
                    }
                }
                bestOfDriver[i] = bestDriver;
                if (file[i].lap[bestOfDriver[i]] < file[best].lap[bestOfDriver[best]]) {
                    best = i;
                }
            }
        }
        int bestLapNo = bestOfDriver[best];
        printf(
            "Best lap : %.3f\nDriver : %s\nLap number : %d\n",
            file[best].lap[bestLapNo], file[best].name, bestLapNo + 1);
        getchar();
        mainMenu();
    } else {
        printf("%c is not an option!\n", gender);
        getchar();
        mainMenu();
    }
}

void brand() {
    struct Content* file = readFile();
    system("clear || cls");

    struct Brand {
        char name[128];
    } brand[128];

    int brandNo = 0;
    int same;

    for (int i = 0; i <= numOfLines(); i++) {
        same = 0;
        for (int j = 0; j < 128; j++) {
            if (strcmp(brand[j].name, file[i].brand) == 0) {
                same++;
            }
        }
        if (same < 1) {
            strcpy(brand[brandNo].name, file[i].brand);
            brandNo++;
        }
    }

    for (int b = 0; b < brandNo; b++) {
        int bestOfDriver[numOfLines() + 1];
        int bestDriver;
        int best = 0;
        for (int i = 0; i <= numOfLines(); i++) {
            if (strcmp(brand[b].name, file[i].brand) == 0) {
                best = i;
                break;
            }
        }
        for (int i = 0; i <= numOfLines(); i++) {
            if (strcmp(brand[b].name, file[i].brand) == 0) {
                bestDriver = 0;
                for (int j = 1; j < 5; j++) {
                    if (file[i].lap[j] < file[i].lap[bestDriver]) {
                        bestDriver = j;
                    }
                }
                bestOfDriver[i] = bestDriver;
                if (file[i].lap[bestOfDriver[i]] < file[best].lap[bestOfDriver[best]]) {
                    best = i;
                }
            }
        }
        int bestLapNo = bestOfDriver[best];
        printf(
            "Brand: %s\nBest lap : %.3f\nDriver : %s\nLap number : %d\n\n",
            brand[b].name, file[best].lap[bestLapNo], file[best].name, bestLapNo + 1);
        getchar();
        mainMenu();
    }
}

void year() {
    struct Content* file = readFile();
    int date = 0;

    system("clear || cls");
    while (date < 1 || date> 2020) {
        printf("Enter a year in format YYYY: ");
        scanf("%d", &date);
        getchar();
    }

    system("clear || cls");
    if (date > 1) {
        int bestOfDriver[numOfLines() + 1];
        int bestDriver;
        int best = 0;
        for (int i = 0; i <= numOfLines(); i++) {
            if (date > file[i].date) {
                best = i;
                break;
            }
        }
        for (int i = 0; i <= numOfLines(); i++) {
            if (date > file[i].date) {
                bestDriver = 0;
                for (int j = 1; j < 5; j++) {
                    if (file[i].lap[j] < file[i].lap[bestDriver]) {
                        bestDriver = j;
                    }
                }
                bestOfDriver[i] = bestDriver;
                if (file[i].lap[bestOfDriver[i]] < file[best].lap[bestOfDriver[best]]) {
                    best = i;
                }
            }
        }
        int bestLapNo = bestOfDriver[best];
        printf(
            "%s\nborn %d\nBest lap : %.3f\nLap number : %d\n",
            file[best].name, file[best].date, file[best].lap[bestLapNo], bestLapNo + 1);
        getchar();
        mainMenu();
    }
}

void average() {
    struct Content* file = readFile();
    system("clear || cls");

    float average[numOfLines() + 1];
    int best = 0;

    for (int i = 0; i <= numOfLines(); i++) {
        float sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += file[i].lap[j];
        }
        average[i] = sum / 5;
        printf("%s - %.3f\n", file[i].name, average[i]);
    }
    for (int i = 1; i <= numOfLines(); i++) {
        if (average[i] < average[best]) {
            best = i;
        }
    }
    printf("\nBest:\n%s - %.3f\n", file[best].name, average[best]);
    getchar();
    mainMenu();
}