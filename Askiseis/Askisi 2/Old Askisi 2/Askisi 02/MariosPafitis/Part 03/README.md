/**

@mainpage EPL232 The SED Compare

@author Marios Pafitis

This program implements the SED Compare algorithm. Basically it takes as input
two files with two strings. Then it calculates the minimum amount of movements 
we have to do in order to make the two words the same. To import the files you
have to use this command: sedcmp file1.txt file2.txt

The distance is calculated in movement. You can do three movements in order to 
change a word. 

1) Insertion of a letter
2) Deletion of a letter
3) Change one letter to another

Each movements costs 1. In the end you can have the minimum number of movements 
that are required. This program uses two algorithms two solve this problem. The 
first is recursive and it is very slow. It performs well when the length of the
two string is small. The second algorithm is using an array and a different 
technique in order to calculate the distance and it is vary fast. By default the
second algorithm is activated for solving the problem. If you wan to try the 
recursive algorithm you can just uncomment it and try it. Good luck for this...
you have to be patient. 

From this project I have learned that the recursion is not always the best choice
for all the problems. It is important to see what suits you better and use it 
properly. 

*/