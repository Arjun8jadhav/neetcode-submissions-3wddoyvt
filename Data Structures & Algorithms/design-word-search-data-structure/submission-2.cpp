
struct TreeNode{
   bool isEnd=false;
   vector<TreeNode*> child;
   TreeNode(){
      child.resize(26,NULL);
   }
};
class WordDictionary {
    TreeNode* root;
public:
    WordDictionary() {
        root= new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* dummy=root;
        int n=word.size();
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
    bool solve(int idx,int n,string str,TreeNode* root1){
          if(idx==n){
            return root1->isEnd;
          }
          if(str[idx]!='.'){
              if(root1->child[str[idx]-'a']){
                 return solve(idx+1,n,str,root1->child[str[idx]-'a']);
              }
              else{
                return false;
              }
          }
          else{
            bool fix=false;
            for(int i=0;i<26;i++){
                if(root1->child[i]){
                    fix= (fix || solve(idx+1,n,str,root1->child[i]));
                }
            }
            return fix;
          }
    }
    bool search(string word) {
        int n=word.length();
        return solve(0,n,word,root);
    }
};
