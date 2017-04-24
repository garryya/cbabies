#include <iostream>
#include <string>
#include <map>
#include <vector>

/*
paperless postcard 
-----------------
paperless postcard
paperless post card
paper less postcard
paper less post card
*/

bool inDictionary(const std::string& word)
{
    static std::map<std::string,int> dictionary = 
        {{"green",0}, {"red",0}, {"paperless",0}, {"paper",0}, {"less",0}, {"postcard",0}, {"post",0}, {"card",0}};
    return dictionary.find(word) != dictionary.end();
}

void findWords(const std::string& s, const std::string& before, char sep=' ')
{
    std::string word, variant = before;
    for(std::string::const_iterator ci = s.begin(); ci != s.end(); ci++)
    {
        char c = *ci;
        bool eow = c == sep || ci+1 == s.end();
        if(!eow)
        {
            word += c;
            if(*(ci+1) != sep && inDictionary(word))
            {
                findWords(std::string(ci+1, s.end()), variant+word+sep);
            }
        }
        else if(!word.empty())
        {
            variant += word + c;
            word = "";
        }
    }
    std::cout << variant << std::endl;
}

int main(int argc, const char ** argv)
{
    //findWords("paperless postcard", "");
    findWords(argv[1], "");
    return 0;
}
