#include<iostream>
using namespace std;
class Complex {
      public :
  float real , imag ;
   Complex(float r = 0 , float i = 0 ) : real(r) , imag(i) {}
 Complex add(Complex c){
 return Complex(real+c.real, imag+c.imag);
  }
  Complex subtract(Complex c){
    return Complex(real-c.real , imag-c.imag);
      }
   Complex multiply(Complex c){
  float r = real*c.real - imag*c.imag;
   float i = real*c.real + imag*c.imag;
  return Complex(r,i);
      }
void display(){
cout<<real;
if (imag>=0) cout<<"+"<<imag<<"i"<<endl;
else cout<<"-"<<-imag<<"i"<<endl;
}
};

int main(){
Complex c1(2,3) , c2(1,5) ;
Complex sum = c1.add(c2);
Complex diff = c1.subtract(c2);
Complex prod = c1.multiply(c2);

cout<<"SUM";
sum.display();
cout<<"DIFFERENCE";
diff.display();
cout<<"PRODUCT";
prod.display();
return 0 ;
    }
    
