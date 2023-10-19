# <p align="center">Problem B - A Pyramid Scheme</p>
### Description
A pyramid scheme is a well-known business model that is illegal in many countries. A member (the recruiter) of the organization that leads the pyramid scheme offers to an individual (the recruited) the possibility to join it under a given payment. In exchange, the organization shares part of this money with the recruiter and with every other member in the pyramid scheme. In addition, the directors of the organization (at the top of the pyramid) also receive a share.

The following picture illustrates the pyramid scheme, where the first recruited member is in the top of the tree. Each edge indicates who is the recruiter (top node) and the recruited (bottom node). Each label gives the amount of money paid by the recruited.

You are a finance inspector working to the government and you have received an anonymous information about a large pyramid scheme operating in your country. This information contains the list of all recruiters and members recruited by them, as well as the amount of money paid by each recruited member.

You need this information to be confirmed by checking that every recruitment reported in this list was established, but without doing too much fuss, otherwise, your investigation may be noticed by the organization that leads the pyramid scheme. The possibility that you have considered is to investigate the least number of members of this organization that can validate all the recruitments. You can assume that reaching either the recruiter or the recruited will be enough to confirm that a recruitment was performed. In addition, note that a member can, not only validate that he/she was recruited, but also that he/she was a recruiter, if applicable.

##
### Input
Each input may contain several test cases, each of which ends with a -1. Each test case contains several lines, each of which gives the id of a member, followed by the ids of those recruited by her/him, if any. The last number in each line corresponds to the amount of money paid by that member when he/she was recruited to the organization.

The id of the first member (in the top of tree) is always 0. The remaining ids range from 1 to 100000. There is no particular ordering of the ids in the input. You can assume that a recruiter has not been able to recruit more than 10 new members and that each recruited member paid no more than 100 Euros.
##
### Output
The goal is to find the least number of members to investigate that confirm all the recruitments as well as to report the total amount of money paid by them when they were recruited. In case there are several possibilities of forming such a group, consider those that maximize the total amount of money paid and report this value. For each test case, print these two values in a single line.

In the figure above, the solution is given by members 1, 2, and 3, with total value 91. Note that the solution given my members 1, 6, and 3 has value 116 but it is not valid since it is not possible to confirm that member 0 recruited member 2 (or that member 2 was recruited by member 0).
##
### Example
#### Example input:
0 1 1<br>
1 2 4 5 2<br>
2 3 8<br>
3 4<br>
4 16<br>
5 32<br>
-1<br>
0 1 2 3 30<br>
1 4 5 54<br>
2 6 12<br>
3 7 8 25<br>
4 41<br>
5 29<br>
6 37<br>
7 12<br>
8 23<br>
-1
#### Example output:
2 10<br>
3 91<br>
