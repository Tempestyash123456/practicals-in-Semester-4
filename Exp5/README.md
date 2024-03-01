## Experiment: 5

**Aim:** To find the order of performing the job sequencing for maximum profits using greedy algorithm

**Algorithm:** Follow the given steps to solve the problem:

1. Sort all jobs in decreasing order of profit. 
2. Iterate on jobs in decreasing order of profit.For each job , do the following : 
   * Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in 
this slot and mark this slot filled. 
   * If no such i exists, then ignore the job. 

**Program code:** [Source-code](https://github.com/Tempestyash123456/practicals-in-Semester-4/blob/Design-and-Analysis-of-Algorithms/Exp5/jobScheduling_Exp5.cpp)

**Output:**

![Image](https://1.bp.blogspot.com/-eAzicsvNDtw/YRde3DMRncI/AAAAAAAAAFg/ydERoWBu3JA2s60vVXlYqX-Qxw87l3DJQCLcBGAsYHQ/s487/job.png)
