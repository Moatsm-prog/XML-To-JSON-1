#include <utility>
#include <string>
#include <vector>

#define max(a,b) ((a)>(b)?(a):(b))

#ifndef NODE_T
#define NODE_T
struct Node{
    int index;
    std::string tag;
    int height;
    std::vector<Node*> childs;
};
#endif

using std::string;
using std::pair;
using std::vector;

std::pair<string, int> extract_tag(int indx, string xml);

int tree(int from, Node* root, string xml){
    if(from < (int)xml.size()-1 && xml[from+1] == '/'){
        return from;
    }
    pair<string, int> tag_p = extract_tag(from, xml);
    root->tag = tag_p.first;
    root->index = from;

    bool done = (xml[from] != '<');
    for(int i = tag_p.second;!done;){
        Node* child = new Node();
        i = tree(i, child, xml);
        tag_p = extract_tag(i, xml);
        done = (tag_p.first == root->tag);
        if(child->tag.length()) root->childs.push_back(child);
        else delete child;
    }
    return tag_p.second;
}

void clac_height(Node* root){
    if(!root->childs.size()){
        root->height = 0;
        return;
    }
    int max_ = -1;
    for (int i = 0; i < (int)root->childs.size(); i++){
        clac_height(root->childs[i]);
        max_ = max(max_, root->childs[i]->height);
    }
    root->height = max_+1;
}

Node* xml_to_tree(string xml){
    Node* node = new Node();
    tree(0, node, xml);
    clac_height(node);
    return node->childs[0];
}
