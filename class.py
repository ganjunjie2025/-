class Hero:   #英雄基类
    def __init__(self,name:str,bleed:float,speed:str,hurt:int):
        self.name=name
        self.bleed=bleed
        self.speed=speed
        self.hurt=hurt
    def base_attributes(self):
        return f"{self.name}的血量为：{self.bleed},速度为：{self.speed},基础伤害为：{self.hurt}点！"
    def hurt_harm(self):
        return f"英雄{self.name}可造成{self.hurt}点伤害！"

class Tank(Hero):   #坦克为派生类
    def __init__(self,name:str,bleed:float,speed:str,hurt:int,defence:int):
        super().__init__(name,bleed,speed,hurt)
        self.defence=defence
    def Defence(self):
        return f"{self.name}可免疫{self.defence}点伤害！"
    
class Shooter(Hero):      #射手为派生类
    def __init__(self,name:str,bleed:float,speed:str,hurt:int,berserk:int):
        super().__init__(name,bleed,speed,hurt)
        self.berserk=berserk
    def hurt_harm(self):
        return f"{self.name}由于携带狂暴,多造成{self.berserk}点伤害！"
    
def show_base_attributes(hero:Hero): #定义一个展示父类基础属性的函数
    print(hero.base_attributes())
    return

a=Shooter("鲁班七号",3000,100,100,50)
show_base_attributes(a)    #多态的实现
print(a.hurt_harm())

b=Tank("白起",4201,75,65,54)
show_base_attributes(b)
print(b.Defence())


