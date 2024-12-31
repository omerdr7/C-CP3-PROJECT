#ifndef FILE_OPS
#define FILE_OPS
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\material.h"
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\train.h"

int loadTrainStatus(Train* train);
int saveTrainStatusFile(const Train* train);
int loadMaterialStatusFromFile(MaterialType materials[], int materialCount);
int saveMaterialStatusToFile(const MaterialType materials[], int materialCount);
int loadWagonstatusFromFile(Wagon wagons[], int materialCount);
int saveWagonsStatusToFile(const Wagon wagons[], int materialCount);

#endif



