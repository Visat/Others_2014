% If list equal then stop, or eliminate the duplicate elements to 1 and 
% do until every element appears once.

eliminate([], []).
eliminate([X], [X]).
eliminate([X,X|Xs], Z) :- eliminate([X|Xs], Z).
eliminate([X,Y|Ys], [X|Z]) :- X\=Y, eliminate([Y|Ys], Z).

