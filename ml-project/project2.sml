(*
!usr/bin/SMLNJ
project2.sml
MAT 374 ML Projct
By AbdulHameed Ahmed.
*)

(*Question 1*)
(*Define a function which computes the product of all integers between m and n
(with n >= m) inclusive. Use this function to define the function Cn,k (the number
of combinations of n elements taken k by k), which is defined by 
Cn,k = n! * (n - k!) *)

fun product( m, n ) = if n <= m then m else n * product( m, n - 1 );
fun C( n, k ) = product( n - k + 1, n ) div product( 1, k );

(*Question 2*)
(*Define a function single : 'a list list -> 'a list
 which takes in input a list of lists and gives back the list consisting of all the 
 elements, in the same order in which they appear in the argument.*)
 
 fun single [] = [] | single (h::t) = h @ single t;
 







