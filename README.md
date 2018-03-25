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
C|Play cards that are common in hands of others (they are rare in player's hand nor in played pile) 
H|Always play the card with the highest value
R|Play randomly
L|Always play the card with the lowest value
U|Play cards that are uncommon/rare in hands of others (they are common in player's hand and in played pile) 

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

```
cat *.log | egrep ".*\|.*" -o
```

Matchup|First player wins|Second player wins
---|---|---
CR|48.1627|51.8373
HR|52.1526|47.8474
LR|52.0926|47.9074
RR|51.7178|48.2822
UR|54.8951|45.1049
RC|55.7963|44.2037
RH|51.1961|48.8039
RL|51.3625|48.6375
RR|51.7178|48.2822
RU|47.9368|52.0632

What to do as any player:

 * Play cards that are uncommon in hands; 
   that combine with as much cards on the table and in hand possible

You'll win in 53.5% when playing against random opponents.

### Three player matches

Matchup|First player wins|Second player wins|Third player wins
---|---|---|---
CRR|31.4501|36.7911|31.7588
HRR|35.7508|33.4775|30.7717
LRR|35.7899|33.4253|30.7848
RRR|35.8241|33.4079|30.768
URR|39.7026|30.5399|29.7575
RCR|37.0027|29.1799|33.8174
RHR|35.7803|33.4608|30.7589
RLR|35.7916|33.5139|30.6945
RRR|35.8241|33.4079|30.768
RUR|34.7961|37.2843|27.9196
RRC|39.1564|34.3302|26.5134
RRH|35.8205|33.5193|30.6602
RRL|35.7225|33.4736|30.8039
RRR|35.8241|33.4079|30.768
RRU|32.7392|32.589|34.6718

What to do as a first player:
 * Play cards that are uncommon in hands; 
   that combine with as much cards on the table and in hand possible

## Four players

Matchup|1 wins|2 wins|3 wins|4 wins
---|---|---|---|---
CRRR|23.5352|28.8916|25.036|22.5372
HRRR|27.6259|26.0936|24.1867|22.0938
LRRR|27.6349|26.1853|24.1638|22.016
RRRR|27.8279|26.0283|24.0209|22.1229
URRR|31.6392|23.6056|23.226|21.5292
RCRR|28.3062|22.0182|26.6791|22.9965
RHRR|27.867|25.9588|24.0936|22.0806
RLRR|27.9239|26.0294|24.0375|22.0092
RRRR|27.8279|26.0283|24.0209|22.1229
RURR|27.272|29.984|21.6323|21.1117
RRCR|28.7217|26.5645|20.2471|24.4667
RRHR|27.8075|26.2833|23.8989|22.0103
RRLR|27.8178|26.1981|23.9864|21.9977
RRRR|27.8279|26.0283|24.0209|22.1229
RRUR|26.8576|25.6247|27.746|19.7717
RRRC|30.5232|26.8027|24.2814|18.3927
RRRH|27.7941|26.2073|24.1083|21.8903
RRRL|27.7263|26.1903|24.0932|21.9902
RRRR|27.8279|26.0283|24.0209|22.1229
RRRU|25.1749|25.4156|23.7917|25.6178

For player 1:
 * Play cards that are uncommon in hands; 
   that combine with as much cards on the table and in hand possible

It does not matter how the others team up, player 1 will always win,
no matter which strategy.



