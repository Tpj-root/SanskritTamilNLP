#include "PhonemeMapper.h"

/*
 Very primitive phoneme mapping.
 This is NOT linguistically perfect.
 Purpose: working foundation.
*/
PhonemeMapper::PhonemeMapper() {
    phonemeMap["ra"] = "ர";
    phonemeMap["ma"] = "ம";
    phonemeMap["ga"] = "க";
    phonemeMap["ch"] = "ச்";
    phonemeMap["cha"] = "ச";
    phonemeMap["ti"] = "தி";
    phonemeMap["na"] = "ந";
    phonemeMap["va"] = "வ";
    phonemeMap["a"]  = "அ";
}

// /*
//  Maps a Sanskrit word into Tamil-like phoneme string
// */
// std::string PhonemeMapper::mapWord(const std::string& word) {
//     std::string result;

//     // VERY naive scanning (upgrade later)
//     for (size_t i = 0; i < word.size(); ++i) {
//         std::string p(1, word[i]);
//         auto it = phonemeMap.find(p);
//         if (it != phonemeMap.end())
//             result += it->second;
//     }
//     return result.empty() ? "[UNMAPPED]" : result;
// }

std::string PhonemeMapper::mapWord(const std::string& word) {
    std::string result;

    for (size_t i = 0; i < word.size();) {

        // 1️⃣ Try TWO-character phoneme (ra, ma, cha, etc.)
        if (i + 1 < word.size()) {
            std::string two = word.substr(i, 2);
            auto it2 = phonemeMap.find(two);
            if (it2 != phonemeMap.end()) {
                result += it2->second;
                i += 2;
                continue;
            }
        }

        // 2️⃣ Try ONE-character phoneme (a, i, u)
        std::string one = word.substr(i, 1);
        auto it1 = phonemeMap.find(one);
        if (it1 != phonemeMap.end()) {
            result += it1->second;
            i += 1;
            continue;
        }

        // 3️⃣ Unknown character → skip safely
        i += 1;
    }

    return result.empty() ? "[UNMAPPED]" : result;
}
