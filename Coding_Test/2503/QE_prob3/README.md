### **Problem Statement**

You are tasked with designing a simple simulation for different types of car engines using **object-oriented programming** principles. Specifically, you must create three classes to model their behaviors:

1. **Abstract Class `Engine`**  
   - Must have a pure virtual function, `startEngine()`, which is implemented by its subclasses.  
   - Acts as a base class for all kinds of engines.

2. **Concrete Class `GasolineEngine`** (inherits from `Engine`)
   - Has a single data member representing **fuel efficiency** (e.g., kilometers per liter).  
   - Implements `startEngine()` so that it prints out a message indicating the gas engine has started.  
   - Provides a function `computeFuelConsumption(distance)` which, given a certain travel distance in kilometers, returns the amount of fuel (liters) consumed (using the formula `distance / fuelEfficiency`).  

3. **Concrete Class `HybridEngine`** (inherits from `GasolineEngine`)
   - Includes additional data members:
     1. `batteryCapacity` (float): capacity of the battery in kWh.  
     2. `efficiencyFactor` (float): factor that determines electric consumption.  
     3. `hybridMode` (bool): indicates whether the hybrid system is enabled.  
   - Overrides `startEngine()` to print a message for the hybrid engine, then starts the gas engine, and if `hybridMode` is true, prints a message for the electric motor.  
   - Contains a function `computeBatteryConsumption(distance)`, which calculates how many kWh the battery consumes for the given distance based on `efficiencyFactor`.  
   - Includes a function `computeTotalPowerConsumption(distance)` that calculates the total energy usage (fuel + battery), based on:  
     - If `hybridMode` is **true**:  
       - 70% of the distance is powered by gasoline, 30% by electricity.  
       - Convert gasoline liters to kWh (assume 1 liter ≈ 9.7 kWh) to show final results in kWh.  
     - If `hybridMode` is **false**:  
       - Everything is powered by gasoline alone, with zero battery usage.  
   - Provides a `displaySpecs()` function that prints the engine’s current specifications, including battery capacity, fuel efficiency, and the hybrid mode status.

#### Your goal is to:

- **Implement the above classes** (`Engine`, `GasolineEngine`, `HybridEngine`) with all described data members and methods.
- Make sure you demonstrate **object-oriented design** effectively (inheritance, virtual functions, overriding, etc.).

---

#### Sample Output

Below is an example of what might be printed when these classes are used in a hypothetical test:

```
Gasoline engine started.
Fuel consumption is 5.0 liters.
Hybrid engine started.
Gasoline engine started.
Electric motor started.
Hybrid engine specifications:
Fuel efficiency: 18.5
Battery capacity: 15.0
Hybrid mode: Enabled
Computing power consumption for 100.0 km:
Fuel used: 3.8 liters
Battery used: 4.3 kWh
Total power used: 41.2 kWh
Hybrid engine started.
Gasoline engine started.
Hybrid engine specifications:
Fuel efficiency: 18.5
Battery capacity: 15.0
Hybrid mode: Disabled
Computing power consumption for 100.0 km:
Fuel used: 5.4 liters
Battery used: 0.0 kWh
Total power used: 52.4 kWh
```
