#Homework 1 : The Jello Cube (Continuous Simulation Assignment)
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)
Official website for IDS6938 Simulation Techniques

Devyn Dodge
Note: Discussed some code with classmates/chat.
Referenced the setup of structural springs and bend springs from Piazza.
Euler and Midpoint were pieced together by sources from class and meetup sessions. 

Cited: 
http://edutechwiki.unige.ch/en/X3D_shape_and_geometry 
https://www.opengl.org/archives/resources/code/samples/glut_examples/examples/scube.c 
https://www.w3schools.com/cssref/css_colors_legal.asp
https://www.cs.rpi.edu/~cutler/classes/advancedgraphics/S09/lectures/06_mass_spring_systems.pdf

Part 1:

Step A:

Solve for the exact symbolic (analyitcal) solution.

	Exact Solution = exp(x / 2.0)*sin(5.0 * x);
		*Thank you WolframAlpha

Step B:

After step (a) you ahve the values for the df and exact functions. Translate the mathematical formulas you now have into the df and exact functions.

	double df(double x, double y){
		return y - (1.0 / 2.0)*exp(x / 2.0)*sin(5.0 * x) + 5.0 * exp(x / 2.0)*cos(5.0 * x);
	}
	double exact(double x){
		return exp(x / 2.0)*sin(5.0 * x);
	}

Step C:

Run three numerical integration solutions: RK1, RK2, and RK4 to generate the numerical and exact values. 

Part1a 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework1/images/Part1a.PNG)
Part1b 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework1/images/Part1b.PNG)
Part1c 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework1/images/Part1c.PNG)

Step D:

Plot the error percentages for RK1, RK2, and RK4 in another graph.

Part1d 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework1/images/Part1d.PNG)

Step E:

Vary the step siz h=n where you define three n values for x=<0.0,10.0>, PLot the results just for RK4 with three differnt n values with the exact solution. Plot the error rate.
***I wanted to zoom in certain sections of the table. It allows for a great shot of the variances. If the whole graph was included, you couldnt see the slight differences.

Part1e 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework1/images/Part1e.PNG)

Part1f 

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework1/images/Part1f.PNG)

Part1g
 
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework1/images/Part1g.PNG)

Step F:

1) Describe how varying the integration method changes the accuracy.

Use the .PNGs from the Images folder for reference. If you take a look at Part1.PNG you can see that each method has its level of accuracy. The Euler method is the least accurate. Next is the Midpoint method, followed by RK4 as the most accurate (closest to the EXACT value). 
The image shows the variance as time goes on.  

2) What happens as you increase the x value to the accuracy?

Take a look at Part1d.PNG. This image clearly shows the accuracy as the x value increases. The error percentages are how far off each method is from the EXACT result. 
As x increases, it can be seen that the variance from teh EXACT value starts to show up, some more than others. But in all cases, as the x value increases the less accurate each method becomes. This can also be seen from the data charts in Part1a.PNG and Part1b.PNG. 

3) How does varying the step size effect the accuracy.

Turn your attention to Part1e.PNG, Part1f.PNG, and Part1g.PNG. With these increases, you can see how sharply it jumps between each points instead of the even flow from the previous images. 
You can see the error percentage shoot way up from the the event snapshot I took. With these increased step sizes, it is easier to visualize with the graphs and data charts to see the variances.  

4) Which method is the most accurate and why?

Rk4 is the most accurate because it goes up to a higher order. Euler only goes to one, midpoint only goes to 2, but RK4 goes up to the fourth interation. 
Having the first, second, third, and fourth derivative/integration is way more accurate than just having the first lile Euler's method, or the second from the Midpoint method. The higher the order, the better the accuracy.  

Part 2:

I chose to implement for the 2 mandatory extra features:

-A sphere collision

-Create a movie of my jello cube environment (https://youtu.be/oSDw5t43vew)

For extra credit I chose to implement:

-Create a movie exploring the differences in integrations types and stiffness. (https://youtu.be/XigIpat2yFc)

-Own choosing: Change the color? (If not totaly understandable, did it more for fun anyways.)

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework1/images/Cube.png)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework1/images/Cube2.png)

Part 3:

1) What is the effect of the Ks and Kd parameters on the Jello?

Ks and Kd effect the jello's stiffness. The variables specifically alter the spring compression strength. You can either have the springs contract quickly or slowly. The combination of Ks and Kd will determine how the cube bounces around the objects and the floor. A stiffer spring may not compress as much, but it will make the jello less fluid like.

2) What are the benefits and the drawbacks of the collision system used here? What are some different ways in which it could be improved?

I thought the collision system was ok. I would be curous to see how much it could handle, ie. numerous cubes bouncing off of each other and other objects. I'm assuming right off the bat, the frame rate would drop drasstically, and it would slow the whole program down. Are there better methods of testing a jello cube against objects?

3) What are some example systems you could model with Mass-Spring Simulations? Explain how you would construct the model.

Modeling cloth/fabrics have an elasticity. I would assume anything that is elastic can be modeled using a spring system. A spring itself, maybe a model of a rubber band?

4) Does the jello behave realistically? What integration method did you choose to make the jello stable?

For the most part I think it behaves realistically. The only way to find out would be to make a cube of jello and test it out. Hmmmmmm (https://youtu.be/y4s5VBqJems) Yep it seems to be realistic to me. I chose the RK4 method. It was the most reliable and produced the most desirable outcomes. 

5) How would you model and simulate water (In terms of a continuous simulation)?

I would model a simulation of water using a particel system. It is a collection of many small, simple particles that maintain state. The particle motions are influenced by external forces.  


*Test 

