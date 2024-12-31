#include <stdio.h>
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\file_ops.h" 
//#define MAX_LINE_LENGTH 256
#include <stdlib.h>
#include <string.h>
#define MAX_MATERIALS 100

int loadTrainStatus(Train* train) {
    FILE* file = fopen("src\\dosya.txt", "r");
    if (file==NULL) {
        printf("Error: Could not open file for reading.\n");
        return -1;
    }
    fscanf(file, "TRAIN:%s:%d\n",train->trainId, &train->wagonCount);
    train->firstWagon = NULL;
    printf("%s %d\n",train->trainId,train->wagonCount);
    //T123:3 0
    for (int i = 0; i < train->wagonCount; i++) {
        if(train->trainId==NULL){
            break;
        }
        Wagon* newWagon = (Wagon*)malloc(sizeof(Wagon));
        if (!newWagon) {
            printf("Error\n");
            fclose(file);
            return 0;
        }
        fscanf(file, "WAGON:%d:%f:%f\n", &newWagon->wagonId, &newWagon->maxWeight, &newWagon->currentWeight);
        printf("%d %f %f\n",&newWagon->wagonId, &newWagon->maxWeight, &newWagon->currentWeight);
        newWagon->loadedMaterials = NULL;
        newWagon->next = NULL;
        newWagon->prev = NULL;
        addWagon(train, newWagon);
    }

    fclose(file);
    printf("Train status loaded successfully.\n");
    printf("-----------------\n");
    return 0;
}

int saveTrainStatusFile(const Train* train) {
    FILE* file = fopen("src\\dosya.txt", "w");
    if (file==NULL) {
        printf("Error: Could not open file for writing.\n");
        return 0;
    }

    fprintf(file, "TRAIN:%s:%d\n", train->trainId, train->wagonCount);

    Wagon* current = train->firstWagon;
    while (current) {
        fprintf(file, "WAGON:%d:%.2f:%.2f\n", current->wagonId, current->maxWeight, current->currentWeight);
        current = current->next;
    }

    fclose(file);
    printf("Train status saved successfully.\n");
    return 0;
}

int loadMaterialStatusFromFile(MaterialType materials[], int materialCount) {
    FILE* file = fopen("src\\dosya.txt", "r");
    if (file==NULL) {
        printf("Error: Could not open file for reading.\n");
        return 0;
    }
    materialCount = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if(line[0]==' '){
            break;
        }
        if (line[0] == 'M' && line[1] == ':') {
            if (materialCount >= MAX_MATERIALS) {
                fprintf(stderr, "Maximum material number.!\n");
                break;
            }

            sscanf(line, "M:%49[^:]:%49[^:]:%f:%d:%d", 
                   materials[materialCount].name,
                   materials[materialCount].type,
                   &materials[materialCount].weight,
                   &materials[materialCount].quantity,
                   &materials[materialCount].loaded);

            materialCount++;
        }
    }
    for (int i = 0; i < materialCount; i++) {
        printf("Name: %s\n", materials[i].name);
        printf("Type: %s\n", materials[i].type);
        printf("Weight: %.2f\n", materials[i].weight);
        printf("Quantity: %d\n", materials[i].quantity);
        printf("Loaded: %d\n", materials[i].loaded);
        printf("-----------------\n");
    }
    fclose(file);
    printf("Material status loaded successfully.\n");
    printf("\n");
    return 0;
}

int saveMaterialStatusToFile(const MaterialType materials[], int materialCount) {
    FILE* file = fopen("src\\dosya.txt", "w");
    if (file==NULL) {
        printf("Error: Could not open file for writing.\n");
        return 0;
    }

    fprintf(file, "MATERIALS:%d\n", materialCount);
    for (int i = 0; i < materialCount; i++) {
        if(i==3){
            break;
        }
        fprintf(file, "M:%s:%s:%.2f:%d:%d\n", materials[i].name, materials[i].type, materials[i].weight, materials[i].quantity, materials[i].loaded);
    }

    fclose(file);
    printf("Material status saved successfully.\n");
    return 0;
}

int loadWagonstatusFromFile(Wagon wagons[], int materialCount) {
    FILE* file = fopen("src\\dosya.txt", "r");
    if (file==NULL) {
        printf("Error: Could not open file for reading.\n");
        return 0;
    }
    materialCount = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if(line[0]==' '){
            break;
        }
        if (line[0] == 'W' && line[5] == ':') {
            if (materialCount >= MAX_MATERIALS) {
                fprintf(stderr, "Maximum material number.!\n");
                break;
            }

            sscanf(line, "WAGON:%d:%f:%f", 
                   &wagons[materialCount].wagonId,
                   &wagons[materialCount].maxWeight,
                   &wagons[materialCount].currentWeight);

            materialCount++;
        }
    }
    for (int i = 0; i < materialCount; i++) {
        printf("Wagon id: %d\n", wagons[i].wagonId);
        printf("Max Weight: %f\n", wagons[i].maxWeight);
        printf("Current Weight: %f\n", wagons[i].currentWeight);
        printf("-----------------\n");
    }
    fclose(file);
    printf("Wagon status loaded successfully.\n");
    return 0;
}

int saveWagonsStatusToFile(const Wagon wagons[], int materialCount) {
    FILE* file = fopen("src\\dosya.txt", "w");
    if (file==NULL) {
        printf("Error: Could not open file for writing.\n");
        return 0;
    }

    for (int i = 0; i < materialCount; i++) {
        if(i==3){
            break;
        }
        fprintf(file, "WAGON:%d:%f:%f\n", wagons[i].wagonId, wagons[i].maxWeight, wagons[i].currentWeight);
    }

    fclose(file);
    printf("Wagon status saved successfully.\n");
    return 0;
}


    /*if(train->first_wagon==NULL){
        printf("Train is null and avoid for loading.");
    }else{
        Wagon* currentWagon=train->first_wagon;
        while (currentWagon!=NULL){
            printf("Vagon %d,Max Kapasite:%f, Current Weight:%f\n", 
            currentWagon->wagon_id, currentWagon->max_weight, currentWagon->current_weight);
        currentWagon = currentWagon->next;
        }
        
    }*/
/*void load_train_from_file(Train *train, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Dosya açılamadı: %s\n", filename);
        return;
    }*/