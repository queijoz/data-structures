#include "../src/test/test.h"

int main() {

    int totalTests = 4;

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

    return test(tests, totalTests);
}
