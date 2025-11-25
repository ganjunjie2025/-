#include<iostream>
using namespace std;
class Secondary_Card;

class Master_Card {       //定义一个主卡为基类  
    friend Master_Card operator+(Secondary_Card a,Master_Card b);
private:
	double balance=5000;
public:
	string name="张三";
	string pass="123456";
	virtual void show_balance() {    //设置一个虚函数
		cout << "当前主卡余额为：" << balance << "元"<<endl;
	}
    void visit_secondary_card(Secondary_Card &a);
    void visit_balance(){
        cout<<"余额为："<<balance<<"元"<<endl;
    }
};

class Secondary_Card :public Master_Card {   //定一个副卡为派生类
	friend class Master_Card;             //假设主卡有权利访问副卡私有属性（设置一个友元）
    friend Master_Card operator+(Secondary_Card a,Master_Card b);
private:
	double balance = 1000;
	string pass = "654321";
public:
    
	string name = "李四";
	 void show_balance() {    
		cout << "当前副卡余额为：" << balance << "元" << endl;
	}
};

void Master_Card::visit_secondary_card(Secondary_Card &a) {
		cout << "副卡密码为：" << a.pass << endl;                               
		cout << "副卡余额为：" << a.balance <<"元"<< endl;
	}

void balance() {
	Master_Card* abs = new Secondary_Card;          //利用指针指向派生类实现多态
	abs->show_balance();
	delete abs;
}

void pass(){
     Master_Card a;
	Secondary_Card b;
	b.visit_secondary_card(b);
}

Master_Card operator+(Secondary_Card a,Master_Card b){  //全局函数重载运算符计算两卡余额之和
    Master_Card temp;
    temp.balance=b.balance+a.balance;
    return temp;


}

int main() {
    pass();
	balance();
    Master_Card a;
    Secondary_Card b;
    Master_Card c;
    c=b+a;
    c.visit_balance();          //运算符重载

	return 0;
}