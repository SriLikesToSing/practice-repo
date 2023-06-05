module plfa.part1.Naturals where
open import IO

data ℕ : Set where
    zero : ℕ
    suc : ℕ → ℕ 



-- this is a comment 
{- this is a multi line comment-}

-- pragma has affect on the code
{-# BUILTIN NATURAL ℕ #-}

import Relation.Binary.PropositionalEquality as Eq
open Eq using (_≡_; refl)
open Eq.≡-Reasoning using (begin_; _≡⟨⟩_; _∎)

_+_ : N → N → N 
zero + n = n
(suc m) + n = suc(m + n)

_ : 2+3 ≡ 5
_ = 
  begin 
    2 + 3
  ≡⟨⟩
    (suc (suc zero)) + (suc (suc (suc zero)))

  ≡⟨⟩
    suc ((suc zero) + (suc (suc (suc zero))))

  ≡⟨⟩
    suc(suc(zero + (suc (suc (suc zero)))))

  ≡⟨⟩
    5
  ∎
 -- ≡ is equal with all appropriate instantuations of the variable
_ : 2+3 ≡ 5
_ = refl

-- +-exercise : 
sum : 3 + 4 ≡ 7 
sum = 
    begin 
      3 + 4
    ≡⟨⟩
       (suc(suc(suc zero))) + (suc (suc (suc (suc zero))))  

    ≡⟨⟩
        7
    
    ∎

sum : 2 + 3 ≡ 5
sum = refl


-- multiplication

_*_ : ℕ → ℕ → ℕ
zero     * n = zero
(suc m)  * n = n + (m * n)

_ = 
  begin 
    2 * 3
  ≡⟨⟩ -- inductive case
    3 + (1 * 3)
  ≡⟨⟩ -- inductive case
    3 + (3 + (0 * 3))
  ≡⟨⟩ -- base case 
    3 + (3 + 0)
  ≡⟨⟩ -- simplify 
    6
  ∎

*-example : 3*4 ≡ 12
*-example =
  begin 
    3 * 4
  ≡⟨⟩ -- inductive case
    4 + (2 * 4)
  ≡⟨⟩ -- inductive case
    4 + (4 + (1 * 4))
  ≡⟨⟩ -- base case 
    4 + (4 + (4 + (0 * 4)))
  ≡⟨⟩ -- simplify 
    4 + (4 + (4 + 0))
  ≡⟨⟩ -- inductive case
    4 + (4 + 4)
  ≡⟨⟩ -- inductive case
    4 + 8
  ≡⟨⟩ -- inductive case
    12  
  ∎


_^_ : ℕ → ℕ → ℕ
m ^ zero = 1
m ^ suc(n) = m * (m ^ n)

exp : 3 ^ 4 ≡ 81

exp =
  begin 
    3 ^ 4
  ≡⟨⟩ 
    3 * (3 ^ 3)
  ≡⟨⟩ 
    3 * (3 * (3 ^ 2))
  ≡⟨⟩ 
    3 * (3 * (3 * (3 ^ 1)))
  ≡⟨⟩ 
    3 * (3 * (3 * (3 * (3 ^ 0))))
  ≡⟨⟩ 
    3 * (3 * (3 * (3 * (1))))
  ≡⟨⟩ 
    3 * (3 * (3 * 3))
  ≡⟨⟩ 
    3 * (3 * 9)
  ≡⟨⟩ 
    3 * 27 
  ≡⟨⟩ 
    81 
  ∎

_∸_ : ℕ → ℕ → ℕ
m ∸ zero = m
zero ∸ suc n = zero
suc m ∸ suc n = m ∸ n 

_ = 
  begin
    3 ∸ 2
  ≡⟨⟩ 
    2 ∸ 1
  ≡⟨⟩ 
    1 ∸ 0 
  ≡⟨⟩ 
    1
  ∎

-- subtracting a  larger number from a smaller one
_ = 
  begin
    2 ∸ 3
  ≡⟨⟩ 
    1 ∸ 2
  ≡⟨⟩ 
    0 ∸ 1 
  ≡⟨⟩ 
    0 
  ∎

∸-example₁ : 5 ∸ 3 ≡ 2
∸-example₁ = 
  begin
    5 ∸ 3
  ≡⟨⟩ 
    4 ∸ 2 
  ≡⟨⟩ 
    3 ∸ 1
  ≡⟨⟩ 
    2 ∸ 0 
  ≡⟨⟩ 
    2
  ∎

∸-example₂ :  3 ∸ 5 ≡ 0 
∸-example₁ = 
  begin
    3 ∸ 5
  ≡⟨⟩ 
    2 ∸ 4 
  ≡⟨⟩ 
    1 ∸ 3
  ≡⟨⟩ 
    0 ∸ 2 
  ≡⟨⟩ 
    0 
  ∎

-- precedence and associativity of infix operations needs to be declared

infixl 6 _+_  _∸_
infixl 7 _*_


{-# BUILTIN NATPLUS _+_ #-}
{-# BUILTIN NATTTIMES _*_ #-}
{-# BUILTIN NATMINUS _∸_ #-}


-- Exercise Bin (stretch)


data Bin : Set where
  ⟨⟩ : Bin
  _O : Bin → Bin
  _I : Bin → Bin
  

inc : Bin → Bin 
inc(⟨⟩) = I
inc(x O) = x I 
inc(x I) = inc(x) O 


to : ℕ → Bin
to(0) = ⟨⟩ O  
to (x) = inc(to(x-1))

{-
11 -> 1011 
to(11) = inc(to(10))
to(10) = inc(to(9)) 
to(9) = inc(to(8))
...
to(1) = inc(to(zero)) ≡ inc(⟨⟩ O)

to(1) = ⟨⟩ I  
to(2) = inc(⟨⟩ I)
to(3) = inc(⟨⟩ I)
to(4) = inc(to(3))
to(5) = inc(to(4))
to(6) = inc(to(5))
to(7) = inc(to(6))
to(8) = inc(to(7))
to(9) = inc(to(8))
to(10) = inc(to(9))
to(11) = inc(to(10))
-}

from : Bin → ℕ
from ⟨⟩ O  = 0 
from inc(x) = inc(from(x))








