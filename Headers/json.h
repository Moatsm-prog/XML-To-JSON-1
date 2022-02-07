#include <string>
#include <vector>

using std::string;

#ifndef NODE_T
#define NODE_T
struct Node{
    int index;
    string tag;
    int height;
    std::vector<Node*> childs;
};
#endif

typedef enum{compressed, normal} json_type;

string conv_children_comp(Node* root);

#ifndef SAME_CHILDS
#define SAME_CHILDS

bool same_childs(Node* root){
    if(root->childs.size() == 1) return 0;
    string first_tag = root->childs[0]->tag;
    for (int i = 1; i < (int)root->childs.size(); i++){
        if(first_tag != root->childs[i]->tag) return false;
    }
    return true;
}

#endif

string conv_children(Node* root, int identCount){
    if(!root->height) return "";
    if(root->height == 1) return '\"' + root->childs[0]->tag + '\"';
    
    string res = "";
    
    if(same_childs(root)){
        res += "[\n";
        for (int i = 0; i < (int)root->childs.size(); i++){
            res += string(identCount*2, ' ');
            res += conv_children(root->childs[i], identCount + 1);
            if(i < (int)root->childs.size()-1) res += ",";
            res += '\n';
        }
        res += string((identCount-1)*2, ' ') + "]";
    }
    else{
        res += "{\n";
        for (int i = 0; i < (int)root->childs.size(); i++){
            res += string(identCount*2, ' ');
            res += '\"' + root->childs[i]->tag + "\": ";
            res += conv_children(root->childs[i], identCount + 1);
            if(i < (int)root->childs.size()-1) res += ',';
            res += '\n';
        }
        res += string((identCount-1)*2, ' ') + "}";
    }

    return res;
}

string tree_to_json(Node* root, json_type type){
    if(type == normal)
        return conv_children(root, 1);
    else return conv_children_comp(root);
}
