# TNT Script used by Guoyi

The TNT script follows MIT and part of script is from setk.run belonging to Salvador Arias (Instituto Miguel Lillo, San Miguel de Tucumán, Argentina).

## Usage

- Place this script and your matrix tnt file `filename` under the folder that you call `tnt` or `exe` file is placed

- Enter `tnt`

- Enter command `guoyi filename;`

## Functions

- Estimate implied weighting K value.      

- Search trees via TBR Mult and Xmult.     

- Perform Strict consensus.            

- Calculate Relative Bremer support, jackknifing, and bootstrap.

- Map apomorphic characters on the consensus tree.

- Calculate TL, CI, and RI. 

## Options

- Results instructions are at the end of `tnt.log`.

- `trees.tre`, `con.tre` are trees with taxname.

- `trees_no.tre`, `con_no.tre` are trees without taxname.

- `nelsen` can be replaced by `majority`.

- `xmult` and `mult` replications and hold trees number can be adjusted.

- `winclada.tre` can be transferred to the acceptable format for WinClada by tnt2winclada and the output file can be put into Winclada with your tnt matrix file `filename` for mapping apomorphic characters and homoplasy.

# TNT2WinClada

```
~|~|\ |~|~  ~)  |    |o._ |~| _  _| _ 
 | | \| |   /_   \/\/ || ||_|(_|(_|(_|

MIT, Guoyi Zhang, 2023
```

## Function

Convert TNT output tree file without tags and taxname, e.g. `winclada.tre` produced by TNT script, to WinClada acceptable format tree.

## Compile

### Linux & Unix

```
g++ tnt2winclada.cpp -o tnt2winclada
```

or

```
clang++ -o tnt2winclada tnt2winclada.cpp
```

### Windows

```
cl /EHsc tnt2winclada.cpp
```

## Usage

```
tnt2winclada -i ${input_file} -o ${output_file}
```
