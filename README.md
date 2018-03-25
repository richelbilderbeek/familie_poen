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
CC|52.2012|47.7988
CH|47.9993|52.0007
CL|47.5984|52.4016
CR|48.1627|51.8373
CU|44.3608|55.6392
HC|56.1318|43.8682
HH|51.61|48.39
HL|51.8642|48.1358
HR|52.1526|47.8474
HU|48.2165|51.7835
LC|56.3672|43.6328
LH|51.8426|48.1574
LL|51.6373|48.3627
LR|52.0926|47.9074
LU|48.5655|51.4345
RC|55.7963|44.2037
RH|51.1961|48.8039
RL|51.3625|48.6375
RR|51.7178|48.2822
RU|47.9368|52.0632
UC|59.0546|40.9454
UH|54.7955|45.2045
UL|54.3489|45.6511
UR|54.8951|45.1049
UU|51.2759|48.7241

What to do as any player:

 * Play cards that are uncommon in hands; 
   that combine with as much cards on the table and in hand possible

You'll win in 53.5% when playing against random opponents.

### Three player matches

Matchup|First player wins|Second player wins|Third player wins
---|---|---|---
CCC|36.0261|33.2597|30.7142
CCH|32.8364|31.8685|35.2951
CCL|32.4443|31.9091|35.6466
CCR|32.6441|31.8137|35.5422
CCU|29.4477|30.6711|39.8812
CHC|34.2645|38.0588|27.6767
CHH|31.9984|36.7385|31.2631
CHL|30.9933|36.7926|32.2141
CHR|31.4431|36.7373|31.8196
CHU|28.6393|35.4394|35.9213
CLC|34.3951|38.2088|27.3961
CLH|31.4388|36.5054|32.0558
CLL|31.3536|36.8836|31.7628
CLR|31.3876|36.6932|31.9192
CLU|28.7941|35.5536|35.6523
CRC|34.2987|38.1554|27.5459
CRH|31.6129|36.6275|31.7596
CRL|31.1138|36.8168|32.0694
CRR|31.4501|36.7911|31.7588
CRU|28.7178|35.4639|35.8183
CUC|32.8746|42.4646|24.6608
CUH|30.6379|40.9475|28.4146
CUL|30.1765|40.9804|28.8431
CUR|30.3015|40.9877|28.7108
CUU|28.1223|39.6205|32.2572
HCC|40.8603|30.1122|29.0275
HCH|36.3221|29.6462|34.0317
HCL|37.5637|28.9742|33.4621
HCR|36.8951|29.339|33.7659
HCU|33.5026|28.4197|38.0777
HHC|39.2146|33.9084|26.877
HHH|35.5635|33.5005|30.936
HHL|36.3067|32.6865|31.0068
HHR|35.9701|33.0335|30.9964
HHU|32.8687|31.9921|35.1392
HLC|39.1486|34.7647|26.0867
HLH|34.8596|34.082|31.0584
HLL|36.4399|33.6172|29.9429
HLR|35.6433|33.8675|30.4892
HLU|32.7842|32.9874|34.2284
HRC|39.1662|34.3475|26.4863
HRH|35.1794|33.808|31.0126
HRL|36.3725|33.1318|30.4957
HRR|35.7508|33.4775|30.7717
HRU|32.7469|32.6|34.6531
HUC|37.6029|38.5165|23.8806
HUH|33.8799|38.0051|28.115
HUL|35.2542|37.1024|27.6434
HUR|34.6682|37.4935|27.8383
HUU|32.0409|36.4784|31.4807
LCC|40.9774|29.8354|29.1872
LCH|37.6052|28.7158|33.679
LCL|36.5949|29.1503|34.2548
LCR|37.1313|28.9123|33.9564
LCU|33.5589|28.1775|38.2636
LHC|38.8833|34.7431|26.3736
LHH|36.4179|33.6696|29.9125
LHL|34.8488|34.0622|31.089
LHR|35.6621|33.8707|30.4672
LHU|32.4332|33.0377|34.5291
LLC|39.3869|34.1569|26.4562
LLH|36.3429|32.6789|30.9782
LLL|35.5815|33.4901|30.9284
LLR|35.9672|33.0623|30.9705
LLU|32.9812|32.3475|34.6713
LRC|39.1492|34.4296|26.4212
LRH|36.3222|33.1355|30.5423
LRL|35.1734|33.7424|31.0842
LRR|35.7899|33.4253|30.7848
LRU|32.7065|32.6626|34.6309
LUC|37.7528|38.1333|24.1139
LUH|35.3871|36.8137|27.7992
LUL|34.3064|37.317|28.3766
LUR|34.8154|37.0949|28.0897
LUU|32.2194|36.1552|31.6254
RCC|40.9012|30.0293|29.0695
RCH|36.9534|29.2444|33.8022
RCL|37.0657|29.0686|33.8657
RCR|37.0027|29.1799|33.8174
RCU|33.5724|28.3471|38.0805
RHC|39.0922|34.263|26.6448
RHH|35.9383|33.6597|30.402
RHL|35.6534|33.2995|31.0471
RHR|35.7803|33.4608|30.7589
RHU|32.7453|32.4674|34.7873
RLC|39.3024|34.4574|26.2402
RLH|35.5672|33.371|31.0618
RLL|36.0668|33.5381|30.3951
RLR|35.7916|33.5139|30.6945
RLU|32.8559|32.6996|34.4445
RRC|39.1564|34.3302|26.5134
RRH|35.8205|33.5193|30.6602
RRL|35.7225|33.4736|30.8039
RRR|35.8241|33.4079|30.768
RRU|32.7392|32.589|34.6718
RUC|37.7455|38.2785|23.976
RUH|34.6193|37.4445|27.9362
RUL|34.7556|37.2227|28.0217
RUR|34.7961|37.2843|27.9196
RUU|32.1211|36.3636|31.5153
UCC|45.2052|27.057|27.7378
UCH|41.1544|26.4949|32.3507
UCL|40.7082|26.6477|32.6441
UCR|40.9693|26.5195|32.5112
UCU|37.0823|26.1674|36.7503
UHC|43.403|30.9908|25.6062
UHH|40.1901|30.6534|29.1565
UHL|39.2183|30.5181|30.2636
UHR|39.7204|30.6035|29.6761
UHU|36.1565|30.065|33.7785
ULC|43.3867|31.2108|25.4025
ULH|39.6359|30.3919|29.9722
ULL|39.5362|30.8464|29.6174
ULR|39.6294|30.5964|29.7742
ULU|36.3511|30.2223|33.4266
URC|43.4044|31.0636|25.532
URH|39.8151|30.5703|29.6146
URL|39.3174|30.7133|29.9693
URR|39.7026|30.5399|29.7575
URU|36.2245|30.1164|33.6591
UUC|41.8722|34.6776|23.4502
UUH|38.6822|34.0579|27.2599
UUL|38.3081|34.1573|27.5346
UUR|38.5243|34.0945|27.3812
UUU|35.5598|33.5405|30.8997

What to do as a first player:
 * Play cards that are uncommon in hands; 
   that combine with as much cards on the table and in hand possible

## Four players

Matchup|1 wins|2 wins|3 wins|4 wins
---|---|---|---|---
.|.|.|.|.


For player 1:
 * Play cards that are uncommon in hands; 
   that combine with as much cards on the table and in hand possible

It does not matter how the others team up, player 1 will always win,
no matter which strategy.



