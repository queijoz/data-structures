#include "../src/test/test.h"
#include "../src/array/array.h"

int main() {

    int totalTests = 3;
    int size = totalTests;
    Array array = CreateArray(totalTests);

    array.Set(&array, 0, getIntVariant(420));
    array.Set(&array, size, getIntVariant(69));

    Test tests[] = {
        {
            .Name = "Test Array Creation",
            .Expected = getIntVariant(size),
            .Received = getIntVariant(array.size)
        },
        {
            .Name = "Test First Index",
            .Expected = getIntVariant(420),
            .Received = array.Get(&array, 0)
        },
        {
            .Name = "Test Last Index",
            .Expected = getIntVariant(69),
            .Received = array.Get(&array, size-1)
        }
    };

    return test(tests, totalTests);
}
