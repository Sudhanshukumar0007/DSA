#include<iostream>
using namespace std;
class Student{
    protected:
        string name;
        int age;
        int roll;
};
class male:protected Student{
    public:
        void print(){
            cout<<"He is a male"<<endl;
        }
        int getAge(){
            return this->age;
        }
        void setAge(int x){
            this->age=x;
        }
};
int main(){
    male sudhanshu;
    //Protected class can be accesed inside the class and also by their inherited child
    // sudhanshu.age=19;
    cout<<sudhanshu.getAge()<<endl;
    sudhanshu.print();
    sudhanshu.setAge(19);
    cout<<sudhanshu.getAge();
    return 0;
}