(defun palindrome (x) 
   (do ((x x (cdr x)) 
        (y x (cddr y)) 
        (z () (cons (car x) z)))
       ((null (cdr y)) 
        (equal z (if y (cdr x) x)))
   )
)

