#include<bits/stdc++.h>

using namespace std;

void funtion_to_explain_static_variable(){
    static int a;// this is a staic local variable not static member variable 
    int b;
    // b has garbage value whereas a is assigned to 0;
    // the variable b will get the memory in the function and will be distoryed at the end of this function
    // where as a will get the memory at the start of the program and will be destroyed at the end of the main program;
}
class Complex// not same as complex the letter casing matters
{
    private:
    int a,b;// this is not class variable they are object variable
    static int c;// this is a class variable (static member variable)
    // the static variable is allocated memory once at the start of the program and is destroyed at the end of the program 
    // when a object is created then it does not create the memory for c, it only has the copy of a,b hence object size is 4byte 
    // therefore for a object c1 there exist no variable c
    // but all the objects can access the static member variable c but all the objects are linked to the same c variable
    // so if you change the value of c in one object then it will change for all
    // c ( class variable ) is only assigned memory once but you have to define it outside the class
    
    public: 
    // if you dont define your own constructer the compiler make its own constructer 
        //  it makes two constructer 1) Default Constructer
                                //   2) Copy Constructer
    // but if you have defined  it then it wont make its own Default Constructer
    // also if we have make our own Copy Constucter then it will not make its own Copy Constructer

    static int vinay;// this is in public section so it can be accessed by any object
    Complex(){ // it is an object member function so can use static over here
        // it has no return type
        // when a object is created then the constructer is called
        a=0;
        b=0;
    }
    Complex(int x,int y){ // (parameterized Constructer) constructer overloading
        a=x;
        b=y;
    }
    // Complex(Complex c){ this is a error because a copy of the object is not sent then it has to call a constructer to 
    //                     make this c object this is (c=c1) then recurive contructer called so error
    //     a=c.a;
    //     b=c.b;
    // }
    Complex(const Complex &c){ // copy constructer
        // const has a very specific purpose (discussion with aman tiwari guru )
        // const is needed for security so that we do not change the value of object ref whose scope is outside this
        // if you remove it then Complex c3=c1.add(c2); will give error 
        a=c.a;
        b=c.b;
    }


    void set_data(int x,int y); //the are object member function not class
    // have to give different name from the class variable
    
    static void assign_data(int x){ // this is a static member function 
        // it can only access the static variable
        // if the static varible was present in public then no need for this function
        c=x;
        // a=15; this will give error because it is a object variable
    }
    void show_data() {
        cout<<a<<" "<<b<<endl;
        cout<<"c is "<<c<<endl;
    }

    Complex add(Complex c){
        Complex temp;
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }

    ~Complex(){ // destructor is an instance member function 
        // destructor can never be static 
        // no argument in destrucor hence no overloading possible in destructor
        /* destructor doesnot destroy the object rather it is the last function which 
            executes before the destruction of the object
        */
        //     

    }



};
int Complex::c = 0; // c is a class variable (static) and here it gets the memory 
// this will get the memory even if we dont create a object
// we can access this static member variable without creating a object
int Complex::vinay=0;
void Complex :: set_data(int a,int b){// have to give different name from the class variable
    // but using this keyword the function know which object is performing the operation 
    this->a=a;
    this->b=b;
}
int main(){
    Complex::assign_data(10); // assign the value even before creating any object
    Complex c1,c2;
    c1.set_data(2,5);
    c2.set_data(3,3);

    // c1.c=3 not possible because c is a private static member variable
    c1.assign_data(30); // object can also access the static member variable
    // every object acces the same static member variable
    c1.vinay=3; // vinay is public static memeber variable 
    cout<<c1.vinay<<endl; 
    Complex c3=c1.add(c2);
    c3.show_data();

    Complex c4(1,3);// constructer === Complex c4=Complex(1,3);
    return 0;
}
