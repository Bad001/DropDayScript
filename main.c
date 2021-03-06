#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dropdaylib.h"
#include "ansiescapes.h"

int main() {
  unsigned short int choice = 0;
  setupConsole();
  srand(time(NULL));
  do {
    printMenu();
    printf(" --> ");
    scanf("%hu", &choice);
    while (getchar()!='\n');
    switch(choice) {
      case 1: fixHouseNumberESP();
        break;
      case 2: numberForAccountGen();
        break;
      case 3: printf(" Bye! :D\n");
        break;
      default: printf(" The choice does not exist...\n");
    }
  } while(choice != 3);
  restoreConsole();
  return 0;
}