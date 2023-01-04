// Author : Hanine A.

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        if(tasks.size() < 2)
            return -1;

        // Sort "tasks" vector
        sort(tasks.begin(), tasks.end());

        int level = tasks[0];   // first level in the vector
        int nbTasks = 1;  // number of tasks of the same difficulty level 

        int index = 1;
        int lastIndex = tasks.size() - 1;
        
        int rounds = 0;     // minimum rounds to complete all the tasks
        int rounds_3 = 0;   // rounds of 3 identical tasks
        int rounds_2 = 0;   // rounds of 2 identical tasks

        while(index <= lastIndex)
        {
            // Compute the number of tasks of the same difficulty level
            while(index <= lastIndex && tasks[index] == level)
            {
                ++nbTasks;
                ++index;
            }

            // It is not possible to complete only one task of a certain level
            if(nbTasks == 1)
                return -1;
            else {
                // Compute the maximum rounds of 3 tasks needed to complete tasks of the same difficulty
                // Ensure that remaining tasks can be done by a group of 2 tasks per round
                // If not adjust the number of rounds where 3 tasks can be completed then those with 2 tasks
                // In this way we obtain the minimum rounds required to complete all tasks
                rounds_3 = nbTasks / 3;
                rounds_2 = (nbTasks % 3) / 2;

                if(((nbTasks % 3) % 2) != 0) {
                    rounds_3 -= 1;
                    rounds_2 += 2;
                }
            }
            rounds += (rounds_2 + rounds_3);

            level = tasks[index];
            nbTasks = 0;
        }

        return rounds;  
    }
};
