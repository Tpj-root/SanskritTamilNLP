#pragma once
#include <string>
#include <unordered_map>

/*
 PhonemeMapper:
 Maps Sanskrit phonemes → Tamil phonemes.
 This replaces dictionary-based translation.

 Later upgrades:
  - Context-aware mapping
  - Morphology-aware mapping
*/
class PhonemeMapper {
private:
    std::unordered_map<std::string, std::string> phonemeMap;

public:
    PhonemeMapper();
    std::string mapWord(const std::string& word);
};
