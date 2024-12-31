#include <stdio.h>
#include "C:\Users\hp\OneDrive\Desktop\CP3_TRAİN_MANAGEMENT_PROJECT\include\util.h" 
#include <stdlib.h>

void pauseExecution() {
    printf("Press Enter to continue...");
    getchar();
}

void printLine(char ch, int count) {
    for (int i = 0; i < count; i++) {
        putchar(ch);
    }
    putchar('\n');
}