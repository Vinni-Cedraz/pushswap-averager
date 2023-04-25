# pushswap-averager

# STILL IN CONSTRUCTION (to be finished by the 28th of April)

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Foreword](#installation)
- [Trivia](#trivia)

## Installation
This is the installation section.

## Usage
This is the usage section.

## Foreword (or, Why bother?)

Buckle up for a long ride!

This tester is designed to try out a very broad range of combinations for the
5, 100, and 500 array sizes that your `push_swap` program is supposed to sort.

As you probably know by now, during your `push_swap` evaluation, your evaluator
will be asked to take the average case of your program and then rank your
project according to this average case for each array size.

However, evaluations where the average case is measured with some accuracy have
been very hard to find. This is because the number of permutations that can be
generated from an N sized array is N!, which is an astronomical number. And I
mean, it is a number so big that it couldn't fit in a million `size_t` variables,
even if we divided it by a billion.

So, for any case beyond the array 5 elements, it is impossible for the
evaluator to calculate the exact average case of your `push_swap` algorithm. But
this is not an excuse to simply test your program with 5 or 10 random arrays of
size 100 and 500 and draw conclusions out of it!

This is so much of a big deal that it could make or break your project! Imagine
how insufficient it is to measure 10 cases out of 100! The average of those ten
could be really far from the truth. It would be 10 random cases out of:

93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000

For an array of size 500 the number is even more obscene:

1220136825991110068701238785423046926253574342803192842192413588385845373153881997605496447502203281863013616477148203584163378722078177200480785205159329285477907571939330603772960859086270429174547882424912726344305670173270769461062802310452644218878789465754777149863494367781037644274033827365397471386477878495438489595537537990423241061271326984327745715546309977202781014561081188373709531016356324432987029563896628911658974769572087926928871281780070265174507768410719624390394322536422605234945850129918571501248706961568141625359056693423813008856249246891564126775654481886506593847951775360894005745238940335798476363944905313062323749066445048824665075946735862074637925184200459369692981022263971952597190945217823331756934581508552332820762820023402626907898342451712006207714640979456116127629145951237229913340169552363850942885592018727433795173014586357570828355780158735432768888680120399882384702151467605445407663535984174430480128938313896881639487469658817504506926365338175055478128640000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

This is why the `push_swap-averager` was born

To test thousands of permutations in a semi-random pattern that would be as
representative as possible, I have divided the total number of permutations
of an N-sized array into N groups. Then, I pick up 160 random permutations
from each of these N groups to create the sample set of permutations that will
be tested as input for your `push_swap`. These permutations are generated by a
simple Fisher-Yates algorithm function you can find at `ft_randomize_array.c`.

This means that for the 100 size case, the `push_swap-averager` will be
executing your push_swap 16,000 times. It is still a small number compared to
the total. But because of the way the combinations are selected, the result is
a very consistent measurement of your average case and it can be finished
within 30 seconds on the 4 cores / 2 threads per core iMacs we have at the 42
school.

If you run the `push_swap-averager` 10 times in a row, you'll see what I'm
talking about: each time the test is taken, the count of the average case will
be slightly different (because the sample selected will be unavoidably
different) but only by a very small deviation. For example, out of 10 tests, my
`push_swap` program ranked averages between 579 and 589. Seems close enough for me.

But then I applied the same logic to randomize the 500 elements array and it
ended up not being consistent enough.

So I had to do some research on the basics of Pseudorandomness in computer science
and decided to implement the Mersenne-Twister algorithm to improve both the
consistency of the average-case calculations and the execution speed of the
program. See? If the permutations are not well-distributed enough then we need
a bigger set of permutations to get an accurate average-case, which leads to a
longer execution time. On the other hand, better distributed permutations can
be representative enough without the need for a huge number of arrays to be
generated and tested.

The Mersenne Twister algorithm is a well-known and widely used algorithm for
generating high-quality pseudo-random numbers. It has been extensively tested
and shown to be very efficient and effective at generating well-distributed
permutations. In fact, it is commonly used in scientific simulations and other
applications that require high-quality random number generation. That is why I
chose it. You can find its implementation in the source file called
`mersenne_twister.c`.

I know I could have done it all with a short `Bash` script, and it would make
for a shorter code and a simpler program. In fact, I had done it before... But
it was taking three and one half hours to test 10,000 combinations of size
500. This is why I've written this tester was written in `C` a compiled
language which is usually faster and supports a multithreaded approach.

So this is why I bothered to make this test: to have a quick and accurate way
of assessing the average-cases of push_swap programs, but mostly to learn a lot
of stuff in the process of (hopefully) achieving that.

## Trivia
- The longest English word with all its letters in alphabetical order is
"aegilops," which is a type of plant.
- Scientists have discovered a set of snow crystals that may be the first
matching pair ever found, challenging the common belief that no two snowflakes
are alike. The crystals were collected on a glass plate during a research
flight over Wisconsin in 1986 and were found to have almost identical growth
histories. The discovery raises the possibility that more identical pairs of
snow crystals could be found in the future.
- The traditional method of shuffling playing cards, known as the riffle
shuffle, is not truly random. A study published in the Proceedings of the
National Academy of Sciences found that if someone knows the initial order of
the cards, they can predict the outcome of a riffle shuffle with high
accuracy.
