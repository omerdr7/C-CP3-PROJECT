#ifndef TRAIN
#define TRAIN
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\wagon.h"

typedef struct {
char trainId[20];
Wagon* firstWagon;
int wagonCount;
} Train;

Train* createTrain(const char* id);
void addWagon(Train* train, Wagon* newWagon);
void removeWagon(Train* train, int wagonId);
void displayTrainStatus(const Train* train);
void emptyTrain(Train* train);

#endif



