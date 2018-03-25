# Familie Poen

Branch|[![Travis CI logo](TravisCI.png)](https://travis-ci.org)|[![Codecov logo](Codecov.png)](https://www.codecov.io)
---|---|---
master|[![Build Status](https://travis-ci.org/richelbilderbeek/familie_poen.svg?branch=master)](https://travis-ci.org/richelbilderbeek/familie_poen) | [![codecov.io](https://codecov.io/github/richelbilderbeek/familie_poen/coverage.svg?branch=master)](https://codecov.io/github/richelbilderbeek/familie_poen?branch=master)
develop|[![Build Status](https://travis-ci.org/richelbilderbeek/familie_poen.svg?branch=develop)](https://travis-ci.org/richelbilderbeek/familie_poen) | [![codecov.io](https://codecov.io/github/richelbilderbeek/familie_poen/coverage.svg?branch=develop)](https://codecov.io/github/richelbilderbeek/familie_poen?branch=develop)

Card game.

![Cards](Cards.jpg)

 * Cards have values 1,2,5,10,20,50
 * Each card has 6 colors
 * Initial coins: 1 x 50, 1 x 20, 2 x 10, 2 x 5, 4 x 2, 4 x 1 = 112

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

```
Player 1 playing L won 508434 times
Player 2 playing L won 491566 times
```

```
Player 1 playing L won 511433 times
Player 2 playing H won 488567 times
```

```
Player 1 playing H won 511206 times
Player 2 playing L won 488794 times
```

```
Player 1 playing H won 508699 times
Player 2 playing H won 491301 times
```

