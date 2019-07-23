/**

@mainpage EPL232 The Page Ranking

@author Marios Pafitis

This program implements the Page Ranking algorithm. It takes as input two
files, the hostnames and the hostgraph. The format of the command is
pagerank hostnames.txt hostgraph.txt . The program is using an algorithm which 
calculates three parts. 

I(hi) the total number of hosts with yperlinks to the host i
Oi(hj) the number of hyperlniks fromt the host j to the host i
O(hj) the total number of hyperlinks to the host j

With a specific algorithm it calculates the page rank for every single host
and it prints in detail the results. 

This exercise was very interesting for me. It was a bit confusing at the begining because 
I couldn't understand what I had to calculate for the  I, Oi and O in order to use them in the 
Page Rank calculation. I suggest not to use greek words for international terms such as 
hostnames and hyperlinks.

Note: I assume that the files are consistent and valid.

Note: In order to compile you have to add the argument "-lm" for the Math library
*/
