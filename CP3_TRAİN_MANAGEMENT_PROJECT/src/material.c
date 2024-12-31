#include <stdio.h>
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\material.h"
#include <stdlib.h>
//#include <string.h>

MaterialType* createMaterial(const char* name, const char* type, float weight, int quantity) {
    MaterialType* material = (MaterialType*)malloc(sizeof(MaterialType));
    if (!material) {
        printf("Error\n");
        return NULL;
    }
    snprintf(material->name, sizeof(material->name), "%s", name);
    snprintf(material->type, sizeof(material->type), "%s", type);
    material->weight = weight;
    material->quantity = quantity;
    material->loaded = 0;
    return material;
}

void displayMaterialStatus(const MaterialType* material) {
    if (!material) return;

    printf("Material Name: %s\n", material->name);
    printf("Type: %s\n", material->type);
    printf("Weight: %.2f\n", material->weight);
    printf("Quantity: %d\n", material->quantity);
    printf("Loaded: %d\n", material->loaded);
}