### Data Averages:
Naive algorithm result: 625025000
Naive algorithm time: 1.949004 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000067 seconds

### Measurement Methodology
Before starting any benchmarks, its important to formulate a methodology, where the data is measured accurately. The experiment started with choosing a baseline function which will be compared to the function that to be tested. After deciding the baseline function, the time is measured by getting the timestamp just before the execution time, and another timestamp directly after, once these two timestamps were recorded,the difference is computed which will be the total execution time for the baseline function. The function to be tested went through the same measurements, where the timestamp is recorded before and after the function was executed, then getting the difference.
The measurements were run multiple times with both of the functions, in our case, we have run it three times, and got the average of all the measurements, since we do not have the ability to make all the variables consistent, having a bigger dataset is important to arrive to the correct conclusion.

### Observed Performance Differences
Both functions loops and executes the same base code, the biggest difference is the native function has a loop inside of a loop which is also known as a nested loop, while the single pass function only has a loop. The result of the single pass algorithm is 25000 while the 625025000, which is the square of the single pass's result. The native function's average execution time is 1.9449004 seconds while the single pass algorithm has an average execution time of 0.000067 seconds. In summary, the single-pass algorithm is 35779.57 times more efficient than the native algorithm and the single-pass algorithm loops though 25001 times less than the native algorithm.
The data above supports our conclusion that the single pass function is more efficient than the native function.

### Relation Between Runtime and Energy Consumption
Based on the data above the the difference between the two functions is quite significant. The single pass function iterates 25001 times less than the native function. Each iteration requrires a certain amount of time and CPU activity, hence the more iteration your program has, the more time and harder your CPU will need to work, in other words, the runtime and energy consumption are directly proportional to each other. While sometimes nested loops are needed, when writing code, software engineers should be aware of the implications of uneffient algorithms.

### Limitations of the Experiment
As with most experiments, the methology has its flaws, its imporatant to know what the limitations of your experiment to have the correct conclusion. In this experiment, we do not have complete control of our system, while we can try to reduce the variables like executing the experiment around the same time and have the same programs running, the data will still be different, as there are computations happening under the hood that we have not factored, even moving your mouse will affect the result. To add, there might be difference in the hardware as well, for example, on the last iteration, your hardware will have different temperature which will affect the processing time. To help counteract these factors, running multiple experiments and getting the average will be essential.

### Practical Engineering Takeaway
Looking at the data, the difference of efficient vs inefficient algorithms is significant. As mentioned before, while sometimes having nested or inefficient algorithms is essential, when we design an alogorithmwe as software engineers should take into account the efficiency of our codebase, especially when handling nested loops. For example the loop of the native function could be rewritten in one loop, while this requres more thought and math to get to the same result, this is still worth it, with this experiment its not as important since each function runs for only a few seconds. But imagine if you have thousands of inefficient functions running at the same time, this can result to slow and stuttery software, and even worse its possible to completely break your system.
