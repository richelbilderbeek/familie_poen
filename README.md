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

Always play the card with the highest value. The first player has an advantage
of three percent in a three player game 
and an advantage of four percent in a four player game.

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
CC|50.6391|49.3609
CH|23.6371|76.3629
CL|49.9098|50.0902
CR|37.9831|62.0169
CU|32.8634|67.1366
HC|77.4228|22.5772
HH|50.3997|49.6003
HL|76.2829|23.7171
HR|67.1588|32.8412
HU|60.9868|39.0132
LC|51.2968|48.7032
LH|24.6793|75.3207
LL|50.6148|49.3852
LR|38.7692|61.2308
LU|34.2591|65.7409
RC|63.2623|36.7377
RH|33.8978|66.1022
RL|62.3904|37.6096
RR|50.549|49.451
RU|44.8317|55.1683
UC|68.1829|31.8171
UH|39.936|60.064
UL|66.635|33.365
UR|56.0348|43.9652
UU|50.4096|49.5904

What to do as any player:

 * Play H
 * Being the first to start is a small advantage

To counteract this:

 * Play H

### Three player matches

Matchup|First player wins|Second player wins|Third player wins
---|---|---|---
CCC|34.4492|33.2808|32.27
CCH|25.3361|25.6044|49.0595
CCL|31.4648|34.4951|34.0401
CCR|28.6638|30.2812|41.055
CCU|24.7759|29.6436|45.5805
CHC|26.2673|50.3892|23.3435
CHH|18.3279|43.8775|37.7946
CHL|24.1805|50.7361|25.0834
CHR|21.4915|47.6835|30.825
CHU|18.4269|46.31|35.2631
CLC|35.6396|35.2293|29.1311
CLH|27.2958|27.4773|45.2269
CLL|33.1741|36.3076|30.5183
CLR|30.5994|32.2385|37.1621
CLU|27.3718|31.7951|40.8331
CRC|31.0493|42.4056|26.5451
CRH|23.0349|34.8737|42.0914
CRL|28.8282|43.0578|28.114
CRR|26.1783|39.4579|34.3638
CRU|22.9316|38.5447|38.5237
CUC|30.4199|46.8214|22.7587
CUH|22.9775|40.2345|36.788
CUL|28.5699|47.0809|24.3492
CUR|26.1103|44.0717|29.818
CUU|23.4212|43.0184|33.5604
HCC|51.4725|24.206|24.3215
HCH|39.9445|17.7507|42.3048
HCL|47.8117|26.0105|26.1778
HCR|44.542|22.1286|33.3294
HCU|39.0472|22.1262|38.8266
HHC|44.4144|38.7137|16.8719
HHH|34.2441|33.4223|32.3336
HHL|41.3485|40.162|18.4895
HHR|38.355|37.3702|24.2748
HHU|33.3821|37.0379|29.58
HLC|51.713|25.9647|22.3223
HLH|41.428|19.5177|39.0543
HLL|48.6696|27.7772|23.5532
HLR|45.6514|24.0122|30.3364
HLU|41.2845|24.0788|34.6367
HRC|48.5265|31.6887|19.7848
HRH|38.2517|25.4467|36.3016
HRL|45.3545|33.4155|21.23
HRR|42.429|29.8776|27.6934
HRU|37.7808|29.8333|32.3859
HUC|47.1355|36.0404|16.8241
HUH|37.9182|30.6504|31.4314
HUL|44.5839|37.2742|18.1419
HUR|41.7455|34.5017|23.7528
HUU|37.901|34.2708|27.8282
LCC|36.3756|30.3395|33.2849
LCH|27.1732|23.5927|49.2341
LCL|32.725|32.1939|35.0811
LCR|30.1975|28.0174|41.7851
LCU|26.2753|27.874|45.8507
LHC|28.211|46.6882|25.1008
LHH|20.3122|40.5382|39.1496
LHL|25.4269|47.7071|26.866
LHR|23.0688|44.5334|32.3978
LHU|19.7293|43.8492|36.4215
LLC|37.5697|31.6126|30.8177
LLH|29.138|24.8198|46.0422
LLL|34.4549|33.386|32.1591
LLR|32.1333|29.2876|38.5791
LLU|28.8713|29.3016|41.8271
LRC|33.2011|38.5177|28.2812
LRH|24.9867|31.6797|43.3336
LRL|30.2133|39.9407|29.846
LRR|27.8905|36.1504|35.9591
LRU|24.5917|35.8169|39.5914
LUC|32.6791|42.0931|25.2278
LUH|25.0809|36.0308|38.8883
LUL|30.1081|43.1367|26.7552
LUR|27.9281|39.8832|32.1887
LUU|25.0433|39.3597|35.597
RCC|43.4404|27.5982|28.9614
RCH|33.0062|20.8218|46.172
RCL|39.6617|29.5066|30.8317
RCR|36.6912|25.3128|37.996
RCU|32.0415|25.2285|42.73
RHC|35.6193|43.35|21.0307
RHH|26.2169|37.5696|36.2135
RHL|32.4954|44.561|22.9436
RHR|29.6227|41.6143|28.763
RHU|25.4888|41.0116|33.4996
RLC|44.2005|29.0915|26.708
RLH|34.8029|22.3451|42.852
RLL|41.1169|30.8993|27.9838
RLR|38.3235|26.9044|34.7721
RLU|34.5119|27.0049|38.4832
RRC|40.4075|35.4839|24.1086
RRH|30.7562|28.9788|40.265
RRL|37.1167|37.144|25.7393
RRR|34.3751|33.3983|32.2266
RRU|30.3463|33.2261|36.4276
RUC|39.3131|39.5222|21.1647
RUH|30.7309|33.635|35.6341
RUL|36.6846|40.6858|22.6296
RUR|34.1904|37.6421|28.1675
RUU|30.6833|37.2127|32.104
UCC|47.9608|23.8405|28.1987
UCH|37.396|17.7885|44.8155
UCL|43.138|26.413|30.449
UCR|40.7829|22.1528|37.0643
UCU|35.6697|22.7055|41.6248
UHC|40.9855|37.94|21.0745
UHH|31.4555|32.634|35.9105
UHL|36.7676|40.1788|23.0536
UHR|34.5163|36.8735|28.6102
UHU|29.7019|37.1284|33.1697
ULC|48.2453|25.2556|26.4991
ULH|38.697|19.1683|42.1347
ULL|44.1544|27.8445|28.0011
ULR|41.9049|23.7092|34.3859
ULU|37.7371|24.2603|38.0026
URC|45.0003|30.8951|24.1046
URH|35.5418|24.8029|39.6553
URL|40.7931|33.3333|25.8736
URR|38.5588|29.4472|31.994
URU|34.1227|29.8457|36.0316
UUC|43.9225|34.5326|21.5449
UUH|35.2693|28.8946|35.8361
UUL|40.2277|36.6498|23.1225
UUR|38.1717|33.1758|28.6525
UUU|34.2422|33.4814|32.2764

What to do as any player:

 * Play H
 * Being the first to start is a small advantage

To counteract this:

 * Play H

## Four players

Matchup|1 wins|2 wins|3 wins|4 wins
---|---|---|---|---
CCCC|26.3669|25.4972|24.5339|23.602
CCCH|21.3477|21.6315|21.4213|35.5995
CCCL|23.6194|25.5732|25.3368|25.4706
CCCR|22.601|23.5119|23.3726|30.5145
CCCU|19.4953|22.7624|23.2021|34.5402
CCHC|22.3654|22.1242|36.5717|18.9387
CCHH|18.1073|18.8682|34.3671|28.6574
CCHL|20.0197|22.3248|36.8634|20.7921
CCHR|19.0613|20.627|35.7113|24.6004
CCHU|16.4135|19.8518|35.2319|28.5028
CCLC|26.3673|26.3154|26.2737|21.0436
CCLH|21.8317|22.7569|23.2334|32.178
CCLL|23.9933|26.5238|27.3524|22.1305
CCLR|22.9855|24.7257|25.3786|26.9102
CCLU|20.361|24.063|25.3926|30.1834
CCRC|24.3188|24.2384|31.3436|20.0992
CCRH|19.9308|20.8484|28.6391|30.5817
CCRL|21.9358|24.4303|32.0991|21.5348
CCRR|21.037|22.6749|30.4629|25.8252
CCRU|18.3404|22.0123|30.252|29.3953
CCUC|23.4009|23.9414|35.4167|17.241
CCUH|19.3599|20.8051|33.4034|26.4316
CCUL|21.3132|24.2052|36.0731|18.4085
CCUR|20.4401|22.5577|34.807|22.1952
CCUU|18.1565|22.0796|34.563|25.2009
CHCC|22.8776|37.6823|19.6257|19.8144
CHCH|18.2022|33.5399|16.8626|31.3953
CHCL|20.4824|37.4048|20.6079|21.5049
CHCR|19.4656|35.4225|18.8107|26.3012
CHCU|16.6526|34.0535|18.7098|30.5841
CHHC|19.3671|35.3192|29.3026|16.0111
CHHH|15.0808|31.8197|27.443|25.6565
CHHL|17.3642|34.9732|29.9896|17.673
CHHR|16.3102|33.3717|28.751|21.5671
CHHU|13.8057|32.1515|28.5325|25.5103
CHLC|23.0239|37.8789|21.4266|17.6706
CHLH|18.7271|34.1652|18.7413|28.3664
CHLL|20.9909|37.766|22.5834|18.6597
CHLR|19.938|36.0717|20.7188|23.2715
CHLU|17.5539|35.0539|20.7831|26.6091
CHRC|21.1068|36.6045|25.3952|16.8935
CHRH|16.9379|33.0917|22.8324|27.138
CHRL|19.2201|36.4239|26.2386|18.1174
CHRR|18.0089|34.968|24.5738|22.4493
CHRU|15.6024|33.6939|24.5658|26.1379
CHUC|20.2758|36.0789|29.2794|14.3659
CHUH|16.4426|32.8106|27.3636|23.3832
CHUL|18.6396|35.9243|29.9135|15.5226
CHUR|17.5843|34.5652|28.6859|19.1646
CHUU|15.4586|33.6139|28.5886|22.3389
CLCC|27.1589|27.397|21.8064|23.6377
CLCH|22.3267|23.6692|19.2144|34.7897
CLCL|24.4983|27.4189|22.8257|25.2571
CLCR|23.4685|25.5955|20.9733|29.9627
CLCU|20.6419|24.5903|21.0048|33.763
CLHC|23.4627|24.1513|33.1438|19.2422
CLHH|19.3681|20.8271|31.1722|28.6326
CLHL|21.1039|24.2095|33.6636|21.023
CLHR|20.2778|22.4818|32.4762|24.7642
CLHU|17.7441|21.7408|32.2909|28.2242
CLLC|27.3024|28.36|23.0162|21.3214
CLLH|22.8821|24.8291|20.4026|31.8862
CLLL|25.0056|28.5524|24.0752|22.3668
CLLR|24.0356|26.7627|22.2285|26.9732
CLLU|21.5749|26.1349|22.3601|29.9301
CLRC|25.36|26.3369|27.8448|20.4583
CLRH|21.1688|22.8554|25.5388|30.437
CLRL|23.157|26.43|28.6534|21.7596
CLRR|22.1721|24.6564|27.2233|25.9482
CLRU|19.6987|24.0029|27.1202|29.1782
CLUC|24.7171|26.3241|30.9106|18.0482
CLUH|20.7869|22.9909|29.2266|26.9956
CLUL|22.7782|26.3873|31.6542|19.1803
CLUR|21.7537|24.7849|30.53|22.9314
CLUU|19.573|24.2268|30.412|25.7882
CRCC|24.9466|32.5472|20.7796|21.7266
CRCH|20.2593|28.4574|18.0565|33.2268
CRCL|22.4438|32.2908|21.808|23.4574
CRCR|21.4105|30.4203|20.0152|28.154
CRCU|18.7008|29.2553|19.8666|32.1773
CRHC|21.3595|29.5377|31.45|17.6528
CRHH|17.2849|26.0593|29.4758|27.18
CRHL|19.2152|29.4367|31.9746|19.3735
CRHR|18.2556|27.7563|30.8415|23.1466
CRHU|15.7307|26.7787|30.5249|26.9657
CRLC|25.1556|33.1369|22.2164|19.4911
CRLH|20.8077|29.4056|19.484|30.3027
CRLL|23.0052|33.1847|23.2785|20.5316
CRLR|21.9633|31.4457|21.4474|25.1436
CRLU|19.6043|30.4748|21.6667|28.2542
CRRC|23.2251|31.3972|26.7641|18.6136
CRRH|19.0469|27.8702|24.2302|28.8527
CRRL|21.0916|31.3708|27.6003|19.9373
CRRR|20.1594|29.6261|25.9431|24.2714
CRRU|17.683|28.6677|25.974|27.6753
CRUC|22.5331|31.0753|30.1856|16.206
CRUH|18.6623|27.7415|28.3324|25.2638
CRUL|20.7588|31.036|30.855|17.3502
CRUR|19.6573|29.5925|29.6389|21.1113
CRUU|17.5471|28.8241|29.5568|24.072
CUCC|24.6121|36.7501|17.898|20.7398
CUCH|20.0282|32.9958|15.4594|31.5166
CUCL|22.3361|36.1587|19.0221|22.4831
CUCR|21.2773|34.6374|17.1631|26.9222
CUCU|18.7376|33.177|17.4268|30.6586
CUHC|21.3533|34.3852|27.2202|17.0413
CUHH|17.2823|31.2873|25.3285|26.1019
CUHL|19.3125|33.7913|28.1275|18.7687
CUHR|18.3314|32.5239|26.7785|22.3662
CUHU|15.9829|31.2326|26.8156|25.9689
CULC|24.9327|37.1261|19.0745|18.8667
CULH|20.6544|33.7262|16.564|29.0554
CULL|22.9254|36.8004|20.3297|19.9445
CULR|21.936|35.2959|18.4703|24.2978
CULU|19.6442|34.2293|18.7956|27.3309
CURC|23.1678|35.85|22.8704|18.1118
CURH|19.0113|32.5159|20.6832|27.7896
CURL|21.1484|35.3125|24.1049|19.4342
CURR|20.0842|34.0175|22.4395|23.4588
CURU|17.8795|32.7779|22.65|26.6926
CUUC|22.636|35.5023|25.887|15.9747
CUUH|18.7593|32.501|24.0415|24.6982
CUUL|20.8978|35.1452|26.8061|17.1509
CUUR|19.9496|33.8034|25.5752|20.6718
CUUU|17.8086|32.9149|25.662|23.6145
HCCC|38.6499|20.4199|20.5555|20.3747
HCCH|31.3389|17.4751|18.0611|33.1249
HCCL|35.3866|20.7752|21.7003|22.1379
HCCR|33.49|19.1751|19.881|27.4539
HCCU|29.2864|18.6169|19.9914|32.1053
HCHC|34.3836|17.417|32.1621|16.0373
HCHH|27.9627|14.6147|30.9353|26.4873
HCHL|31.3857|17.9231|32.8558|17.8354
HCHR|29.7807|16.2582|31.9813|21.9798
HCHU|25.936|15.8417|31.863|26.3593
HCLC|38.1123|21.3871|22.3038|18.1968
HCLH|31.5925|18.6019|19.8199|29.9857
HCLL|35.291|21.8323|23.5692|19.3075
HCLR|33.5772|20.3037|21.771|24.3481
HCLU|29.8916|19.991|22.0822|28.0352
HCRC|36.363|19.3116|27.0862|17.2392
HCRH|29.8875|16.6218|25.0847|28.406
HCRL|33.3679|19.9192|28.0736|18.6393
HCRR|31.7389|18.2912|26.6829|23.287
HCRU|28.006|17.9296|26.861|27.2034
HCUC|34.7013|19.253|31.4481|14.5976
HCUH|28.8299|16.6904|30.1236|24.3561
HCUL|32.22|19.8201|32.1843|15.7756
HCUR|30.6695|18.3436|31.2361|19.7508
HCUU|27.4398|18.0715|31.4049|23.0838
HHCC|35.9829|30.259|16.5318|17.2263
HHCH|28.8413|27.2625|14.0273|29.8689
HHCL|32.9918|30.3655|17.7102|18.9325
HHCR|31.106|28.9273|15.9173|24.0494
HHCU|26.9634|27.9844|16.0787|28.9735
HHHC|32.4059|28.0234|26.2397|13.331
HHHH|26.0873|25.421|24.6932|23.7985
HHHL|29.5709|28.2821|27.1083|15.0387
HHHR|27.9294|26.9205|26.0239|19.1262
HHHU|23.9175|26.1576|26.0488|23.8761
HHLC|35.6944|30.7434|18.2707|15.2915
HHLH|29.1185|28.1743|15.8508|26.8564
HHLL|33.0155|30.9808|19.5715|16.4322
HHLR|31.3299|29.6388|17.8|21.2313
HHLU|27.6897|29.0946|18.0933|25.1224
HHRC|34.0677|29.4388|22.1034|14.3901
HHRH|27.707|26.8506|19.9215|25.5209
HHRL|31.2528|29.7491|23.2662|15.7319
HHRR|29.5605|28.4102|21.7423|20.287
HHRU|25.8319|27.7338|21.9194|24.5149
HHUC|32.6616|29.0691|26.2251|12.0442
HHUH|26.7236|26.7311|24.7377|21.8076
HHUL|30.2425|29.3988|27.1822|13.1765
HHUR|28.6577|28.2323|26.1238|16.9862
HHUU|25.3753|27.7827|26.2718|20.5702
HLCC|38.9607|22.2707|18.3174|20.4512
HLCH|31.9395|19.3866|16.1632|32.5107
HLCL|35.918|22.6381|19.35|22.0939
HLCR|34.0543|20.9982|17.8694|27.0781
HLCU|30.1121|20.5785|17.9053|31.4041
HLHC|34.9625|19.3546|29.2176|16.4653
HLHH|28.8911|16.6295|27.9547|26.5247
HLHL|32.1197|19.7715|29.9206|18.1882
HLHR|30.6394|18.1564|29.0406|22.1636
HLHU|27.0017|17.7994|29.0294|26.1695
HLLC|38.6651|23.3554|19.4172|18.5623
HLLH|32.1377|20.6434|17.3045|29.9144
HLLL|36.028|23.8067|20.529|19.6363
HLLR|34.2271|22.335|19.0305|24.4074
HLLU|30.7915|22.0425|19.2989|27.8671
HLRC|36.9778|21.362|24.012|17.6482
HLRH|30.6743|18.5879|22.2514|28.4864
HLRL|34.2022|21.8689|24.9578|18.9711
HLRR|32.5335|20.2894|23.6918|23.4853
HLRU|28.9855|20.0068|23.8483|27.1594
HLUC|35.7347|21.4432|27.3951|15.427
HLUH|29.9632|18.8807|26.2114|24.9447
HLUL|33.2791|21.8967|28.2177|16.6065
HLUR|31.7901|20.4857|27.1536|20.5706
HLUU|28.6485|20.2427|27.4087|23.7001
HRCC|37.5972|26.2132|17.4253|18.7643
HRCH|30.446|23.2037|15.0897|31.2606
HRCL|34.4976|26.478|18.5764|20.448
HRCR|32.6958|24.834|16.9128|25.5574
HRCU|28.5682|24.2567|17.0137|30.1614
HRHC|33.7305|23.5497|27.7822|14.9376
HRHH|27.5835|20.6056|26.525|25.2859
HRHL|30.8917|23.9172|28.6231|16.568
HRHR|29.3781|22.3332|27.5696|20.7191
HRHU|25.5351|21.7672|27.6968|25.0009
HRLC|37.2214|27.1304|18.7543|16.8939
HRLH|30.6816|24.3377|16.6316|28.3491
HRLL|34.558|27.3457|20.1014|17.9949
HRLR|32.8407|25.9663|18.4068|22.7862
HRLU|29.2756|25.566|18.6833|26.4751
HRRC|35.6537|25.3394|23.0273|15.9796
HRRH|29.2142|22.6407|21.1499|26.9952
HRRL|32.8093|25.7798|24.1167|17.2942
HRRR|31.2118|24.2411|22.7396|21.8075
HRRU|27.4299|23.7548|22.945|25.8703
HRUC|34.2361|25.2514|26.8707|13.6418
HRUH|28.4175|22.6266|25.515|23.4409
HRUL|31.8868|25.621|27.6631|14.8291
HRUR|30.2957|24.2023|26.6955|18.8065
HRUU|27.0827|23.9059|26.8722|22.1392
HUCC|36.939|30.0878|14.9504|18.0228
HUCH|29.9991|27.4606|12.7559|29.7844
HUCL|34.1017|30.0654|16.104|19.7289
HUCR|32.2469|28.8484|14.48|24.4247
HUCU|28.3715|28.0622|14.7362|28.8301
HUHC|33.4686|28.0641|23.9979|14.4694
HUHH|27.4182|25.6529|22.5397|24.3892
HUHL|30.7374|28.034|25.1278|16.1008
HUHR|29.1939|26.8333|23.9152|20.0576
HUHU|25.5891|26.0715|24.0903|24.2491
HULC|36.6914|30.7925|16.1151|16.401
HULH|30.3649|28.3753|13.8837|27.3761
HULL|34.2698|30.8312|17.4407|17.4583
HULR|32.5166|29.6705|15.6798|22.1331
HULU|29.2397|29.1645|16.0822|25.5136
HURC|35.145|29.5936|19.785|15.4764
HURH|29.0218|27.0983|17.8582|26.0217
HURL|32.5868|29.5081|20.9929|16.9122
HURR|30.9332|28.4686|19.485|21.1132
HURU|27.5277|27.6856|19.7926|24.9941
HUUC|34.2396|29.2971|22.8778|13.5855
HUUH|28.4995|27.2039|21.4387|22.8579
HUUL|31.8902|29.3222|24.0883|14.6993
HUUR|30.319|28.4095|22.7991|18.4724
HUUU|27.3199|27.8673|23.1054|21.7074
LCCC|28.3086|22.7741|24.5284|24.3889
LCCH|23.4072|19.3203|21.5965|35.676
LCCL|24.7851|23.3266|25.5844|26.3039
LCCR|24.1332|21.1724|23.6427|31.0517
LCCU|20.8319|20.7547|23.5695|34.8439
LCHC|24.2463|19.8651|35.9872|19.9014
LCHH|20.1458|16.9315|33.9104|29.0123
LCHL|21.1714|20.4345|36.5684|21.8257
LCHR|20.6745|18.6016|35.3208|25.4031
LCHU|17.7487|18.1422|34.9729|29.1362
LCLC|28.2414|23.6264|26.2299|21.9023
LCLH|23.7384|20.4408|23.2453|32.5755
LCLL|25.1135|24.2257|27.549|23.1118
LCLR|24.4849|22.3937|25.4389|27.6825
LCLU|21.68|22.0896|25.5664|30.664
LCRC|26.2507|21.7838|31.0607|20.9048
LCRH|21.9838|18.5674|28.4495|30.9993
LCRL|23.1201|22.3584|32.1241|22.3974
LCRR|22.5473|20.5465|30.2428|26.6634
LCRU|19.6378|20.1839|30.2219|29.9564
LCUC|25.337|21.6515|34.765|18.2465
LCUH|21.3923|18.748|32.716|27.1437
LCUL|22.637|22.2505|35.5204|19.5921
LCUR|22.036|20.5537|34.1755|23.2348
LCUU|19.5739|20.2572|34.0986|26.0703
LHCC|24.8392|34.3547|20.0315|20.7746
LHCH|20.173|30.5001|17.3061|32.0208
LHCL|21.8387|34.4448|21.1777|22.5388
LHCR|21.0275|32.6304|19.1738|27.1683
LHCU|17.9115|31.5657|19.2667|31.2561
LHHC|21.3554|32.1663|29.4095|17.0688
LHHH|17.0975|28.9851|27.4559|26.4615
LHHL|18.6471|32.3192|30.1282|18.9055
LHHR|17.8576|30.7047|28.8888|22.5489
LHHU|15.0408|29.6984|28.7593|26.5015
LHLC|24.8393|34.7715|21.763|18.6262
LHLH|20.665|31.1712|19.0913|29.0725
LHLL|22.1892|35.1157|22.9889|19.7062
LHLR|21.4712|33.2719|21.0429|24.214
LHLU|18.8046|32.5867|21.2464|27.3623
LHRC|23.0757|33.5641|25.4964|17.8638
LHRH|18.8807|30.1917|23.0897|27.8379
LHRL|20.3623|33.8414|26.5628|19.2335
LHRR|19.6387|31.9746|24.9529|23.4338
LHRU|16.9302|31.2309|24.9643|26.8746
LHUC|22.3088|33.0695|29.1443|15.4774
LHUH|18.3609|30.0081|27.2351|24.3959
LHUL|19.875|33.4551|29.9881|16.6818
LHUR|19.2184|31.8667|28.6174|20.2975
LHUU|16.7921|31.2441|28.6835|23.2803
LLCC|29.3335|24.0291|22.2783|24.3591
LLCH|24.5317|20.6209|19.6846|35.1628
LLCL|25.8592|24.3853|23.4149|26.3406
LLCR|25.1788|22.4279|21.574|30.8193
LLCU|22.1243|21.9815|21.6316|34.2626
LLHC|25.5258|21.0679|33.1482|20.2581
LLHH|21.4941|18.1531|31.1884|29.1644
LLHL|22.3893|21.585|33.9182|22.1075
LLHR|21.953|19.7747|32.6307|25.6416
LLHU|19.1443|19.3752|32.4739|29.0066
LLLC|29.4121|24.9375|23.3302|22.3202
LLLH|24.9855|21.7716|20.6915|32.5514
LLLL|26.3256|25.4853|24.6209|23.5682
LLLR|25.7481|23.6649|22.6046|27.9824
LLLU|23.0634|23.3665|22.9007|30.6694
LLRC|27.4969|23.063|28.0798|21.3603
LLRH|23.3496|19.9628|25.5867|31.1009
LLRL|24.4862|23.537|29.0934|22.8834
LLRR|23.9211|21.7948|27.4647|26.8194
LLRU|21.0476|21.4395|27.494|30.0189
LLUC|26.7847|23.1524|30.8886|19.1743
LLUH|22.9526|20.1921|28.9961|27.8592
LLUL|24.0315|23.6386|31.8883|20.4416
LLUR|23.604|21.934|30.5189|23.9431
LLUU|21.1786|21.6685|30.5655|26.5874
LRCC|27.16|28.8964|21.1904|22.7532
LRCH|22.4063|25.2638|18.5653|33.7646
LRCL|23.8483|29.2224|22.4003|24.529
LRCR|23.1307|27.3071|20.44|29.1222
LRCU|20.0473|26.575|20.5773|32.8004
LRHC|23.395|26.3069|31.4975|18.8006
LRHH|19.3315|23.1526|29.5493|27.9666
LRHL|20.5328|26.592|32.2354|20.6398
LRHR|19.9686|24.8642|30.9686|24.1986
LRHU|17.1325|24.1505|30.8941|27.8229
LRLC|27.1415|29.7696|22.5097|20.5792
LRLH|22.8044|26.2737|19.9288|30.9931
LRLL|24.2238|30.2937|23.8451|21.6374
LRLR|23.6029|28.3524|21.9517|26.093
LRLU|21.0126|27.8266|22.1341|29.0267
LRRC|25.3315|28.0929|26.8823|19.6933
LRRH|21.1177|24.731|24.5312|29.6201
LRRL|22.3953|28.538|27.8602|21.2065
LRRR|21.8351|26.6831|26.3179|25.1639
LRRU|19.0258|26.11|26.3825|28.4817
LRUC|24.6281|27.8793|30.0641|17.4285
LRUH|20.675|24.8172|28.2058|26.302
LRUL|21.997|28.3976|30.9956|18.6098
LRUR|21.4619|26.6553|29.6616|22.2212
LRUU|19.035|26.2186|29.6986|25.0478
LUCC|26.9646|32.2607|18.7731|22.0016
LUCH|22.376|28.8413|16.2743|32.5084
LUCL|23.8042|32.2371|20.0793|23.8794
LUCR|23.1665|30.5907|18.2167|28.0261
LUCU|20.2425|29.6737|18.4486|31.6352
LUHC|23.6158|30.1681|27.8743|18.3418
LUHH|19.5424|27.1601|26.079|27.2185
LUHL|20.7115|30.0843|28.9679|20.2363
LUHR|20.1116|28.6876|27.5226|23.6782
LUHU|17.4734|27.6945|27.6012|27.2309
LULC|27.0392|32.9164|19.9133|20.1311
LULH|22.8662|29.5564|17.4396|30.1378
LULL|24.2638|33.0838|21.3719|21.2805
LULR|23.6082|31.4081|19.453|25.5307
LULU|21.0836|30.8183|19.7012|28.3969
LURC|25.3342|31.5997|23.7463|19.3198
LURH|21.3531|28.4253|21.4402|28.7814
LURL|22.5709|31.5829|25.004|20.8422
LURR|21.9751|30.003|23.3365|24.6854
LURU|19.3151|29.3299|23.5246|27.8304
LUUC|24.8177|31.29|26.584|17.3083
LUUH|21.0711|28.4262|24.6426|25.8601
LUUL|22.2486|31.4385|27.7276|18.5853
LUUR|21.6906|29.9709|26.2761|22.0624
LUUU|19.3573|29.3899|26.404|24.8488
RCCC|33.5469|21.5721|22.5386|22.3424
RCCH|27.3901|18.4746|19.7366|34.3987
RCCL|29.9315|22.0934|23.7442|24.2309
RCCR|28.7006|20.2648|21.7399|29.2947
RCCU|24.8193|19.7595|21.8423|33.5789
RCHC|29.2115|18.6937|34.1437|17.9511
RCHH|23.9709|15.7966|32.4827|27.7498
RCHL|26.0255|19.2266|34.9195|19.8284
RCHR|25.0267|17.4671|33.7887|23.7175
RCHU|21.5941|17.0138|33.5879|27.8042
RCLC|33.1985|22.5348|24.2009|20.0658
RCLH|27.6228|19.4619|21.5416|31.3737
RCLL|30.0079|23.1483|25.5696|21.2742
RCLR|29.1023|21.3099|23.5786|26.0092
RCLU|25.6685|21.0589|23.8816|29.391
RCRC|31.2445|20.6355|29.0987|19.0213
RCRH|25.818|17.7079|26.7361|29.738
RCRL|28.0517|21.2431|30.1147|20.5905
RCRR|26.9879|19.508|28.5469|24.9572
RCRU|23.5898|19.0685|28.6315|28.7102
RCUC|29.8564|20.51|33.1584|16.4752
RCUH|25.057|17.825|31.3557|25.7623
RCUL|27.2293|21.1619|33.9574|17.6514
RCUR|26.1214|19.54|32.8021|21.5365
RCUU|23.2283|19.3399|32.8048|24.627
RHCC|30.3463|32.4105|18.2513|18.9919
RHCH|24.4523|28.9188|15.652|30.9769
RHCL|27.1349|32.6108|19.4268|20.8275
RHCR|25.8323|30.8947|17.6419|25.6311
RHCU|22.1394|30.0297|17.6994|30.1315
RHHC|26.6248|30.1792|27.9731|15.2229
RHHH|21.2741|27.3014|26.1812|25.2433
RHHL|23.6912|30.5295|28.7209|17.0584
RHHR|22.5944|28.9546|27.5291|20.9219
RHHU|19.1661|28.1663|27.4305|25.2371
RHLC|30.1616|32.8789|20.0203|16.9392
RHLH|24.747|29.7136|17.4314|28.108
RHLL|27.2854|33.2893|21.3319|18.0934
RHLR|26.1575|31.6579|19.4601|22.7245
RHLU|22.966|31.0049|19.7582|26.2709
RHRC|28.4003|31.6711|23.8718|16.0568
RHRH|22.9797|28.7285|21.5506|26.7412
RHRL|25.4991|31.9069|25.0702|17.5238
RHRR|24.3578|30.3344|23.3743|21.9335
RHRU|21.0133|29.6857|23.5291|25.7719
RHUC|27.2076|31.2847|27.6626|13.8451
RHUH|22.3213|28.5435|26.0385|23.0967
RHUL|24.6942|31.6438|28.6394|15.0226
RHUR|23.6455|30.2176|27.3808|18.7561
RHUU|20.6963|29.6908|27.5653|22.0476
RLCC|34.21|23.0937|20.1779|22.5184
RLCH|28.3016|19.9955|17.8017|33.9012
RLCL|30.8031|23.5522|21.4108|24.2339
RLCR|29.6946|21.7168|19.6988|28.8898
RLCU|25.9917|21.3048|19.8055|32.898
RLHC|30.1345|20.2197|31.227|18.4188
RLHH|25.1134|17.3281|29.6235|27.935
RLHL|27.0734|20.7312|31.9561|20.2393
RLHR|26.172|18.9954|30.8767|23.9559
RLHU|22.8692|18.6411|30.8849|27.6048
RLLC|34.105|24.1333|21.3168|20.4449
RLLH|28.6023|21.2097|18.8977|31.2903
RLLL|31.0871|24.7858|22.6179|21.5092
RLLR|29.9591|23.0419|20.8094|26.1896
RLLU|26.8902|22.7306|21.0439|29.3353
RLRC|32.2345|22.2371|25.9917|19.5367
RLRH|26.9|19.3938|23.9218|29.7844
RLRL|29.185|22.7776|27.1122|20.9252
RLRR|28.1599|21.0652|25.5039|25.271
RLRU|24.9741|20.709|25.7423|28.5746
RLUC|31.208|22.3919|29.1514|17.2487
RLUH|26.4875|19.5163|27.4785|26.5177
RLUL|28.6184|22.8295|30.0521|18.5
RLUR|27.6328|21.2723|28.8395|22.2554
RLUU|24.7725|21.0182|28.9855|25.2238
RRCC|32.2339|27.7301|19.2668|20.7692
RRCH|26.3156|24.3048|16.7652|32.6144
RRCL|28.9281|27.9265|20.5135|22.6319
RRCR|27.7865|26.1426|18.6723|27.3986
RRCU|24.0734|25.4906|18.8753|31.5607
RRHC|28.3948|25.0554|29.7168|16.833
RRHH|23.1972|22.0188|28.041|26.743
RRHL|25.424|25.3928|30.5228|18.6604
RRHR|24.4151|23.7251|29.398|22.4618
RRHU|21.0795|23.0695|29.369|26.482
RRLC|32.1571|28.4884|20.6432|18.7113
RRLH|26.6951|25.3654|18.2917|29.6478
RRLL|29.1535|28.9801|22.008|19.8584
RRLR|28.0212|27.323|20.1238|24.532
RRLU|25.014|26.7345|20.4546|27.7969
RRRC|30.3413|26.8844|24.9803|17.794
RRRH|25.1459|23.6478|22.8343|28.372
RRRL|27.3031|27.2041|26.2019|19.2909
RRRR|26.2635|25.5927|24.5349|23.6089
RRRU|23.0434|25.0753|24.7036|27.1777
RRUC|29.2789|26.7036|28.4795|15.538
RRUH|24.4293|23.8653|26.819|24.8864
RRUL|26.7327|27.1412|29.4132|16.7129
RRUR|25.6751|25.6315|28.1869|20.5065
RRUU|22.7779|25.3008|28.3543|23.567
RUCC|31.9183|31.1884|16.8174|20.0759
RUCH|26.1373|28.2267|14.427|31.209
RUCL|28.744|31.2948|18.1317|21.8295
RUCR|27.594|29.7225|16.3067|26.3768
RUCU|24.1577|28.8531|16.6007|30.3885
RUHC|28.3824|29.1684|26.024|16.4252
RUHH|23.3945|26.4732|24.2619|25.8704
RUHL|25.5142|29.2319|27.1076|18.1463
RUHR|24.4998|27.8436|25.8246|21.832
RUHU|21.2868|27.0175|25.9947|25.701
RULC|31.8713|31.8412|17.9689|18.3186
RULH|26.5982|29.0029|15.5963|28.8026
RULL|29.1349|31.981|19.4488|19.4353
RULR|28.033|30.5963|17.5613|23.8094
RULU|25.049|29.9296|17.9575|27.0639
RURC|30.2|30.5608|21.8048|17.4344
RURH|25.1115|27.8445|19.5557|27.4883
RURL|27.4102|30.6749|23.0496|18.8653
RURR|26.3639|29.228|21.4175|22.9906
RURU|23.1691|28.6814|21.7244|26.4251
RUUC|29.4187|30.3602|24.736|15.4851
RUUH|24.6356|28.0314|22.9396|24.3934
RUUL|26.8751|30.5604|25.9051|16.6594
RUUR|25.9141|29.3171|24.5589|20.2099
RUUU|23.1087|28.7776|24.7896|23.3241
UCCC|37.723|18.6453|21.5991|22.0326
UCCH|31.4344|15.8387|19.0374|33.6895
UCCL|33.18|19.6244|23.0107|24.1849
UCCR|32.3269|17.6886|21.0742|28.9103
UCCU|28.0551|17.5685|21.3315|33.0449
UCHC|33.6544|15.9581|32.5742|17.8133
UCHH|28.2591|13.33|31.0317|27.3792
UCHL|29.5243|16.8867|33.6989|19.8901
UCHR|28.9385|15.067|32.4998|23.4947
UCHU|24.8115|14.9583|32.6552|27.575
UCLC|36.9649|19.8313|23.356|19.8478
UCLH|31.2896|17.0259|20.7515|30.933
UCLL|33.0952|20.751|24.8814|21.2724
UCLR|32.2812|18.9624|22.9651|25.7913
UCLU|28.5658|18.9987|23.3314|29.1041
UCRC|35.3139|17.855|27.8125|19.0186
UCRH|29.8948|15.252|25.6484|29.2048
UCRL|31.2338|18.9212|29.2796|20.5654
UCRR|30.6569|17.0752|27.4225|24.8454
UCRU|26.7213|17.0098|27.8725|28.3964
UCUC|33.8595|18.0515|31.539|16.55
UCUH|28.8872|15.4681|29.8951|25.7496
UCUL|30.3142|18.9813|32.8833|17.8212
UCUR|29.7205|17.2628|31.4909|21.5258
UCUU|26.2664|17.3032|31.8435|24.5869
UHCC|35.1171|28.2365|17.7474|18.899
UHCH|29.0523|25.1644|15.1676|30.6157
UHCL|30.82|29.073|19.1759|20.9311
UHCR|30.0057|27.1648|17.2497|25.5798
UHCU|25.6619|26.7615|17.4985|30.0781
UHHC|31.6686|26.0959|26.9421|15.2934
UHHH|26.3064|23.3438|25.2485|25.1013
UHHL|27.7196|26.9932|28.0374|17.2498
UHHR|27.1132|25.1106|26.7648|21.0114
UHHU|22.8649|24.8317|26.9994|25.304
UHLC|34.473|29.0526|19.473|17.0014
UHLH|28.9098|26.2377|16.9488|27.9037
UHLL|30.8124|29.9227|21.0035|18.2614
UHLR|30.0675|28.1859|18.9728|22.7738
UHLU|26.2916|28.0561|19.4865|26.1658
UHRC|33.1143|27.6599|23.078|16.1478
UHRH|27.7259|24.8517|20.8721|26.5503
UHRL|29.1924|28.5692|24.503|17.7354
UHRR|28.5161|26.7604|22.7971|21.9264
UHRU|24.5756|26.5132|23.1192|25.792
UHUC|31.7203|27.5214|26.7338|14.0245
UHUH|26.793|24.9177|25.1004|23.1889
UHUL|28.2725|28.4693|27.9376|15.3206
UHUR|27.6234|26.8663|26.5883|18.922
UHUU|24.1998|26.677|26.9317|22.1915
ULCC|38.1258|19.9333|19.7146|22.2263
ULCH|32.0879|17.0801|17.3515|33.4805
ULCL|33.7694|20.9375|21.0513|24.2418
ULCR|33.1056|18.8983|19.2031|28.793
ULCU|29.1353|18.8017|19.5205|32.5425
ULHC|34.383|17.2512|30.0272|18.3386
ULHH|29.21|14.606|28.5941|27.5899
ULHL|30.3378|18.1812|31.2243|20.2567
ULHR|29.7867|16.3675|29.9931|23.8527
ULHU|25.9903|16.3087|30.1701|27.5309
ULLC|37.6437|21.1894|20.7652|20.4017
ULLH|32.1061|18.3931|18.4423|31.0585
ULLL|33.8799|22.1|22.34|21.6801
ULLR|33.1505|20.3913|20.4206|26.0376
ULLU|29.7295|20.3634|20.8313|29.0758
ULRC|36.1187|19.26|25.1822|19.4391
ULRH|30.6951|16.5819|23.1802|29.5428
ULRL|32.2304|20.2202|26.5116|21.0378
ULRR|31.5916|18.4334|24.8379|25.1371
ULRU|27.869|18.3734|25.2737|28.4839
ULUC|34.9665|19.4874|28.1816|17.3645
ULUH|30.1082|16.8997|26.5573|26.4348
ULUL|31.4097|20.4313|29.4731|18.6859
ULUR|30.8458|18.7247|28.0659|22.3636
ULUU|27.6942|18.7269|28.3355|25.2434
URCC|36.6279|23.9678|18.7179|20.6864
URCH|30.585|20.9265|16.3791|32.1094
URCL|32.389|24.788|20.1406|22.6824
URCR|31.6436|22.8377|18.2453|27.2734
URCU|27.4522|22.576|18.5756|31.3962
URHC|33.0717|21.3985|28.6479|16.8819
URHH|27.8883|18.5661|27.1144|26.4312
URHL|29.001|22.2998|29.8636|18.8356
URHR|28.52|20.4886|28.4483|22.5431
URHU|24.4452|20.2725|28.7831|26.4992
URLC|36.0868|25.0179|20.1558|18.7395
URLH|30.5833|22.1382|17.6986|29.5799
URLL|32.401|25.9457|21.6704|19.9829
URLR|31.5422|24.0765|19.8291|24.5522
URLU|27.9577|24.095|20.1901|27.7572
URRC|34.6891|23.2387|24.1741|17.8981
URRH|29.3049|20.4171|22.1178|28.1602
URRL|30.6788|24.2613|25.5704|19.4895
URRR|30.0972|22.3424|23.9912|23.5692
URRU|26.3549|22.1876|24.2789|27.1786
URUC|33.3313|23.3054|27.6047|15.7586
URUH|28.5182|20.6015|25.9582|24.9221
URUL|29.9487|24.2631|28.7709|17.0173
URUR|29.3384|22.5467|27.4268|20.6881
URUU|26.0819|22.425|27.7269|23.7662
UUCC|36.166|27.0558|16.64|20.1382
UUCH|30.3426|24.1748|14.3226|31.16
UUCL|32.1383|27.7507|18.0367|22.0743
UUCR|31.4436|25.8999|16.1892|26.4673
UUCU|27.4746|25.6155|16.5926|30.3173
UUHC|33.0591|24.841|25.4416|16.6583
UUHH|27.8532|22.3759|23.8869|25.884
UUHL|29.0931|25.5138|26.909|18.4841
UUHR|28.5007|24.0076|25.3809|22.1108
UUHU|24.6566|23.6333|25.7284|25.9817
UULC|35.8112|27.9121|17.8591|18.4176
UULH|30.4636|25.1697|15.5283|28.8384
UULL|32.2313|28.7026|19.4239|19.6422
UULR|31.4531|27.0439|17.5411|23.9619
UULU|28.0936|26.9011|17.9826|27.0227
UURC|34.4914|26.4663|21.4292|17.6131
UURH|29.2696|23.8853|19.3129|27.5322
UURL|30.7205|27.2163|22.98|19.0832
UURR|30.144|25.5384|21.1814|23.1362
UURU|26.39|25.3916|21.6302|26.5882
UUUC|33.4498|26.4048|24.4663|15.6791
UUUH|28.6114|24.0226|22.6916|24.6744
UUUL|30.0388|27.2938|25.6623|17.0051
UUUR|29.4459|25.6668|24.2234|20.6639
UUUU|26.2283|25.6173|24.5989|23.5555

What to do as any player:

 * Play H
 * Being the first to start is a small advantage

To counteract this:

 * Play H

## External links

 * [Dutch tutorial](https://youtu.be/P4CWD06RxUw) 
 * [Chinese/Japanese tutorial](https://youtu.be/clnthCZ3mz0)


