/*
1. Friend Function is not a member function of a class to which it is a friend
2. Friend function is declared in the class with friend keyword
3. It must be defined outside the class to which it is friend
4. Friend function can access any memeber of the class to which it is friend
5. Friend function cannot access member of the clas directly
6. It has no caller object
7. It should not be defined with membership label
8. Friend function can become friend to more than one class
9. Member function of one class can be friend function of other Class 
*/


#include<bits/stdc++.h>

using namespace std;
class Complex; // forword declaration of the class Complex
class A{
    private:
    int a;
    public:
    void set_val(int a){
        this->a=a;
    }
    void helloworld( Complex &);
    friend void fun(Complex,A);
};
class Complex{
    
    private:
    int a;
    int b;
    
    public:
    void set_data(int a,int b){
        this->a=a;
        this->b=b;
    }
    void show_data(){
        cout<<a<<" "<<b<<endl;
    }
    
    friend void A::helloworld(Complex &); // this means that the class A object can access private variable of Class Complex
    friend A; // the all the member function of Class A are friend function
    friend void fun(Complex,A);// this is friend function , it is not called by any object
    // you can write it in public or in private because it is not a member function so no effect
    // you have to forward declare the class A
    // benefit of friend is that you can access private variable of both class
    friend Complex operator+(Complex ,Complex ); // binary operator as a friend function
    friend Complex operator-(Complex); // uninary opeator as a friend function
    // one observation if you define a operator as a member function then you will need one less argument than
    // defining the operator as friend fucntion because if its a member function then it will be called by and object
    // and you will need the other object (if binary operator ) as argument
    
    
    friend ostream& operator<<(ostream & ,Complex); // this has to be made as friend function
    // because if you make it as member function then the caller object has to be the ostream object so
    // you have to make this operator overloading in ostream Class which you cant
    friend istream& operator>>(istream&, Complex&); // this has to be made as friend function
};

void A::helloworld(Complex &c){
    c.a=10;
    c.b=30;
}





Complex operator+(Complex x,Complex y){
    Complex temp;
    temp.a=x.a+y.a;
    temp.b=x.b+y.b;
    return temp;
}

Complex operator-(Complex x){
    Complex temp;
    temp.a=-x.a;
    temp.b=-x.b;
    return temp;
}

ostream& operator<<(ostream &dout, Complex C){
    dout<<" "<<C.a<<" "<<C.b<<endl;
    return dout;
}
istream& operator>>(istream &din,Complex &C){
    din>>C.a>>C.b;

    return din;
}

void fun(Complex o1,A o2) // define the friend function after the class definition else error
{
    cout<<" a val is "<<o2.a<<endl;
    cout<<" the sum is "<<o1.a+o1.b<<endl;
}

int main(){

    Complex c1;
    Complex c2;

    c1.set_data(2,4);
    c2.set_data(3,5);
    Complex c3=c1+c2;
    c3.show_data();
    c3=-c3;
    c3.show_data();
    A a1;
    a1.set_val(10);
    a1.helloworld(c3);


    cout<<c3<<endl;
    fun(c1,a1); 
    

    cout<<c1<<c2<<endl;

    Complex c5;
    cin>>c5;
    cout<<c5;
    return 0;
}