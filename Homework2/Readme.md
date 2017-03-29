#Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/) This is the framework for homework #2.
 
The assignment is due: **Tuesday, March 28 at 11:59PM (EST)**

# Devyn Dodge 

# Part 1: Empirical Tests of Randomness (20 pts)

* **(a) - 3pts: Output the results of five different random number engines, using a uniform distribution for values between [0-100]. Generate useful charts and statistics from the output to analyze how uniform these values truly are. You are expected to look at some advanced statistics and test, for example: tests like the Kolmogorov-Smirnov test, Chi-square test, Autocorrelation test, and Spearman’s Rank Correlation Coefficient are a few examples of ones your could use.)

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/all.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/Variance.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/SEM.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/SD.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/Range.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/Mode.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/Median.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/Mean.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/Max.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/Chi.PNG)

* **(b) - 2pts:**  Vary *N* (amount of samples). How do things change.

When changing the N to a much higher number, patterns were substantially clearer compared to the lower Ns. Because this is "random" I ran this experiment a few times and obtained fluctuating results. Means, ranges, variances, Chi scores, Standard deviations, etc. all fluctuated lower and higher than the very large data set of 100,000. For the most part though, the variances of the smaller data sets were larger as well as the standard deviations, but once again this is "random," so it can be flipped around if I were to run it again.


* **(c)- 3pts:** Fix a random engine of your choice from part (a), and now vary five different [distributions](http://www.cplusplus.com/reference/random/) for just the psedo-random numbers. Again, analyze your results with graphs and statistics of choice.

I chose the minstd_rand engine.

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/partc.PNG)

* **(d)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different random number engines. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines.
* **(e)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different distributions. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines. (See [Random Numbers Webcourse page](https://webcourses.ucf.edu/courses/1246518/pages/random-numbers?module_item_id=10541423) for a rough idea what you should produce.)

Parts D and E are below.

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/partde.PNG)

* **(f)- 4pts:** Repeat parts (d) and (e) with a unit circle.

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/partf.PNG)

# Part 2 - Snakes and Ladders (Discrete Event Markov Chains and Monte Carlo Simulations) (30 pts)

* **(a) Null State Game transition matrix - 10pts:** The *null state game* is defined by a game with no snakes and no ladders. This simplifies the game to just the moves of the two dice rolls. Create the transition matrix for the null state game. The Transition Matrix would be decided by the roll of a fair, six-sided die, so it would start to look like:
<BR>![](images/null.png?raw=true)<BR>
From state 0 it is equally probable of landing on squares 1-6. From state 1 t is equally probable of landing on squares 2-7, and so on. Create this transition matrix. The end is trickier, we will consider any roll past 100 a win case. (Opposed to rolling exactly onto square 100.) Confirm you have a well formed stochastic matrix (Write checks for confirming each row of T sums to one and all elements are non-negative). The Transition Matrix methods can be found in the TransitionMatrix.h file.

The Matrix is in the TransitionMatrix.h file.

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/transmatrix.PNG)

* **(b) Simulate and analyze the results of Null State Game - 10pts:** What is the modal number of moves required by a single player to finish the game? We will be simulating the game two different ways. **(1) Markov Chain**: The game can be analyzed with a row vector, *v* with 101 components, representing the probabilities that the player is on each of the positions. V(0) is (1,0,0,...,0) since we know we start at square 0. v evolves by: <BR>![](images/prob.png?raw=true)<BR>
For this part (1) use the *Markov project* in the Snake and Ladders starter code.<BR>
**(2) Monte Carlo**: he will will use a monte carlo process to solve our Discrete Time Markov Chains. Here (2) use the DTMC project, and utilize the DTMC method similar to what we did in class. <BR><BR>Produce graphs to analyze the results and show how the game evolves over time for both methods. Plot useful statistics of the results such as percentage chance of finishing the game in n-moves, cumulative probability of finishing the game in n-moves, and other ways to convey useful information of the results.

dtmc

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/dtmc.PNG)

markov

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/markov.PNG)

You can beat the game in just seven roles. The Modal number of rolls required to complete a game is 20. That's a pretty quick game. The average number of die rolls per game is approx 36.2.

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/nmoves.PNG)

Cited: http://www.datagenetics.com/blog/november12011/

* **(c) Simulate and analyze the results of Snakes and Ladders -10pts:**  Construct a new transition matrix based on the table:


Ladders From  | Ladders To | |  Snakes From  | Snakes To 
-------- | -------- | ------------- | -------- | -------- 
3|19| |11|7
15|37| |18|13
22|42| |28|12
25|64| |36|34
41|73| |77|16
53|74| |47|26
63|86| |83|39
76|91| |92|75
84|98| |99|70

********In the code*****************

Run the same simulation and analyze your results similar to part (b) for the proper game of *Snakes and Ladders* for both methods. How often are the snakes and ladders used, how do the probability of finishing change, etc? What is the maximum and expected amount of moves for the game? Use charts and graphs to illustrate these points.
* **(d) Think - 0pts:** If these games are built entirely on chance, do they require any strategy? Is it really a *game*, would you rather play games of chance or games of strategy?


# Part 3 - Discrete Event Simulation - Queue Simulation (30 pts)

I have a working example in my folders. Here are some pictures of it working.

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/part3.PNG)
![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/part3a.PNG)

* **(e) - 15pts:** Download the personal edition of **[Anylogic](http://www.anylogic.com/)**, read through the [documentation](http://www.anylogic.com/learn-simulation) as needed, and set up the same type of simulation discussed above.

Anylogic folder also uploaded.

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/anylogic.PNG)

# Part 4 - Implementing Extra Features (10 pts)

Implementing 2 features on the extra features list. Pick any feature on the "*extra features*" list below to customize your assignment to fit your interests. Please document this in your writeup. (*Note: These should total 10pts. You could successfully implement a feature worth 10pts or greater. This also fulfills this requirement. The features are assigned points based on difficulty. The 5pt features are more straightforward.*)

For another class I am doing research on how different assembly lines alter total output and I thought this would be a great addition. I can improve upon this and even create different layouts!
* **(10 Points)** - Setup another resource allocation / queueing problem related to your research in Anylogic with a basic visualization

Anylogic folder also uploaded.

![Alt text](https://github.com/Dmcdodge1/IDS6938-SimulationTechniques-1/blob/master/Homework2/images/Extra.PNG)

# Part 5 - Final Report (10 pts)

Write up the results to the previous sections in the main readme.md in your forked repository. Turn in the URL for your fork in webcourses. Be visual. The report should contain the graphs and analysis requested. I have high expectations for the documentation here and you should allot the proper time to compose the writeup.

Completed! 

##Extra Features (Extra Credit - 25pts)
You have to implement two features from this list for Part 4. You may choose any two features you wish from this list. (Please explicitly note them in your *Readme.md*)

If you feel like going beyond the scope of the assignment, you should consider implementing more of the following extra features. *Get the assignment working without them first.* You can get a maximum of 25 points in extra credit. Simply implementing these things doesn't guarantee you a 25; you really need to go above and beyond to get the full amount. (*The instructor reserves the right to hand out extra credit as his he sees fit.*)

* **(5 Points)** - Implement and compare Halton, Hammersley, (Or another quasi method) Quasi sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement different distributions inside the Quasi random sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement and compare another (advanced) psedo random sequences and add them to your analysis for all subparts of Part 1 (Examples include: [PCG](http://www.pcg-random.org/), or [Random123](https://github.com/DEShawResearch/Random123-Boost)).
* **(20 Points)** - Complete Part 2 with a different board game. Construct the game's transition matrix, simulate the game, and analyze the results (Run the game past the instructor).
* **(20 Points)** - Complete Part 2 with a 3D version of Snakes and Ladders. Construct the game's transition matrix, simulate the game, and analyze the results.
* **(10 Points)** - Provide code in (Python, R, Matlab...) that demonstrates an animation of the board itself evolving overtime for Snakes in Ladder for part 2. 
* **(10 Points)** - Add a 2D visualization to AnyLogic for Part 3.
* **(10 Points)** - Add a 3D visualization to AnyLogic for Part 3.
* **(5 Points)** - Pick a research problem (from your dissertation, Energy Microgrids, Missle Defence...). Compare and contrast different software packages (AnyLogic, Simio, Simulu8, Arena etc). Convince me as your "manager/advisor" what advantages, weaknesses, and costs each program has. Come to a conclusion. Roughly sketch out how you would formulate the problem in the framework.
* **(10 Points)** - Create an Anylogic simulation for Part 2 - Snakes and Ladders.
* **(10 Points)** - Setup another resource allocation / queueing problem related to your research in Anylogic with a basic visualization
* **(10 Points)** - Setup up SmartGrid or a Microgrid System that creates resources of power from wind, solar, and electric grid. Set up various devices in your house to draw power. [Reference 1](http://www.sciencedirect.com/science/article/pii/S1877050916301740),   [Reference 2](http://www.tandfonline.com/doi/full/10.1080/19401493.2013.866695?src=recsys&).
* **(25 Points)** - Set up a discrete simulation of your choice that uses an approved real-time data source and visualizes the results. (See instructor for approval).
* **(N Points)** - You are welcome to make suggestions for a feature of your own choosing, but they must be approved by instructor before implementing.