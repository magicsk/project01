// writtern by Rastislav Brna
// Licence is available on https://github.com/magicsk/project01
// IDE: Visual Studio Code
// Compiler: gcc  args:-lm -I./include

int lineNum = 0;
char fileName[50];

struct Content {
    char name[128];
    char surname[128];
    char gender;
    int date;
    char brand[128];
    float lap[5];
} file[128];

struct Content* readFile() {
    lineNum = 0;
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

        return file;
    } else {
        printf("Error: Failed to read a file.\n");
        printf("Make sure that \"%s\" in results exists!\n", fileName);
        printf("Press enter to go back to menu...");
        getchar();
        mainMenu();
    }
}

int numOfLines() {
    return lineNum;
}

char* nameOfFile() {
    return fileName;
}