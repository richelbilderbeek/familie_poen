# Familie Poen

Branch|[![Travis CI logo](TravisCI.png)](https://travis-ci.org)|[![Codecov logo](Codecov.png)](https://www.codecov.io)
---|---|---
master|[![Build Status](https://travis-ci.org/richelbilderbeek/familie_poen.svg?branch=master)](https://travis-ci.org/richelbilderbeek/familie_poen) | [![codecov.io](https://codecov.io/github/richelbilderbeek/familie_poen/coverage.svg?branch=master)](https://codecov.io/github/richelbilderbeek/familie_poen?branch=master)
develop|[![Build Status](https://travis-ci.org/richelbilderbeek/familie_poen.svg?branch=develop)](https://travis-ci.org/richelbilderbeek/familie_poen) | [![codecov.io](https://codecov.io/github/richelbilderbeek/familie_poen/coverage.svg?branch=develop)](https://codecov.io/github/richelbilderbeek/familie_poen?branch=develop)

`Familie Poen` is a card game.

![Cards](Cards.jpg)

## Goal

Goal of this experiment is to find out if there are strategies
that are easy and better.

Strategy|Description
---|---
L|Always play the card with the lowest value
H|Always play the card with the highest value

## Methods

  * Assign 2, 3, or 4 players with a fixed strategy, in all combinations
    of strategies
  * Play 1M games, score who wins

## Results

Whatever strategy, the first player has an advantage of
51%, 34.6% and 27.7% in 2, 3 and 4 player games respectively.

## Discussion

There may be smarter strategies, for example, those that
count cards.

## Short manual

`Familie Poen` is a 2-4 player game

### Cards

There are 36 cards, as there is a card for
each combination of one of the six colors and one of the six value.
Values are: 1, 2, 5, 10, 20, 50.

![Cards](Cards.png)

### Setup

 * Each player gets 112 coins (1 x 50, 1 x 20, 2 x 10, 2 x 5, 4 x 2, 4 x 1)
 * Each player get five random cards
 * The other cards are put on drawing pile
 * Top card of drawing pile is put open on playing pile

## Playing

 * The active player must place any card on the playing
   pile that has either the same color or value. If
   the player does so, it is the next player's turn
 * If no card can be played, the active player must draw a card.
   If that card can be played, it is played. Then, it is
   the next player's turn.
 * Whoever gets rid of all cards wins the game

## Results

### Two player matches

Matchup|First player wins|Second player wins
---|---|---
LL|508434|491566
LH|511433|488567
HL|511206|488794
HH|508699|491301

What to do as a first player:

 * No info: 
    * When playing L, you'll win 508434 + 511433 = 1019867
    * When playing H, you'll win 511206 + 508699 = 1019905
    * Conlusion: it does not matter, you will win 51% of all times
 * Other plays L:
    * When playing L (LL), you'll win 508434 
    * When playing H (HL), you'll win 511206   
    * Conlusion: it does not matter, you will win 51% of all times
 * Other plays H:
    * When playing L (LH), you'll win 511433 
    * When playing H (HH), you'll win 508699    
    * Conlusion: it does not matter, you will win 51% of all times
 * Conclusion: even if knowing what the other plays, player
   1 will win 51% of all cases

### Three player matches

Matchup|First player wins|Second player wins|Third player wins
---|---|---|---
LLL|343617|333134|323249
LLH|350884|311338|337778
LHL|323798|350744|325458
LHH|364319|336266|299415
HLL|364166|336025|299809
HLH|324299|351300|324401
HHL|351325|311875|336800
HHH|343733|333531|322736

What to do as a first player:
  * If no info about the others
    * If player 1 plays L, wins will be: 343617+350884+323798+364319=1382618
    * If player 1 plays H, wins will be: 364166+324299+351325+343733=1383523
    * Conclusion: strategy of player 1 is irrelevant. Without info player 1 wins 34.6%

If the first players know the strategies of the other players,
it does not matter much, but

Would player 2 and 3 team up and ...
 
  * play two different things: player 1 should play the same as player 2.
  * play the same way: player 1 should do the opposite


## Four players

Matchup|1 wins|2 wins|3 wins|4 wins
---|---|---|---|---
LLLL|274688|260206|242828|222278
LLLH|284186|254673|234728|226413
LLHL|270433|255269|248375|225923
LLHH|285798|255114|244539|214549
LHLL|268105|270465|245476|215954
LHLH|279073|259974|240624|220329
LHHL|269758|268875|235534|225833
LHHH|286811|264299|234034|214856
HLLL|286768|264359|234113|214760
HLLH|270158|267900|236267|225675
HLHL|278610|260112|241084|220194
HLHH|268616|270213|246150|215021
HHLL|285711|254635|244447|215207
HHLH|271531|254129|248859|225481
HHHL|282880|255110|235056|226954
HHHH|275943|260243|242038|221776

For player 1:
  * Without info:
    * Playing L: 2218852
    * Playing H: 2220217
    * Conclusion: does not matter, will win in 27.7% of all cases 

It does not matter how the others team up, player 1 will always win,
no matter which strategy.



