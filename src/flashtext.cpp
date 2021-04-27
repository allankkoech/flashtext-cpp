//
// Created by lalanke on 27/04/2021.
//

#include "flashtext.h"

KeywordProcessor::KeywordProcessor(const bool &caseSensitive) : m_caseSensitive(caseSensitive)
{
    cout << "Entering KeywordProcessor Class!" << endl;

    m_keyword = "_keyword_";
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
    // auto m = {'b': {'i': {'g': {' ': {'a': {'p': {'p': {'l': {'e': {"_keyword_": "Big Apple"}}}}}}}}}};

    if( !m_caseSensitive )
    {
        // To lowercase
        std::transform(localWord.begin(), localWord.end(), localWord.begin(),
                       [](unsigned char c){ return std::tolower(c); });
    }

    Dict currentDict = m_keywordTrieMap;
    Node *currentNode = m_keywordTrieMap.at(0);

    unsigned int lenCovered = 0;

    for(const auto &c: localWord)
    {
        cout << "Char: '" << c << "'" << endl;

        int foundId = currentDict.hasKey(c);

        if( foundId != -1 )
        {
            cout << "Found at index: " << foundId;

            currentNode = currentDict.at(foundId);

            cout << " and the key = '" << currentNode->key << "'" << endl;

            lenCovered ++;
        }

        else
            break;
    }

    cout << "currentNode->first = " << currentNode->first << "\tlenCovered==word.length() = " << (lenCovered==word.length()) << endl;

    return currentNode->first == m_keyword && lenCovered==word.length();
}

string KeywordProcessor::getItem(const std::string &word)
{
    string localWord = word;

    if( !m_caseSensitive )
    {
        // To lowercase
        std::transform(localWord.begin(), localWord.end(), localWord.begin(),
                       [](unsigned char c){ return std::tolower(c); });
    }

    Dict currentDict = m_keywordTrieMap;
    Node *currentNode = m_keywordTrieMap.at(0);

    unsigned int lenCovered = 0;

    for(const auto &c: localWord)
    {
        cout << "Char: '" << c << "'" << endl;

        int foundId = currentDict.hasKey(c);

        if( foundId != -1 )
        {
            cout << "Found at index: " << foundId;

            currentNode = currentDict.at(foundId);

            cout << " and the key = '" << currentNode->key << "'" << endl;

            lenCovered ++;
        }

        else
            break;
    }

    cout << "currentNode->first = " << currentNode->first << "\tlenCovered==word.length() = " << (lenCovered==word.length()) << endl;

    if( currentNode->first == m_keyword && lenCovered==word.length() )
        return currentNode->second;
}

/**
 *
 * @param word
 * @return
 */
string KeywordProcessor::stringToLower(const string &word)
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

        auto currentDict = m_keywordTrieMap;
        auto currentNode = m_keywordTrieMap.at(0);


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
