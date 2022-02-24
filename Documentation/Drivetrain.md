# Drivetrain Class

**Purpose:**
___
This class will contain methods that will control the drivetrain. 

<br>

____
**Basic movements:**
____

Methods include having the rover to be able to move **FORWARD** and **BACKWARDS**. Future implementation of **LEFT** and **RIGHT** movements will be considered. 

Initial joystick implementation in last year's competition where its 1:1 (joystick to drivetrain side). Hence two forward commands to the two left and right sides of the drivetrain.

This year's implementation shall try to control both sides of the drivetrain with one command. Hence, one method will set the speeed and direction of BOTH motors.

<br>

______
**Speed Adjustment:**
_______
Other than movements, speed adjustment of the motors will also be another functionality required. Two types of speed adjustment methods are considered: **Direct Input** and **Auto-Adjustment**.

<br>

**Direct speed adjustment:**

The physical user or controller inputting a numerical value, and the numerical data is sent directly to the motor driver.

<br>

**Auto-Adjustment:**

Due to the fact that not all DC motors will rotate at the same constant speed, auto-adjusting motor speeds should be considered so that one side of the rover will not be faster than the other. 

The implementation of this is only possible with the usage of a rotary encoder sensor to calculate the rotational speed in which will adjust the desired speed with the actual adjusted speed.  


<br>

___
**Hardware Interfaced:**
___