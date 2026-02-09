#include <iostream>
#include <string>
#include "engine/Translator.h"

/*
    Simple unit test for Translator

    Test logic:
    - Provide known input
    - Compare translator output with expected output
    - PASS if both strings match exactly
    - FAIL otherwise (shows diff-friendly output)
*/

bool runTest(const std::string& testName,
             const std::string& input,
             const std::string& expected) {

    Translator translator;
    std::string output = translator.translate(input);

    if (output == expected) {
        std::cout << "[PASS] " << testName << std::endl;
        return true;
    } else {
        std::cout << "[FAIL] " << testName << std::endl;
        std::cout << "Input:\n" << input << std::endl;
        std::cout << "Expected:\n" << expected << std::endl;
        std::cout << "Got:\n" << output << std::endl;
        return false;
    }
}

int main() {

    int passed = 0;
    int total  = 0;

    // ---------- TEST 1: Single line ----------
    total++;
    passed += runTest(
        "Single line basic",
        "Erai vaaeleththu",
        "இறை வாழ்த்து"
    );

    // ---------- TEST 2: Multiple lines ----------
    total++;
    passed += runTest(
        "Multi-line preserve newline",
        "Erai vaaeleththu\nTamil thai vaazhthu",
        "இறை வாழ்த்து\nதமிழ் தாய் வாழ்த்து"
    );

    // ---------- TEST 3: Preserve spaces ----------
    total++;
    passed += runTest(
        "Preserve spaces",
        "Erai   vaaeleththu",
        "இறை   வாழ்த்து"
    );

    // ---------- SUMMARY ----------
    std::cout << "\nResult: " << passed << " / " << total << " tests passed." << std::endl;

    return (passed == total) ? 0 : 1;
}
