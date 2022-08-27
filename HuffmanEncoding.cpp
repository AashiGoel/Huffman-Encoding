#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int *countFrequency(string og)
{
    int *arr = new int[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < og.length(); i++)
    {
        int index = og[i] - 'a';
        arr[index]++;
    }
    return arr;
}
class node
{
public:
    char ch; int f; node*left; node*right; int weight;
    node(){ ch = '\0'; f = 0; left=NULL; right=NULL; weight=-1;}
    node(int fe){ ch = '\0'; f = fe; left=NULL; right=NULL; weight=-1;}
    node(char c, int fe) { ch = c; f = fe; left=NULL; right=NULL; weight=-1;}
};
class comp
{
public:
    bool operator()(node *a, node *b)
    {
        return a->f > b->f;
    }
};
priority_queue<node *, vector<node *>, comp> *sortByF(int *arr)
{
    priority_queue<node *, vector<node *>, comp> *pq=new priority_queue<node *, vector<node *>, comp>;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            char ch = 'a' + i;
            node *n = new node(ch, arr[i]);
            pq->push(n);
        }
    }
    return pq;
}
node *huffman_tree(priority_queue<node *, vector<node *>, comp> *pq){
    if(pq->size()==1){ node*root=new node(pq->top()->f); root->right=pq->top(); pq->top()->weight=1; return root;}
    while(pq->size()!=1){
    node *root=new node; int f=pq->top()->f; root->right=pq->top(); pq->top()->weight=1; pq->pop(); 
    f+=pq->top()->f; root->left=pq->top(); pq->top()->weight=0; pq->pop(); root->f=f; pq->push(root);}
    node *head=pq->top(); return head;
}
void generateTable(node *root,vector<bool> wa,unordered_map<char,vector<bool>> *a){
    if(root->ch){
        bool y=root->weight?(bool)1:(bool)0;
        wa.push_back(y);
        pair<char,vector<bool>> p={root->ch,wa};
        a->insert(p);
        return;
    }
    if(root->weight!=-1){
    bool y=root->weight?(bool)1:(bool)0;
    wa.push_back(y);}
    generateTable(root->left,wa,a);
    generateTable(root->right,wa,a);
}
unordered_map<char,vector<bool>> *huffmanEncoding(string input){
    int *arr = countFrequency(input);
    priority_queue<node *, vector<node *>, comp> *pq = sortByF(arr);
    node *tree=huffman_tree(pq);
    vector<bool> wa;
    unordered_map<char,vector<bool>> *table=new unordered_map<char,vector<bool>>;
    generateTable(tree,wa,table);
    return table;
}
void printEncoded(unordered_map<char,vector<bool>> *table,string test){
    for(auto ch:test){
        vector<bool> b=table->at(ch);
        for(auto x:b){
            cout<<x;
        }
    }
    cout<<endl;
}
vector<bool> compressed(unordered_map<char,vector<bool>> *table,string test){
    vector<bool> ans;
    for(auto ch:test){
        vector<bool> b=table->at(ch);
        for(auto x:b){
            ans.push_back(x);
        }
    }
    return ans;
}
string decode(unordered_map<char,vector<bool>> *table,vector<bool> test){
    string ans="";
    unordered_map<vector<bool>, char> *revTable=new unordered_map<vector<bool>, char>;
    for(auto p:*table){
        pair<vector<bool>, char> g={p.second,p.first};
        revTable->insert(g);
    }
    int i=0;
    vector<bool> wait;
    while(i<test.size()){
        bool c=test[i];
        wait.push_back(c);
        if(revTable->count(wait)>0){
            ans+=revTable->at(wait);
            while(!wait.empty()){
                wait.pop_back();
            }
        }
        i++;
    }
    return ans;
}
int main()
{   //sample string: fabdedbfebbefee
    string test;
    cout<<"Enter the string to be encoded: "; cin>>test;
    unordered_map<char,vector<bool>> *table=new unordered_map<char,vector<bool>>;
    table=huffmanEncoding(test);
    cout<<"HUFFMAN CODE: "<<endl;
    for(auto p:*table){
        cout<<p.first<<": ";
        vector<bool> code=p.second;
        for(int i=0;i<code.size();i++){
            cout<<code[i];
        }
        cout<<endl;
    }
    cout<<endl; cout<<"Encoded String: ";
    vector<bool> com=compressed(table,test);
    for(auto ca:com){
        cout<<ca;
    }
    cout<<endl;
    string og=decode(table,com);
    cout<<"Decoded String: "<<og<<endl;
    return 0;
}
/*void print(node *root){
    if(root==NULL){ return; }
    print(root->left); cout<<root->ch<<" "<<root->f<<" "<<root->weight<<endl; print(root->right);
}*/