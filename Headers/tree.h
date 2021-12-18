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

int tree(int from , Node* parent, string xml){
	pair<string , int> tag;
	bool done = 0;
	while(!done){
		tag = extract_tag(from, xml);
		Node* child = new Node();
		child->tag = tag.first;
		child->index = from;
		parent->childs.push_back(child);
        if(xml[from] == '<') from = tree(tag.second , child, xml);
		else from = tag.second;
		tag = extract_tag(from, xml);
        done = (parent->tag == tag.first);
    }
    return tag.second;
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
