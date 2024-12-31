#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\train.h"
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\material.h"
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\file_ops.h"
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\wagon.h" 
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\util.h"
#define MAX_MATERIALS 100

void displayMenu() {
    printf("=== Train Loading Management System ===\n");
    printf("1. Load train status from file\n");
    printf("2. Load material, starting from first suitable wagon from head of the train\n");
    printf("3. Load material to specific wagon\n");
    printf("4. Unload material, starting from first suitable wagon from tail of the train\n");
    printf("5. Unload material from specific wagon\n");
    printf("6. Display train status\n");
    printf("7. Display materials status\n");
    printf("8. Empty train\n");
    printf("9. Save train status to file\n");
    printf("10. Exit\n");
}

int main() {
    Train* train = createTrain("T123");
    MaterialType materials[MAX_MATERIALS];
    Wagon wagons[MAX_MATERIALS];
    int materialCount = 3;
    Wagon wagon;
    int choice;
    int wagonId, quantity;
    char materialName[50];
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);        
        switch (choice) {
            case 1:
                loadTrainStatus(train);
                loadMaterialStatusFromFile(materials,materialCount);
                loadWagonstatusFromFile(wagons,materialCount);
                break;

            case 2:     
                printf("Enter material name: ");//You have to write the name like this LargeBox or MediumBox or SmallBox
                scanf("%s",materialName);
                printf("Quantity to load: ");
                scanf("%d", &quantity);
                for (int i = 0; i < materialCount; i++) {
                    printf("%s%d\n",materials[i].name,materials[i].weight);
                    if (strcmp(materials[i].name, materialName) == 0) {
                        loadMaterialToWagon(&wagon, &materials[i], quantity);
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter wagon ID: ");
                scanf("%d", &wagonId);
                printf("Enter material name: ");//You have to write the name like this LargeBox or MediumBox or SmallBox      
                scanf("%s",materialName);
                printf("Quantity to unload: ");
                scanf("%d", &quantity);
                //getchar();
                for (int i = 0; i < materialCount; i++) {
                    if (strcmp(materials[i].name, materialName) == 0) {
                        Wagon* current = train->firstWagon;
                        while (current) {
                            if (current->wagonId == wagonId) {
                                loadMaterialToWagon(current, &materials[i], quantity);
                                break;
                            }
                            current = current->next;
                        }
                        break;
                    }
                }
                pauseExecution();
                break;

            case 4:
                printf("Enter material name: "); //You have to write the name like this LargeBox or MediumBox or SmallBox     
                scanf("%s",materialName);
                printf("Quantity to unload: ");
                scanf("%d", &quantity);
                //getchar();
                for (int i = 0; i < materialCount; i++) {
                    if (strcmp(materials[i].name, materialName) == 0) {
                        Wagon* current = train->firstWagon;
                        while (current) {
                            unloadMaterialFromWagon(current, &materials[i], quantity);
                            current = current->next;
                        }
                        break;
                    }
                }
                pauseExecution();
                break;

            case 5:
                printf("Enter wagon ID: ");
                scanf("%d", &wagonId);
                printf("Enter material name: ");//You have to write the name like this LargeBox or MediumBox or SmallBox      
                scanf("%s",materialName);
                printf("Quantity to unload: ");
                scanf("%d", &quantity);
                //getchar();
                for (int i = 0; i < materialCount; i++) {
                    if (strcmp(materials[i].name, materialName) == 0) {
                        Wagon* current = train->firstWagon;
                        while (current) {
                            if (current->wagonId == wagonId) {
                                unloadMaterialFromWagon(current, &materials[i], quantity);
                                break;
                            }
                            current = current->next;
                        }
                        break;
                    }
                }
                pauseExecution();
                break;

            case 6:
                displayTrainStatus(train);
                pauseExecution();
                break;

            case 7:
                for (int i = 0; i < materialCount; i++) {
                    displayMaterialStatus(&materials[i]);
                }
                pauseExecution();
                break;

            case 8:
                emptyTrain(train);
                printf("Train emptied successfully.\n");
                pauseExecution();
                break;

            case 9:
            if(saveTrainStatusFile(train)==0){
                printf("Save succesfull.");
            }
                pauseExecution();
                break;

            case 10:
                printf("Program closing.\n");
                break;

            default:
                printf("Invalid choice. Please give a number between 1-10.\n");
                pauseExecution();
                break;
        }
    } while (choice != 10);

    emptyTrain(train);
    free(train);
    return 0;
}
//OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT
/*
gcc -Iinclude -c src/main.c -o main.o
gcc -Iinclude -c src/train.c -o train.o
gcc -Iinclude -c src/wagon.c -o wagon.o
gcc -Iinclude -c src/material.c -o material.o
gcc -Iinclude -c src/fiel_ops.c -o file_ops.o
gcc -Iinclude -c src/util.c -o utils.o
*/
//gcc main.o train.o wagon.o material.o file_ops.o utils.o -o program
//./program
