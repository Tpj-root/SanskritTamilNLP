#include "PhonemeMapper.h"

/*
 Very primitive phoneme mapping.
 This is NOT linguistically perfect.
 Purpose: working foundation.
*/

PhonemeMapper::PhonemeMapper() {

    /* ===============================
       5–4 CHARACTER PHONEMES (rare)
       =============================== */
    phonemeMap["nggaa"] = "ங்கா";
    phonemeMap["ththaa"] = "த்தா";

    /* ===============================
       3 CHARACTER PHONEMES
       =============================== */
    phonemeMap["ngaa"] = "ங்கா";
    phonemeMap["nga"]  = "ங்க";
    phonemeMap["nya"]  = "ஞ";
    phonemeMap["sha"]  = "ஷ";
    phonemeMap["kha"]  = "க";
    phonemeMap["gha"]  = "க";
    phonemeMap["cha"]  = "ச";
    phonemeMap["jha"]  = "ஜ";
    phonemeMap["tha"]  = "த";
    phonemeMap["dha"]  = "த";
    phonemeMap["pha"]  = "ப";
    phonemeMap["bha"]  = "ப";

    /* ===============================
       2 CHARACTER PHONEMES
       =============================== */
    phonemeMap["aa"] = "ஆ";
    phonemeMap["ii"] = "ஈ";
    phonemeMap["uu"] = "ஊ";
    phonemeMap["ee"] = "ஏ";
    phonemeMap["ai"] = "ஐ";
    phonemeMap["oo"] = "ஓ";
    phonemeMap["au"] = "ஔ";

    phonemeMap["ka"] = "க";
    phonemeMap["ga"] = "க";
    phonemeMap["ca"] = "ச";
    phonemeMap["sa"] = "ச";
    phonemeMap["ta"] = "த";
    phonemeMap["da"] = "த";
    phonemeMap["na"] = "ந";
    phonemeMap["pa"] = "ப";
    phonemeMap["ba"] = "ப";
    phonemeMap["ma"] = "ம";
    phonemeMap["ya"] = "ய";
    phonemeMap["ra"] = "ர";
    phonemeMap["la"] = "ல";
    phonemeMap["va"] = "வ";
    phonemeMap["ha"] = "ஹ";

    phonemeMap["zh"] = "ழ";
    phonemeMap["ll"] = "ள";
    phonemeMap["rr"] = "ற";
    phonemeMap["nn"] = "ண";

    /* ===============================
       1 CHARACTER PHONEMES (fallback)
       =============================== */
    phonemeMap["a"] = "அ";
    phonemeMap["i"] = "இ";
    phonemeMap["u"] = "உ";
    phonemeMap["e"] = "எ";
    phonemeMap["o"] = "ஒ";

    phonemeMap["k"] = "க";
    phonemeMap["c"] = "ச";
    phonemeMap["t"] = "த";
    phonemeMap["n"] = "ந";
    phonemeMap["p"] = "ப";
    phonemeMap["m"] = "ம";
    phonemeMap["y"] = "ய";
    phonemeMap["r"] = "ர";
    phonemeMap["l"] = "ல";
    phonemeMap["v"] = "வ";
    phonemeMap["s"] = "ச";
    phonemeMap["h"] = "ஹ";
}


// PhonemeMapper::PhonemeMapper() {
//     // Example mappings (you can extend freely)
//     phonemeMap["nga"] = "ங";
//     phonemeMap["cha"] = "ச";
//     phonemeMap["ra"]  = "ர";
//     phonemeMap["ma"]  = "ம";
//     phonemeMap["ga"]  = "க";
//     phonemeMap["ti"]  = "தி";
//     phonemeMap["na"]  = "ந";
//     phonemeMap["va"]  = "வ";
//     phonemeMap["a"]   = "அ";
// }


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

        bool matched = false;

        // Try phoneme lengths: 5 → 4 → 3 → 2 → 1
        for (int len = 5; len >= 1; --len) {

            // Ensure substring does not go out of bounds
            if (i + len > word.size())
                continue;

            std::string chunk = word.substr(i, len);
            auto it = phonemeMap.find(chunk);

            if (it != phonemeMap.end()) {
                result += it->second;
                i += len;
                matched = true;
                break;  // stop once longest match is found
            }
        }

        // If nothing matched, skip safely
        if (!matched) {
            i += 1;
        }
    }

    return result.empty() ? "[UNMAPPED]" : result;
}
