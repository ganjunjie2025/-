class Master_Card:
    total_Card=0     #类属性     

    def __init__ (self,name:str,passwd:str,balance:int): #实例属性
        self.name=name
        self.__private_passwd=name
        self.__private_balance=balance    #将银行卡余额和密码设定为私用属性
        Master_Card.total_Card+=1   
    
    def visit_balance(self):
        return f"{self.name}的银行帐户余额为：{self.__private_balance}元！"     #类内访问私有属性
    
    @classmethod   #类方法
    def  get_card_number(cls):
        return f"此银行一共有{cls.total_Card}张卡"    #统计银行卡数
    
a=Master_Card("张三","123456",1000)
b=Master_Card("李四","123789",5000)
print(a.name)
print(a.visit_balance())
print(b.visit_balance())
print(a.get_card_number())
    

