#include<iostream>
using namespace std;
# define P 3.14  //定义和宏常量

class Shape{  //图形基类
public:
    virtual void CalculateArea(){   //设置虚函数
        return ;
    }
};

class Rectangle :public Shape  //长方形派生类
{
public:
      int Long=20;
      int Width=10;
void CalculateArea(){               //重写计算面积的虚函数
    cout<<"长方形的面积为："<<Long*Width<<endl;
}
};

class Circular:public Shape   //圆形派生类
{
 public:
       double R=10;
 void CalculateArea(){
     cout<<"圆形的面积为："<<R*R*P<<endl;
 }
};

void calculate(){
     Shape *abs1=new Rectangle;   //指针引用
     abs1->CalculateArea();

     Shape *abs2=new Circular;
     abs2->CalculateArea();

     delete abs1,abs2;
}

int main(){

      calculate();
    return 0;
}