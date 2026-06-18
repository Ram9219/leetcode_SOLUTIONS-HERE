class Node{
    public:
    Node*child[26];
    bool isEnd;
    Node(){
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

class Trie {
public:
Node*root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node*node=root;
        for(char ch:word){
            int index=ch-'a';
            if(node->child[index]==NULL){
                node->child[index]=new Node();
            }
            node=node->child[index];
        }
        node->isEnd=true;
        
    }
    
    bool search(string word) {
        Node*node=root;
        for(char ch:word){
            int index=ch-'a';
            if(node->child[index]==NULL){
                return false;
            }
            node=node->child[index];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node*node=root;
        for(char ch:prefix){
            int index=ch-'a';
            if(node->child[index]==NULL){
                return false;
            }
            node=node->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */