(defun prime (n &optional (d (- n 1))) 
   (or (= d 1)
      (and (/= (rem n d) 0)
           (prime  n (- d 1))
      )
   )
)

; (print (prime 1009))

