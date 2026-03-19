#This is a simple program to add two numbers using input function.
#y = input("Enter Any Number : ")
#z = input("Enter Another Number : ")
#print("The sum is :" , int(y) + int(z))

#y = int(input("Enter Any Number : "))
#z = int(input("Enter Another Number : "))
#print("The sum is :" , y + z)

#x = str(input("Enter Your Name : "))
#y = str(input("Enter Your Surname :"))
#print("Hello", x,y)

price = 150
vat = 7
result = price + (price*vat/100)
print("Total price including VAT is :", result,"THB")

x = float(input("Enter the price of the item : "))
y = float(input("Enter the VAT percentage : "))
z = x + (x*y/100)
print("-----------PremtongThani shop-----------")
print("Price of the item         ", x, "THB")
print("Vat percentage               " , y,"%")
print("---------------------------------------")
print("Total price including VAT ", z,"THB")
print("---------------------------------------")

