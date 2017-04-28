# Devyn Dodge

Due: Friday 4/28/2017 (three extra days saved during the semester and the one extra stated in class)

Note: During this assignment, I had assistance from fellow classmates, utilized webcourses, notes, Piazza, and discussions.

# Homework 3 : Agent based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

This is the framework for homework #3. 

### Part 1: Behaviors

**(a) - 10 points** : Compute derivative vector given input and state vectors. Implement the function *SIMAgent::FindDeriv()*. This function sets derive vector to appropriate values after being called.

Description of agent state vector and input vector:  
* state[0] is the position of the agent in local body coordinates (almost useless in this project);  
* state[1] is the orientation angle of the agent with respect to world (i.e. global) coordinates;  
* state[2] is the velocity of the agent  in local body coordinates.  
* state[3] is the angular velocity of the agent in world coordinates. 
* input[0] is the force in local body coordinates;  
* input[1] is the torque in local body coordinates

You will need to set deriv[0], deriv[1], deriv[2], deriv[3]. Compute derivative vector given input and state vectors. This function sets derive vector to appropriate values after being called. 
* deriv[0] is the velocity of the agent  in local body coordinates
* deriv[1] is the angular velocity of the agent in world coordinates
* deriv[2] is the force in local body coordinates divided by the mass.
* deriv[3] is the torque in local body coordinates divided by the inertia.

--------------------------------------------------------------------------------------------------------

**Answer for Part 1 A: From lines 272-275 in my Agent.cpp file are the derivatives.**

**deriv[0] = state[2];**

**deriv[1] = state[3];**

**deriv[2] = input[0] / Mass;**

**deriv[3] = input[1] / Inertia;**

---------------------------------------------------------------------------------------------------------

You also must implement *SIMAgent::InitValues()*: Try to figure out appropriate values for control and behavior settings. You need to find out appropriate values for: *SIMAgent::Kv0, SIMAgent::Kp1, SIMAgent::Kv1, SIMAgent::KArrival, SIMAgent::KDeparture,
SIMAgent::KNoise,	SIMAgent::KWander, SIMAgent::KAvoid, SIMAgent::TAvoid, SIMAgent::RNeighborhood, SIMAgent::KSeparate, SIMAgent::KAlign, SIMAgent::KCohesion.*

----------------------------------------------------------------------------------------------------------

**Below is a snapshot of my values used for the simulation.**

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Values.PNG)

-----------------------------------------------------------------------------------------------------------

**(b) - 20 points**: In this part of the assignment you will need to implement 6 types of individual behaviors and 5 types of group behaviors. Create the following behaviors through appropriate computation of V<sub> d</sub>  and θ<sub>d</sub>  commands:

------------------------------------------------------------------------------------------------------------

### Seek 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Seek.PNG)

------------------------------------------------------------------------------------------------------------

### Flee 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Flee.PNG)

------------------------------------------------------------------------------------------------------------

### Arrival 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Arrival.PNG)

------------------------------------------------------------------------------------------------------------

### Departure 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Departure.PNG)

------------------------------------------------------------------------------------------------------------

### Wander 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Wander.PNG)

------------------------------------------------------------------------------------------------------------

### Obstacle Avoidance

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Avoid.PNG)

------------------------------------------------------------------------------------------------------------

**(c) - 20 points**: Implement the functions for the following group behaviors: 

### Separation

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Sep.PNG)

------------------------------------------------------------------------------------------------------------

### Cohesion 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Cohesion.PNG)

------------------------------------------------------------------------------------------------------------

### Alignment 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Align.PNG)

------------------------------------------------------------------------------------------------------------

### Flocking

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Flock.PNG)

------------------------------------------------------------------------------------------------------------


### Leader Following

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Leader.PNG)

------------------------------------------------------------------------------------------------------------


Note: Feel free to reference the code saved in the src or build folder. Here is a link to a Youtube video showing all the required functions: https://youtu.be/spPMkCekizI 

------------------------------------------------------------------------------------------------------------

# Part 2 - Simulating a simple pedestrian flow
**(a) - 0 points:** Follow the Anylogic example for the Subway Entrance example. Create the appropriate boundaries and walls, and the display ther pedestrian density map, statistics, 2D and 3D animations.

Below is the Subway Entrance Simulation with appropriate boundaries and walls with the pedestrian density map and statistics of people along side it.

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/Subway.PNG)

------------------------------------------------------------------------------------------------------------

**(b) - 20 points**: Create a maze. Generate the pdm, stats, and animations like before. Vary [parameters in your agents](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Attributes.html) to give them different behaviors and show the pedistrians change how they navigate the maze.

Below is my maze simulation with the heat map, statistics, parameters, and in a 3D version. The file to this will be saved up. I have to say. I really enjoyed this assignment. I can see using this often in the real world for work. It was fun watching the guys run around. Setting up the maze was tricky at first. To begin with, they would automatically just head to the end, but i figured out how to avoid that. Once again. This was interesting and fun. I would recommend this for your following semesters.
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/maze1.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/maze2.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework3/images/maze3.PNG)

------------------------------------------------------------------------------------------------------------

**(c) - 30 points**: Model and analyze a building (or floor/outdoor space/stadium) on campus. (There is help on piazza how to find rough building plans - we expect something plausible). Create a senario: evacuation, daily office routine, special event, normal egress.... etc., and model and design your own experiment to determine if the building design suits the needs of its users. Start with photographs of your site, describe your site, describe your senario and hypothesis. Then use an agent-based pedistrian simulation to visualize your experiment's results.



