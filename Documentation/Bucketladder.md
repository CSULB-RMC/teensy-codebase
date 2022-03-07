# Bucketladder Class

**Purpose:**
___
This class will contain methods that will control the bucketladder. 

____
**Basic movements:**
____

So the bucketladder has 3 types of movements:
1. Extend/Retract (Vertical)
2. Extend/Retract (Horizontal)
3. Dig

**Extend/Retract (Vertical)**
To help visualize this essentially think of the linear actuators that help angle/life the auger towards the ground for last year's design. 

This movement will be controlled by the HDA-4 Linear Actuator.

<br>

**Extend/Retract (Horizontal)**
To help visualize this essentially think of the telescoping system that moves the auger tube up and down.

This movement will be controlled by the Mini CIM motor. Furthermore the distance of how far it has extended and retracted will be tracked by the CIM motor encoder.

<br>

**Dig**
Essentially the auger rotating but this time its a bucketladder.

This movement will be controlled by the BAG motor.

<br>

**ALL OF THESE MOVEMENTS CAN GO FORWARDS OR BACKWARDS BASED ON CONTEXT**


____
**Speed adjustment:**
____

Linear Actuators have no need to be adjusted for their speed (they're pretty much slow based on Maurice's experience with them)

