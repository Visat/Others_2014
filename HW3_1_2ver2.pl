% Factorial tail recurion.

factorialTail(N,Result) :- factorialTail(N,1,Result).
factorialTail(0,Result,Result) :- !.
factorialTail(N,RTemp,Result) :-
   NextN is N-1,
   NextRTemp is RTemp*N,
   factorialTail(NextN,NextRTemp,Result).

