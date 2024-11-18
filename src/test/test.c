#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../variant/variant.h"

const char GREEN[] = "\033[32m";
const char RED[] = "\033[31m";
const char YELLOW[] = "\033[33m";
const char RESET[] = "\033[0m";

enum TestStatus { Failed, Passed };

typedef struct {
    char Name[200];
    enum TestStatus Status;
    Variant* Expected;
    Variant* Received;
} Test;

void printTest (Test* test) {

    char* buffer = (char*)malloc(sizeof(char) * 200);

    if (test->Status == Passed) sprintf(buffer, "%s%s%s", GREEN, "✅ PASSED", RESET);
    else sprintf(buffer, "%s%s%s", RED, "❌ FAILED", RESET);

    printf("TEST NAME: %s\n", test->Name);
    printf("STATUS: %s\n", buffer);

    free(buffer);
}

void test (Test tests[], int qty) {

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
}

int main() {

    Test tests[] = {
        {
            .Name = "Test Int Type",
            .Expected = getIntVariant(42),
            .Received = getIntVariant(42)
        },
        {
            .Name = "Test Char Type",
            .Expected = getCharVariant('c'),
            .Received = getCharVariant('c')
        },
        {
            .Name = "Test Float Type",
            .Expected = getFloatVariant(2.5),
            .Received = getFloatVariant(2.5)
        },
        {
            .Name = "Test Int Type 2",
            .Expected = getIntVariant(0),
            .Received = getIntVariant(0)
        }
    };

    test(tests, 4);

    return 0;
}