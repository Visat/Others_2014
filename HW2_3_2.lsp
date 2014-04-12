(defun fib2(n)
   (fib2-kernel 0 1 n) )

(defun fib2-kernel(current next remaining)
   (if (= 0 remaining)
      current
      (fib2-kernel next (+ current next) (- remaining 1) )
   )
)

