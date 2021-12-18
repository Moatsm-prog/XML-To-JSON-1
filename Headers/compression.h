#include <string>
#include <vector>
#include <map>

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

bool same_childs(Node* root);

string open_scheme[] = {"users", "user", "id", "name", "posts", "post", "body", "topics", "topic", "followers", "follower"};
string close_scheme[] = {"/users", "/user", "/id", "/name", "/posts", "/post", "/body", "/topics", "/topic", "/followers", "/follower"};

std::map<string, char> tagToChar;

std::pair<string, int> extract_tag(int indx, string xml){
    if(xml[indx] != '<'){
        string txt = "";
        while(xml[indx] != '<' && indx < (int)xml.size()) txt += xml[indx++];
        return {txt, indx};
    }
    string res = "";
    indx++; /*skip '<' */
    if(xml[indx++] != '/') res += xml[indx-1]; /* ++ for skip second char */
    while(xml[indx] != '>') res += xml[indx++];
    return {res, indx+1};
}

std::string conv_children_comp(Node* root){
    if(!root->height) return "";
    if(root->height == 1) return '\"' + root->childs[0]->tag + '\"';
    
    std::string res = "";
    
    if(same_childs(root)){
        res += '[';
        for (int i = 0; i < (int)root->childs.size(); i++){
            res += conv_children_comp(root->childs[i]);
            if(i < (int)root->childs.size()-1) res += ",";
        }
        res += ']';
    }
    else{
        res += '{';
        for (int i = 0; i < (int)root->childs.size(); i++){
            res += tagToChar[root->childs[i]->tag];
            res += conv_children_comp(root->childs[i]);
            if(i < (int)root->childs.size()-1) res += ',';
        }
        res += '}';
    }

    return res;
}

string decode(string xml){
    string res;
    for (int i = 0; i < (int)xml.size(); i++){
        if((int)xml[i] >= 14 && (int)xml[i] <= 24){
            res += "<" + open_scheme[((int)xml[i])-14] + ">";
        }
        else if((int)xml[i] >= 33 && (int)xml[i] <= 43){
            res += "<" + close_scheme[((int)xml[i])-33] + ">";
        }
        else res += xml[i];
    }
    return res;
}

string encode(string xml){
    string res = "";
    for (int i = 0; i < (int)xml.size();){
        if(xml[i] == '<' && xml[i+1] != '/'){
            std::pair<string, int> tag_p = extract_tag(i, xml);
            res += tagToChar[tag_p.first];
            i = tag_p.second;
        }
        else if(xml[i] == '<' && xml[i+1] == '/'){
            std::pair<string, int> tag_p = extract_tag(i, xml);
            res += tagToChar['/'+tag_p.first];
            i = tag_p.second;
        }
        else res += xml[i++];
    }
    return res;
}


string decode_json(string json){
    string res = "";
    for (int i = 0; i < (int)json.size(); i++){
        if((int)json[i] >= 14 && (int)json[i] <= 24){
            res += '\"' + open_scheme[((int)json[i])-14] + "\": ";
        }
        else res += json[i];
    }
    return res;
}
