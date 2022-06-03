#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string word;
    string phrase;
    vector<string> text;
    while(cin>>word){
        text.push_back(word);
        if(cin.get() == '\n')break;
    }
    int lenth = text.size();
    for(int i=lenth-1;i>=0;i--){
        cout<<text[i];
        if(i>0)cout<<" ";
    }
    return 0;
}
