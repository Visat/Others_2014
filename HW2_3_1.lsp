(DEFUN fib1(n)
   (IF (< n 2)
    n
      (+ (fib1 (- n 1))  (fib1 (- n 2)) )
   )
)

