#include <iostream>
using namespace std;

void generateSubset(string s, string curr = "", int i=0) {
    if (i== s.length()) {
        cout<<curr<<endl;
        return;
    };

    generateSubset(s,curr,i+1);
    generateSubset(s,curr+s[i],i+1);
};

int main() {
    generateSubset("ABC");
    
    return 0;
};