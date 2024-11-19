#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "test.h"

const char GREEN[] = "\033[32m";
const char RED[] = "\033[31m";
const char YELLOW[] = "\033[33m";
const char RESET[] = "\033[0m";

void printTest (Test* test) {

    char* buffer = (char*)malloc(sizeof(char) * 200);

    if (test->Status == Passed) sprintf(buffer, "%s%s%s", GREEN, "✅ PASSED", RESET);
    else sprintf(buffer, "%s%s%s", RED, "❌ FAILED", RESET);

    printf("TEST NAME: %s\n", test->Name);
    printf("STATUS: %s\n", buffer);
    if (test->Status == Failed) {
        printf("EXPECTED: ");
        printVariant(test->Expected);
        printf(" | GOT: ");
        printVariant(test->Received);
        printf("\n");
    }

    free(buffer);
}

int test (Test tests[], int qty) {

    int failed = qty;
    for (int i = 0; i < qty; i++) {
        Test test = tests[i];

        test.Status = compareVariant(test.Expected, test.Received);
        if (test.Status == Passed) failed--;

        printTest(&test);

        freeVariant(test.Expected);
        freeVariant(test.Received);
    }

    printf("\nTotal: %d | Passed: %d | Failed: %d\n", qty, qty - failed, failed);
    return 0;
}
