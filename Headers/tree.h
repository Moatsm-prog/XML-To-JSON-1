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
    return node;
}

std::map<int, string> nameMap(Node* root){
    Node* it;
    std::map<int, string> names;
    bool namef, idf;
    int rootSize = root->childs.size();
    for(int i = 0; i < rootSize; i++){
        it = root->childs[i];
        string name = "";
        int id;
        namef = false;
        idf = false;
        for(int j = 0; j < it->childs.size(); j++){
            if(it->childs[j]->tag == "name"){
                name = it->childs[j]->childs[0]->tag;
                namef = true;
            }
            if(it->childs[j]->tag == "id"){
                id = stoi(it->childs[j]->childs[0]->tag);
                idf = true;
            }
            if(idf && namef) break;
        }
        names[id] = name;
    }
    return names;
}

string visualize(vector<vector<int>> followersList, std::map<int, string> names){
    string dotFormat = "";
    dotFormat += "digraph G{\n";
    for(int i = 0; i < followersList.size(); i++){
        dotFormat +=  '"' + names[followersList[i][0]] + "\" -> {";
        for(int j = 1; j < followersList[i].size(); j++){
            dotFormat += '"' + names[followersList[i][j]] + '"';
            if(j != followersList[i].size() - 1) dotFormat += ", ";
        }
        dotFormat += "}\n";
    }
    dotFormat += "}\n";
    return dotFormat;
}

void makeList(Node* root){
    vector<vector<int>> followersList;
    int rootSize = root->childs.size();
    std::map<int, string> names = nameMap(root);
    Node* it;
    for(int i = 0; i < rootSize; i++){
        vector<int> userList;
        for(int j = 0; j < root->childs[i]->childs.size(); j++){
            if(root->childs[i]->childs[j]->tag == "id"){
                userList.push_back(stoi(root->childs[i]->childs[j]->childs[0]->tag));
                break;
            }
        }
        for(int j = 0; j <root->childs[i]->childs.size(); j++){
            if(root->childs[i]->childs[j]->tag == "followers"){
                it = root->childs[i]->childs[j];
                for(int k = 0; k < it->childs.size(); k++){
                    userList.push_back(stoi(it->childs[k]->childs[0]->childs[0]->tag));
                }
            }
        }
        followersList.push_back(userList);
    }
    string Dot = visualize(followersList, names);
    saveAsFile("sample.dot", Dot);
}
