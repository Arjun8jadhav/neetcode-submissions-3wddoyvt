struct TreeNode{
    bool isEnd=false;
    vector<TreeNode*> child;
    TreeNode(){
        child.resize(26,0);
    }

};

class PrefixTree {
    unordered_set<string> vk;
    TreeNode * root;
public:
    PrefixTree() {
        root=new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* dummy=root;
        int n=word.length();
        for(int i=0;i<n;i++){
             if(!dummy->child[word[i]-'a']){
                dummy->child[word[i]-'a']=new TreeNode();
             }
             dummy=dummy->child[word[i]-'a'];
             if(i==n-1){
                dummy->isEnd=true;
             }
        }
    }
    
    bool search(string word) {
        TreeNode* dummy= root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!dummy->child[word[i]-'a']){
                return false;
            }
            dummy=dummy->child[word[i]-'a'];
            if(i==n-1 && dummy->isEnd){
                return true;
            }
        }
        return false;
        
    }
    
    bool startsWith(string word) {
        TreeNode* dummy= root;
        int n=word.size();
        for(int i=0;i<n;i++){
           if(!dummy->child[word[i]-'a']){
                return false;
            }
            dummy=dummy->child[word[i]-'a'];
        }
        return true;
    }
};
