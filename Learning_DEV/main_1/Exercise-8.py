A = str(input("Enter your username :"))
B = int(input("Enter your password:"))
if (A == "Jack" and B == 1234) or (A == "Maria" and B == 5678) or (A == "Skypia" and B == 9101112) :
    print("----------------------------")
    print("Login successful!")
    print("Loading...")
    print("------------------------------------------")
    print("----------Welcome to Banana shop!---------")
    print("This store sells many brands of smartphones")
    print("Here are the list of smartphones that we have :")
    phone = ["Iphone 17 Pro Max", "Oppo reno 8", "Samsung galaxy s27 Ultra"]
    print("Iphone 17 Pro Max               60,500 THB")
    print("Oppo reno 8                     17,750 THB")
    print("Samsung galaxy s27 Ultra        31,250 THB")
    print("------------------------------------------")
    C = str(input("Which phone do you want to buy? : "))
    if C == phone[0] or C == phone[1] or C == phone[2]:    
        D = int(input("How many do you want to buy? : "))
        print("------------------------------------------")
        price = [60500,17750,31250]
        if C == phone[0]:
            print("Total price : "+str(D*price[0])+" THB")
        elif C == phone[1]:
            print("Total price : "+str(D*price[1])+" THB")
        elif C == phone[2]:
            print("Total price : "+str(D*price[2])+" THB")
        print("------------------------------------------")
        E = str(input("Do you want to buy? :"))
        answer = ["yes","no"]
        if E == answer[0] :
            print("Thank you for your purchase!")
        elif E == answer[1] :
            print("Purchase was canceled!")
        else:
            print("Please answer yes or no")
    else:
        print("Sorry, we don't have that phone")
else:
    print("Invalid username or password!")




















