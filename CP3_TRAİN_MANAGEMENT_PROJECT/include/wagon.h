#ifndef WAGON
#define WAGON
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\material.h"

typedef struct LoadedMaterial {
MaterialType* type;   // Type of box
struct LoadedMaterial *next, *prev;
} LoadedMaterial; 

typedef struct Wagon {
    int wagonId;        // Sequential 
    float maxWeight;
    float currentWeight;
    LoadedMaterial* loadedMaterials;
    struct Wagon *next, *prev;
} Wagon;
    Wagon* createWagon(int id, float maxWeight);
    void loadMaterialToWagon(Wagon* wagon, MaterialType* material, int quantity);
    void unloadMaterialFromWagon(Wagon* wagon, MaterialType* material, int quantity);
    void displayWagonStatus(const Wagon* wagon);
#endif




