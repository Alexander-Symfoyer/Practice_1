menu = {"Tonkatsiu":510,"Ramen":365,"Udong":290,"Yakisoba":630}
listab =[]
total = 0

def bill():
    print("--------Myfood--------")
    for i in range(len(listab)):
        print(listab[i][0],listab[i][1])
    print("Total :",total,"JPY")

while True :
    A = input("Please enter menu : ")
    if A.lower() == "exit" :
        break
    elif A in menu:
        listab.append([A,menu[A]])
        total += menu[A]
    else:
        print("Menu not found!!!")
print(listab)
bill()





















