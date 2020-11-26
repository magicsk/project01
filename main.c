// writtern by Rastislav Brna
// Licence is available on https://github.com/magicsk/project01
// IDE: Visual Studio Code
// Compiler: gcc  args:-lm

#include <stdio.h>

int main(){

    system("clr || clear");
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

    switch (option){
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

        default:
            getchar();
            main();
            break;
    }

    return 0;
}
