//
// Created by lalanke on 26/04/2021.
//

#ifndef FLASHTEXT_CPP_FLASHTEXT_H
#define FLASHTEXT_CPP_FLASHTEXT_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <algorithm>


using std::cout, std::endl, std::cerr, std::string;


class KeywordProcessor
{
public:
    // Public Data Here
    /**
     * Application constructor
     */
    KeywordProcessor(const bool &caseSensitive = false );
    
    int trieSize();
    bool contains(const string &word);
    string stringToLower(const string &word);
    void addNonWordBoundaries(const char &nonWordChar);
    bool setItem(const string &keyword, const string &prettyName=NULL);
    bool addKeyword(const string &keyword, const string &prettyName=NULL);
    void setNonWordBoundaries(const std::unordered_set<char> &nonWordBoundaries);

private:
    // Private Data Here
    bool m_caseSensitive;
    int m_termsInTrie;
    std::unordered_set<char> m_whiteSpaceChars;
    std::unordered_set<char> m_nonWordBoundaries;
    std::map<string, string> m_keywordTrieMap;
};

#endif //FLASHTEXT_CPP_FLASHTEXT_H


KeywordProcessor::KeywordProcessor(const bool &caseSensitive)
    : m_caseSensitive(caseSensitive)
{
    cout << "Entering KeywordProcessor Class!" << endl;

    m_termsInTrie = 0;

    // Whitespace characters unordered set
    m_whiteSpaceChars.insert('.');
    m_whiteSpaceChars.insert('\t');
    m_whiteSpaceChars.insert('\n');
    m_whiteSpaceChars.insert('\a');
    m_whiteSpaceChars.insert(' ');
    m_whiteSpaceChars.insert(',');

    // For Digits, Letters ( both cases (Aa) ), underscore (_)
    char _chars[] = {'7', '0', '2', '9', '8', '3', '4', '6', '1', '5', 'v', 'Q', 'r', 'g', 'K', 'U', 'n', 'f', 's', 'G', 'E', 'M', 'W', 'a', 't', 'i', 'H', 'J', 'V', 'O', 'l', 'A', 'd', 'u', 'T', 'p', 'P', 'F', 'B', 'Z', 'q', 'o', 'D', 'c', 'y', 'X', 'Y', 'h', 'x', 'm', 'w', 'S', 'I', 'C', 'k', 'e', 'j', 'L', 'R', 'z', 'N', 'b', '_'};
    for(const auto &s: _chars)
    {
        m_nonWordBoundaries.insert(s);
    }
}


/**
 * Number of terms present in the keyword_trie_dict
 *
 * @return int Count of number of distinct terms in trie map
 */
int KeywordProcessor::trieSize()
{
    return m_termsInTrie;
}

/**
 * Checks whether the passed word is contained in the keyword trie map
 *
 * @param word String word that you want to check
 * @return true if word is present as it is in m_keywordTrieMap then we return True, else False
 */
bool KeywordProcessor::contains(const string &word)
{
    string localWord = word;

    if( !m_caseSensitive )
    {
        // To lowercase
        std::transform(localWord.begin(), localWord.end(), localWord.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        cout << "To lower: " << localWord << endl;
    }

    // std::map<int, string> keywordTrieMap = m_keywordTrieMap;
    return true;
}

/**
 *
 * @param word
 * @return
 */
string stringToLower(const string &word)
{
    string data = word;
    std::transform( data.begin(), data.end(), data.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return data;
}

/**
 *
 * @param keyword
 * @param prettyName
 * @return
 */
bool KeywordProcessor::setItem(const string &keyword, const string &prettyName)
{
    bool status = false;
    string pretty = prettyName;
    string _keyword = keyword;

    if( (prettyName=="") || (prettyName=="") )
        pretty = keyword;

    if ( (keyword != "") && (pretty != "") )
    {
        if( !m_caseSensitive )
        _keyword = stringToLower(keyword);
    }

    std::map<string, string> currentTrieMap = m_keywordTrieMap;

    for( auto &letter: _keyword )
    {

    }

    return status;
}

/**
 * The new nonWordBoundary set
 *
 * @param nonWordBoundaries Set to replace the existing m_nonWordBoundary set
 */
void KeywordProcessor::setNonWordBoundaries(const std::unordered_set<char> &nonWordBoundaries)
{
    m_nonWordBoundaries = nonWordBoundaries;
}

/**
 * Add a character that will be considered as part of word.
 *
 * @param nonWordChar Character to be added to the nonWordBoundarySet
 */
void KeywordProcessor::addNonWordBoundaries(const char &nonWordChar)
{
    m_nonWordBoundaries.insert(nonWordChar);
}

/**
 *
 * @param keyword
 * @param prettyName
 * @return
 */
bool KeywordProcessor::addKeyword(const string &keyword, const string &prettyName)
{
    string data = keyword;
    string pretty = prettyName;


}