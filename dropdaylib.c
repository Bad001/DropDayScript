#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dropdaylib.h"

char* string;
FILE* file;

char* randomLetters(int jigLength) {
    if(string != NULL) {
        free(string);
    }
    string = calloc(jigLength, sizeof(char*));
    for(int i = 0; i < jigLength; i++) {
        string[i] = (char)((rand() % 26)+65);
    }
    return string;
}

void fixHouseNumberESP() {
    int profiles = 0, jigLength = 4;
    unsigned short int choice = 0;
    char fileName[200];
    printf(" Digit the numbers of ESP profiles: ");
    scanf("%d", &profiles);
    while (getchar()!='\n');    // Clean the buffer
    printf(" Where would you like to save your jig:\n 1) Print on the CLI 2) Save on a .txt file 3) Modify your \"profiles.csv\" for you\n 4) Return to main menu'\n");
    do {
        printf(" Choose the mode or insert \"4\" to exit: ");
        scanf("%hu", &choice);
        while (getchar()!='\n');
        switch(choice) {
            case 1:
                for(int i = 0; i < profiles; i++) {
                    printf("22 BAI%s\n", randomLetters(jigLength));
                }
            break;
            case 2:
                printf(" Write your directory and file name to save the results\n or only file name (if you want the file on the same DIR of the script): ");
                scanf("%s", fileName);
                if((file = fopen(fileName,"w")) == NULL) {
                    printf(" Error to create the file!\n");
                }
                else {
                    for(int i = 0; i < profiles; i++) {
                        fprintf(file,"%s%s\n","22 BAI",randomLetters(jigLength));
                    }
                    fclose(file);
                    printf(" %d HouseNumbers saved on %s!\n", profiles, fileName);
                }
            break;
            case 3: printf(" Work in progress...\n");
            break;
            case 4: printf(" Returning to main menu'...\n");
            break;
            default: printf(" The choice does not exist...\n");
        }
    } while(choice != 4);
}

void numberForAccountGen() {
    unsigned short int choice = 0;
    int profiles = 0;
    printf(" Many Sneaker's bots on the accounts gen section requires a list of your profiles that you want to generate.\n");
    printf(" Usually this procedure is annoying because the bot ask you to select the following profiles with numbers\n");
    printf(" and there isn't an option to select ALL without write one by one the numbers for example \"1+2...+20\"\n");
    printf(" or different character separator like \"1-2...-20\" or \"1,2...,20\" this module allows you to select all your\n");
    printf(" profiles and paste on your Bot to speed up this procedure\n");
    printf(" Available templates: \n");
    printf(" 1) \"1+2...+20\"\n");
    printf(" 2) \"1-2...-20\"\n");
    printf(" 3) \"1,2...,20\"\n");
    printf(" 4) \"1\n     2\n     .\n     .\n     .\n     3\"\n");
    printf(" Digit the number of profiles: ");
    scanf("%d", &profiles);
    while (getchar()!='\n');
    do {
    printf(" Choose the template or insert \"5\" to exit: ");
    scanf("%hu", &choice);
    while (getchar()!='\n');
    switch(choice) {
      case 1:
      printf(" ");
        for(int i = 0; i < profiles; i++) {
            if(i == profiles-1) {
                printf("%d", i+1);
            }
            else {
                printf("%d+", i+1);
            }
        }
        printf("\n");
        break;
      case 2:
      printf(" ");
        for(int i = 0; i < profiles; i++) {
            if(i == profiles-1) {
                printf("%d", i+1);
            }
            else {
                printf("%d-", i+1);
            }
        }
        printf("\n");
        break;
      case 3:
      printf(" ");
        for(int i = 0; i < profiles; i++) {
            if(i == profiles-1) {
                printf("%d", i+1);
            }
            else {
                printf("%d,", i+1);
            }
        }
        printf("\n");
        break;
      case 4:
        for(int i = 0; i < profiles; i++) {
            printf(" %d\n", i+1);
        }
        break;
      case 5: printf(" Returning to main menu'...\n");
        break;
      default: printf(" The choice does not exist...\n");
    }
  } while(choice != 5);
}

void printMenu() {
    printf("                                                                                \n");
    printf("                               ,(&&*,&&************      DropDayScript 1.0      \n");
    printf("                           ****,%%*&&&&&/***************  1) Fix HouseNumber ESP \n");
    printf("                        ((((/***(,*.&&&.******************  2) List of numbers to gen account with bots \n");
    printf("               *#####/(((((/,,***/.,&,************,,,*****,*. 3) Exit the program \n");
    printf("     .############## (((((((//((((**********.*(((*(((((((((((( ##*              \n");
    printf("    ###############/(((((((((((.**,**********,(((((((((((((((((,#######,        \n");
    printf("       ,##########,((((((((,*************,(((**.(((.**((*((((((( ############*  \n");
    printf("           ###### (((,**,.***************,(((((,****,((((.(((((((#########(     \n");
    printf("              . * **,((***,,************((((((((((((((((./(((((((, ###          \n");
    printf("            ##########/  ,(.***********((((((((((((((*,(((***,*  (###/          \n");
    printf("          ,####################, ,******.(((((((((((*  /###############*        \n");
    printf("         ##############################(  *  *###########################*      \n");
    printf("       ##################################   ###############################,    \n");
    printf("             /########################## # # .########################(         \n");
    printf("              ###,   ################## ## ### ################,   #            \n");
    printf("              ###########.  .######### ### #### #######(   *########            \n");
    printf("              ##################(   , #### #####   .(###############            \n");
    printf("              ############################ #########################            \n");
    printf("              ############################ #########################            \n");
    printf("              ############################ #########################            \n");
    printf("              ############################ #########&&##############            \n");
    printf("                     (#################### ##@#&.&/&@@##########/               \n");
    printf("                             .############ ##@*@@@@@&##/                        \n");
    printf("                                      *### ###*                                 \n");
}