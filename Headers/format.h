#include <string>

std::string ident(std::string xml){
    std::string res;
    int cnt = 0;
    for (int i = 0; i < (int)xml.size(); i++){
        res += std::string(cnt, '\t');
        if(xml[i] == '<'){
            if(xml[i+1] != '/') cnt++;
            else{
                res.pop_back();
                cnt--;
            }
            while(xml[i] != '>') res += xml[i++];
            res += xml[i];
        }
        else{
            while(xml[i] != '<') res += xml[i++];
            i--;
        }
        res += '\n';
    }
    return res;
}