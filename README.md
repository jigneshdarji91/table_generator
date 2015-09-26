# Table Generator
Project to generate ASCII based tables from user data

### Introduction
Table Generator reads a file having delimeted table elements and creates a formatted table.

### Examples
Input:

No. Professor   Course Name Course Number
1   Dr. Heber   Design and Analysis of Algorithms   CSC505
2   Dr. Dutta   Internet Protocols  CSC573
3   Dr. Perros  Networking Services CSC576

Output from FairFormatter:

+-----+------------+-----------------------------------+---------------+
|No.  |Professor   |Course Name                        |Course Number  |
+-----+------------+-----------------------------------+---------------+
|1    |Dr. Heber   |Design and Analysis of Algorithms  |CSC505         |
+-----+------------+-----------------------------------+---------------+
|2    |Dr. Dutta   |Internet Protocols                 |CSC573         |
+-----+------------+-----------------------------------+---------------+
|3    |Dr. Perros  |Networking Services                |CSC576         |
+-----+------------+-----------------------------------+---------------+

Output from UnfairFormatter:

+=====+============+===================================+===============+
|No.  |Professor   |Course Name                        |Course Number  |
+=====+============+===================================+===============+
|1    |Dr. Heber   |Design and Analysis of Algorithms  |CSC505         |
+-----+------------+-----------------------------------+---------------+
|2    |Dr. Dutta   |Internet Protocols                 |CSC573         |
+-----+------------+-----------------------------------+---------------+
|3    |Dr. Perros  |Networking Services                |CSC576         |
+-----+------------+-----------------------------------+---------------+
