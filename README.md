# TNT Script used by Guoyi

This script follows MIT and part of script is from setk.run belonging to Salvador Arias (Instituto Miguel Lillo, San Miguel de Tucumán, Argentina).

## Usage

- Place this script and your matrix tnt file `filename` under the folder that you call `tnt` or `exe` file is placed

- Enter `tnt`

- Enter command `guoyi filename;`

## Functions

- Estimate implied weighting K value.      

- Search trees via TBR Mult and Xmult.     

- Perform Strict consensus.            

- Calculate Relative Bremer support, jackknifing, and bootstrap.

- Calculate TL, CI, and RI. 

## Options

- Results instructions are at the end of `tnt.log`.

- `trees.tre`, `con.tre` are trees with taxaname.

- `trees_no.tre`, `con_no.tre` are trees without taxaname.

- `con_no.tre` can be put into Winclada with your tnt matrix file `filename`.

- `nelsen` can be replaced by `majority`.

- `xmult` and `mult` replications and hold trees number can be adjusted.

