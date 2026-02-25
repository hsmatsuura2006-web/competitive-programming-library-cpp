#include <iostream>
#include <vector>
#include <string>

/**
 * @brief 部分一致テーブル（Next配列）の構築
 * table[i] : pattern[0...i] において、接頭辞と接尾辞が一致する最大長
 */
std::vector<int> buildNextTable(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> next(m, 0);
    int j = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

/**
 * @brief KMP法による文字列探索
 * @return 一致した開始インデックスのリスト
 */
std::vector<int> KMPSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> results;
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return results;

    std::vector<int> next = buildNextTable(pattern);
    int j = 0; // patternのポインタ

    for (int i = 0; i < n; ++i) { // textのポインタ
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1]; // 不一致ならテーブルを参照してスキップ
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) { // 完全に一致
            results.push_back(i - m + 1);
            j = next[j - 1]; // 次の出現を探す
        }
    }
    return results;
}

int main() {
    std::string text = "ABC ABCDAB ABCDABCDABDE";
    std::string pattern = "ABCDABD";

    std::vector<int> positions = KMPSearch(text, pattern);

    for (int pos : positions) {
        std::cout << "Pattern found at index: " << pos << std::endl;
    }

    return 0;
}
