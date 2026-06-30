/*It basically means wrapping up the data members and functions
fully Encapsulated class means ALL data members are private
Advantages:-
    Data Hiding
    if we want we can make class Read Only
    Code Reusability
    Unit testing
*/
//Implementation

#include<iostream>
using namespace std ;
class Student{
    private:
        string name;
        int age;
        int height;
    public:
        int getAge(){
            return this->age;
        }

};
int main(){
    Student first;
    return 0 ;
}