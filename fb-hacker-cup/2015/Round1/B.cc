#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

class Trie {
    private:
        struct TrieNode {
            int value;
            TrieNode *children[ALPHABET_SIZE];
            TrieNode() { 
                value = 0;
                for(int i = 0; i < ALPHABET_SIZE; i++) {
                    children[i] = NULL;
                }
            }
        };
        TrieNode *root;
        int count;

    public:
        Trie() {
            root = new TrieNode;
            count = 0;
        }

        int insert(string key) {
            int level;
            int length = key.length();
            int index;
            int in;
            TrieNode *pCrawl;

            count++;
            pCrawl = root;
            in = 0;
            for( level = 0; level < length; level++ ) {
                index = key[level] - 'a';
                if( pCrawl->children[index] ) 
                    pCrawl = pCrawl->children[index];
                else {
                    if (in == 0) in = level + 1;
                    pCrawl->children[index] = new TrieNode;
                    pCrawl = pCrawl->children[index];
                }
            }
            pCrawl->value = count;
            if(in==0) return length; else return in;
        }

        bool search(string key) {
            int length = key.length();
            int index;

            TrieNode *pCrawl;
            pCrawl = root;
            for(int level = 0; level < length; level++ ) {
                index = key[level] - 'a';
                if( !pCrawl->children[index] ) return 0;
                pCrawl = pCrawl->children[index];
            }
            return (pCrawl!=NULL && pCrawl->value);
        }

        bool leafNode(TrieNode *pNode) {
            return (pNode->value != 0);
        }

        bool isItFreeNode(TrieNode *pNode) {
            for(int i = 0; i < ALPHABET_SIZE; i++) 
                if( pNode->children[i] ) return 0;
            return 1;
        }

        bool deleteHelper(TrieNode *pNode, string key, int level, int len) {
            if( pNode ) {
                if( level == len ) {
                    if( pNode->value ) {
                        pNode->value = 0;
                        if( isItFreeNode(pNode) ) return true;
                        return false;
                    }
                }
                else {
                    int index = key[level] - 'a';

                    if( deleteHelper(pNode->children[index], key, level+1, len) ) {
                        delete pNode->children[index];
                        pNode->children[index] = NULL;
                        return ( !leafNode(pNode) && isItFreeNode(pNode) );
                    }
                }
            }
            return false;
        }

        void deleteKey(string key) {
            int len = key.length(); 
            if( len > 0 ) 
                deleteHelper(root, key, 0, len);
        }
};

int main() {
    int T;
    int N;
    int ans;
    string word;
    
    cin >> T;
    for(int testcase = 1;testcase <= T; testcase ++) {
        Trie tree;
        cin >> N;
        ans = 0;
        for(int i=0;i<N;i ++) {
            cin >> word;
            ans += tree.insert(word);
        }
        cout << "Case #" << testcase << ": " << ans << endl;
    }
    return 0;
}
