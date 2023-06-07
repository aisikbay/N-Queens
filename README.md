# N-Queens
The n-queens problem is that of placing _n_ queens on an _n_ x _n_ chess board such that no queens can attack each other. 
Queens can advance any number of spaces vertically, horizontally, or diagonally. As this problem has a lower bound of n=4, the following is the base example.

# Example
<img align="left" src="https://user-images.githubusercontent.com/94331548/243140235-f6fd78a1-9571-482f-8b00-0b49689475a5.png">The first queen is placed in the first available position with no issue.

<img align="right" src="https://user-images.githubusercontent.com/94331548/243140572-d7a32ff6-9260-44d9-b489-f33b9e7a0063.png"><p align="right">The second queen must go in the next row. Immediately, the first two columns in this row are 'unsafe,' so the second queen will take the third column spot.</p><br clear="right">

<img align="left" src="https://user-images.githubusercontent.com/94331548/244177560-6c7b044a-2c3e-442c-a74d-f5a472dc26bc.png">We encounter a problem when placing the third queen. All of the column slots in this row are unsafe due to the arrangement of the two previous queens. To solve this problem we will use *backtracking*.

<img align="right" src="https://user-images.githubusercontent.com/94331548/243140957-53334be1-3bd4-45ed-8cef-9927eedcc952.png"><p align="right">We will move the last placed queen to its next available position. We then return to placing the third queen, this time in the second column.</p><br clear="right">

<img align="left" src="https://user-images.githubusercontent.com/94331548/244180581-0aeb4e90-a7b2-48ec-a591-94f36d4c108d.png">
When attempting to place the last queen, we find that we must backtrack once again, as there are no available spots.

<img align="right" src="https://user-images.githubusercontent.com/94331548/243141367-53ea1489-ed60-4770-a473-9516e187e9cb.png"><p align="right">However, the third queen has no more safe spots to shift to. This means we must backtrack the second queen as well. As the second queen is in the last column position, we will have to backtrack to the first queen.</p><br clear="right">

<img align="left" src="https://user-images.githubusercontent.com/94331548/243141430-748c38f9-67bd-4492-b1b8-45999608a900.png">After shifting the first queen to the second column, the second queen must go in the last column of the second row.

<img align="right" src="https://user-images.githubusercontent.com/94331548/243141474-ee34195e-a2cf-4c1e-96a8-f83e85db9315.png"><p align="right">The rest of the queens can be placed following this process with no issue. This is a valid solution for the N-Queens problem where n=4. No two queens are aligned vertically, horizontally, or diagonally.</p><br clear="right">

# Implementation
The following is a brute-force backtracking approach to the n-queens problem. It utilizes a vector to store the column positions of each queen. <br>
See it run: https://youtu.be/38OKWlAC8PE