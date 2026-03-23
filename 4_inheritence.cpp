/*
It is a process of inheriting properties and behaviours of existing class into a new class
Existing class = Parent Class
New Class = Child Class

Types of Inheritance

1. Single inheritance

class A{
};
class B:public A{
};

2. Multilevel inheritance

class A{
};
class B:public A{
};
class C:pubilc B{
};

3. Multiple Inheritance

class A1{
};
class A2{
};
class B:pubilc A1,pubic A2{
};

4. Hierarchical Inheritance

class A{
};
class B1:pubilc A{
};
class B2:public A{
};

5. Hybrid Inheritance



Private - everything becomes private 
Protected - private remains private , protected and public becomes protected
Public - private remains private , protected remains protected and public remain to be public

Avaliability Vs Accessibility
if from a parent class you make a child then the child cannot access the private member directy 
but it is still avaliable becaue you can access it though public member fucntion 

is a relationship is always implemented as a public inheritance.
but why?
when to use private and protected inheritance?

*/

#include<bits/stdc++.h>

using namespace std;

class Base {
private:
    int a;
protected:
    int b;
public:
    int c;
    void setData(int x,int y,int z){
        a=x;
        b=y;
        c=z;
    }
    void showBase() {
        cout << "Inside Base class:\n";
        cout << "a = " << a << endl;      // ✅ Accessible
        cout << "b = " << b << endl;      // ✅ Accessible
        cout << "c = " << c << endl;      // ✅ Accessible
    }
};

class Derived : public Base {
    // a is not accessible but avaliable
    // b remains protected so it is not accessible but avaliable
    // c remains public
    // showBase remain public 
    
    void showvalues(){
        // cout<<a<<endl; // ❌
        cout<<b<<endl; // ✅ Accessible
        cout<<c<<endl; // ✅ Accessible

    }
};

class Derived2 : protected Base {
    // a is not accessible but avaliable
    // b becomes protected so it is not accessible but avaliable
    // c becomes protecteds so it is not accessible but avaliable
    // showBase becomes protected
     void showvalues(){
        // cout<<a<<endl; // ❌
        cout<<b<<endl; // ✅ Accessible
        cout<<c<<endl; // ✅ Accessible
    }
};

class Derived3 : private Base {
    // a is not accessible but avaliable
    // b becomes private so it is not accessible but avaliable
    // c becomes private so it is not accessible but avaliable
    // showBase becomes private
     void showvalues(){
        // cout<<a<<endl; // ❌
        cout<<b<<endl; // ✅ Accessible
        cout<<c<<endl; // ✅ Accessible
    }
    void show_val_using(){
        showBase(); // show base is private and we can call it 
        // and showbase can access a
    }
};


int main(){
    
    Base b;
    b.setData(1,2,3);
    Derived d;
    d.setData(4,5,6);
    d.showBase();

    return 0;
}