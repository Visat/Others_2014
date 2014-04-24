% when search the first element, return list first element.
% If not the first element, search remain list till satisfy the upper case.

element_pos(X,[X|_],1).
element_pos(X,[_|L],I) :- I>1, K is I-1, element_pos(X,L,K).

