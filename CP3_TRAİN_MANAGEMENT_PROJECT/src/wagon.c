#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\wagon.h" 
#include <stdio.h>
#include <stdlib.h>

Wagon* createWagon(int id, float maxWeight) {
    Wagon* wagon = (Wagon*)malloc(sizeof(Wagon));
    if (!wagon) {
        printf("Memory allocation failed for Wagon\n");
        return NULL;
    }
    wagon->wagonId = id;
    wagon->maxWeight = maxWeight;
    wagon->currentWeight = 0;
    wagon->loadedMaterials = NULL;
    wagon->next = NULL;
    wagon->prev = NULL;
    return wagon;
}

void loadMaterialToWagon(Wagon* wagon, MaterialType* material, int quantity) {
    wagon->wagonId=createWagon(4,1000)->wagonId;
    wagon->maxWeight=createWagon(4,1000)->maxWeight;
    if (!wagon || !material) return;
    printf("%f\n",material->weight);
    printf("%d\n",quantity);
    float totalWeight = (material->weight * quantity); 
    printf("%f\n",totalWeight);
    printf("%f\n",wagon->currentWeight);
    if ((wagon->currentWeight + totalWeight) > wagon->maxWeight) {
        printf("Wagon %d cannot take more weight.\n", wagon->wagonId);
        return;
    }
    LoadedMaterial* newMaterial = (LoadedMaterial*)malloc(sizeof(LoadedMaterial));
    if (!newMaterial) {
        printf("Memory allocation failed for Loaded Material\n");
        return;
    }
    newMaterial->type = material;
    newMaterial->next = wagon->loadedMaterials;
    newMaterial->prev = NULL;

    if (wagon->loadedMaterials) {
        wagon->loadedMaterials->prev = newMaterial;
    }
    wagon->loadedMaterials = newMaterial;

    wagon->currentWeight += totalWeight;
    material->loaded += quantity;
    printf("Loaded %d units of %s to Wagon %d.\n", quantity, material->name, wagon->wagonId);
}

void unloadMaterialFromWagon(Wagon* wagon, MaterialType* material, int quantity) {
    if (!wagon || !material) return;

    LoadedMaterial* current = wagon->loadedMaterials;
    while (current) {
        if (current->type == material) {
            int unloadQty = (current->type->loaded < quantity) ? current->type->loaded : quantity;
            wagon->currentWeight -= unloadQty * material->weight;
            material->loaded -= unloadQty;
            quantity -= unloadQty;

            if (quantity == 0) {
                printf("Unloaded %d units of %s from Wagon %d.\n", unloadQty, material->name, wagon->wagonId);
                return;
            }
        }
        current = current->next;
    }
    printf("Could not unload requested quantity from Wagon %d.\n", wagon->wagonId);
}

void displayWagonStatus(const Wagon* wagon) {
    if (!wagon) return;

    printf("Wagon ID: %d\n", wagon->wagonId);
    printf("Max Weight: %.2f\n", wagon->maxWeight);
    printf("Current Weight: %.2f\n", wagon->currentWeight);
    printf("Loaded Materials:\n");

    LoadedMaterial* current = wagon->loadedMaterials;
    while (current) {
        printf("- %s: %d units\n", current->type->name, current->type->loaded);
        current = current->next;
    }
}
