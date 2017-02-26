# IDS6938-SimulationTechniques
Official website for IDS6938 Simulation Techniques

Devyn Dodge
Note: Discussed some code with classmates/chat
Pulled the setup of structural springs and bend springs from Piazza.
Euler and Midpoint were pulled from sources from class and meetup sessions. 

Step A:

	exp(x / 2.0)*sin(5.0 * x);

Step B:

	double df(double x, double y)           {
		return y - (1.0 / 2.0)*exp(x / 2.0)*sin(5.0 * x) + 5.0 * exp(x / 2.0)*cos(5.0 * x);
	}


	double exact(double x)           {
		return exp(x / 2.0)*sin(5.0 * x);
	}

Step C-F *Pictures of graphs in Images Folder

1) Describe how varying the integration method changes the accuracy.
	Open up the .PNGs from the Images folder for reference. If you take a look at Part1.PNG you can see that each method has its level of accuracy. 
	The Euler method is the least accurate. Next is the Midpoint method, followed by RK4 as the most accurate (closest to the EXACT value). 
	The image shows the variance as time goes on.  

2)What happens as you increase the x value to the accuracy?
	Take a look at Part1d.PNG. This image clearly shows the accuracy as teh x value increases. The error percentages are how far off each method is from the EXACT result. 
	As x increases, it can be seen that the variance from teh EXACT value starts to show up, some more than others. 
	But in all cases, as the x value increases the less accurate each method becomes. This can also be seen from the data charts in Part1a.PNG and Part1b.PNG. 

3)How does varying the step size effect the accuracy.
	Turn your attention to Part1e.PNG, Part1f.PNG, and Part1g.PNG.  
	With these increases, you can see how sharply it jumps between each points instead of the even flow from the previous images. 
	You can see the error percentage shoot way up from the the event snapshot I took. With these increased step sizes, it is easier 
	to visualize with the graphs and data charts to see the variances.  

4)Which method is the most accurate and why?
	Rk4 is the most accurate because it goes up to a higher order. Euler only goes to one, midpoint only goes to 2, but RK4 goes up to the fourth interation. 
	Having the first, second, third, and fourth derivative/integration is way more accurate than just having the first lile Euler's method, or the 
	second from the Midpoint method. The higher the order, the better the accuracy.  

