# guoyi.run

[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.8428198.svg)](https://doi.org/10.5281/zenodo.8428198)

TNT Script for Maximum Parsimony Analysis (Phylogeny)

## Usage

- Place this script and your matrix tnt file `filename` under the folder that you call `tnt` or `exe` file is placed

- Enter `tnt`

- Enter command `guoyi filename;`

## Functions

- Extended implied weighting with K value setting (default, default K=12) or implied weighting with K value setting (default K=12) or equal weighting.      

- Search trees via implicit enumeration (ntax<=25, but not for eiw) or TBR Mult (1000 times) with branch swapping (25<ntax<75, also for ntax<=25 with eiw) or Mult with branch swapping and Xmult (use random sectorial searches, produce 50 hits to best length and stop, 10 cycles of drifting, ratchet and fusing) (ntax>=75).      

- Perform Strict consensus / Majority-rule consensus (without bremer support variations) / Half strict consensus (without bremer support variations).            

- Calculate relative Bremer support, jackknifing (1,000 times), bootstrap (1,000 times) and symmetric resampling (1,000 times).

- Map apomorphic characters on the consensus tree.

- Calculate TL, CI, and RI. 

## Options

For Windows users

```
tnt run guoyi.run filename datatype weight 0/K cons resample prefix;
```

For Linux and Mac users

```
tnt run guoyi.run filename datatype weight 0/K cons resample prefix,
```

- datatype should be `32`, `dna`, `prot`, `num` or any types tnt allowed 

  -  num=number, dna=DNA, prot=protein, 32=max number allowed (default)        

- weight should be `iw`, `ew`, `eiw`

  -  iw=implied weight, ew=equal weight, eiw=extended implied weight (default) N.B. ew must followed 0 (the K value position for ew iw and eiw)               

- K is `12` (default) following Goloboff et al. 2017 (Cladistics 34: 407–437)

  - it must more than 0 

- cons should be `str`, `mjr`, `hlf`  

  -  mjr=majority rule, hlf=half, str=strict (default)                   

- resample should be sum of what you want

  -  relative bremer support (rbrs)=0.1, bremer support (brs)=0.2, jackknifing (jak)=1, bootstrap (boot)=2, symmetric resampling (sym)=4 i.e. rbrs+jak+boot+sym=7.1 (default)       

- prefix can  be empty or a string

  - default is empty

## Results

- Results instructions are at the end of `tnt.log`.

- `*.tre` are trees with taxname, `*_no.tre` are trees without taxname.

- `*.tnt.tre` can be read by TNT/WinClada directly.

- `*.ctf` can only be read by TNT via `shortread`.

- `*.svg` is the tree file, which can be edited by [inkscape](https://inkscape.org)

- `original*` is the consensus tree.

- `apo.tre` is the apomorphic character mapping tree.

- `resample.tre` is the consensus tree with support.

- `trees*.tre` contains he MPTs.

- `resample/apo.log` contains the tree tags.

- `eiw.log` contains character concavities.

- `homo.log` contains homoplasy report of all characters.

- `report.log` contains CI RI TL.

- `winclada.ss` includes data matrix and consensus tree and it can be read by winclada directly.

- `winclada.tre` can be transferred to the acceptable format for WinClada by tnt2winclada and the output file can be put into Winclada with your tnt matrix file `filename` for mapping apomorphic characters and homoplasy.

## Cite

Cite this script is mandatory, list me (Guoyi Zhang) in your Acknowledgements is recommended. This script follows MIT License.

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
mkdir -p build && cd build
cmake ..
make && make install
```

### Windows

```
cl /EHsc tnt2winclada.cpp
```

## Usage

```
tnt2winclada -i ${input_file} -o ${output_file}
```

Interactive commands are also available.

```
tnt2winclada

~|~|\ |~|~  ~)  |    |o._ |~| _  _| _ 
 | | \| |   /_   \/\/ || ||_|(_|(_|(_|
TNT2WinClada
MIT, Guoyi Zhang, 2023
please type help to see more commands

tnt2winclada> help
help			show interactive commands help
input <filename>	input a TNT output tree from the specified file
output <filename>	output a winclada accessible tree file
quit			quit the program
exit			exit the program

tnt2winclada>
```
