#ifndef MATERİAL
#define MATERİAL

typedef struct {
    char name[50];  
    char type[50];      // e.g., "Large Box"
    float weight;         // Weight in kg
    int quantity;         // Total available
    int loaded;          // Currently on train
} MaterialType;
    MaterialType* createMaterial(const char* name, const char* type, float weight, int quantity);
    void displayMaterialStatus(const MaterialType* material);

#endif




