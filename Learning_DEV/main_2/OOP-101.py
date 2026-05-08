class Customer:
    name = ""
    lastname = ""
    age = 0

    def addcart(self):
        print("Added to",self.name,self.lastname+"'s cart!")

customer1 = Customer()
customer1.name = "Charle"
customer1.lastname = "Innosent"
customer1.age = 16
customer1.addcart()

customer2 = Customer()
customer2.name ="Mikasa"
customer2.lastname ="Ackerman"
customer2.age = 22
customer2.addcart()


