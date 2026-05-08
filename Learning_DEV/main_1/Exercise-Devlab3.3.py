x = int(input("Enter a distance in kilometers : "))
y = 35
if x > 1: 
    y += (min(x,10)-1)*5.5
if x > 10:
    y += (min(x,20)-10)*6.5
if x > 20:
    y += (min(x,40)-20)*7.5
if x > 40:
    y += (min(x,60)-40)*8
if x > 60:
    y += (min(x,80)-60)*9
if x > 80:
    y += (x-80)*10.5
print("The total bus fare is : "+str(y)+" Baht")




A = int(input("Enter a rent : "))
B = int(input("Enter a water bill : "))
C = int(input("Enter a electricity bill : "))
D = int(input("Enter a internet bill : "))
E = int(input("Enter a call charge : "))
total = A+B+C+D+E
if total <= 2000 :
    print("----------Summary----------")
    print("Rent            ",A,"THB")
    print("Water           ",B,"THB")
    print("Electricity     ",C,"THB")
    print("Internet        ",D,"THB")
    print("Phone           ",E,"THB")
    print("---------------------------")
    print("Total :",A,"+",B,"+",C,"+",D,"+",E)
    print("      =",total,"THB")
    print("---------------------------")
    rest = 2000 - total
    meal = ["Drinking Water", "Soup", "Instant Noodles", "Chewy Noodles"]
    if rest == 0:
        print("Select :  " +meal[0]+" (0 THB)")
        print("Saving :       0 THB")
    if 6 > rest >= 2:
        print("Select :  " +meal[1]+" (2 THB)")
        print("Saving : ",   rest-2,"THB")
    if 10 > rest >= 6:
        print("Select :  " +meal[2]+" (6 THB)")
        print("Saving : ",    rest-6,"THB")
    if rest >= 10:
        print("Select :  " +meal[3]+" (10 THB)")
        print("Saving : ",    rest-10,"THB")
    print("---------------------------")
else :
    print("Go earn some more money, YOU BASTARD!")

























