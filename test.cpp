#include<iostream>
#include<string>
using namespace std;

class Base{
    public:
        string testPublic(){
            return string("this is a public function");
        }
    protected:
        string test;
};

class Son:public Base{
    public:
        string testProPublic(){
            test = "In Son";
            return test+testPublic();
        }
};

int main(){
     Son s;
     cout << s.testProPublic();
}
