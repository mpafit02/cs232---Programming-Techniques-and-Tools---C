/**

@mainpage EPL232 The Kenken Puzzle 

@author Marios Pafitis

This program implements the Kenken Puzzle. In this program you can import your 
own Kenken Puzlle and play to solve it. Also you can import a Kenken Puzzle and
let the algorithm to solve it for you. This program is capable to work with 
dimensions of Kenken Puzzles 2x2 - 9x9.

At the beginning you have to import a Kenken Puzzle. Use the command 
kenken.exe -i inputfileName for windows and ./kenken.out -i inputfileName for Linux.

If you want to play in order to solve the puzzle use the command
kenken.exe -i inputfileName for windows or ./kenken.out -i inputfileName for Linux,
else if you want to let the computer solve it for you use the command
kenken.exe -s inputfileName for windows or ./kenken.out -s inputfileName for Linux.

The rules in order to solve the Kenken Puzzle: 
1. If you have for example a 4x4 Kenken Puzzle the only numbers you can use in 
order to solve it is 1, 2, 3 and 4. 
2. In each row and column, a number can be presented only once. 
3. The puzzle is separated in cages. For example the first cage could be the 
cells (1,1) and (1,2) and this cage has to have sum equal with 6. Then you have to
find two numbers that the have sum 6. The two possible cases are 2, 4 and 4, 2. It 
can't be 3, 3 due to those two positions are in the same row in which we can't 
have the same number presented two times.
 
If you want to add the number 3 in the cell in the position (1,2) for example 
you have to use the command 1,2=3 (i,j=val). If you want to change the number in a position
that there is already a number set you have to use the command 1,2=0 (i,j=0) in order to 
clear the cell and then add a different number.

If you want to exit and save you game use the command 0,0=0. The game will be saved
in a txt file with the same name as in the input file but it will also add "out-" in 
front of the name.

In case you are too lazy to solve the puzzle, don't worry! Use the solving command and
you will have the solution before you can even blink! Our algorithm for solving the puzzle is 
really fast. It uses a method that we call "Backtrack Recursion".

I really would enjoy this project if it was in Java. I found it very difficult to work with the
characters I read because in C there are no Strings. It was not a hard project but it took me 
40 - 50 hours to finish it. I think it will be better for future projects to be more specific for 
learning how to use the language than thinking how to solve an algorithm. Especially if a language
such as C is not friendly user enough. 

Enjoy our game!

*/