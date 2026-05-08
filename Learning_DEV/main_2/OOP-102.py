class Vehicle:
    license = ""
    serial = ""
    face = ""
    def turn_air(self):
        print("Turn on : Air")

class Ship(Vehicle):
    __name = ""
    def setname(self,text):
        self.name = text
        print("Setting new cat name :",self.name)
    def turn_air(self):
        print("Turn on : Fan |",self.name)

class Pickup(Vehicle):
    def open_trunk(self):
        print("Open : Trunk")

car1 = Pickup()
car1.turn_air()
car1.open_trunk()

ship1 = Ship()
ship1.setname("Titanic")
ship1.turn_air()