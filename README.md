hi welcome to null.pid

--for starters--
pid values are in pid.cpp
and the robot config (bot dimensions and motors) are in robotconfiguration.cpp
both have a h and a hpp file
you will find these under src and include folders

before touching the pid make sure all your motors are set to the correct ports in the robotconfiguration.cpp or your pid will not work 

for pid tuning set all values to 0 for driving increase p value till the bot moves side to side very slightly then increase d value to smooth it out 
if d value is to high the values for moving foward will be either lower or higher than your exspected outcome

for turning pid repeat the same proccess as above 

once that all done go to main and make and auton undervoid autonomous()

--troubleshooting--

-bot is over stearing or under steeering (example when turnPID is set to 70 or -70 it turns 90deg)    change the D value 

-include path not found           set include path to "." in settings then reset then reset it back to the original

-bot spins in place         check the inertial connection 
