#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

/* ---------- Token ---------- */
class Token {
public:
    std::string text;
    explicit Token(const std::string& t) : text(t) {}
};

/* ---------- Tokenizer ---------- */
class Tokenizer {
public:
    std::vector<Token> tokenize(const std::string& input) {
        std::stringstream ss(input);
        std::string word;
        std::vector<Token> tokens;

        while (ss >> word) {
            tokens.emplace_back(word);
        }
        return tokens;
    }
};

/* ---------- Lexicon ---------- */
class SanskritTamilLexicon {
private:
    std::unordered_map<std::string, std::string> dict;

public:
    SanskritTamilLexicon() {
        // Very basic dictionary (expand later)
        dict["rama"] = "ராமன்";
        dict["gachchati"] = "செல்கிறான்";
        dict["vanam"] = "காடு";
    }

    std::string translate(const std::string& word) const {
        auto it = dict.find(word);
        if (it != dict.end())
            return it->second;
        return "[UNKNOWN]";
    }
};

/* ---------- Translator ---------- */
class Translator {
private:
    Tokenizer tokenizer;
    SanskritTamilLexicon lexicon;

public:
    std::string translate(const std::string& input) {
        auto tokens = tokenizer.tokenize(input);
        std::string output;

        for (const auto& token : tokens) {
            output += lexicon.translate(token.text) + " ";
        }
        return output;
    }
};

/* ---------- Main ---------- */
int main() {
    Translator translator;

    std::string input;
    std::cout << "Enter Sanskrit (IAST): ";
    std::getline(std::cin, input);

    std::string result = translator.translate(input);
    std::cout << "Tamil Output: " << result << std::endl;

    return 0;
}
