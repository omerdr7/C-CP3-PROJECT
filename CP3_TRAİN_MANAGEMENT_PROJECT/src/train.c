#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\train.h" 
//#include <string.h>

Train* createTrain(const char* id) {
    Train* train = (Train*)malloc(sizeof(Train));
    if (!train) {
        printf("Error\n");
        return NULL;
    }
    snprintf(train->trainId, sizeof(train->trainId), "%s", id);
    train->firstWagon = NULL;
    train->wagonCount = 0;
    return train;
}

void addWagon(Train* train, Wagon* newWagon) {
    if (!train || !newWagon) return;

    if (!train->firstWagon) {
        train->firstWagon = newWagon;
    } else {
        Wagon* current = train->firstWagon;
        while (current->next) {
            current = current->next;
        }
        current->next = newWagon;
        newWagon->prev = current;
    }
    train->wagonCount++;
    printf("Added Wagon %d to Train %s.\n", (newWagon->wagonId+1), train->trainId);
}

void removeWagon(Train* train, int wagonId) {
    if (!train || !train->firstWagon) return;

    Wagon* current = train->firstWagon;
    while (current) {
        if (current->wagonId == wagonId) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                train->firstWagon = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            free(current);
            train->wagonCount--;
            printf("Removed Wagon %d from Train %s.\n", wagonId, train->trainId);
            return;
        }
        current = current->next;
    }
    printf("Wagon %d not found in Train %s.\n", wagonId, train->trainId);
}

void displayTrainStatus(const Train* train) {
    if (!train) return;

    printf("Train ID: %s\n", train->trainId);
    printf("Wagon Count: %d\n", train->wagonCount);

    Wagon* current = train->firstWagon;
    while (current) {
        displayWagonStatus(current);
        current = current->next;
    }
}

void emptyTrain(Train* train) {
    if (!train) return;

    Wagon* current = train->firstWagon;
    while (current) {
        Wagon* toFree = current;
        current = current->next;
        free(toFree);
    }
    train->firstWagon = NULL;
    train->wagonCount = 0;
    printf("Train %s is now empty.\n", train->trainId);
}
