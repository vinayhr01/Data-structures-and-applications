Hasing :  Hashing is searching technique takes time complexity of O(1).

-> linear searching is a searching algorithm takes the time complexity of
O(n)(N no of comprasions)
-> similarly binary search takes the time complexity O(log n)


But there is need of searching technique which takes very less time
complexity,
-> The hashing takes very less time for searching.
->Hasing is divied into teo types
1. Static hashing
2. Dynamic Hasing

Static Hasing: In static hasing the dictionary paris are store in a table
called ht called hash table.

-> The hash table is partitioned into b buckets
  ht[0],  .......bt[b-1] // b is bucket

-> Each bucket is capable of holding s dictionary pairs.
->Thus the bucket consists of s slots.

-> Each slot being large enough to hold one dictionary pair.

Creation of hash table:  Consider thee hash table ht with
b=26 buckets  and s=2     , we have 10 distinct identifiers.
-> Libaray  function like
1. acos  2. define  3. float  4. exp  5.char  6.atan  6. ceil 8. floor
9. clock 10.ctime


..................................
	    slot 0      Slot 1
..................................
0 a          acos        atan
..................................
1 b
..................................
2 c          char	 ceil
..................................
3 d          define
.................................
4 e          exp
......................................
5 f          float       floor
.....................................
6
....................................

.

.
.
.

.
.
.
.
......................................
25
......................................

Files: