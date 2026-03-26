fruits = {"apple","banana","mango","orange","dragon fruit"}
for i in fruits:
    print(i)
print("apple" in fruits)
print("pear" not in fruits)

fruits.remove("orange")
fruits.add("lemon")
print(fruits)

num = int(input("Enter number of your favs fruits : "))
myfruit = set()
while len(myfruit)<num:
    myfruit.add(str(input("Enter a fruit : ")))
    print(myfruit)

a = [1,2,3,4,5]
b = set(a)
print(b)
