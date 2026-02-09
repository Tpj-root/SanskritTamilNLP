This is happening **exactly because of how the current code scans phonemes**.

Let me explain clearly, then give you the **FIX**.

---

## ❌ Why you get `அஅ` for `rama`

Input:

```
rama
```

### What your current code does

In `mapWord()` you wrote (simplified):

```cpp
for (size_t i = 0; i < word.size(); ++i) {
    std::string p(1, word[i]);   // 👈 ONE CHARACTER ONLY
    auto it = phonemeMap.find(p);
    if (it != phonemeMap.end())
        result += it->second;
}
```

So the word is read **character by character**:

```
r  a  m  a
```

Now check your `phonemeMap`:

| key | exists? | output  |
| --- | ------- | ------- |
| "r" | ❌       | ignored |
| "a" | ✅       | அ       |
| "m" | ❌       | ignored |
| "a" | ✅       | அ       |

### Final output

```
அ + அ = அஅ
```

So:
👉 `"ra"` and `"ma"` are **NEVER matched**
👉 because your code **never checks 2-letter phonemes**

---

## ✅ Core Problem (Important NLP concept)

> **Phoneme mapping must be greedy and multi-character**

Sanskrit phonemes are:

```
ra, ma, ga, cha, ti, na ...
NOT r, a, m, a
```

Your current scanner is **too naive**.

---

## ✅ FIX: Greedy Phoneme Scanner (Correct Way)

We must:

1. Try **2-character match first**
2. If not found → try **1-character**
3. Move index correctly

---

## 🛠️ FIXED `PhonemeMapper::mapWord`

Replace your function with this 👇

### 📁 `phoneme/PhonemeMapper.cpp`

```cpp
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
```

---

## 🧪 Test Again

### Input

```
rama
```

### Now scanning is:

```
ra  ma
```

### Output

```
ரம
```

✔️ Correct for a **phoneme-only engine**

---

## 🔥 Why this matters (BIG lesson)

This single fix is the **difference between**:

* ❌ toy string replace
* ✅ real NLP phoneme engine

Every future feature depends on this:

* long vowels (ā ī ū)
* aspirated consonants (kh gh chh)
* sandhi
* morphology

---

## 🔮 Next logical upgrades (in correct order)

1️⃣ Support **3-letter phonemes** (`chh`, `ksh`)
2️⃣ Long vowels (`ā ī ū ṛ`)
3️⃣ Devanagari Unicode input
4️⃣ Sandhi splitter

If you want, next I can:

* extend this scanner to **3-char greedy**
* add **IAST diacritics**
* or add **Devanagari → IAST transliterator**
