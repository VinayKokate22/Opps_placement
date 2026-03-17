#include<bits/stdc++.h>

using namespace std;

class Complex{

    private:
    int a;
    int b;

    public:
    void set_data(int a,int b){
        // if you dont know (this) keyword dont worry disscussed in 6_pointer
        this->a=a;
        this->b=a;
    }
    void show_data(){
        cout<<a<<" "<<b<<endl;
    }
    Complex add(Complex c){
        Complex temp;
        temp.a=a+c.a;
        temp.b=b+c.a;
        return temp;
    }
    Complex operator+(Complex c){// operator overloading (binary operator)
        // you can only do this with the valid operator given by C language
        // you can not overload . :: typeid sizeof and ?: operator
        Complex temp;
        temp.a=a+c.a;
        temp.b=b+c.a;
        return temp;
        
    } 
    Complex operator-(){ // uniary opeator 
        Complex temp;
        temp.a=-a;
        temp.b=-b;
        return temp;
    }
    Complex operator++(){ // preincrement 
        Complex temp;
        temp.a=++a;
        return temp;
    }

    Complex operator++(int dummy)// postincrement
    // the int in the fuction is just to distinguish between pre and post increment 
    // you dont have to send anything as a parameter
    {
        Complex temp;
        temp.a=a++;
        return temp;
    }

};

int main(){

    Complex c1;
    Complex c2;

    c1.set_data(2,4);
    c2.set_data(3,5);

    Complex c3;
    c3=c1.add(c2);// adding with member fuction
    c3.show_data();

    Complex c4;
    c4=c1+c2; //adding with operator overloading == c4=c1.operator+(c2)

    Complex c5;
    c5=-c2;

    c5=++c2;// c5=c2.operator++();
    c5=c3++;// this actually send a dummy int val c5=c3.operator++(0);
    return 0;
}