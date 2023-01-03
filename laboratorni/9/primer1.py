# vehicle
#sport car, max speed, method pri podavane na metoda i podavane na kolata na vrne max skorost
# umnozenie od 1 do 20
# 1 do 20 , za predisnata cifra, i sumata na tqh
from random import randint, choice

class Vehicle:
    def __init__(self, brand, model, fuel_consumtion):
        self.brand = brand
        self.model = model
        self.fuel_consumtion = fuel_consumtion

    @staticmethod
    def find_car(brand, model, cars):
        for car in cars:
            if car.brand == brand and car.model == model:
                return car.fuel_consumtion
    
class SportCar(Vehicle):
    def __init__(self, brand, model, fuel_consumtion, speed):
        super().__init__(brand, model, fuel_consumtion)
        self.speed = speed

    def max_speed(self):
        return self.speed

car_brands = ("Mercedes", "Yugo", "Audi", "BMW")
car_models = ("S", "TDI", "124", "C")
car_fuel = (1, 2, 3, 4)

cars = [Vehicle(choice(car_brands), choice(car_models), choice(car_fuel)) for i in range(10)]

print(Vehicle.find_car("Mercedes", "S", cars))