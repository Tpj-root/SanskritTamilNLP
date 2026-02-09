# SanskritTamilNLP
Natural Language Processing system for Sanskrit to Tamil language processing/translation.



```md
# Sanskrit → Tamil Translator (C++ OOP)

A step-by-step project to build a **rule-based + extensible Sanskrit to Tamil translator** using **C++ (Object-Oriented Programming)**.  
Designed to grow from **basics → advanced → research-grade**.

---

## 🎯 Goal
- Translate **Sanskrit words/sentences → Tamil**
- Start with **script + grammar rules**
- Later support **sandhi, samasa, morphology**
- Keep architecture clean, modular, and extensible

---

## 🧠 Learning Path (Concept → Code)

### Phase 1: Language Foundations
**What to learn**
- Sanskrit:
  - Devanagari / IAST
  - Varnas (vowels, consonants)
  - Simple nouns & verbs
- Tamil:
  - Uyir, Mei, Uyirmei
  - Agglutination basics

**Output**
- Character & phoneme mapping table

---

### Phase 2: System Architecture (OOP)

```

src/
├── core/
│    ├── Token.h
│    ├── Tokenizer.h
│    ├── Phoneme.h
│    ├── Mapper.h
│    └── GrammarRule.h
├── sanskrit/
│    ├── SanskritTokenizer.h
│    ├── SandhiSplitter.h
│    └── SanskritLexicon.h
├── tamil/
│    ├── TamilGenerator.h
│    └── TamilMorphology.h
├── engine/
│    ├── Translator.h
│    └── Pipeline.h
└── main.cpp

````

---

### Phase 3: Core Classes (OOP Design)

#### Token
- Represents word / morpheme / phoneme

#### Tokenizer
- Splits Sanskrit input
- Handles sandhi (later)

#### Mapper
- Sanskrit → Tamil phoneme mapping

#### GrammarRule (Base Class)
```cpp
class GrammarRule {
public:
    virtual bool apply(Token& t) = 0;
    virtual ~GrammarRule() = default;
};
````

---

### Phase 4: Translation Pipeline

```
Input Sanskrit
   ↓
Tokenizer
   ↓
Sandhi Splitter
   ↓
Lexicon Lookup
   ↓
Grammar Rules
   ↓
Tamil Morphology
   ↓
Tamil Output
```

---

### Phase 5: Lexicon (Dictionary)

* Store as:

  * JSON / CSV / SQLite
* Fields:

  * Root
  * POS (noun/verb)
  * Gender / tense
  * Tamil equivalent

Example:

```
गच्छति → செல்கிறான்
```

---

### Phase 6: Advanced Grammar (Later)

* Sandhi rules
* Samasa (compound words)
* Vibhakti → Tamil case suffix
* Verb tense & person agreement

---

## 🛠️ Tech Stack

* Language: **C++17 / C++20**
* Build: **CMake**
* Style: **OOP + SOLID**
* Optional:

  * ICU (Unicode)
  * SQLite (dictionary)
  * Unit tests (Catch2)

---

## 🧪 Milestones

* [ ] Character transliteration
* [ ] Word-level translation
* [ ] Simple sentence translation
* [ ] Grammar rules engine
* [ ] Sandhi handling
* [ ] Accuracy evaluation

---

## 📚 References

* Paninian grammar basics
* Tamil grammar (Tolkāppiyam concepts)
* Sanskrit morphology resources
* Open Sanskrit corpora

---

## 🚀 Vision

This project can evolve into:

* NLP engine
* Research tool
* Cultural language bridge
* Offline translator

---

## 🤝 Contribution

Planned for solo research first.
Future: plugin-based grammar rules.

---

## 📌 Status

**Early design phase — foundations first, accuracy later.**

```

If you want next:
- UML class diagram  
- First working C++ prototype  
- Sanskrit → Tamil phoneme table  
Just say 👍
```



Input:
rama gachati

Output:
ரஅமஅ கஅசஅதஇ


NEXT UPGRADES (IMPORTANT – ORDER MATTERS)
1️⃣ Devanagari → IAST Transliterator

Unicode handling

ICU library

2️⃣ Real Phoneme Scanner

Digraphs (kh, gh, chh)

Vowels & matras

3️⃣ Sandhi Splitter

Rule-based (Panini sutras)

4️⃣ Tamil Morphology Generator

Case suffix

Verb agreement

5️⃣ Grammar Rule Engine

Rule chaining

Confidence scoring



real language engines start.
What you have built

✔ NLP pipeline
✔ OOP extensible architecture
✔ Research-grade foundation
✔ Language-agnostic design


Note:
Devanagari Unicode transliterator

Real Sanskrit phoneme table

Sandhi algorithm (step-by-step)

UML diagram