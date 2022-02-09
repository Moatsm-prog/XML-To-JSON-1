#include <string> 
#include <cwctype>
#include <fstream>
#include <stack>
#include <utility>
#include <vector>

std::string INPUT_FILE;
std::string xml;

std::pair<std::string, int> extract_tag(int indx, std::string xml);

class XML_Exception{
public:
    std::string msg;
    std::string corrected_xml;
    std::vector<int> errors_indxs;

    XML_Exception(std::string msg, std::string corrected_xml, std::vector<int> errors_indxs){
        this->msg = msg;
        this->corrected_xml = corrected_xml;
        this->errors_indxs = errors_indxs;
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

std::string get_err_massege(std::vector<int> &errors){
    std::string error_list = "";
    int line1;
    int line2;
    for(int i = 0; i < errors.size() - 1; i++){
        line1 = line_numer(errors[i]);
        line2 = line_numer(errors[i + 1]);
        if(line1 == line2){
            errors.erase(errors.begin() + i + 1);
            i--;
        }
    }
    error_list += "There are " + std::to_string(errors.size()) + " errors in:\n";
    for (int i = 0; i < (int) errors.size() ; i++){
        int line = line_numer(errors[i]);
        // error_list += "\t- Tag: " + extract_tag(i, xml).first + " at line " + std::to_string(line) + "\n";
        error_list += "\t- at line " + std::to_string(line) + "\n";
        errors[i] = line;
    }
    return error_list;
}

std::string correct_string(std::string Original_file){
    std::vector<int> errors;
    std::string correct = "";
    bool last_object = 0, closing_tag = 0;
    std::stack<std::string> s;
    for(int i = 0; i < (int)Original_file.size(); i++){
        if(Original_file[i] != '<'){
            if(!closing_tag){
                correct += Original_file[i];
                last_object = 1;
            }
            if(closing_tag){
                errors.push_back(i);
            }
        }
        else if(Original_file[i] == '<'){
            std::string tag = "";
            int j = i;
            while(Original_file[j+1] != '>' && j < (int)Original_file.size()) tag += Original_file[++j];

            if(Original_file[i+1] != '/'){/* Opening Tag */
                if(last_object){
                    correct += "</" + s.top() + ">";
                    s.pop();
                    errors.push_back(i);
                }
                correct += "<" + tag + ">";
                s.emplace(tag);
                i = j+1;
                closing_tag = 0;
            }
            else{ /* Closing Tag */
                closing_tag = 1;
                i = j+1;
                if(s.empty()){
                    errors.push_back(i);
                    continue;
                }
                else if(s.top() != tag.substr(1)){
                    errors.push_back(i);
                    correct += "</" + s.top() + ">";
                    s.pop();
                    last_object = 0;
                    continue ;
                }
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

    int j = 0;
    std::string start_tag = "";
    while(Original_file[j+1] != '>' && j < (int)Original_file.size()) start_tag += Original_file[++j];
    std::string end_tag = "";
    j = Original_file.size()-1;
    while(Original_file[j-1] != '/' && j > 0) end_tag += Original_file[--j];
    
    if(start_tag != std::string(end_tag.rbegin(),end_tag.rend())) errors.push_back(j);
    
    if(errors.size()) throw new XML_Exception(get_err_massege(errors), correct, errors);
    return correct;
}
