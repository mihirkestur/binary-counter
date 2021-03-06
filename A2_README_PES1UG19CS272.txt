Name    : Mihir Madhusudan Kestur
SRN     : PES1UG19CS272
Section : E 
Semester: 4

Data structure used:
The data structure used is an adjacency list. It is implemented by using a doubly linked list to make it easier 
to access the previous list. Roughly the data structure can be represented as shown below.
NULL<--M1<==>M2<==>M3<==>M4<==>...<==>Mn-->NULL
       |     |     |     |            |
       v     v     v     v            v
  player player player player      player   
       |     |     |     |            |
       v     v     v     v            v
  player player player player      player   
       .     .     .     .            .
       .     .     .     .            .
M1,M2...Mn represents the match lists, every match list has a pointer to a player who is the winner of that
particular match list and every player has a pointer to a loser or a list of losers of that particular winner.

player is a structure having a data field (it holds the number) and another field that points to the next player. 

Compilation:
The math.h module has been included. Hence, use -lm flag during compilation.
===> gcc *.c -lm 
===> ./a.out

Key take-away from this project:
Although, the complexity of finding the second largest element by the brute force method is linear (2*n - 2),
by using stepanov binary counter we can obtain a better linear complexity (n + log n - 2) for greater values of n.
With a little bit of concentration, conceptually the idea of binary counter is intuitive and easy to understand
however, actually implementing the stepanov binary counter was quite challenging. 