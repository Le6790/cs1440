## Overview
In this assignment, you will create a program to analyze weather data, namely precipitation data from the National Centers for Environmental Information. Since the purpose of this assignment is to become familiar with Cloud9 and to start thinking about code organization, you won’t actually need to write any new code yourself. Instead, you will reorganize a single .cpp file into separate .cpp and .h files.

## Setup
0. Open Cloud9 and create a new private C++ workspace (you will use this same workspace for all of your assignments).
1. Clone my WeatherAnalyzer repository from BitBucket into a directory called "cs1440-hw1".
2. Open a terminal, navigate into the cs1440-hw1 directory, and build the project with the "make" command.
3. Play with the program to understand how it works. Try running it with the following arguments:
  * (no argument)
  * Data/2012-Jan-to-Mar.csv
  * Data/2013-Jan-to-Mar.csv
  * Data/2013-Jan-to-Mar.csv COOP:425186
  * Data/2013-Jan-to-Mar.csv COOP:426414


## Instructions
Now that you have a working program to start from, begin refactoring and improving the program.

0. Review the main.cpp file. This file contains all the code needed for a properly functioning program, but it is not organized well.
1. Decide how you want to organize the code into .cpp and .h files. Remember that
	.h files declare components, (e.g. functions and classes)
	.cpp implement those components
2. Create your desired .cpp and .h files, and then move code snippets from the main.cpp file into them. When you are finished, main.cpp will only contain the definition of the main() function, along with some #include directives.
3. As you work, frequently test that your program still compiles without error and produces the correct results. If you focus on moving one class at a time you will be able to maintain a working program at each step of your work.
4. Improve the user-friendlyness of the program by causing the main() function to display a helpful usage message when called with no arguments.
