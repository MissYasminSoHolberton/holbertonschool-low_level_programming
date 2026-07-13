All recordings are from the comparison_algorithms.c test

Data:

Result 1:
Naive algorithm result: 625025000
Naive algorithm time: 2.182554 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000061 seconds

Result 2:
Naive algorithm result: 625025000
Naive algorithm time: 1.950997 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000077 seconds

Result 3:
Naive algorithm result: 625025000
Naive algorithm time: 1.713461 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000064 seconds

Average:
Naive algorithm result: 625025000
Naive algorithm time: 1.949004 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000067 seconds

### Measurement Methodology
- Get the baseline data.
- Record the time before the execution of the baseline function, then recorded the time after the baseline function has fully executed.
- Get the difference of the recorded times, the result will be the total execution time for the baseline function.
- Run this a couple of times to get the average execution time of the baseline function.
- Do the same for the other function.
- Compare both execution times.

### Observed Performance Differences
- The single-pass algorithm is 35779.57 times more efficient than the native algorithm.
- The single-pass algorithm loops though 25001 times less than the native algorithm.

### Relation Between Runtime and Energy Consumption
- It takes time running one loop, the more times you run a loop the more time passes. The runtime is directly proportional to the number of times the code loops.

### Limitations of the Experiment
- Both of the functions should be executed in the same hardware, around the same time, if another program starts between the execution of both functions, then the results will be inaccurate.

### Practical Engineering Takeaway
- Efficient algorithms can reduce runtime and loop counts significantly. When designing an algorithm, especially with loops, you would need to think about how many times your codebase loops. if possible think of ways to maximize each loop.
