class WordDictionary
{
public:
    struct TrieNode
    {
        bool isEndofWord;
        TrieNode *children[26];
    };

    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();
        newNode->isEndofWord = false;
        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = nullptr;
        }
        return newNode;
    }

    TrieNode *root;

    WordDictionary()
    {
        root = getNode();
    }

    void addWord(string word)
    {
        TrieNode *crawler = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (crawler->children[idx] == nullptr)
            {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndofWord = true;
    }

    bool searchUtil(TrieNode *node, string word, int index)
    {
        if (index == word.length())
        {
            return node->isEndofWord;
        }

        char ch = word[index];
        if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->children[i] != nullptr && searchUtil(node->children[i], word, index + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            int idx = ch - 'a';
            if (node->children[idx] != nullptr)
            {
                return searchUtil(node->children[idx], word, index + 1);
            }
            else
            {
                return false;
            }
        }
    }

    bool search(string word)
    {
        return searchUtil(root, word, 0);
    }
};
