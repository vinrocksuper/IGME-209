HW5.cpp is main.cpp

Check comments for further details

Order of code run:

Push x3 into default constructor 
Prints out queue
Prints out # of elements in queue(3)

Pops x1
Prints out queue
Prints out # of elements in queue(2)

Pops x2
Prints out queue(nothing is printed)
Prints out # of elements in queue(0)
Prints out that there are no elements in queue(IsEmpty==true)

Push x2
Uses copy constructor to make second queue
Prints out size of both queues (2,2)
Push x1 into copy queue
Prints out both queues(3,2)

Sets original queue to copy queue via = operator
Prints out original queue(3)