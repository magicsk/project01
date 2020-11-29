// writtern by Rastislav Brna
// Licence is available on https://github.com/magicsk/project01
// IDE: Visual Studio Code
// Compiler: gcc  args:-lm -I./include

void change() {
    char surname[128];
    int lapNo = 0;
    float newLapTime;

    system("clear || cls");

    while (lapNo < 1 || lapNo > 5 || newLapTime < 1 || newLapTime > 64000) {
        printf("Enter surname, number of lap and new time of that lap (separated with spaces):\n");
        scanf("%s %d %f", surname, &lapNo, &newLapTime);
        getchar();
    }

    char d1[] = "drivers1.csv";
    char d2[] = "drivers2.csv";
    char d3[] = "drivers3.csv";
    char d4[] = "drivers4.csv";
    char d5[] = "drivers5.csv";
    char fullAddress[150] = "results/";

    system("clear || cls");
    printf("[1]drivers1.csv - default\n");
    printf("[2]drivers2.csv\n");
    printf("[3]drivers3.csv\n");
    printf("[4]drivers4.csv\n");
    printf("[5]drivers5.csv\n");
    printf("[o]Other - enter a filename\n");
    printf("----------\n");
    printf("[x]Back\n");

    char nameOption = getchar();

    switch (nameOption) {
    case '1':
        getchar();
        strcpy(fileName, d1);
        break;

    case '2':
        getchar();
        strcpy(fileName, d2);
        break;

    case '3':
        getchar();
        strcpy(fileName, d3);
        break;

    case '4':
        getchar();
        strcpy(fileName, d4);
        break;

    case '5':
        getchar();
        strcpy(fileName, d5);
        break;

    case 'o':
        system("clear || cls");
        printf("Enter a name of file with suffix: ");
        scanf("%s", fileName);
        getchar();
        break;

    case 'x':
        getchar();
        mainMenu();
        break;

    default:
        strcpy(fileName, d1);
        break;
    }

    strcat(fullAddress, fileName);
    FILE* input = fopen(fullAddress, "r");

    if (input != NULL) {
        char temp;
        char temp2[128];
        char* temp3, * tempSur;
        int length = 0;
        lineNum = 0;

        while (fscanf(input, "%c", &temp) != EOF) {
            if (temp == 10) {
                lineNum++;
            }
        }

        fseek(input, 0, SEEK_SET);

        for (int i = 0; i <= lineNum; i++) {
            fscanf(input,
                "%[^;];%c;%d;%[^;];%f;%f;%f;%f;%f\n",
                file[i].name,
                &file[i].gender,
                &file[i].date,
                file[i].brand,
                &file[i].lap[0],
                &file[i].lap[1],
                &file[i].lap[2],
                &file[i].lap[3],
                &file[i].lap[4]);
            temp3 = file[i].name;
            while (sscanf(temp3, "%s", temp2) == 1) {
                tempSur = temp3;
                length = strlen(temp2);
                temp3 = temp3 + (length + 1);
            }
            strcpy(file[i].surname, tempSur);
        }
        fclose(input);

        int found = 0;
        for (int i = 0; i < lineNum; i++) {
            if (strcmp(surname, file[i].surname) == 0) {
                file[i].lap[lapNo - 1] = newLapTime;
                found++;
            }
        }

        if (found != 0) {
            FILE* output = fopen(fullAddress, "w");
            for (int i = 0; i <= lineNum; i++) {
                if (i == lineNum) {
                    fprintf(output,
                        "%s;%c;%d;%s;%.3f;%.3f;%.3f;%.3f;%.3f",
                        file[i].name,
                        file[i].gender,
                        file[i].date,
                        file[i].brand,
                        file[i].lap[0],
                        file[i].lap[1],
                        file[i].lap[2],
                        file[i].lap[3],
                        file[i].lap[4]);
                } else {
                    fprintf(output,
                        "%s;%c;%d;%s;%.3f;%.3f;%.3f;%.3f;%.3f\n",
                        file[i].name,
                        file[i].gender,
                        file[i].date,
                        file[i].brand,
                        file[i].lap[0],
                        file[i].lap[1],
                        file[i].lap[2],
                        file[i].lap[3],
                        file[i].lap[4]);
                }
            }
            fclose(output);
            system("clear || cls");
            for (int i = 0; i <= lineNum; i++) {
                printf("%s, born %d, %s, Car:%s\nLap times: %.3f;%.3f;%.3f;%.3f;%.3f \n",
                    file[i].name, file[i].date, file[i].gender > 108 ? "male" : "female", file[i].brand,
                    file[i].lap[0], file[i].lap[1], file[i].lap[2], file[i].lap[3], file[i].lap[4]);
            }
            getchar();
            mainMenu();
        } else {
            printf("Surname not found!\n");
            getchar();
            mainMenu();
        }



    } else {
        printf("Error: Failed to read a file.\n");
        printf("Make sure that \"%s\" in results exists!\n", fileName);
        printf("Press enter to go back to menu...");
        getchar();
        mainMenu();
    }

}

void newdriver() {
    char name[128];
    char surname[128];
    int date;
    char brand[128];
    float lap[5];

    system("clear || cls");

while (strcmp(name, "") == 0 || strcmp(surname, "") == 0)
    printf("Enter name and surname:");
    scanf("%s %s", name, surname);
    strcat(name, " ");
    strcat(name, surname);

    while (date < 1 || date> 2020) {
        printf("Enter year of birth:");
        scanf("%d", &date);
        getchar();
    }
    char gender;
    while (gender != 'm' || gender != 'f') {
        printf("Chose a gender:\n[m]Male\n[f]Female\n");
        gender = getchar();
        getchar();
    }

    printf("Enter car brand:");
    scanf("%s", brand);
    getchar();

    while (lap[0] < 1 || lap[1] < 1 || lap[2] < 1 || lap[3] < 1 || lap[4] < 1) {
        printf("Enter five lap times separated by semicolon:");
        scanf("%f;%f;%f;%f;%f", &lap[0], &lap[1], &lap[2], &lap[3], &lap[4]);
        getchar();
    }

   char d1[] = "drivers1.csv";
    char d2[] = "drivers2.csv";
    char d3[] = "drivers3.csv";
    char d4[] = "drivers4.csv";
    char d5[] = "drivers5.csv";
    char fullAddress[150] = "results/";

    system("clear || cls");
    printf("[1]drivers1.csv - default\n");
    printf("[2]drivers2.csv\n");
    printf("[3]drivers3.csv\n");
    printf("[4]drivers4.csv\n");
    printf("[5]drivers5.csv\n");
    printf("[o]Other - enter a filename\n");
    printf("----------\n");
    printf("[x]Back\n");

    char nameOption = getchar();

    switch (nameOption) {
    case '1':
        getchar();
        strcpy(fileName, d1);
        break;

    case '2':
        getchar();
        strcpy(fileName, d2);
        break;

    case '3':
        getchar();
        strcpy(fileName, d3);
        break;

    case '4':
        getchar();
        strcpy(fileName, d4);
        break;

    case '5':
        getchar();
        strcpy(fileName, d5);
        break;

    case 'o':
        system("clear || cls");
        printf("Enter a name of file with suffix: ");
        scanf("%s", fileName);
        getchar();
        break;

    case 'x':
        getchar();
        mainMenu();
        break;

    default:
        strcpy(fileName, d1);
        break;
    }

    strcat(fullAddress, fileName);
    FILE* input = fopen(fullAddress, "r");

    if (input != NULL) {
        char temp;
        lineNum = 0;

        while (fscanf(input, "%c", &temp) != EOF) {
            if (temp == 10) {
                lineNum++;
            }
        }

        fseek(input, 0, SEEK_SET);

        for (int i = 0; i <= lineNum; i++) {
            fscanf(input,
                "%[^;];%c;%d;%[^;];%f;%f;%f;%f;%f\n",
                file[i].name,
                &file[i].gender,
                &file[i].date,
                file[i].brand,
                &file[i].lap[0],
                &file[i].lap[1],
                &file[i].lap[2],
                &file[i].lap[3],
                &file[i].lap[4]);
        }

        fclose(input);

        FILE* output = fopen(fullAddress, "w");
        for (int i = 0; i <= lineNum; i++) {
            fprintf(output,
                "%s;%c;%d;%s;%.3f;%.3f;%.3f;%.3f;%.3f\n",
                file[i].name,
                file[i].gender,
                file[i].date,
                file[i].brand,
                file[i].lap[0],
                file[i].lap[1],
                file[i].lap[2],
                file[i].lap[3],
                file[i].lap[4]);
        }
        fprintf(output,
            "%s;%c;%d;%s;%.3f;%.3f;%.3f;%.3f;%.3f",
            name,
            gender,
            date,
            brand,
            lap[0],
            lap[1],
            lap[2],
            lap[3],
            lap[4]);
        fclose(output);

        FILE* lastInput = fopen(fullAddress, "r");

        lineNum = 0;

        while (fscanf(lastInput, "%c", &temp) != EOF) {
            if (temp == 10) {
                lineNum++;
            }
        }

        fseek(lastInput, 0, SEEK_SET);

        for (int i = 0; i <= lineNum; i++) {
            fscanf(lastInput,
                "%[^;];%c;%d;%[^;];%f;%f;%f;%f;%f\n",
                file[i].name,
                &file[i].gender,
                &file[i].date,
                file[i].brand,
                &file[i].lap[0],
                &file[i].lap[1],
                &file[i].lap[2],
                &file[i].lap[3],
                &file[i].lap[4]);
        }

        fclose(lastInput);
        system("clear || cls");
        for (int i = 0; i <= numOfLines(); i++) {
            printf("%s, born %d, %s, Car:%s\nLap times: %.3f;%.3f;%.3f;%.3f;%.3f \n",
                file[i].name, file[i].date, file[i].gender > 108 ? "male" : "female", file[i].brand,
                file[i].lap[0], file[i].lap[1], file[i].lap[2], file[i].lap[3], file[i].lap[4]);
        }
        getchar();
        mainMenu();
    } else {
        printf("Error: Failed to read a file.\n");
        printf("Make sure that \"%s\" in results exists!\n", fileName);
        printf("Press enter to go back to menu...");
        getchar();
        mainMenu();
    }

}

void rmdriver() {
    char surname[128];

    system("clear || cls");

    printf("Enter surname of driver that you want to remove:\n");
    scanf("%s", surname);
    getchar();

    char d1[] = "drivers1.csv";
    char d2[] = "drivers2.csv";
    char d3[] = "drivers3.csv";
    char d4[] = "drivers4.csv";
    char d5[] = "drivers5.csv";
    char fullAddress[150] = "results/";

    system("clear || cls");
    printf("[1]drivers1.csv - default\n");
    printf("[2]drivers2.csv\n");
    printf("[3]drivers3.csv\n");
    printf("[4]drivers4.csv\n");
    printf("[5]drivers5.csv\n");
    printf("[o]Other - enter a filename\n");
    printf("----------\n");
    printf("[x]Back\n");

    char nameOption = getchar();

    switch (nameOption) {
    case '1':
        getchar();
        strcpy(fileName, d1);
        break;

    case '2':
        getchar();
        strcpy(fileName, d2);
        break;

    case '3':
        getchar();
        strcpy(fileName, d3);
        break;

    case '4':
        getchar();
        strcpy(fileName, d4);
        break;

    case '5':
        getchar();
        strcpy(fileName, d5);
        break;

    case 'o':
        system("clear || cls");
        printf("Enter a name of file with suffix: ");
        scanf("%s", fileName);
        getchar();
        break;

    case 'x':
        getchar();
        mainMenu();
        break;

    default:
        strcpy(fileName, d1);
        break;
    }

    strcat(fullAddress, fileName);
    FILE* input = fopen(fullAddress, "r");

    if (input != NULL) {
        char temp;
        char temp2[128];
        char* temp3, * tempSur;
        int length = 0;
        lineNum = 0;

        while (fscanf(input, "%c", &temp) != EOF) {
            if (temp == 10) {
                lineNum++;
            }
        }

        fseek(input, 0, SEEK_SET);

        for (int i = 0; i <= lineNum; i++) {
            fscanf(input,
                "%[^;];%c;%d;%[^;];%f;%f;%f;%f;%f\n",
                file[i].name,
                &file[i].gender,
                &file[i].date,
                file[i].brand,
                &file[i].lap[0],
                &file[i].lap[1],
                &file[i].lap[2],
                &file[i].lap[3],
                &file[i].lap[4]);
            temp3 = file[i].name;
            while (sscanf(temp3, "%s", temp2) == 1) {
                tempSur = temp3;
                length = strlen(temp2);
                temp3 = temp3 + (length + 1);
            }
            strcpy(file[i].surname, tempSur);
        }
        fclose(input);

        char name[128];
        int found = 64000;
        for (int i = 0; i < lineNum; i++) {
            if (strcmp(surname, file[i].surname) == 0) {
                strcpy(name, file[i].name);
                found = i;
            }
        }

        if (found != 64000) {
            FILE* output = fopen(fullAddress, "w");
            for (int i = 0; i <= lineNum; i++) {
                if (i == found) {
                } else if (i == lineNum) {
                    fprintf(output,
                        "%s;%c;%d;%s;%.3f;%.3f;%.3f;%.3f;%.3f",
                        file[i].name,
                        file[i].gender,
                        file[i].date,
                        file[i].brand,
                        file[i].lap[0],
                        file[i].lap[1],
                        file[i].lap[2],
                        file[i].lap[3],
                        file[i].lap[4]);
                } else {
                    fprintf(output,
                        "%s;%c;%d;%s;%.3f;%.3f;%.3f;%.3f;%.3f\n",
                        file[i].name,
                        file[i].gender,
                        file[i].date,
                        file[i].brand,
                        file[i].lap[0],
                        file[i].lap[1],
                        file[i].lap[2],
                        file[i].lap[3],
                        file[i].lap[4]);
                }
            }
            fclose(output);
            system("clear || cls");
            printf("Driver with name \"%s\" was deleted.", name);
            getchar();
            mainMenu();
        } else {
            printf("Surname not found!\n");
            getchar();
            mainMenu();
        }
    } else {
        printf("Error: Failed to read a file.\n");
        printf("Make sure that \"%s\" in results exists!\n", fileName);
        printf("Press enter to go back to menu...");
        getchar();
        mainMenu();
    }
}