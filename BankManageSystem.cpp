
#include<iostream>//创建一个银行管理系统
#include<vector>
using namespace std;

class p_account{             //个人账户类
private:                           //将密码和余额设置为私用属性
    string account_pass;
    double balance;
public:
     string host_name;
    p_account(string name,string pass,double balance){  //构造函数初始化
            host_name=name;
            account_pass=pass;
            p_account::balance=balance;
    }

   //公有成员函数
    bool inputpass(){  //检验密码
        string pass;
        cout<<"请你输入帐户密码"<<endl;
        int sum=0;
        do{
        cin>>pass;
        if(pass==account_pass){
            cout<<"密码正确！"<<endl;
            cout<<"当前余额是："<<balance<<endl;
            return true;
        }
        else cout<<"当前密码错误，请重新输入"<<endl;
        sum++;
        }while(sum<3);
         cout<<"密码输入超过验证次数，已退出！"<<endl;  
        return false;
    }

    bool check_balance(string name){  //检查帐户
        if(name==host_name)
        cout<<"当前帐户存在！"<<endl;
        else {cout<<"当前帐户不存在！"<<endl;
        return false;}
        inputpass();
        return true;
    }

    //类内访问私用属性余额并且进行存钱和取钱的操作
    void getaccount(){
        double money;
        cout<<"请输入您需要取出的钱额"<<endl;
        cin>>money;
        if(money<=balance){
         balance-=money;
         cout<<"取钱成功！"<<endl;
         cout<<"当前余额为："<<balance<<endl;
        }
        else{
            cout<<"当前取钱数超过银行余额，取钱失败！"<<endl;
        }
    }

    void addaccount(){
        double money;
        cout<<"请输入您需要存入的钱额"<<endl;
        cin>>money;
        balance+=money;
        cout<<"存钱成功！"<<endl;
        cout<<"当前余额为："<<balance<<endl;
    }

};


void menushow(){ //菜单系统
    cout<<endl;
cout<<"======银行管理系统======"<<endl;
cout<<"    1.添加个人银行帐号   "<<endl;
cout<<"    2.查询个人储蓄余额   "<<endl;
cout<<"    3.存款             "<<endl;
cout<<"    4.取钱             "<<endl;
cout<<"    0.退出系统          "<<endl;
}

class bank{//银行管理类
 public:
       vector<p_account>account;
     
       void add_account(){//添加银行帐户
            string name;
            cout<<"请输入您的帐户名"<<endl;
            cin>>name;
            string pass;
            cout<<"请输入您的帐户密码"<<endl;
            cin>>pass;
            double balance;
            cout<<"请存入您想存入的钱"<<endl;
            cin>>balance;
            account.push_back(p_account(name,pass,balance));
            cout<<"添加成功"<<endl;
       }

       bool  check_account(){  //查询帐户
           string name;
           cout<<"请您输入帐户名"<<endl;
           cin>>name;
         for(auto &element: account){
            if(element.check_balance(name));
            return true;
         }
         return false;
       }

       void  add_balance(){  //存钱
          string name;
       cout<<"请输入您的帐户名"<<endl;
       cin>>name;
       for(auto &element:account){
        if(element.host_name==name){
        if(element.inputpass())
        element.addaccount();
    }
       }
       }

    void get_balance(){  //取钱
       string name;
       cout<<"请输入您的帐户名"<<endl;
       cin>>name;
       for(auto &element:account){
        if(element.host_name==name){
        if(element.inputpass())
        element.getaccount();
    }
       }
    }

};

int main(){
      bank Bank;
      int choice;
      do{
        menushow();
        cin>>choice;
        switch(choice){
          case 1:Bank.add_account();//添加帐户
              break;
           case 2:Bank.check_account();//查询余额
               break;
           case 3:Bank.add_balance();//存款
               break;
           case 4:Bank.get_balance();//取钱
               break;
            case 0:
            break;
        }
      }while(choice!=0);
         cout<<"退出成功，感谢使用！"<<endl;
    return 0;
}