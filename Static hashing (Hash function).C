Hash Function:(static Hashing):
Division:
	This has function which is the most widely used hash function in
practice.Assume the keys are non negtive integers. The home bucket is
obtained by using the nodulo(%)operator. The key K iis divided by some number
D and the ramainder is used as the home bucket for K. More formally


Exam 1:	h(K)= k%D
	key=5000
	D=20
	h(K)=0

Exam 2: h(k)=K%D
	key=5002
	D=20
	h(k)=2

Mid square: The Mid square hash function determines the home bucket for a key
by squaring the key and using appropriate number of bits from the middle of
the square to obtain the bucket address.

	key=242
	squaring a key: 242*242=58564
	we can chose bucket no as =5 (By chosing single digit)

				  =56(By chosing double digit).

Folding Method: In this method the key is partitioned into several parts, all
but possibly the last being of the same length. the partitions are added
together to obtain the hash address for the key.

	Example:Assume key=12320324111220

	    Partitioning  key 123  203 241 112  20

	    adding the Parts:  123+203+241+112+20=699

	    hash address =699


Open addressing: Opening addressing is mainly used to handle overflow.
-> First we need to understand what is overflow.
-> Assume 5 buckets with 2 slots.

	      slot (1)       slot(2)
.............................................
b[0]           01		 021

b[1]           12               123      < ->   assume anothe key  1345

b[2]           23               2345

b[3]          345               354

b[4]          455               453

Bucket 1 is having only two slots  so we cannot insert thrid one, this creats
the overflow.
-> There are 4 open addressing methods
 1 . Linear probing  (Linear open addressing)
 2.  Quadratic probing
 3.  Rehashing
 4.  Radom Probing

 We have Linear probing:
  consider the below given table:

  ..................................................................
   identifier  Additive Transformations                 x      hash(Key%D)
  ...................................................................
     for            102+111+114                         327      2
     do             100+111                             211      3
     while          119+104+105+108+101                 537      4
     if             105+102                             207      12
     else           101+108+115+101                     425       9
     function       102+117+110+99+116+105+111+110      870      12


		      [0] -> function (with cocept of linear probing)
		      [1]
		      [2] ->for
		      [3] ->do
		      [4] ->while
		      [5]
		      [6]
		      [7]
		      [8]
		      [9] ->else
		      [10]
		      [11]
		      [12] -> if
Linear probing. (Lab  Exp 12)
