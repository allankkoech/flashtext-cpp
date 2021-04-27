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

using std::cout;
using std::endl;
using std::cerr;
using std::string;

struct Node
{
    char key;
    string first, second;
    Node* next;
    // Node* prev;
    // std::map<std::string, std::string> data;
};

class Dict
{
public:
    Dict()
    {
        n=nullptr;
        t=nullptr;
        h=nullptr;
    }

    Dict(const char &key, const std::string &first = "", const std::string &second="")
    {
        // Create a new node and insert data if any
        n = new Node();
        h = n;
        t = n;
        t->next=nullptr;

        // Set the Key Value
        n->key = key;

        if( first !="" )
        {
            n->first=first;
            if(second=="")
                n->second=first;
            else
                n->second=second;
        }

        m_count = 1; // One node, the head node
    }

    ~Dict()
    {
        cout << "Clear text" << endl;
        clearList(h);

        // Delete the pointers
        delete n;
        delete t;
        delete h;
    }

    void clearList(Node *head)
    {
        Node *current = head;
        Node *next = nullptr;

        current = h;
        next = nullptr;
        n = nullptr;
        t = nullptr;

        while ( current->next != nullptr )
        {
            next = current->next;
            free(current);
            current=next;
        }

        h = nullptr;
        current = nullptr;
        next = nullptr;

        delete next;
        delete current;
    }

    void add(const char &key, const std::string &first = "", const std::string &second="")
    {
        n = new Node();

        if ( h==nullptr )
        {
            h = n;
            t = n;
            t->next=nullptr;
        }

        else
        {
            t->next = n;
            t = t->next;
            t->next=nullptr;
        }

        // Set the Key Value
        n->key = key;

        // Set data if its passed
        if( first !="" )
        {
            n->first=first;
            if(second=="")
                n->second=first;
            else
                n->second=second;
        }
    }

    int size()
    {
        Node *hd = h;
        int count_ = 1;

        while( hd->next != nullptr )
        {
            count_ ++;
            hd = hd->next;
        }

        m_count = count_;
        return count_;
    }

    Node* at(int index)
    {
        if( index >= size() )
            throw "Linked List Index is out of range";

        Node *current = h;

        if( index == 0 )
            return current;

        int i = 0;
        while( current->next != nullptr )
        {
            i++;
            current = current->next;

            if( index == i )
                break;
        }

        return current;
    }

    int hasKey(const char &key)
    {
        Node *current = h;

        if( h == nullptr )
            return -1;

        int index = 0;

        while( true )
        {
            if( current->key == key )
                return index;

            if( current->next == nullptr )
                break;

            current = current->next;
            index ++;
        }

        return -1;
    }


private:
    // node, temp, head
    Node * n, * t, * h;
    int m_count;
};


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
    string getItem(const string &word);
    string getItem(const string &keyword, const string &cleanName = "");
    string stringToLower(const string &word);
    void addNonWordBoundaries(const char &nonWordChar);
    bool setItem(const string &keyword, const string &prettyName=NULL);
    bool addKeyword(const string &keyword, const string &prettyName=NULL);
    void setNonWordBoundaries(const std::unordered_set<char> &nonWordBoundaries);

private:
    // Private Data Here
    string m_keyword;
    bool m_caseSensitive;
    int m_termsInTrie;
    std::unordered_set<char> m_whiteSpaceChars;
    std::unordered_set<char> m_nonWordBoundaries;
    Dict m_keywordTrieMap;
};

#endif //FLASHTEXT_CPP_FLASHTEXT_H
