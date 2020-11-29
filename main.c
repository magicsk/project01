// writtern by Rastislav Brna
// Licence is available on https://github.com/magicsk/project01
// IDE: Visual Studio Code
// Compiler: gcc  args:-lm -I./include

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <readFile.h>
#include <sum.h>
#include <laps.h>
#include <under.h>
#include <changes.h>

int mainMenu() {
    system("clear || cls");
    printf("[s]List of all values\n");
    printf("[d]List of values by lastname\n");
    printf("[l]Best lap\n");
    printf("[g]Best lap by gender\n");
    printf("[b]Best lap by brand\n");
    printf("[y]Best lap by year\n");
    printf("[a]Best average round\n");
    printf("[u]List of drivers by time\n");
    printf("[c]Change some lap time\n");
    printf("[n]Add new driver\n");
    printf("[r]Remove driver\n");
    printf("----------\n");
    printf("[x]Exit\n");

    char option = getchar();
    getchar();

    switch (option) {
    case 's':
        sum();
        break;

    case 'd':
        driver();
        break;

    case 'l':
        lap();
        break;

    case 'g':
        gender();
        break;

    case 'b':
        brand();
        break;

    case 'y':
        year();
        break;

    case 'a':
        average();
        break;

    case 'u':
        under();
        break;

    case 'c':
        change();
        break;

    case 'n':
        newdriver();
        break;

    case 'r':
        rmdriver();
        break;

    case 'x':
        system("clear || cls");
        printf("Exiting...\n");
        exit(0);
        break;

    default:
        mainMenu();
        break;
    }

    return 0;
}

int main() {

    mainMenu();

    return 0;
}
