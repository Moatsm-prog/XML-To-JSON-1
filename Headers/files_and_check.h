#include <string>
#include <cwctype>
#include <fstream>
#include <stack>
#include <utility>

std::string INPUT_FILE;
std::string xml;

class XML_Exception{
public:
    std::string msg;
    int lineNum;

    XML_Exception(std::string msg, int lineNum){
        this->msg = msg;
        this->lineNum = lineNum;
    }
};

inline std::string trim(const std::string &str){
    const char* s = str.c_str();
    int size = (int)str.size();
    std::string res = "";
    int i = 0;

    while(iswspace(s[i]) && size >= 0) s++, size--;
    while(iswspace(s[size-1]) && size >= 0) size--;

    while(i < size){
        if(s[i] == '>' && i < size-1 && iswspace(s[i+1])){
            res += '>';
            i++;
            while(iswspace(s[i]) && i < size) i++;
        }
        else if(s[i] == '<' && i && iswspace(s[i-1])){
            int j = i-1;
            while(iswspace(s[j]) && j >= 0){
                j--;
                res.pop_back();
            }
        }
        res += s[i++];
    }
    return res;
}

std::string open_file(std::string path){
    INPUT_FILE = path;
    xml = "";
    std::string orginal;
    std::ifstream file(path.c_str());
    std::string tmp;
    while(getline(file, tmp)){
        orginal += tmp + '\n';
        tmp = trim(tmp);
        xml += tmp;
    }
    file.close();
    return orginal;
}

void saveAsFile(std::string path, std::string txt){
    std::ofstream ofile(path.c_str());
    ofile << txt;
    ofile.close();
}

int line_numer(int indx){
    if(indx >= (int)xml.size()) return -1;
    
    int res = 1, char_cnt = 0;
    std::ifstream fin(INPUT_FILE);
    std::string line;
    while(getline(fin, line)){
        char_cnt += trim(line).size();
        if(indx < char_cnt) return res;
        res++;
    }
    return -1;
}

void check(){
    std::stack<std::pair<int, std::string>> s;

    for (int i = 0; i < (int)xml.size(); i++){
        if(xml[i] == '<'){
            std::string tag = "";
            int j = i;
            while(xml[j+1] != '>' && j < (int)xml.size()) tag += xml[++j];
            
            if(xml[i+1] != '/') /* Opening Tag */
                s.emplace(i, tag);
            else{ /* Closing Tag */
                if(s.empty()){
                    int lineNum = line_numer(i+2); 
                    std::string msg = "Invalid XML: Tag at index " + std::to_string(i+2) + " at line " + std::to_string(lineNum) + " has no opening tag";
                    throw new XML_Exception(msg, lineNum);
                }
                if(s.top().second != tag.substr(1)){
                    int lineNum = line_numer(i+2);
                    std::string msg =  "Invalid XML: Tag at index: " + std::to_string(i+2) + " at line " + std::to_string(lineNum) + " should be " + s.top().second;
                    throw new XML_Exception(msg, lineNum);
                }
                s.pop();
            }
            i = j-1;
        }
    }
    if(!s.empty()){
        int lineNum = line_numer(s.top().first);
        std::string msg = "Invalid XML: Tag \'" + s.top().second + "\' at index " + std::to_string(s.top().first) + " at line " + std::to_string(lineNum) + " is not closed";
        throw new XML_Exception(msg, lineNum);
    }
    //if(!s.empty()) throw "Invalid XML: " + s.top().second + " is not closed";
}

std::string correct_string(std::string Original_file){
    std::string correct = "";
    bool last_object = 0;
    std::stack<std::string> s;
    for(int i = 0; i < (int)Original_file.size(); i++){
        if(Original_file[i] != '<'){
            correct += Original_file[i];
            last_object = 1;
        }
        else if(Original_file[i] == '<'){
            std::string tag = "";
            int j = i;
            while(Original_file[j+1] != '>' && j < (int)Original_file.size()) tag += Original_file[++j];

            if(Original_file[i+1] != '/'){/* Opening Tag */
                if(last_object){
                    correct += "</" + s.top() + ">";
                    s.pop();
                }
                correct += "<" + tag + ">";
                s.emplace(tag);
                i = j+1;
            }
            else{ /* Closing Tag */
                i = j+1;
                if(s.empty()) continue;
                else if(s.top() != tag.substr(1)) continue ;
                else{
                    correct += "<" + tag + ">";
                    s.pop();
                }
            }
            last_object = 0;
        }
    }
    while(!s.empty()){
        correct += "</" + s.top() + ">";
        s.pop();
    }
    return correct;
}
